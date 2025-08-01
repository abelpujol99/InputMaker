#include <ApplicationManager.h>
#include <WindowManager.h>

int main()
{
    ApplicationManager::GetApplicationManagerInstance()->Update();

    ApplicationManager::DestroyApplicationManagerInstance();

    return 0;
}
