#include <UITexture.h>

#include <RenderManager.h>
#include <ResolutionManager.h>
#include <TextureUtils.h>

UITexture::UITexture(MyVector2<int> origin, MyVector2<int> position, const char *path, MyVector2<float> scale,
    int orderInLayers, int zOrder) : Drawable(origin, position, zOrder), _scale(scale)
{
    ChangeTexture(path);

    RenderManager::GetRenderManagerInstance()->InsertIDrawableInLayer(this, orderInLayers, _zOrder);
}

void UITexture::ChangeTexture(const char *path)
{
    _texture = ReturnTexture(path);
    _rectangle = (Rectangle){0, 0, static_cast<float>(_texture.width), static_cast<float>(_texture.height)};
}

void UITexture::ChangeOrderInLayers(int layer)
{
    RenderManager::GetRenderManagerInstance()->RemoveIDrawableFromLayers(this);
    RenderManager::GetRenderManagerInstance()->InsertIDrawableInLayer(this, layer, _zOrder);
}

void UITexture::Draw()
{
    MyDrawTexturePro(GetPosition(), _rectangle, _scale, _texture, 0, WHITE);
}
