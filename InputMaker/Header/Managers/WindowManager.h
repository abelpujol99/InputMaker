#pragma once

#include <MyVector2.h>

class UITexture;

class WindowManager
{

private:

    static WindowManager* _windowManagerInstance;

    const float DRAG_HEIGHT;

    MyVector2<int> offsetVector;

    UITexture* _testUITexture;
    UITexture* _testUITexture2;

    WindowManager();

public:

    WindowManager(const WindowManager& other) = delete;

    static WindowManager* GetWindowManagerInstance();

    static void DestroyWindowManagerInstance();

    MyVector2<int> GetWindowSize();

    void StartDragWindow();

    [[nodiscard]] bool DragWindow() const;

    void StopDragWindow();

    int GetWindowCurrentMonitor();
};
