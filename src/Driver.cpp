#include "Driver.h"

#ifdef _DEBUG
#include <Windows.h>
#endif

vr::EVRInitError SteamVRDriverTemplate::Driver::Init(vr::IVRDriverContext* pDriverContext)
{
#ifdef _DEBUG
	while (!IsDebuggerPresent())
		Sleep(100);
	DebugBreak();
#endif

	vr::EVRInitError initError = vr::InitServerDriverContext(pDriverContext);
	if (initError != vr::EVRInitError::VRInitError_None)
		return initError;

	return vr::VRInitError_None;
}

void SteamVRDriverTemplate::Driver::RunFrame()
{
	//Collect events
	vr::VREvent_t event;
	std::vector<vr::VREvent_t> events;
	while (vr::VRServerDriverHost()->PollNextEvent(&event, sizeof(event)));

	//Update the devices.
	for (std::shared_ptr<IVRDevice> device : devices)
		device->RunFrame();
}

bool SteamVRDriverTemplate::Driver::AddDevice(std::shared_ptr<IVRDevice> device)
{
	bool result = vr::VRServerDriverHost()->TrackedDeviceAdded(device->GetSerial().c_str(), device->GetDeviceType(), device.get());
	if (result)
		this->devices.push_back(device);
	return result;
}
