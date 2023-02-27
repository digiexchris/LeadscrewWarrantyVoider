#ifndef FSMLIST_HPP_INCLUDED
#define FSMLIST_HPP_INCLUDED

#include <tinyfsm.hpp>

#include "StepperFsm.h"
#include "MeasurementSystemFsm.h"

using stepperFsmList = tinyfsm::FsmList<StepperFsm::StepperState>;

//TODO figure out how to send an event only to stepper and not machine. I'm guessing template a Machine class
//and use it in place of typename below
using machineFsmList = tinyfsm::FsmList<MeasurementSystem::MeasurementSystemState>;
//using machineFSMList = tinyfsm::FsmList<Machine>;


template<typename E>
void SendStepperEvent(E const & event)
{
	stepperFsmList::template dispatch<E>(event);
}


/** dispatch event to both "MachineState" and probably "Display" when I make that fsm*/
template <typename E>
void SendMachineEvent(E const &event)
{
	machineFsmList::template dispatch<E>(event);
}

#endif
