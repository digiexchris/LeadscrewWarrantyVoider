#pragma once
#include "tinyfsm.hpp"
#include "config.h"

namespace MeasurementSystem
{
	// ----------------------------------------------------------------------------
	// Event declarations
	//

	struct SwitchToSAEEvent : tinyfsm::Event
	{
	};

	struct SwitchToMetricEvent : tinyfsm::Event
	{
	};

	class MeasurementSystemState
		: public tinyfsm::Fsm<MeasurementSystemState>
	{
		/* NOTE: react(), entry() and exit() functions need to be accessible
   * from tinyfsm::Fsm class. You might as well declare friendship to
   * tinyfsm::Fsm, and make these functions private:
   *
   * friend class Fsm;
   */
		friend class Fsm;

	  private:
		/* default reaction for unhandled events */
		void react(tinyfsm::Event const &){};

		/* non-virtual declaration: reactions are the same for all states */
		void react(SwitchToSAEEvent const &);
		void react(SwitchToMetricEvent const &);

		virtual void entry(void) = 0; /* pure virtual: enforce implementation in all states */
		void exit(void){};			  /* no exit actions at all */
	};

	class SAE : public MeasurementSystemState
	{
		void entry() override{};
	};

	class METRIC : public MeasurementSystemState
	{
		void entry() override{};
	};
}
