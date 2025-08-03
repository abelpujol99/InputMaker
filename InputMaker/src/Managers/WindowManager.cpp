#include <WindowManager.h>

#include <cfloat>
#include <math.h>
#include <WindowsUtils.h>
#include <MyVector2.h>
#include <raylib.h>
#include <ResolutionManager.h>
#include <GlobalDefines.h>
#include <UIText.h>
#include <UITexture.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

WindowManager* WindowManager::_windowManagerInstance = nullptr;

WindowManager::WindowManager()
{
    InitWindow(1, 1, "Input Maker");

    MyVector2<int> windowSize {ResolutionManager::GetResolutionManagerInstance()->RescaleSize(MyVector2<int>{SCREEN_WIDTH, SCREEN_HEIGHT})};

    SetWindowSize(windowSize.x, windowSize.y);

    Vector2 monitorPosition {GetMonitorPosition(MONITOR_INDEX)};

    SetWindowPosition(monitorPosition.x + GetMonitorWidth(MONITOR_INDEX) / 2 - windowSize.x / 2,
        monitorPosition.y + GetMonitorHeight(MONITOR_INDEX) / 2 - windowSize.y / 2);

    SetTargetFPS(GetMonitorRefreshRate(MONITOR_INDEX));

    Image icon {LoadImage("res/icon/game_icon.png")};
    SetWindowIcon(icon);
    UnloadImage(icon);

    _testUITexture = new UITexture({0, 0}, {0, 0}, "res/test/descarga.jpeg", {1, 1}, 1, 1);
    _testUITexture2 = new UITexture({0, 0}, {0, 100}, "res/test/descarga.jpeg", {1, 1}, 0, 0);
    _testText = new UIText({0, 0}, {0, 0}, "res/fonts/notomono_regular.ttf", 64, 2, WHITE, HORIZONTAL_LEFT_TEXT_ALIGNMENT,
        VERTICAL_TOP_TEXT_ALIGNMENT, 2, 0);

    _testText->InsertString("Holi");
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

