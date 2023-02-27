#include "StepperFsm.h"
#include "types.h"
#include "Convert.h"

namespace StepperFsm
{

	// ----------------------------------------------------------------------------
	// Motor states
	//

	class Stopped
		: public StepperState
	{
		void entry() override{};
	};

	class CCW
		: public StepperState
	{
		void entry() override
		{
			direction = Stepper::CCW;
		};
	};

	class CW
		: public StepperState
	{
		void entry() override
		{
			direction = Stepper::CW;
		};
	};

	// ----------------------------------------------------------------------------
	// Base State: default implementations
	//

	void StepperState::react(StopEvent const &)
	{
		zStepper.Stop();
		transit<Stopped>();
	}

	void StepperState::react(MoveEvent const &move)
	{
		if (move.distance == 0)
		{
			zStepper.Stop();
			transit<Stopped>();
		}
		else if (move.distance < 0)
		{
			zStepper.Move(move.distance);
			transit<CW>();
		}
		else
		{
			transit<CCW>();
		}
	}

	StepperState::StepperState()
	{
		zStepper.StartService(Util::Convert::LeadInMM());
	}

	Stepper StepperState::zStepper;

	
}
// ----------------------------------------------------------------------------
	// Initial state definition
	//
FSM_INITIAL_STATE(StepperFsm::StepperState, StepperFsm::Stopped);