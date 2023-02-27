#ifndef FSMLIST_HPP_INCLUDED
#define FSMLIST_HPP_INCLUDED

#include <tinyfsm.hpp>

#include "StepperFsm.h"
#include "MeasurementSystemFsm.h"

using stepperFsmList = tinyfsm::FsmList<StepperState, MeasurementSystem::MeasurementSystemState>;
//using machineFSMList = tinyfsm::FsmList<Machine>;

/** dispatch event to both "StepperState" and "MachineState" */
template<typename E>
void send_event(E const & event)
{
	stepperFsmList::template dispatch<E>(event);
}

#endif
