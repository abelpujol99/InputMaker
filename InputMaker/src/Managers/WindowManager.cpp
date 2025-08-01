#include <WindowManager.h>

#include <cfloat>
#include <math.h>
#include <WindowsUtils.h>
#include <MyVector2.h>
#include <raylib.h>
#include <ResolutionManager.h>
#include <GlobalDefines.h>

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400

WindowManager* WindowManager::_windowManagerInstance = nullptr;

WindowManager::WindowManager() : DRAG_HEIGHT(0)
{
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_BORDERLESS_WINDOWED_MODE | FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_UNDECORATED);

    InitWindow(1, 1, "Input Maker");

    MyVector2<int> windowSize = ResolutionManager::GetResolutionManagerInstance()->RescaleSize(MyVector2<int>{SCREEN_WIDTH, SCREEN_HEIGHT});

    SetWindowSize(windowSize.x, windowSize.y);

    SetTargetFPS(GetMonitorRefreshRate(MONITOR_INDEX));

    Image icon = LoadImage("res/icon/game_icon.png");
    SetWindowIcon(icon);
    UnloadImage(icon);
}

WindowManager* WindowManager::GetWindowManagerInstance() {

    if (!_windowManagerInstance)
    {
        _windowManagerInstance = new WindowManager();
    }

    return _windowManagerInstance;
}

void WindowManager::DestroyWindowManagerInstance()
{
    delete _windowManagerInstance;
    _windowManagerInstance = nullptr;
}

MyVector2<int> WindowManager::GetWindowSize()
{
    MyVector2<int> vector {GetScreenWidth(), GetScreenHeight()};

    return vector;
}

void WindowManager::StartDragWindow()
{
    MyVector2<int> mousePosition {GetGlobalMousePosition()};

    MyVector2<int> windowPosition {GetWindowPosition()};

    offsetVector = {windowPosition.x - mousePosition.x, windowPosition.y - mousePosition.y};
}

bool WindowManager::DragWindow() const
{
    MyVector2<int> mousePosition {GetGlobalMousePosition()};

    SetWindowPosition(offsetVector.x + mousePosition.x, offsetVector.y + mousePosition.y);

    return IsMouseDragging();
}


void WindowManager::StopDragWindow()
{

}

int WindowManager::GetWindowCurrentMonitor()
{
    Vector2 windowPosition = GetWindowPosition();

    windowPosition.x += GetScreenWidth() / 2;
    windowPosition.y += GetScreenHeight() / 2;

    int monitorCount = GetMonitorCount();
    float closestDistance = FLT_MAX;
    int bestMonitor = -1;

    for (int i = 0; i < monitorCount; ++i)
    {
        Vector2 monitorPosition = GetMonitorPosition(i);
        int monitorWidth = GetMonitorWidth(i);
        int monitorHeight = GetMonitorHeight(i);

        Vector2 clamped;

        clamped.x = fmaxf(monitorPosition.x, fminf(windowPosition.x, monitorPosition.x + monitorWidth));
        clamped.y = fmaxf(monitorPosition.y, fminf(windowPosition.y, monitorPosition.y + monitorHeight));

        Vector2 delta = (Vector2){windowPosition.x - clamped.x, windowPosition.y - clamped.y};

        float distanceSquared = delta.x * delta.x + delta.y * delta.y;

        if (distanceSquared < closestDistance)
        {
            closestDistance = distanceSquared;
            bestMonitor = i;
        }
    }

    return bestMonitor;
}

void WindowManager::Draw()
{
    BeginDrawing();
    ClearBackground(WHITE);

    EndDrawing();
}

