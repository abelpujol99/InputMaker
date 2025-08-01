#pragma once

class MyGesture;

class ApplicationManager
{

private:

    static ApplicationManager* _applicationManager;

    MyGesture* _gesture;

    bool _isWindowBeingDragged;

    ApplicationManager();

public:

    ApplicationManager(const ApplicationManager& other) = delete;

    static ApplicationManager* GetApplicationManagerInstance();

    static void DestroyApplicationManagerInstance();

    void Update();

    void DragAndDrop();

    void UpdateGesture();
};
