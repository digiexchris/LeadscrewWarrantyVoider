#include "Stepper.h"
#include "config.h"
#include "tinyfsm.hpp"
#include <iostream>
#include "MeasurementSystemFsm.h"

//Remember, all stepper distances need to be in MM. Convert to mm before you use this.
Stepper::Stepper()
{
	//setup the stepper engine, assign pins, set acceleration, etc
	stepper.connectToPins(Z_STEP_PIN, Z_DIR_PIN);
	stepper.setSpeedInStepsPerSecond(STEPPER_STEPS_PER_SECOND);
	stepper.setAccelerationInStepsPerSecondPerSecond(STEPPER_ACCELERATION);
	stepper.setDecelerationInStepsPerSecondPerSecond(STEPPER_DECELERATION);
	stepsPerRotation = static_cast<__UINT16_TYPE__>(STEPPER_STEPS_PER_REV) * static_cast<__UINT16_TYPE__>(DRIVER_MICROSTEPS);
}

void Stepper::StartService(double leadInMM) 
{
	stepper.setStepsPerMillimeter(leadInMM / stepsPerRotation);
	
	//start background service on core 1
	stepper.startAsService(1);
}

__UINT16_TYPE__ Stepper::GetStepsPerRotation()
{
	return stepsPerRotation;
}

void Stepper::Move(double distance) 
{
	if (MeasurementSystem::MeasurementSystemState::is_in_state<MeasurementSystem::SAE>())
	{
		//dunno what to do about this. since it's a move function, maybe squiz this conversion into
		//move directly
		distance *= 25.4;
		stepper.moveRelativeInMillimeters(distance);
	}
	else
	{
		stepper.moveRelativeInMillimeters(distance);
	}
}

void Stepper::Stop()
{
	stepper.setTargetPositionToStop();
}