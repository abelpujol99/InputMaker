#pragma once

#include <MyRectangle.h>
#include <MyVector2.h>
#include <raylib.h>

Texture2D ReturnTexture(const char* texturePath);

void MyDrawTexturePro(MyVector2<int> position, MyRectangle sourceRectangle, MyVector2<float> scale, Texture2D texture,
    float rotation, Color color);