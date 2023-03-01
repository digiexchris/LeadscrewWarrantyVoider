//#include <esp_log.h>
/* C++ exception handling example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "freertos/FreeRTOS.h"
#include "main.h"
#include "Stepper.h"
#include "Convert.h"
//
#include <iostream>

void loopTask(void *pvParameter)
{
	while (1)
	{
		while (1)
		{
			auto moveEvent(MoveEvent(10));

			SendStepperEvent(moveEvent);
			printf("Sent Stepper Event\r\n");
			vTaskDelay(500 / portTICK_PERIOD_MS);
		}
	}
}

/* Inside .cpp file, app_main function must be declared with C linkage */
extern "C" void app_main(void)
{

   while(1){
      printf("Starting main");
	auto stepperFsmList = new tinyfsm::FsmList<StepperFsm::StepperState,MeasurementSystem::MeasurementSystemState>;
	stepperFsmList->start();
	printf("Main done, starting task \r\n");
	xTaskCreate(&loopTask, "loop_task", 2048, NULL, 5, NULL);
      vTaskDelay(1000/portTICK_PERIOD_MS);
   }
	
	
}
