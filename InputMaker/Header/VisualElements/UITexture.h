#pragma once

#include <MyRectangle.h>
#include <raylib.h>

#include <Drawable.h>

class UITexture : public Drawable
{

public:

    Texture2D _texture;
	Rectangle _rectangle;
    MyVector2<float> _scale;

    UITexture(MyVector2<int> origin, MyVector2<int> position, const char* path, MyVector2<float> scale,
        int orderInLayers, int zOrder);

    ~UITexture() override = default;

    void ChangeTexture(const char* path);

    void ChangeOrderInLayers(int layer);

    void Draw() override;
};
