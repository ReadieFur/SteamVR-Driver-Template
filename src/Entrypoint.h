#pragma once

#include <memory>
#include "Driver.h"

extern "C" __declspec(dllexport) void* HmdDriverFactory(const char* interface_name, int* return_code);

namespace SteamVRDriverTemplate
{
    std::shared_ptr<SteamVRDriverTemplate::Driver> GetDriver();
}
