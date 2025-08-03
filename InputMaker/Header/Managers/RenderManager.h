#pragma once

#include <vector>

class IDrawable;

class RenderManager
{

private:

    static RenderManager* _renderManagerInstance;

    std::vector<std::vector<IDrawable*>> _layers;

    RenderManager();

public:

    RenderManager(const RenderManager& other) = delete;

    static RenderManager* GetRenderManagerInstance();

    static void DestroyRenderManagerInstance();

    void InsertIDrawableInLayer(IDrawable* drawable, int layerNumber, int zOrder);

    void RemoveIDrawableFromLayers(IDrawable* drawableToRemove);

    void RenderTextures();
};
