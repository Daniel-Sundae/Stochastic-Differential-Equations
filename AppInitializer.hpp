#pragma once
#include <memory>
#include <vector>
#include "IViewComponent.hpp"
#include "IPresenterComponent.hpp"
#include "IModelComponent.hpp"
class AppInitializer {
public:
	explicit AppInitializer();
	auto AppHealthy() const -> bool;

private:
	auto InitializeComponents() -> void;
	auto ConnectComponents() -> void;
	
	std::vector<std::unique_ptr<IViewComponent>> m_viewComponents;
	std::vector<std::unique_ptr<IPresenterComponent>> m_presenterComponents;
	std::vector<std::unique_ptr<IModelComponent>> m_modelComponents;
};