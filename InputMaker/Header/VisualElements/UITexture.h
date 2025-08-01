#pragma once

#include <MyRectangle.h>
#include <raylib.h>

class UITexture
{

public:

    MyVector2<int> _uiOriginalPosition;
    MyVector2<int> _uiPosition;
    Texture2D _uiTexture;
	Rectangle _uiRectangle;
    MyVector2<float> _scale;
    int _zOrder;

    UITexture(MyVector2<int> origin, MyVector2<int> position, const char* path, MyVector2<float> scale,
        int orderInLayers, int zOrder);

    ~UITexture() = default;

    void ChangeTexture(const char* path);

    void SetPosition(MyVector2<int> position);

    void SetPositionNoRescale(MyVector2<int> position);

    void ChangeOrderInLayers(int layer);
};
