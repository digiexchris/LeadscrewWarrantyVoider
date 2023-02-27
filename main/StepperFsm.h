#pragma once

#include "tinyfsm.hpp"
#include "Stepper.h"
#include "events.h"

namespace StepperFsm
{
	class StepperState
		: public tinyfsm::Fsm<StepperState>
	{
		friend class Fsm;

	  private:
		static Stepper zStepper;

		/* default reaction for unhandled events */
		void react(tinyfsm::Event const &){};

		/* non-virtual declaration: reactions are the same for all states */
		void react(MoveEvent const & move);
		void react(StopEvent const &);

		virtual void entry(void) = 0; /* pure virtual: enforce implementation in all states */
		void exit(void){};			  /* no exit actions at all */

	  protected:
		Stepper::Direction direction;

	  public:
		StepperState();
	};
}
