#include <UITexture.h>

#include <TextureUtils.h>

UITexture::UITexture(MyVector2<int> origin, MyVector2<int> position, const char *path, MyVector2<float> scale)
{

}

void UITexture::ChangeTexture(const char *path)
{

}

void UITexture::SetPosition(MyVector2<int> position)
{

}

void UITexture::Draw()
{
    MyDrawTexturePro(uiPosition, uiRectangle, scale, uiTexture, 0, WHITE);
}
