#pragma once
#include "Types.hpp"
#include <cassert>
#include <type_traits>
#include <cstdint>

template <IntOrDouble T>
auto InputHandler::OnSimulationParameterModified(const SimulationWidget param, T userValue) -> void
{
	switch (param) {
		case SimulationWidget::TIME:
			if constexpr (std::is_same_v<T, int>)
				m_simulationParameters->time = userValue;
			else
				assert(false && "'Time' parameter must be invoked with int type");
			break;
		case SimulationWidget::dt:
			m_simulationParameters->dt = userValue;
			break;
		case SimulationWidget::SAMPLES:
			if constexpr (std::is_same_v<T, int>)
				m_simulationParameters->samples = userValue;
			else
				assert(false && "'Samples' parameter must be invoked with int type");
			break;
		default:
			assert(false);
	}
}

template <IntOrBool T>
auto InputHandler::OnSettingsParameterModified(const SettingsWidget param, T userValue) -> void
{
	switch (param){
		case SettingsWidget::THREADS:
			if constexpr (std::is_same_v<T, bool>)
				m_settingsParameters->useThreading = userValue;
			else
				assert(false && "Threading checkbox parameter must be invoked with bool type");
			break;
		case SettingsWidget::FIXSEED:
			if constexpr (std::is_same_v<T, std::uint32_t>)
				if(userValue == 0){
					m_settingsParameters->useSeed = {false, 0};
				}
				else{
					m_settingsParameters->useSeed = {true, userValue};
				}
			else
				assert(false && "Seeding checkbox parameter must be invoked with uint32_t type");
			break;
		default:
			assert(false);
	}			
}