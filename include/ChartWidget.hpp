#pragma once

#include <QtWidgets/qwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtCharts/qchartview.h>
#include <QtCharts/qchart.h>


class ChartWidget : public QWidget{
public:
    explicit ChartWidget(QWidget* parent = nullptr);
private:
    QVBoxLayout* m_layout;
    QChartView* m_chartView;
    QChart* m_chart;
};