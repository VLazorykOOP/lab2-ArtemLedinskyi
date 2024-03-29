﻿#include <iostream>
#include <bitset>
#include <fstream>
#include <ios>
#include "Tasks.h"
#include "Examples.h"
#include<string.h>
using namespace std;

void MenuTask()
{
    setlocale(LC_CTYPE, "ukr");
    cout << "     Меню завдань   \n";
    cout << "    1.  Розв'язання прикладу за допомогою зсуву  \n";
    cout << "    2.  Шифрування тексту за допомогою двiйкових операцiй \n";
    cout << "    3.  Розшифрування зашифрованого тексту \n";
    cout << "    4.  Додаткове завдання 4 \n";
    cout << "    5.  Exit \n";
}

void InputFor3task(int a) {
    cin >> a;
}
void WriteBinTextFileforshort(unsigned short QWE[4][16], const char* fileName) {
    ofstream Pew("binary.dat", ios::out | ios::binary);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            Pew.write((const char*)&QWE[i][j], sizeof(unsigned short));
        }
    }
    Pew.close();

}
int ConsoleInputText( char Text[4][16], const char* fileName)
{
    int i, j;
    cout << "input text: " << '\n';
    for (i = 0; i < 4; i++) {
        cin.getline(Text[i], 16);
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 16; j++) {
            if (Text[i][j] == '\0') {
                for (int k = j; k < 16; k++) {
                    Text[i][k] = ' ';
                }
            }
        }
    }
    return 1;
}
void WriteArrayTextFileFor1and3Task(int a, const char* fileName)
{
    ofstream fout(fileName);
        fout << a << " ";
    fout.close(); 
}
void WriteArrayTextFileForChar(char A[4][16], const char* fileName)
{
    ofstream fout(fileName);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) {
            fout << A[i][j] << "  ";
            fout.close();
        }
    }
}


void  ReadArrayTextFileForChar(char A[4][16],const char* fileName)
{
    ifstream fin(fileName);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) {
            fin >>A[i][j];
            fin.close(); 
        }
    }
}
void ReadBinFile( char QWE[4][16], const char* fileName) {
    ifstream Pew("binary.dat", ios::in | ios::binary);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            Pew.read((char*)&QWE[i][j], sizeof(char));
        }
    }
    Pew.close();
    return;
}
void task1() {
    setlocale(LC_CTYPE, "ukr");
      int a, b, c, d, x, y;
        cout << "Enter a:";
        cin >> a;
        WriteArrayTextFileFor1and3Task(a, "firstnumber.txt");
        cout << "Enter b:";
        cin >> b;
        WriteArrayTextFileFor1and3Task(b, "secondnumber.txt");
        cout << "Enter c:";
        cin >> c;
        WriteArrayTextFileFor1and3Task(c, "thirdnumber.txt");
        cout << "Enter d:";
        cin >> d;
        WriteArrayTextFileFor1and3Task(d, "fourthnumber.txt");
        cout << "a*34+((13*a+12*c)/64))-b*2560+d*127-c*18" << endl;
        y = a * 34 + ((13 * a + 12 * c) / 64) - b * 2560 + d * 127 - c * 18;
        x = ((a << 1) + (a << 5)) + ((((a << 3) + ((a << 2) + a)) + (c << 3) + (c << 2)) >> 6) - ((b << 12) - (b << 11) + (b << 9)) + ((d << 7) - d) - ((c << 4) + (c << 1));
        cout << x << " За допомогою операцiй зсуву " << endl;
        WriteArrayTextFileFor1and3Task(x, "Answerfor1taskforx.txt");
        cout << y << " Без операцiй зсуву " << endl;
        WriteArrayTextFileFor1and3Task(y, "Answerfor1taskfory.txt");
        return ;   
}
void task2()
{ 
    char Text[4][16];
    unsigned short Res[4][16];
    unsigned short i, j, z, x, c, sf, ez;
    ConsoleInputText(Text, "Writetask2.bin");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 16; j++)
        {
            z = i;// номера рядка букви.
            x = j << 2;//позиція букви рядку.
            z |= x;
            x = Text[i][j];
            x <<= 6;//ASCII - код букви.
            z |= x;//записується код в змінну z.
            c = 0;//підготовка змінних до обчислення біта парності коду букв.
            ez = 1;//підготовка змінних до обчислення біта парності коду букв.
            for (sf = 0; sf < 15; sf++)//15 біт - біт парності коду букв.
            {
                if (z & ez)//Перевіря чи встановлений поточний біт парності в змінній z.
                {
                    c = 1;//якщо так,то змінна с встановлюється в 1.
                }
                ez <<= 1;// зсув на 1 біт ліворуч, щоб перейти до наступного біту.
            }
            x = 1 << 14;//Використовується для встановлення 15-го біту.
            if (c == 1)//перевіряється, чи встановлений біт парності для поточної букви.
            {
                z |= x;//Якщо так, то відповідний біт парності встановлюється в змінній z.
            }
            Res[i][j] = z;//збереження в зміну,яка зберігатиме відповідь 
        }
    }
    for (i = 0; i < 4; i++)//Вивід зашифрованого тексту
    {
        for (j = 0; j < 16; j++)
        {
            bitset<16> qwe(Res[i][j]);
            cout << qwe<<endl;
            WriteBinTextFileforshort(Res, "Writetask2.bin");
        }
    }
    return;
}

void task3() {
    unsigned short a, b, result = 0;
    cout << "Введiть перше значення: ";
    cin >> a;
    cout << "Введiть друге значення: ";
    cin >> b;
    while (b != 0) {
        if (b & 1) {
            result += a;
        }
        a <<= 1;
        b >>= 1;
    }
    if (result == 0) {
        cout << "Якесь число,що множиться,дорiвнює нулю ";
    }
    else if (result > 0) {
        cout << " A * B = " << result << endl;
    }
    return;
}

void task4() {
    int i, j;
     char ZXC[4][16];
    unsigned short q=0, w=0, e, ASCII;
    ReadBinFile(ZXC, "Writetask2.bin");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 16; j++) {
            q |= ZXC[i][j] << 14;//Зсув для занулення всіх значень,окрім зашифрованого номеру рядка .
            q = q >> 14;//Зсуваємо вправо,щоб повернути значення рядка в початок .
            w |= ZXC[i][j] << 10;//Зсуваємо в ліво,щоб занулити всі значення,крім зашифрованної позиції символа в рядку.
            w = w >> 12;//Зсуваємо вправо,щоб змістити на початок .
            e = ZXC[i][j]<<2;//Зсуваємо вліво,щоб занулити все,окрім ASCII-коду .
            e = e>>8;//Зсуваємо вправо,щоб зміститись на початок .
            ASCII |= e;//Надаємо змінній значення ASCII-коду .
            ZXC[q][w]= static_cast<char>(ASCII);//Перетворємо з двійкового запису в літери .
        }
    }
    for (i = 0; i < 4; i++) {
        cout << endl;
        for (j = 0; j < 16; j++) {
            cout << ZXC[q][w];// Вивід . 
        }
    }
    return;
}

    





