#pragma once
#include "types.h"
/*************Machine Configuration *************/

// Stepper driver Pins
#define Z_STEP_PIN 18
#define Z_DIR_PIN 33

// Spindle Encoder pins
#define EA 25
#define EB 32

//use the display or not. Recommend not, it doesn't have much functionality. Set to 1 to enable.
#define USESSD1306 0

//Leadscrew type. Choices are either LeadscrewType::SAE or LeadscrewType::METRIC
#define LEADSCREW_MEASUREMENT_SYSTEM Types::LeadscrewMeasurementSystem::SAE

//choose either SAE or METRIC
#define DEFAULT_MEASUREMENTSYSTEM SAE

/*
lead of leadscrew per revolution of chuck.
For SAE leadscrews, either measure the lead, or
use 1/TPI.
eg. 7 TPI leadscrew has a lead of 1/7 = 0.14285714285714285714285714285714
I have a 4:1 reduction inside my spindle to where my encoder is attached,
so mine is 1/28 = 0.03571428571428571428571428571429
*/
#define LEADSCREW_LEAD 0.03571428571428571428571428571429

//driver and motor settings.

//driver set to 8 microsteps
#define DRIVER_MICROSTEPS 8
//motor has 200 native steps per rev (without microstepping)
#define STEPPER_STEPS_PER_REV 200

//TODO I think this isn't necessary since we can calculate microsteps per rev with the above
#define STEPPER_DEGREES_PER_STEP 1.8

//maximum speed of the stepper
#define STEPPER_STEPS_PER_SECOND 2000

//acceleration is in steps per second per second
#define STEPPER_ACCELERATION 1200

//should be able to decelerate basically instantly
#define STEPPER_DECELERATION 12000

//DANGER do not touch below this line
