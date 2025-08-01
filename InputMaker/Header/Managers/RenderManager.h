#pragma once

#include <vector>

class UITexture;

class RenderManager
{

private:

    static RenderManager* _renderManagerInstance;

    std::vector<std::vector<UITexture*>> _layers;

    RenderManager();

public:

    RenderManager(const RenderManager& other) = delete;

    static RenderManager* GetRenderManagerInstance();

    static void DestroyRenderManagerInstance();

    void InsertUITextureInLayer(UITexture* uiTexture, int layerNumber, int zOrder);

    void RemoveUITextureFromLayers(UITexture* uiTextureToRemove);

    void RenderTextures();
};
