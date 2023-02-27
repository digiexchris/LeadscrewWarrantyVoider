/* C++ exception handling example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include "main.h"
#include "Stepper.h"
#include "Convert.h"

#include <iostream>

/* Inside .cpp file, app_main function must be declared with C linkage */
extern "C" void app_main(void)
{
	//TODO move events somewhere common since one event can be used by multiple FSMs.

	auto stepperFsmList = new tinyfsm::FsmList<StepperFsm::StepperState,MeasurementSystem::MeasurementSystemState>;
	stepperFsmList->start();
}
