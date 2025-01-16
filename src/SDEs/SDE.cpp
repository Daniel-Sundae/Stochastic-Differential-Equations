#include <vector>
#include "SDE.hpp"
#include "Utils.hpp"

SDE::SDE(
    const std::function<double(Time, State)> drift,
    const std::function<double(Time, State)> diffusion,
    const double startPos
):
m_drift(std::move(drift)),
m_diffusion(std::move(diffusion)),
m_startPos(startPos)
{}

auto SDE::Sample(int points, double dt) const -> Path
{
    std::vector<double> path = {};
    path.reserve(points);
    if(points <= 0) return path;
    path.push_back(StartPos());
    for(int i=1; i<points; ++i)
    {
        path.push_back(path.back() + Increment(i * dt, path.back(), dt));
    }
    return path;
}

auto SDE::Drift() const -> std::function<double(Time, State)>
{
    return m_drift;
}

auto SDE::Diffusion() const -> std::function<double(Time, State)>
{
    return m_diffusion;
}

auto SDE::StartPos() const -> double
{
    return m_startPos;
}

auto SDE::Increment(double TIME, double STATE, double dt) const -> double
{
    return Drift()(TIME, STATE) * dt + Diffusion()(TIME, STATE) * Utils::db(dt);
}


