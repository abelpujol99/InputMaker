#include <RenderManager.h>
#include <UIText.h>

UIText::UIText(MyVector2<int> origin, MyVector2<int> position, const char *fontPath, float fontSize, float spacing,
    Color color, UITextHorizontalAlignment horizontalAlignment, UITextVerticalAlignment verticalAlignment, int orderInLayers,
        int zOrder) : Drawable(origin, position, zOrder), _fontSize(fontSize), _spacing(spacing), _color(color),
            _horizontalAlignment(horizontalAlignment), _verticalAlignment(verticalAlignment)

{
    int customChars[] = {
        32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
        48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
        58, 59, 60, 61, 62, 63, 64,
        65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
        78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
        91, 92, 93, 94, 95, 96,
        97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
        110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122,
        123, 124, 125, 126, 8364, 225, 233, 237, 243, 250, 252,
        193, 201, 205, 211, 218, 220, 241, 209
    };

    _font = LoadFontEx(fontPath, fontSize, customChars, sizeof(customChars)/sizeof(int));

    RenderManager::GetRenderManagerInstance()->InsertIDrawableInLayer(this, orderInLayers, _zOrder);
}

void UIText::InsertString(std::string string)
{
    _text += string;
}

Font UIText::GetFont() const
{
    return _font;
}

std::string UIText::GetText() const
{
    return _text;
}

void UIText::ClearText()
{
    _text = "";
}

float UIText::CalculateXPosition() const
{
    if (_horizontalAlignment == HORIZONTAL_LEFT_TEXT_ALIGNMENT)
    {
        return  _position.x;
    }

    float textWidth = MeasureTextEx(_font, _text.c_str(), _fontSize, _spacing).x;

    if (_horizontalAlignment == HORIZONTAL_RIGHT_TEXT_ALIGNMENT)
    {
        return _position.x - textWidth;
    }

    return _position.x - textWidth / 2;
}

float UIText::CalculateYPosition() const
{
    if (_verticalAlignment == VERTICAL_TOP_TEXT_ALIGNMENT)
    {
        return  _position.y;
    }

    float textWidth = MeasureTextEx(_font, _text.c_str(), _fontSize, _spacing).y;

    if (_verticalAlignment == VERTICAL_BOTTOM_TEXT_ALIGNMENT)
    {
        return _position.y - textWidth;
    }

    return _position.y - textWidth / 2;
}


void UIText::Draw()
{
    DrawTextEx(_font, _text.c_str(), (Vector2){CalculateXPosition(), CalculateYPosition()}, _fontSize, _spacing, _color);
}
