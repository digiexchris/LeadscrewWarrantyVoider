#pragma once

#include "ESP_FlexyStepper.h"
#include "types.h"
#include <memory>
#include "MeasurementSystemFsm.h"

class Stepper
{
  public:
	enum Direction
	{
		CW,
		CCW
	};
	Stepper();
	void StartService(double leadInMM);
	
	__UINT16_TYPE__ GetStepsPerRotation();

	void Move(double distance);
	void Stop();

  private:
	double GetDistanceInMM(double distance, MeasurementSystem::MeasurementSystemState system);
	ESP_FlexyStepper stepper;

	__UINT16_TYPE__ stepsPerRotation;
};