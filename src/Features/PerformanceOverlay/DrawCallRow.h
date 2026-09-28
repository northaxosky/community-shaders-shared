#pragma once

#include <optional>
#include <string>

struct DrawCallRow
{
	std::string label;
	int shaderType;
	int drawCalls;
	float frameTime;
	float percent;
	float costPerCall;
	std::string tooltip;
	bool enabled;
	std::optional<float> testFrameTime;
	std::optional<float> testCostPerCall;
};
