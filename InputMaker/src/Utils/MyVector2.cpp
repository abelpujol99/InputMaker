#include <MyVector2.h>

#include <raylib.h>

template<>
MyVector2<int>::MyVector2(Vector2&& vector) :
    x(static_cast<int>(vector.x)), y(static_cast<int>(vector.y))
{}
