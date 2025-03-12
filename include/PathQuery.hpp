#pragma once
#include "ProcessData.hpp"
#include "DefaultConstants.hpp"

struct SimulationParameters {
    explicit SimulationParameters() = default;
    explicit SimulationParameters(SolverType _solver, Time _time, Time _dt, std::size_t _samples)
        : solver(_solver)
        , time(_time)
        , dt(_dt)
        , samples(_samples)
    {
        AssertValidParameters();
    }
    auto AssertValidParameters() const -> void
    {
        if (dt <= 0 || time <= 0) {
            throw std::invalid_argument("Time and points must be greater than 0");
        }
    }
    [[nodiscard]] auto Points() const -> std::size_t
    {
        return static_cast<std::size_t>(std::ceil(time / dt));
    }
    SolverType solver = SimulationDefault::solver;
    Time time = SimulationDefault::time;
    Time dt = SimulationDefault::dt;
    std::size_t samples = SimulationDefault::samples;
};

struct ProcessDefinition {
private:
    static constexpr ProcessType defaultProcess = ProcessType::BM;
public:
    ProcessType type = defaultProcess;
    Drift drift = ProcessData::GetDrift(defaultProcess, ProcessData::GetMuData(defaultProcess).defaultValue);
    Diffusion diffusion = ProcessData::GetDiffusion(defaultProcess, ProcessData::GetSigmaData(defaultProcess).defaultValue);
    State startValueData = ProcessData::GetStartValueData(defaultProcess).defaultValue;

    ProcessDefinition() = default;
    ProcessDefinition(const ProcessType t)
        : type(t)
        , drift(ProcessData::GetDrift(t, ProcessData::GetMuData(t).defaultValue))
        , diffusion(ProcessData::GetDiffusion(t, ProcessData::GetSigmaData(t).defaultValue))
        , startValueData(ProcessData::GetStartValueData(t).defaultValue)
    {}

    ProcessDefinition(const ProcessType t, Drift d, Diffusion diff, const State start)
        : type(t)
        , drift(d)
        , diffusion(diff)
        , startValueData(start)
    {
    }
};

struct PathQuery {
    const ProcessDefinition processDefinition;
    const SimulationParameters simulationParameters;
    PathQuery(const ProcessDefinition& def, const SimulationParameters& simParam)
        : processDefinition(def)
        , simulationParameters(simParam)
    {
    }
};