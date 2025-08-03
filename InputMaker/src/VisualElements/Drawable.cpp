#include <Drawable.h>
#include <ResolutionManager.h>

Drawable::Drawable(MyVector2<int> origin, MyVector2<int> position, int zOrder) : _origin(origin),
    _position(_origin + ResolutionManager::GetResolutionManagerInstance()->RescaleSize(position)), _zOrder(zOrder)
{}

void Drawable::SetPosition(MyVector2<int> position)
{
    SetPositionNoRescale(ResolutionManager::GetResolutionManagerInstance()->RescaleSize(position));
}

void Drawable::SetPositionNoRescale(MyVector2<int> position)
{
    _position = _origin + position;
}

MyVector2<int> Drawable::GetPosition()
{
    return _position;
}

int Drawable::GetZOrder()
{
    return _zOrder;
}
