#pragma once
#include "ProcessData.hpp"
#include "InputHandler.hpp"
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGroupBox>

class ActionManager;
class DefinitionManager;
class SimulationManager;
class SettingsManager;
class InputHandler;

class InputDispatcher : public QWidget
{
    Q_OBJECT

public:
    explicit InputDispatcher(QWidget* parent);
    auto SetInputHandler(InputHandler* inputHandler) -> void;
    auto OnGoButtonClicked() const -> void;
    auto OnClearButtonClicked() const -> void;
    auto OnCancelButtonClicked() const -> void;
    auto OnProcessTypeModified(const ProcessType newType) const -> void;
    auto OnProcessDefinitionModified(const DefinitionWidget param, double userValue) const -> void;
    auto OnSolverTypeModified(const SolverType newType) const -> void;
    template<IntOrDouble T>
    auto OnSimulationParameterModified(const SimulationWidget param, T userValue) const -> void {
        m_inputHandler->OnSimulationParameterModified(param, userValue);
    }
    template<IntOrBool T>
    auto OnSettingsParameterModified(const SettingsWidget param, T userValue) const -> void {
        m_inputHandler->OnSettingsParameterModified(param, userValue);
    }

private:
    ActionManager* m_actionManager;
    DefinitionManager* m_definitionManager;
    SimulationManager* m_simulationManager;
    SettingsManager* m_settingsManager;
    InputHandler* m_inputHandler;
};

class InputDispatcherGroupBox : public QGroupBox {
public:
    explicit InputDispatcherGroupBox(QWidget* parent = nullptr)
        : QGroupBox(parent)
    {}

    InputDispatcher* Parent() const {
        return qobject_cast<InputDispatcher*>(parent());
    }
};
