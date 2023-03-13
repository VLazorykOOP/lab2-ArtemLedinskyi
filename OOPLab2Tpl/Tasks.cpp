#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  The problem of using bitwise operations \n";
    cout << "    5.  Examples of problems using bitwise operations \n";
    cout << "    6.  Exit \n";
}
void task1() {
    
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
        return ;
}

void task2()
{
    cout << " Data encryption using bitwise operations  \n";
	int i, n, j;
	char Text[4][16];
	char Result[4][16];
	char g[25];
	for (i = 0; i < 4; i++) {
		cout << "Enter Text :";
		cin >> g;
		for (j = 0; j < 16; j++) {
			if (g[i] == NULL) {
				g[j] = ' ';
			}
			Text[i][j] = g[j];
		}
	}
	unsigned short z, x, c, sf, pa;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 16; j++) {
			z = i;
			x = j << 2;
			z |= x;
			x = Text[i][j];
			x <<= 6;
			z |= x;
			c = 0;
			sf = 1;
			for (pa = 0; pa < 15; pa++) {
				if (z & sf) {
					c = 1;
				}
				sf <<= 1;
			}
			x = 1 << 15;
			if (c == 1) {
				z |= x;
			}
			Result[i][j] = z;
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 16; j++) {

		}
	}
	return;
}


