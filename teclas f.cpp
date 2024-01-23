#include <iostream>
#include <conio.h>
using namespace std;
#define ESC 27
 
#define F1  -59
#define F2  -60
#define F3  -61
#define F4  -62
#define F5  -63
#define F6  -64
#define F7  -65
#define F8  -66
#define F9  -67
 
int main()
{
    int key = 0;
    printf("Menu : \n");
    while(key != ESC)
    {
        key = getch();
        if(key == 0)
            key = -getch();
        switch(key)
        {
        case F1:
            cout << "primera opcion elegida" << endl;
            cout << "fin" << endl;
            break;
        case F2:
            cout << "segunda opcion hit" << endl;
            break;
        case F3:
            cout << "F3 hit" << endl;
            break;
        case F4:
            cout << "F4 hit" << endl;
            break;
        case F5:
            cout << "F5 hit" << endl;
            break;
        case F6:
            cout << "F6 hit" << endl;
            break;
        case F7:
            cout << "F7 hit" << endl;
            break;
        case F8:
            cout << "F8 hit" << endl;
            break;
        case F9:
            cout << "F9 hit" << endl;
            break;
        default:
            cout << key << endl;
            break;
 
        }
    }
    return 0;
}
