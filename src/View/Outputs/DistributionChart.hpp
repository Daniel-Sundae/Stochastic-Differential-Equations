#pragma once
#include "PathQuery.hpp"
#include <QtCharts/qchart.h>

class QValueAxis;
class QLineSeries;
class QBarSeries;
class QBarSet;

class DistributionChart : public QChart {
    Q_OBJECT

public:
    explicit DistributionChart();
    auto UpdateTitle(const ProcessType type) -> void;
    auto PlotDistribution(const Distribution& results) -> void;
    auto ClearDistributionChart() -> void;
    auto UpdateDistributionChartPDF(const PDFData& pdfData) -> void;
    auto PlotExpValLine(const State EV) -> void;
    auto SetDistributionChartSupport(const Range range) -> void;
private:
    auto DistributionSet() const -> QBarSet*;
    auto InitializeAxis() -> void;
    auto InitializeDistributionChart() -> void;
private:
    QValueAxis* m_xAxis;
    QValueAxis* m_yAxisRelativeCount;
    QValueAxis* m_yAxisDensity;
    QLineSeries* m_expValLine;
    QLineSeries* m_pdf;
    QBarSeries* m_distribution;
};