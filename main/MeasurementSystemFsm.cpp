#include "MeasurementSystemFsm.h"
#include "tinyfsm.hpp"
#include "config.h"
#include "events.h"

// ----------------------------------------------------------------------------
// Motor states
//

namespace MeasurementSystem
{
	// ----------------------------------------------------------------------------
	// Base State: default implementations
	//

	void MeasurementSystemState::react(SwitchToSAEEvent const &)
	{
		transit<SAE>();
	}

	void MeasurementSystemState::react(SwitchToMetricEvent const &)
	{
		transit<METRIC>();
	}

	// ----------------------------------------------------------------------------
	// Initial state definition
	//
	
	
}

FSM_INITIAL_STATE(MeasurementSystem::MeasurementSystemState, MeasurementSystem::DEFAULT_MEASUREMENTSYSTEM);