#include <ResolutionManager.h>

#include <raylib.h>
#include <cmath>
#include <GlobalDefines.h>

#define BASE_SCREEN_WIDTH 1920
#define BASE_SCREEN_HEIGHT 1080

ResolutionManager* ResolutionManager::_resolutionManager = nullptr;

ResolutionManager::ResolutionManager()
{
    float scaleX {static_cast<float>(GetMonitorWidth(MONITOR_INDEX) / BASE_SCREEN_WIDTH)};
    float scaleY {static_cast<float>(GetMonitorHeight(MONITOR_INDEX) / BASE_SCREEN_HEIGHT)};

    _uniformScale = fminf(scaleX, scaleY);
}

ResolutionManager* ResolutionManager::GetResolutionManagerInstance()
{
    if (!_resolutionManager)
    {
        _resolutionManager = new ResolutionManager();
    }

    return _resolutionManager;
}

void ResolutionManager::DestroyResolutionManagerInstance()
{
    delete _resolutionManager;
    _resolutionManager = nullptr;
}

float ResolutionManager::RescaleUnit(float unit) const
{
    return _uniformScale * unit;
}

