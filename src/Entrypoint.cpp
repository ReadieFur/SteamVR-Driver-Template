#include "Entrypoint.h"

#include <openvr_driver.h>

static std::shared_ptr<SteamVRDriverTemplate::Driver> driver;

void* HmdDriverFactory(const char* interface_name, int* return_code)
{
	if (std::strcmp(interface_name, vr::IServerTrackedDeviceProvider_Version) == 0)
	{
		if (!driver)
		{
			//Instantiate concrete impl.
			driver = std::make_shared<SteamVRDriverTemplate::Driver>();
		}
		//We always have at least 1 ref to the shared ptr in "driver" so passing out raw pointer is ok.
		return driver.get();
	}

	if (return_code)
		*return_code = vr::VRInitError_Init_InterfaceNotFound;

	return nullptr;
}

std::shared_ptr<SteamVRDriverTemplate::Driver> SteamVRDriverTemplate::GetDriver()
{
	return driver;
}
