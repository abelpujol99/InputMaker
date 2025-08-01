#include <ApplicationManager.h>
#include <cstdio>

#include <MyGesture.h>
#include <raylib.h>
#include <RenderManager.h>
#include <ResolutionManager.h>
#include <WindowManager.h>

ApplicationManager* ApplicationManager::_applicationManager = nullptr;

ApplicationManager::ApplicationManager() : _isWindowBeingDragged(false)
{
    _gesture = new MyGesture(WindowManager::GetWindowManagerInstance()->GetWindowSize());
}

ApplicationManager* ApplicationManager::GetApplicationManagerInstance()
{
    if (!_applicationManager)
    {
        _applicationManager = new ApplicationManager();
    }

    return _applicationManager;
}

void ApplicationManager::DestroyApplicationManagerInstance()
{
    delete _applicationManager;
    _applicationManager = nullptr;
}

void ApplicationManager::Update()
{
    while (!WindowShouldClose())
    {
        UpdateGesture();

        DragAndDrop();

        RenderManager::GetRenderManagerInstance()->RenderTextures();
    }
}

void ApplicationManager::DragAndDrop()
{
    if (!_isWindowBeingDragged)
    {
        if (_gesture->GetCurrentGesture() != GESTURE_TAP)
        {
            return;
        }

        _isWindowBeingDragged = true;
        WindowManager::GetWindowManagerInstance()->StartDragWindow();

        return;
    }

    if (WindowManager::GetWindowManagerInstance()->DragWindow())
    {
        return;
    }

    WindowManager::GetWindowManagerInstance()->StopDragWindow();
    _isWindowBeingDragged = false;
}

void ApplicationManager::UpdateGesture()
{
    _gesture->UpdateGesture();
}

