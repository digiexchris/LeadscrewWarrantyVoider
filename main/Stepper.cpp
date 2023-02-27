#include "Stepper.h"
#include "config.h"
#include "tinyfsm.hpp"
#include <iostream>

//Remember, all stepper distances need to be in MM. Convert to mm before you use this.
Stepper::Stepper(double leadInMM)
{
	//TODO setup the stepper engine, assign pins, set acceleration, etc
	stepper.connectToPins(Z_STEP_PIN, Z_DIR_PIN);
	stepper.setSpeedInStepsPerSecond(STEPPER_STEPS_PER_SECOND);
	stepper.setAccelerationInStepsPerSecondPerSecond(STEPPER_ACCELERATION);
	stepper.setDecelerationInStepsPerSecondPerSecond(STEPPER_DECELERATION);
	stepsPerRotation = static_cast<__UINT16_TYPE__>(STEPPER_STEPS_PER_REV) * static_cast<__UINT16_TYPE__>(DRIVER_MICROSTEPS);

	stepper.setStepsPerMillimeter(leadInMM / stepsPerRotation);
	//stepper.setStepsPerRevolution(stepsPerRotation);

	//start background service on core 1
	stepper.startAsService(1);
}

__UINT16_TYPE__ Stepper::GetStepsPerRotation()
{
	return stepsPerRotation;
}

//TODO read measurementsystem from the MeasurementSystem FSM
void Stepper::Move(double distance, Types::LeadscrewMeasurementSystem measurementSystem) 
{
	double distanceInMM = GetDistanceInMM(distance, measurementSystem);
	stepper.moveRelativeInMillimeters(distanceInMM);
}