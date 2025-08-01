#pragma once

#include <MyRectangle.h>
#include <raylib.h>

class UITexture
{

public:

    MyVector2<int> uiOriginalPosition;
    MyVector2<int> uiPosition;
    Texture2D uiTexture;
	MyRectangle uiRectangle;
    MyVector2<float> scale;

    UITexture(MyVector2<int> origin, MyVector2<int> position, const char* path, MyVector2<float> scale);

    ~UITexture() = default;

    void ChangeTexture(const char* path);

    void SetPosition(MyVector2<int> position);

    void Draw();
};
