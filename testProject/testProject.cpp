#include <iostream>
#include <Windows.h>
#include "..\StaticLib\Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
   
    float a;
    float b;
    char oper;
    int opt;


    while (true)
    {
        cout << "Введите первое число: ";
        if (cin >> a)
        {
            cout << "Введите операцию (+, -, *, /): ";
            cin >> oper;
            switch (oper)
            {
            case '+':
                cout << "Введите второе число: ";
                if (cin >> b)
                {
                    cout << "\nРезультат: " << Sum(a, b) << endl;
                }
                else
                {
                    cout << "Э?" << endl;
                    exit(b);
                }
                break;
            case '-':
                cout << "Введите второе число: ";
                if (cin >> b)
                {
                    cout << "\nРезультат: " << Neg(a, b) << endl;
                }
                else
                {
                    cout << "Э?" << endl;
                    exit(b);
                }
                break;
            case '*':
                cout << "Введите второе число: ";
                if (cin >> b)
                {
                    cout << "\nРезультат: " << Mult(a, b) << endl;
                }
                else
                {
                    cout << "Э?" << endl;
                    exit(b);
                }
                break;
            case '/':
                cout << "Введите второе число: ";
                if (cin >> b)
                {
                    if (b == 0)
                    {
                        cout << "\nДелить на 0 нельзя!\n";
                    }
                    else
                    {
                        cout << "\nРезультат: " << Div(a, b) << endl;
                    }
                }
                else
                {
                    cout << "Э?" << endl;
                    exit(b);
                }
                break;
            default:
                cout << "\nТакой операции не предусмотрено.\n";
                break;
            }
        }
        else
        {
            cout << "\nЭ, я так не играю..." << endl;
            exit(a);
        }

        cout << "Продолжить работу калькулятора? 1. да \t2. нет \n";
        cin >> opt;
        cout << endl;
        if (opt == 1)
        {
            continue;
        }
        else if (opt == 2)
        {
            break;
        }
        else
        {
            cout << "Звиняйте, я устал, поэтому решил, что работать не буду :)" << endl;
            break;
        }
    }
}

