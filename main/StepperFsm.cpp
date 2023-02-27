#include "StepperFsm.h"
#include "types.h"
#include "Convert.h"

// ----------------------------------------------------------------------------
// Motor states
//

class Stopped
	: public StepperState
{
	void entry() override
	{
	};
};

class CCW
	: public StepperState
{
	void entry() override
	{
		//std::cout << "Motor: moving CCW" << std::endl;
		direction = Stepper::CCW;
	};
};

class CW
	: public StepperState
{
	void entry() override
	{
		//std::cout << "Motor: moving CW" << std::endl;
		direction = Stepper::CCW;
	};
};

// ----------------------------------------------------------------------------
// Base State: default implementations
//

void StepperState::react(StepperStopEvent const &)
{
	transit<Stopped>();
}

void StepperState::react(StepperMoveEvent const & move)
{
	if (move.distance == 0)
	{
		transit<Stopped>();
	}
	else if (move.distance < 0)
	{
		transit<CW>();
	}
	else
	{
		transit<CCW>();
	}
}

StepperState::StepperState()
{
}

// ----------------------------------------------------------------------------
// Initial state definition
//
FSM_INITIAL_STATE(StepperState, Stopped)