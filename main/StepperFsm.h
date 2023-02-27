#pragma once

#include "tinyfsm.hpp"
#include "Stepper.h"

// ----------------------------------------------------------------------------
// Event declarations
//

struct StepperMoveEvent : tinyfsm::Event
{
	//can be negative or positive. Positive moves to the right.
	double distance;
};

struct StepperStopEvent : tinyfsm::Event
{
};

class StepperState
	: public tinyfsm::Fsm<StepperState>
{
	friend class Fsm;

  private:

	/* default reaction for unhandled events */
	void react(tinyfsm::Event const &){};

	/* non-virtual declaration: reactions are the same for all states */
	void react(StepperMoveEvent const & move);
	void react(StepperStopEvent const &);

	virtual void entry(void) = 0; /* pure virtual: enforce implementation in all states */
	void exit(void){};			  /* no exit actions at all */

  protected:
	Stepper::Direction direction;

  public:
	StepperState();
};