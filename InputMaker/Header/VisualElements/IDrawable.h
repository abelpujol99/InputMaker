#pragma once

class IDrawable
{
public:
    virtual ~IDrawable() = default;

    virtual void Draw() = 0;

    virtual int GetZOrder() = 0;
};
