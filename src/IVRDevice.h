#pragma once

#include <openvr_driver.h>
#include <string>

namespace SteamVRDriverTemplate
{
	class IVRDevice : public vr::ITrackedDeviceServerDriver
	{
	public:
#pragma region ITrackedDeviceServerDriver
		virtual vr::EVRInitError Activate(uint32_t objectID) override = 0;
		virtual void Deactivate() override { objectID = vr::k_unTrackedDeviceIndexInvalid; }
		virtual void EnterStandby() override {}
		virtual void* GetComponent(const char* pchComponentNameAndVersion) override { return nullptr; }
		virtual void DebugRequest(const char* pchRequest, char* pchResponseBuffer, uint32_t unResponseBufferSize) override { if (unResponseBufferSize >= 1) pchResponseBuffer[0] = 0; }
		virtual vr::DriverPose_t GetPose() override { return lastPose; }
#pragma endregion

		virtual vr::ETrackedDeviceClass GetDeviceType() = 0;
		virtual std::string GetSerial() { return serialNumber; }
		virtual void SetPose(const vr::DriverPose_t& pose) { lastPose = pose; }
		virtual void ApplyPose() { if (objectID != vr::k_unTrackedDeviceIndexInvalid) vr::VRServerDriverHost()->TrackedDevicePoseUpdated(objectID, lastPose, sizeof(vr::DriverPose_t)); }
		virtual void RunFrame() = 0;

	protected:
		vr::TrackedDeviceIndex_t objectID = vr::k_unTrackedDeviceIndexInvalid;
		std::string serialNumber;
		vr::DriverPose_t lastPose;
	};
}
