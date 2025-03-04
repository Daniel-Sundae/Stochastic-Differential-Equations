﻿#include "DistributionChart.hpp"
#include <QtCharts/qbarset.h>
#include <QtCharts/qbarseries.h>
#include <QtCharts/qvalueaxis.h>

DistributionChart::DistributionChart()
	: QChart()
	, m_xAxis(new QValueAxis(this))
	, m_yAxisRelativeCount(new QValueAxis(this))
	, m_yAxisPDF(new QValueAxis(this))
	, m_expValLine(nullptr)
	, m_theoreticalPDF(nullptr)
{
	InitializeAxis();
	InitializeDistributionChart();
}

auto DistributionChart::UpdateTitle(const PathQuery& pQuery) -> void
{
	QString title;
	QTextStream ts(&title);
	ts << "Sampled distribution";
	if (ProcessData::GetSolution(pQuery.processDefinition.type)){
		ts << " vs theoretical Probability Density Function";
	}

		//<< QString::fromUtf8(ProcessData::GetName(pQuery.processDefinition.type))
		//<< ": "
		//<< QString::fromUtf8(ProcessData::GetDefinition(pQuery.processDefinition.type))
		//<< " with μ = "
		//<< QString::number(pQuery.processDefinition.drift.Mu())
		//<< ", σ = "
		//<< QString::number(pQuery.processDefinition.diffusion.Sigma())
		//<< ", X<sub>0</sub> = "
		//<< QString::number(pQuery.processDefinition.startValueData)
		//<< '\n'
		//<< "Simulation: Time = "
		//<< QString::number(pQuery.simulationParameters.time)
		//<< ", dt = "
		//<< QString::number(pQuery.simulationParameters.dt)
		//;
	setTitle(title);
}

auto DistributionChart::PlotDistribution(const std::vector<State>& results) -> void
{
	const auto [min_it, max_it] = std::minmax_element(results.begin(), results.end());
	const double barChartWidth = std::min(*max_it - *min_it, 0.5);
	const std::size_t numBins = 20;
	const double binWidth = barChartWidth / numBins;

	std::vector<int> histogram(numBins, 0);
	for (double res : results) {
		int binIndex = static_cast<int>((res - *min_it) / binWidth);
		histogram[binIndex]++;
	}
	QBarSeries* series = new QBarSeries(this);
	QBarSet* set = new QBarSet("Distribution");  // Give it a meaningful name
	for (int count : histogram) {
		set->append(count);
	}
	series->append(set);
	addSeries(series);
}

auto DistributionChart::ClearDistribution() -> void
{
	removeAllSeries();
}

auto DistributionChart::PlotTheoreticalPDF(const std::vector<double> density) -> void
{
}

auto DistributionChart::PlotExpValLine(const State EV) -> void
{
	if(EV){}
}

auto DistributionChart::InitializeAxis() -> void
{
	addAxis(m_xAxis, Qt::AlignBottom);
	addAxis(m_yAxisRelativeCount, Qt::AlignLeft);
	addAxis(m_yAxisPDF, Qt::AlignRight);
	m_xAxis->setTitleText("X<sub>T</sub>");
	m_yAxisRelativeCount->setTitleText("Relative count (%)");
	m_yAxisPDF->setTitleText("Pdf (%)");
	m_xAxis->setGridLineVisible(false);
	m_yAxisRelativeCount->setGridLineVisible(false);
	m_yAxisPDF->setGridLineVisible(false);
	m_xAxis->setRange(0, 10);
	m_yAxisRelativeCount->setRange(0, 1);
	m_yAxisPDF->setRange(0, 1);
}

auto DistributionChart::InitializeDistributionChart() -> void
{
}

