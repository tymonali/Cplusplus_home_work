#include "App.h"

void App::Start()
{
    while (true)
    {
        system("cls");
        int act;
        menu();
        cin >> act;
        switch (act)
        {
        case NEW:
        {
            newgame = new Game(4, 35);
            newgame->Start();
            break;
        }
        case EXIT:
        {
            exit(0);
        }
        default:
            break;
        }
    }
}

void App::menu()
{
    cout << "\t\t *  ___     |___    ___    ___    ___|    ___    ___|  " << endl;
    cout << "\t\t | |   | __ |   |  |   |  |   |  |   |   |___   |   |  " << endl;
    cout << "\t\t | |___|    |   |  |~~~|  |   |  |___|   |___   |___|   " << endl;

    cout << "\t\t/                       \n";
    cout << "\t\t                     ";
    cout << "[1] - Новая игра;\n";
    cout << "\t\t                     ";
    cout << "[0] - Выход.\n";
}