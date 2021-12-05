#include <iostream>
#include <conio.h>
using namespace std;

#define row 10
#define col 10

bool drawMode = true;
bool eraseMode = false;
bool hidePanel = false;

void ShowPanel(int panel[row][col])
{
    system("cls");
    cout << "Press F to open and close DrawMode.      ";
    cout << "DrawMode: " << ((drawMode) ? "On" : "Off") << endl;
    cout << "Press G to open and close EraseMode.     ";
    cout << "EraseMode: " << ((eraseMode) ? "On" : "Off") << endl;
    cout << "Press H to open and close HidePanel.     ";
    cout << "HidePanel: " << ((hidePanel) ? "On" : "Off") << endl;
    cout << "Press Q to quit";
    cout << (hidePanel ? "\n\n" : "\n-----------------------------------------\n");
    for (int i = 0; i < row; i++)
    {
        cout << (hidePanel ? "  " : "| ");
        for (int j = 0; j < col; j++)
        {
            switch (panel[i][j])
            {
            case 0:
                cout << (hidePanel ? "    " : "  | ");
                break;
            case 1:
                cout << (hidePanel ? "*   " : "* | ");
                break;
            case 2:
                cout << (hidePanel ? "#   " : "# | ");
                break;
            }
        }
        cout << (hidePanel ? "\n\n" : "\n-----------------------------------------\n");
    }
}

int main()
{
    int panel[row][col] = {0};
    int x, y;
    cout << "Input StartPos\n";
    cin >> x >> y;
    x--;
    y--;
    panel[x][y] = 2;
    ShowPanel(panel);
    int t;
    while (1)
    {

        if (drawMode)
        {
            panel[x][y] = 1;
        }
        else
        {
            panel[x][y] = t;
        }
        if (eraseMode)
        {
            panel[x][y] = 0;
        }
        char p = getch();
        switch (p)
        {
        case 'w':
            if (x > 0)
            {
                x--;
            }
            break;
        case 'a':
            if (y > 0)
            {
                y--;
            }
            break;
        case 's':
            if (x < row - 1)
            {
                x++;
            }
            break;
        case 'd':
            if (y < col - 1)
            {
                y++;
            }
            break;
        case 'f':
            drawMode = !drawMode;
            break;
        case 'g':
            eraseMode = !eraseMode;
            break;
        case 'h':
            hidePanel = !hidePanel;
            break;
        case 'q':
            return 0;
            break;
        }
        t = panel[x][y];
        panel[x][y] = 2;
        ShowPanel(panel);
    }
    return 0;
}