#pragma once

#include <functional>
#include <vector>
#include "Types.hpp"

class SDE{
public:
    SDE(std::function<double(TIME, STATE)>drift, std::function<double(TIME, STATE)>diffusion);
    auto Sample(int points, double dt, double startPos = 0) const -> const std::vector<double>;
    auto Drift() const -> std::function<double(TIME, STATE)>;
    auto Diffusion() const -> std::function<double(TIME, STATE)>;

private:
    auto Increment(double TIME, double STATE, double dt) const -> double;

    const std::function<double(TIME, STATE)> m_drift;
    const std::function<double(TIME, STATE)> m_diffusion;
};
