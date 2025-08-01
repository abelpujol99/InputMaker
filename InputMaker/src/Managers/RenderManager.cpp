#include <algorithm>
#include <RenderManager.h>
#include <TextureUtils.h>
#include <UITexture.h>

RenderManager* RenderManager::_renderManagerInstance = nullptr;

RenderManager::RenderManager()
{
    _layers.resize(1);
}

RenderManager *RenderManager::GetRenderManagerInstance()
{
    if (!_renderManagerInstance)
    {
        _renderManagerInstance = new RenderManager();
    }

    return _renderManagerInstance;
}

void RenderManager::DestroyRenderManagerInstance()
{
    delete _renderManagerInstance;
    _renderManagerInstance = nullptr;
}

void RenderManager::InsertUITextureInLayer(UITexture *uiTexture, int layerNumber, int zOrder)
{
    while (_layers.size() <= layerNumber)
    {
        _layers.emplace_back();
    }

    std::vector<UITexture*>& layer {_layers[layerNumber]};

    auto index {std::lower_bound(layer.begin(), layer.end(), zOrder, [](UITexture* uiTexture, int value) {
        return uiTexture->_zOrder <= value;
    })};

    _layers[layerNumber].insert(index, uiTexture);
}

void RenderManager::RemoveUITextureFromLayers(UITexture *uiTextureToRemove)
{
    for (size_t i {0}; i < _layers.size(); ++i)
    {
        std::vector<UITexture*>& layer = _layers[i];

        for (size_t j {0}; j < layer.size(); ++j)
        {
            UITexture* uiTexture = layer[j];
            if (uiTexture != uiTextureToRemove)
            {
                continue;
            }

            layer.erase(layer.begin() + j);
            return;
        }
    }
}

void RenderManager::RenderTextures()
{
    BeginDrawing();
    ClearBackground(BLACK);

    for (size_t i {0}; i < _layers.size(); ++i)
    {
        std::vector<UITexture*>& layer = _layers[i];

        for (size_t j {0}; j < layer.size(); ++j)
        {
            UITexture* uiTexture = layer[j];
            MyDrawTexturePro(uiTexture->_uiPosition, uiTexture->_uiRectangle, uiTexture->_scale, uiTexture->_uiTexture, 0, WHITE);
        }
    }

    EndDrawing();
}
