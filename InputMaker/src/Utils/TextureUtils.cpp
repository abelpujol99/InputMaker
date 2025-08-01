#include <TextureUtils.h>

#include <ResolutionManager.h>

Texture2D ReturnTexture(const char *texturePath)
{
    Image image = LoadImage(texturePath);

    Texture2D texture = LoadTextureFromImage(image);

    UnloadImage(image);

    return texture;
}

void MyDrawTexturePro(MyVector2<int> position, Rectangle sourceRectangle, MyVector2<float> scale, Texture2D texture,
    float rotation, Color color)
{
    scale = ResolutionManager::GetResolutionManagerInstance()->RescaleSize(scale);

    Rectangle destination = (Rectangle){position.x +
        ResolutionManager::GetResolutionManagerInstance()->RescaleUnit(sourceRectangle.width / 2),
            position.y + ResolutionManager::GetResolutionManagerInstance()->RescaleUnit(sourceRectangle.height / 2),
                sourceRectangle.width * scale.x, sourceRectangle.height * scale. y};

    Vector2 origin = (Vector2){destination.width / 2, destination.height / 2};

    DrawTexturePro(texture, sourceRectangle, destination, origin, rotation, color);
}
