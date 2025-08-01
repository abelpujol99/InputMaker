#pragma once

#include <MyRectangle.h>
#include <MyVector2.h>

class MyGesture
{
private:

    MyRectangle _gestureArea;

    MyVector2<int> _currentTouchPosition;
    MyVector2<int> _lastTouchPosition;

    MyVector2<int> _currentMousePosition;
    MyVector2<int> _lastMousePosition;

    int _currentGesture;
    int _lastGesture;

public:

    MyGesture(const MyVector2<int>& screenSize);

    ~MyGesture();

    void UpdateGesture();

    int GetCurrentGesture() const;

};