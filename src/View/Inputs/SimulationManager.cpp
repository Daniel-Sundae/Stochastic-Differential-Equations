﻿#include "SimulationManager.hpp"
#include "Constants.hpp"
#include "ViewUtils.hpp"
#include <QtWidgets/qcombobox.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlabel.h>


SimulationManager::SimulationManager(InputDispatcher* parent)
	: InputDispatcherGroupBox(parent)
{
    AddComboBoxes();
    AddSpinBoxes();
    InitializeDesign();
}

auto SimulationManager::AddComboBoxes() -> void
{
    std::array<std::pair< SolverType, std::pair<std::string, std::string> >, 2> solverTypes = {
    std::pair{SolverType::EULER_MARUYAMA, std::pair{"EM", "Euler-Maruyama"}},
    std::pair{SolverType::RUNGE_KUTTA, std::pair{"RK", "Runge-Kutta"}},
    };
    auto* solvers = new QComboBox(this);
    for (std::size_t i = 0; i < solverTypes.size(); ++i) {
        solvers->insertItem(static_cast<int>(i), QString::fromStdString(solverTypes[i].second.first));
        solvers->setItemData(static_cast<int>(i), QString::fromStdString(solverTypes[i].second.second), Qt::ToolTipRole);
    }

    m_widgets[SimulationWidget::SOLVER] = solvers;
    connect(
        qobject_cast<QComboBox*>(m_widgets[SimulationWidget::SOLVER]),
        QOverload<int>::of(&QComboBox::currentIndexChanged),
        this,
        [this, solverTypes]() {
            int currentIdx = qobject_cast<QComboBox*>(m_widgets[SimulationWidget::SOLVER])->currentIndex();
            SolverType newSolver = solverTypes[static_cast<std::size_t>(currentIdx)].first;
            Parent()->OnSolverTypeModified(newSolver);
        }
    );
}

template <IntOrDouble T>
auto SimulationManager::SimulationModifiedCb(SimulationWidget param) const{
    return [this, param](T newValue) {
        Parent()->OnSimulationParametersModified(param, newValue);
    };
}

auto SimulationManager::AddSpinBoxes() -> void
{
    auto* timeWidget = new QSpinBox(this);
    timeWidget->setValue(static_cast<uint64_t>(DefaultConstants::Simulation::time));
    timeWidget->setMinimum(0);
    timeWidget->setMaximum(100);
    timeWidget->setSingleStep(10);
    m_widgets[SimulationWidget::TIME] = timeWidget;
    auto* dtWidget = new QDoubleSpinBox(this);
    dtWidget->setValue(DefaultConstants::Simulation::dt);
    dtWidget->setMinimum(0);
    dtWidget->setMaximum(1);
    dtWidget->setSingleStep(0.1);
    m_widgets[SimulationWidget::dt] = dtWidget;
    auto* samplesWidget = new QSpinBox(this);
    samplesWidget->setValue(1);
    samplesWidget->setMinimum(1);
    samplesWidget->setMaximum(10000);
    samplesWidget->setSingleStep(1);
    m_widgets[SimulationWidget::SAMPLES] = samplesWidget;

    connect(
        timeWidget,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        SimulationModifiedCb<int>(SimulationWidget::TIME)
    );

    connect(
        dtWidget,
        QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this,
        SimulationModifiedCb<double>(SimulationWidget::dt)
    );

    connect(
        samplesWidget,
        QOverload<int>::of(&QSpinBox::valueChanged),
        this,
        SimulationModifiedCb<int>(SimulationWidget::SAMPLES)
    );
}

auto SimulationManager::InitializeDesign() -> void
{
    setTitle("Simulation");
    setStyleSheet(GUI::GroupBoxDescription() + GUI::ComboBoxDescription() + GUI::SpinBoxDescription());
    auto* simulationLayout = new QFormLayout(this);
    simulationLayout->addRow(new QLabel("Solver:", this), m_widgets[SimulationWidget::SOLVER]);
    simulationLayout->addRow(new QLabel("Time (T):", this), m_widgets[SimulationWidget::TIME]);
    simulationLayout->addRow(new QLabel("Time step (dt):", this), m_widgets[SimulationWidget::dt]);
    auto* samplesLabel = new QLabel("Samples:", this);
    samplesLabel->setToolTip("Nr samples (paths) to generate.");
    simulationLayout->addRow(samplesLabel, m_widgets[SimulationWidget::SAMPLES]);

}