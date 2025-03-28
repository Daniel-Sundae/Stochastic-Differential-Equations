#pragma once
#include "Types.hpp"

struct PathQuery;
struct PDFQuery;

class PathEngine{
public:
	auto SamplePaths(const PathQuery& pQuery) const -> Paths;
	auto GeneratePDFData(const PDFQuery& pdfQuery) const -> PDFData;
	auto StopWorking() const -> void;
private:
	inline auto Increment(
		const Drift& drift,
		const Diffusion& diffusion,
		const Time t,
		const State Xt,
		const Time dt) const -> State;
	bool m_isBusy;
};
