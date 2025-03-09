#include "PathEngine.hpp"
#include "Utils.hpp"
#include "PathQuery.hpp"
#include "PDFQuery.hpp"
#include "assert.h"

auto PathEngine::SamplePaths(const PathQuery& pathQuery) const -> Paths
{
    const auto samplePath = [this, &pathQuery]() -> Path {
        const std::size_t points = pathQuery.simulationParameters.Points();
        auto& drift = pathQuery.processDefinition.drift;
        auto& diffusion = pathQuery.processDefinition.diffusion;
        const Time dt = pathQuery.simulationParameters.dt;
        const State startValueData = pathQuery.processDefinition.startValueData;
        Path path = {};
        assert(points != 0);
        path.reserve(points);
        path.push_back(startValueData);
        for (std::size_t i = 1; i < points; ++i)
            path.push_back(path.back() + Increment(drift, diffusion, static_cast<Time>(i) * dt, path.back(), dt));
        return path;
    };
    Paths paths;
    const std::size_t samples = pathQuery.simulationParameters.samples;
    paths.reserve(samples);
    for (std::size_t i = 0; i<samples; ++i)
        paths.push_back(samplePath());
    return paths;
}

auto PathEngine::SamplePDF(const PDFQuery& pdfQuery) const -> PDFData
{
    const std::size_t points = pdfQuery.points;
    
    // const double increment = pdfQuery.increment;
    const double start = pdfQuery.pdf.EV() - 5*pdfQuery.pdf.StdDev();
    const double end = pdfQuery.pdf.EV() + 5*pdfQuery.pdf.StdDev();
    const double increment = (end - start)/points;
    PDFData data = {};
    data.reserve(points);
    for (std::size_t i = 0; i < points; ++i)
        data.push_back(pdfQuery.pdf(start + i * increment));
    return data;
}

auto PathEngine::Increment(
    const Drift& drift,
    const Diffusion& diffusion,
    const Time t,
    const State Xt,
    const Time dt) const -> State
{
    return drift(t, Xt) * dt + diffusion(t, Xt) * Utils::db(dt);
}

