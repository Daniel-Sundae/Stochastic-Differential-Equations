﻿#include "DefinitionManager.hpp"
#include "DefaultConstants.hpp"
#include "InputManager.hpp"
#include "ViewUtils.hpp"
#include <QtWidgets/qdoublespinbox>
#include <QtWidgets/qcombobox>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlabel.h>

DefinitionManager::DefinitionManager(InputManager *parent)
    : QGroupBox(parent)
{
    AddDefinitionWidgets();
    InitializeDesign();
}


auto DefinitionManager::AddDefinitionWidgets() -> void
{
    std::array<ProcessType, 2> processTypes = {
        ProcessType::BM,
        ProcessType::GBM,
    };
    auto* processes = new QComboBox(this);
    for (int i = 0; i < processTypes.size(); ++i) {
        processes->insertItem(i, QString::fromStdString(std::string(ProcessData::Acronym(processTypes[i]))));
        processes->setItemData(i, QString::fromStdString(std::string(ProcessData::Name(processTypes[i]))), Qt::ToolTipRole);
    }
    m_widgets[DefinitionWidget::PROCESS] = processes;
    m_widgets[DefinitionWidget::MU] = GUI::CreateDoubleSpinBox(this, -0.3, 0.3, DefinitionDefault::mu, 0.05);
    m_widgets[DefinitionWidget::SIGMA] = GUI::CreateDoubleSpinBox(this, 0.0, 20, DefinitionDefault::sigma, 0.1);
    m_widgets[DefinitionWidget::STARTVALUE] = GUI::CreateDoubleSpinBox(this, -20.0, 20.0, DefinitionDefault::startValue, 1.0);
    connect(
        qobject_cast<QComboBox*>(m_widgets[DefinitionWidget::PROCESS]),
        QOverload<int>::of(&QComboBox::currentIndexChanged),
        this,
        [this, processTypes]() {
            OnProcessTypeModified(processTypes[qobject_cast<QComboBox*>(m_widgets[DefinitionWidget::PROCESS])->currentIndex()]);
        }
    );
    connect(
        qobject_cast<QDoubleSpinBox*>(m_widgets[DefinitionWidget::MU]),
        QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this,
        [this]() { OnProcessDefinitionModified(DefinitionWidget::MU); });
    connect(
        qobject_cast<QDoubleSpinBox*>(m_widgets[DefinitionWidget::SIGMA]),
        QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this,
        [this]() { OnProcessDefinitionModified(DefinitionWidget::SIGMA); });
    connect(
        qobject_cast<QDoubleSpinBox*>(m_widgets[DefinitionWidget::STARTVALUE]),
        QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this,
        [this]() { OnProcessDefinitionModified(DefinitionWidget::STARTVALUE); });

}

auto DefinitionManager::InitializeDesign() -> void
{
    setTitle("Definition");
    setStyleSheet(GUI::GroupBoxDescription() + GUI::ComboBoxDescription() + GUI::SpinBoxDescription());
    auto* definitionLayout = new QFormLayout(this);
    definitionLayout->addRow(new QLabel("Process:", this), m_widgets[DefinitionWidget::PROCESS]);
    definitionLayout->addRow(new QLabel("Drift (μ):", this), m_widgets[DefinitionWidget::MU]);
    definitionLayout->addRow(new QLabel("Diffusion (σ):", this), m_widgets[DefinitionWidget::SIGMA]);
    definitionLayout->addRow(new QLabel("Start (X<sub>0</sub>):", this), m_widgets[DefinitionWidget::STARTVALUE]);
}

auto DefinitionManager::Parent() const -> InputManager*
{
    return qobject_cast<InputManager *>(parent());
}

auto DefinitionManager::OnProcessTypeModified(const ProcessType newType) const -> void
{
    Parent()->OnProcessTypeModified(newType);
}

auto DefinitionManager::OnProcessDefinitionModified(const DefinitionWidget param) const -> void
{
    Parent()->OnProcessDefinitionModified(param, qobject_cast<QDoubleSpinBox*>(m_widgets.at(param))->value());
}
