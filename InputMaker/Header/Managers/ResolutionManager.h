#pragma once

#include <MyVector2.h>

class ResolutionManager
{
private:

    static ResolutionManager* _resolutionManager;

    float _uniformScale;

    ResolutionManager();

public:

    ResolutionManager(const ResolutionManager& other) = delete;

    static ResolutionManager* GetResolutionManagerInstance();

    static void DestroyResolutionManagerInstance();

    float RescaleUnit(float unit) const;

    template <typename T>
    MyVector2<T> RescaleSize(MyVector2<T> size)
    {
        size.x *= _uniformScale;
        size.y *= _uniformScale;

        return size;
    }
};
