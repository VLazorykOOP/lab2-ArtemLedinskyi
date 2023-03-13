// OOPLab2Tpl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"

/* task1() {
    setlocale(LC_CTYPE, "ukr");
    int a, b, c, d, x, y;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;
    cout << "Enter c:";
    cin >> c;
    cout << "Enter d:";
    cin >> d;
    cout << "a*34+((13*a+12*c)/64))-b*2560+d*127-c*18" << endl;
    y = a * 34 + ((13 * a + 12 * c) / 64) - b * 2560 + d * 127 - c * 18;
    x = ((a << 1) + (a << 5)) + ((((a << 3) + ((a << 2) + a)) + (c << 3) + (c << 2)) >> 6) - ((b << 12) - (b << 11) + (b << 9)) + ((d << 7) - d) - ((c << 4) + (c << 1));
    cout << x << " За допомогою операцiй зсуву " << endl;
    cout << y << " Без операцiй зсуву " << endl;
    return x;
}*/
/// @brief 
/// @return 
int main()
{
    cout << "OOP. Template for laboratory work #2.\n";

    /*char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = cin.get();
        
        cin.get();

        switch (ch) {
        case '1': task1();   break;
        case '2': task1();   break;
        case '3': task1();   break;
        case '4': task1();   break;
		case '5':  Examples(); break;
		case '6': return 0;
	    }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '6');
    */
    cout << "Choose Task which one do you want to watch :";
    int c;
    cin >> c;
    if (c == 1) {
        task1();
    }
    else if (c == 2) {
        task2();
    }
    return 0;
}

