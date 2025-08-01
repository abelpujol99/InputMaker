#include <cstdio>
#include <WindowsUtils.h>

#include <windows.h>

MyVector2<int> GetGlobalMousePosition()
{
    POINT point;
    GetCursorPos(&point);
    return {static_cast<int>(point.x), static_cast<int>(point.y)};
}

bool IsMouseDragging()
{
    return GetAsyncKeyState(VK_LBUTTON) & 0x8000;
}