#include <iostream>
#include <bitset>
#include <fstream>
#include <ios>
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
int ConsoleInputText(char Text,char A[])
{
    int i,j;
    for (i = 0; i < 4; i++)
    {
        cout << "Enter Text :" << endl;
        cin >> A;
        for (j = 0; j < 16; j++)
        {
            if (A[j] == NULL)//Доповнюємо рядок пробілом
            {
                A[j] = ' ';
            }
            Text[i][j] = A[j];//скопіювали символ з одного масива до іншого.
        }
    }
    return ;
}
int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size = 0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    return size;
}

void WriteArrayTextFile(int n, double* arr, const char* fileName)
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); 
}
int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;
    for (int i = 0; i < n; i++)
        fin >> arr[i];
    fin.close();
    return size;
}
void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) * sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
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
        WriteArrayTextFile(a, "Task1.txt");
        WriteArrayTextFile(b, "Task1.txt");
        WriteArrayTextFile(c, "Task1.txt");
        WriteArrayTextFile(d, "Task1.txt");
        cout << "a*34+((13*a+12*c)/64))-b*2560+d*127-c*18" << endl;
        y = a * 34 + ((13 * a + 12 * c) / 64) - b * 2560 + d * 127 - c * 18;
        x = ((a << 1) + (a << 5)) + ((((a << 3) + ((a << 2) + a)) + (c << 3) + (c << 2)) >> 6) - ((b << 12) - (b << 11) + (b << 9)) + ((d << 7) - d) - ((c << 4) + (c << 1));
        cout << x << " За допомогою операцiй зсуву " << endl;
        cout << y << " Без операцiй зсуву " << endl;
        WriteArrayTextFile(x, "Task1.txt");
        WriteArrayTextFile(y, "Task1.txt");
        return ;
}
void task2()
{ 
    char Text[4][16];
    char idk[100];
    unsigned short Res[4][16];
    unsigned short i, j, z, x, c, sf, ez;
   /* for (i = 0; i < 4; i++)
    {
        cout << "Enter Text :" << endl;
        cin >> idk;
        for (j = 0; j < 16; j++)
        {
            if (idk[j] == NULL)//Доповнюємо рядок пробілом
            {
                idk[j] = ' ';
            }
            Text[i][j] = idk[j];//скопіювали символ з одного масива до іншого.
        }
    }*/
    ConsoleInputText(Text, idk);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 16; j++)
        {
            z = i;;//додавання номера рядка
            x = j << 2;
            z |= x;
            x = Text[i][j];
            x <<= 6;//зсув на 6 бітів, виділені під номер символа
            z |= x;
            c = 0;
            ez = 1;
            for (sf = 0; sf < 15; sf++)//15 біт - біт парності коду букв
            {
                if (z & ez)
                {
                    c = 1;
                }
                ez <<= 1;// зсув на 2 бітів, виділені під номер символа
            }
            x = 1 << 15;//зберігаємо біт парності
            if (c == 1)
            {
                z |= x;
            }
            Res[i][j] = z;//збереження в зміну,яка зберігатиме відповідь 
        }
    }
    for (i = 0; i < 4; i++)//Вивід зашифрованого тексту
    {
        for (j = 0; j < 16; j++)
        {
            bitset<16> qwe(Res[i][j]);
        }
    }
    bitset<16> qwe(Res[i][j]);
    WriteArrayBinFile(qwe, "Task2.bim");
    cout<<ReadArrayBinFile(qwe, "Task2.bin");
    return;
}


