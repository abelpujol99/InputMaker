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

void RenderManager::InsertIDrawableInLayer(IDrawable *drawable, int layerNumber, int zOrder)
{
    while (_layers.size() <= layerNumber)
    {
        _layers.emplace_back();
    }

    std::vector<IDrawable*>& layer {_layers[layerNumber]};

    auto index {std::lower_bound(layer.begin(), layer.end(), zOrder, [](IDrawable* drawable, int value) {
        return drawable->GetZOrder() <= value;
    })};

    _layers[layerNumber].insert(index, drawable);
}

void RenderManager::RemoveIDrawableFromLayers(IDrawable *drawableToRemove)
{
    for (size_t i {0}; i < _layers.size(); ++i)
    {
        std::vector<IDrawable*>& layer = _layers[i];

        for (size_t j {0}; j < layer.size(); ++j)
        {
            IDrawable* drawable = layer[j];
            if (drawable != drawableToRemove)
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
        std::vector<IDrawable*>& layer = _layers[i];

        for (size_t j {0}; j < layer.size(); ++j)
        {
            layer[j]->Draw();
        }
    }

    EndDrawing();
}
