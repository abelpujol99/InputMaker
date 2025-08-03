#pragma once

#include <IDrawable.h>
#include <MyVector2.h>

class Drawable : public IDrawable
{
private:

    MyVector2<int> _origin;
    MyVector2<int> _position;

public:

    int _zOrder = 0;

    Drawable(MyVector2<int> origin, MyVector2<int> position, int zOrder);

    ~Drawable() override = default;

    void SetPosition(MyVector2<int> position);

    void SetPositionNoRescale(MyVector2<int> position);

    MyVector2<int> GetPosition();

    int GetZOrder() override;
};
