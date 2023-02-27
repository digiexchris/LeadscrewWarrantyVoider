#pragma once
#include "config.h"
#include <esp_err.h>
const Types::LeadscrewMeasurementSystem MACHINE_LEADSCREW_TYPE = LEADSCREW_MEASUREMENT_SYSTEM;

namespace Util
{
	class Convert
	{
	  public:
		static double LeadInMM()
		{
			switch (MACHINE_LEADSCREW_TYPE)
			{
			case Types::SAE:
				return LEADSCREW_LEAD * 25.4;
			case Types::METRIC:
				return LEADSCREW_LEAD;
				break;
			default:
				ESP_ERROR_CHECK(ESP_ERR_INVALID_STATE);
			}
		}
	};
}