#pragma once

#include <MyVector2.h>

class MyRectangle
{

public:

    MyVector2<int> position;
    MyVector2<int> sizes;

    MyRectangle() = default;
    MyRectangle(const MyVector2<int> &position, const MyVector2<int> &sizes);

    MyRectangle(const MyRectangle& other);
    MyRectangle& operator=(const MyRectangle& other);

    MyRectangle(MyRectangle&& other) noexcept;
    MyRectangle& operator=(MyRectangle&& other) noexcept;

    void ChangePosition(MyVector2<int>&& position);
    void ChangeSize(MyVector2<int>&& sizes);
};