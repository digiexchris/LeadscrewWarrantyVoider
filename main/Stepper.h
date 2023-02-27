#pragma once

#include "ESP_FlexyStepper.h"
#include "types.h"
#include <memory>

class Stepper
{
  public:
	enum Direction
	{
		CW,
		CCW
	};
	Stepper(double leadInMM);
	Stepper() = delete;
	
	__UINT16_TYPE__ GetStepsPerRotation();

	void Move(double distance, Types::LeadscrewMeasurementSystem measurementSystem);

  private:
	double GetDistanceInMM(double distance, Types::LeadscrewMeasurementSystem system);
	ESP_FlexyStepper stepper;

	__UINT16_TYPE__ stepsPerRotation;
};