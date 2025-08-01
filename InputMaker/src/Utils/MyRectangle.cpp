#include <MyRectangle.h>

MyRectangle::MyRectangle(const MyVector2<int> &position, const MyVector2<int> &sizes) : position(position), sizes(sizes)
{}

MyRectangle::MyRectangle(const MyRectangle& other) : position({other.position}), sizes({other.sizes})
{}

MyRectangle& MyRectangle::operator=(const MyRectangle& other)
{
    this->position = other.position;
    this->sizes = other.sizes;

    return *this;
}

MyRectangle::MyRectangle(MyRectangle&& other) noexcept : position(std::move(other.position)), sizes(std::move(other.sizes))
{}

MyRectangle& MyRectangle::operator=(MyRectangle&& other) noexcept
{
    this->position = std::move(other.position);
    this->sizes = std::move(other.sizes);

    return *this;
}

void MyRectangle::ChangePosition(MyVector2<int>&& position)
{
    this->position = std::move(position);
}

void MyRectangle::ChangeSize(MyVector2<int>&& sizes)
{
    this->sizes = std::move(sizes);
}
