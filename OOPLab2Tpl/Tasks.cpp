#include <iostream>
#include <bitset>
#include <fstream>
#include <ios>
#include "Tasks.h"
#include "Examples.h"
using namespace std;

void MenuTask()
{
    setlocale(LC_CTYPE, "ukr");
    cout << "     Меню завдань   \n";
    cout << "    1.  Розв'язання прикладу за допомогою зсуву  \n";
    cout << "    2.  Шифрування тексту за допомогою двiйкових операцiй \n";
    cout << "    3.  Додаткове завдання 4 \n";
    cout << "    4.  Exit \n";
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
int ConsoleInputText(char Text[4][16], char Save[100], const char* fileName)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        cout << "Enter Text :" << endl;
        cin >>Save;
        for (j = 0; j < 16; j++)
        {
            if (Save[j] == NULL)//Доповнюємо рядок пробілом
            {
                Save[j] = ' ';
            }
            Text[i][j] = Save[j];//скопіювали символ з одного масива до іншого.
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
    char idk[100];
    unsigned short Res[4][16];
    unsigned short i, j, z, x, c, sf, ez;
    ConsoleInputText(Text,idk, "Textinputtask.txt");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 16; j++)
        {
            z = i;// номера рядка букви.
            x = j << 2;//позиція букви рядку .
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
    unsigned short c, a, b, an, bn;
    cout << "Enter A:";
    cin >> a;//Введення з консолі
    WriteArrayTextFileFor1and3Task(a, "firstnumberfor3task.txt");
    cout << "Enter B :";
    cin >> b;//Введення з консолі
    WriteArrayTextFileFor1and3Task(b, "secondnumberfor3task.txt");
    bn = b;//Значення bn дорівнює b,щоб працювати в циклі з ним
    an = 0;//Ініціалізуємо перемінну
    while (bn >= 1) {//Поки "bn" більше або дорівнює 1,то виконується наступна дія
        if (bn == 1) {//Перевіряє, чи "bn" дорівнює 1
            an += a;//Якщо так, то програма додає значення "a" до "an" 
            bn--; //зменшує "bn" на 1
        }
        else {
            an += a << 1;//Якщо "bn" не дорівнює 1, то програма додає "a", зсунуте на 1 біт вліво (тобто помножене на 2), до "an"
            bn -= 2;//зменшує "bn" на 2.
        }
    }
    c = a * b;//Щоб перевірити чи верхня частина коду вірна.
    cout << "Результат : " << an << endl;//Результат множення двох беззнакових чисел 
    WriteArrayTextFileFor1and3Task(an, "answerfor3task.txt");
    cout << "Перевiрка : " << c;//Перевірка
    WriteArrayTextFileFor1and3Task(c, "answerfor3taskwithoutbit.txt");
    return;
}



    





