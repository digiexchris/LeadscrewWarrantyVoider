#pragma once

#include "tinyfsm.hpp"

// ----------------------------------------------------------------------------
// Event declarations
//

struct SwitchToSAEEvent : tinyfsm::Event
{
};

struct SwitchToMetricEvent : tinyfsm::Event
{
};

// ----------------------------------------------------------------------------
// Event declarations
//

struct MoveEvent : tinyfsm::Event
{
	//can be negative or positive. Positive moves to the right.
	double distance;
};

struct StopEvent : tinyfsm::Event
{
};