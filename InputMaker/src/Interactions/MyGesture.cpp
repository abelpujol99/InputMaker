#include <cstdio>
#include <MyGesture.h>
#include <raylib.h>

MyGesture::MyGesture(const MyVector2<int>& screenSize) : _gestureArea({MyVector2<int>(), screenSize}),
    _currentGesture(GESTURE_NONE), _lastGesture(_currentGesture), _currentMousePosition(GetMousePosition())
{}

void MyGesture::UpdateGesture()
{
    _lastGesture = _currentGesture;
    _currentGesture = GetGestureDetected();

    _lastMousePosition = _currentMousePosition;
    _currentMousePosition = GetMousePosition();

    Vector2 mousePosition = (Vector2){static_cast<float>(_currentMousePosition.x), static_cast<float>(_currentMousePosition.y)};

    Rectangle gestureArea = (Rectangle){static_cast<float>(_gestureArea.position.x), static_cast<float>(_gestureArea.position.y),
        static_cast<float>(_gestureArea.sizes.x), static_cast<float>(_gestureArea.sizes.y)};

    if (!CheckCollisionPointRec(mousePosition, gestureArea))
    {
        _currentGesture = GESTURE_NONE;
        return;
    }

    if (_currentGesture != GESTURE_TAP)
    {
        return;
    }

    _currentTouchPosition = _currentMousePosition;
}

int MyGesture::GetCurrentGesture() const
{
    return _currentGesture;
}
