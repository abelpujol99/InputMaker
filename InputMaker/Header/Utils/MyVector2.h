#pragma once

#include <algorithm>

struct Vector2;

template<typename T>
class MyVector2
{
public:

    T x;
    T y;

    MyVector2() : x(0), y(0)
    {}

    MyVector2(const MyVector2& other) : x(other.x), y(other.y)
    {}

    MyVector2& operator=(const MyVector2& other)
    {
        this->x = other.x;
        this->y = other.y;

        return *this;
    }

    MyVector2(MyVector2&& other) noexcept : x(std::move(other.x)), y(std::move(other.y))
    {}

    MyVector2& operator=(MyVector2&& other) noexcept
    {
        this->x = std::move(other.x);
        this->y = std::move(other.y);

        return *this;
    }

    MyVector2(T x, T y) : x(x), y(y)
    {}

    MyVector2(Vector2&& vector);

    MyVector2<T> operator+(MyVector2<T> const& other)
    {
        MyVector2 result;
        result.x = x + other.x;
        result.y = y + other.y;

        return result;
    }

    MyVector2<T> operator+=(MyVector2<T> const& other)
    {
        x += other.x;
        y += other.y;

        return *this;
    }

    MyVector2<T> operator-(MyVector2<T> const& other)
    {
        MyVector2 result;
        result.x = x - other.x;
        result.y = y - other.y;

        return result;
    }

    MyVector2<T> operator-=(MyVector2<T> const& other)
    {
        x -= other.x;
        y -= other.y;

        return *this;
    }
};