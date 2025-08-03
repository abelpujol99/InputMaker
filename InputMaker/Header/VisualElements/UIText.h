#pragma once

#include <Drawable.h>
#include <MyVector2.h>
#include <raylib.h>
#include <string>
#include <GlobalEnums.h>

class UIText : public Drawable
{

private:

    float CalculateXPosition() const;
    float CalculateYPosition() const;

public:

    MyVector2<int> _origin;
    MyVector2<int> _position;
    Font _font;
    float _fontSize;
    float _spacing;
    Color _color;
    std::string _text;
    UITextHorizontalAlignment _horizontalAlignment;
    UITextVerticalAlignment _verticalAlignment;

    UIText(MyVector2<int> origin, MyVector2<int> position, const char* fontPath, float fontSize, float spacing,
        Color color, UITextHorizontalAlignment horizontalAlignment, UITextVerticalAlignment verticalAlignment,
            int orderInLayers, int zOrder);

    ~UIText() override = default;

    void InsertString(std::string string);

    [[nodiscard]] Font GetFont() const;

    [[nodiscard]] std::string GetText() const;

    void ClearText();

    void Draw() override;

};
