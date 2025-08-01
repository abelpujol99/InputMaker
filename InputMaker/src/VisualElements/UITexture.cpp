#include <RenderManager.h>
#include <ResolutionManager.h>
#include <UITexture.h>

#include <TextureUtils.h>

UITexture::UITexture(MyVector2<int> origin, MyVector2<int> position, const char *path, MyVector2<float> scale,
    int orderInLayers, int zOrder) : _uiOriginalPosition(origin), _uiPosition(position), _scale(scale), _zOrder(zOrder)
{
    ChangeTexture(path);

    RenderManager::GetRenderManagerInstance()->InsertUITextureInLayer(this, orderInLayers, _zOrder);
}

void UITexture::ChangeTexture(const char *path)
{
    _uiTexture = ReturnTexture(path);
    _uiRectangle = (Rectangle){0, 0, static_cast<float>(_uiTexture.width), static_cast<float>(_uiTexture.height)};
}

void UITexture::SetPosition(MyVector2<int> position)
{
    SetPositionNoRescale(ResolutionManager::GetResolutionManagerInstance()->RescaleSize(position));
}

void UITexture::SetPositionNoRescale(MyVector2<int> position)
{
    _uiPosition = _uiOriginalPosition + position;
}

void UITexture::ChangeOrderInLayers(int layer)
{
    RenderManager::GetRenderManagerInstance()->RemoveUITextureFromLayers(this);
    RenderManager::GetRenderManagerInstance()->InsertUITextureInLayer(this, layer, _zOrder);
}
