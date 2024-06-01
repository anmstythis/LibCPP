#include <iostream>
#include <Windows.h>

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
        std::cout << "Введите первое число: ";
        if (std::cin >> a)
        {
            std::cout << "Введите операцию (+, -, *, /): ";
            std::cin >> oper;
            switch (oper)
            {
            case '+':
                std::cout << "Введите второе число: ";
                if (std::cin >> b)
                {
                    HINSTANCE load;
                    load = LoadLibrary(L"DynamicLib.dll");
                    typedef float(*sum) (float, float);
                    sum Sum;
                    Sum = (sum)GetProcAddress(load, "Sum");
                    std::cout << "\nРезультат: " << Sum(a, b) << std::endl;
                    FreeLibrary(load);
                }
                else
                {
                    std::cout << "Э?" << std::endl;
                    exit(b);
                }
                break;
            case '-':
                std::cout << "Введите второе число: ";
                if (std::cin >> b)
                {
                    HINSTANCE load;
                    load = LoadLibrary(L"DynamicLib.dll");
                    typedef float(*neg) (float, float);
                    neg Neg = (neg)GetProcAddress(load, "Neg");
                    std::cout << "\nРезультат: " << Neg(a, b) << std::endl;
                    FreeLibrary(load);
                }
                else
                {
                    std::cout << "Э?" << std::endl;
                    exit(b);
                }
                break;
            case '*':
                std::cout << "Введите второе число: ";
                if (std::cin >> b)
                {
                    HINSTANCE load;
                    load = LoadLibrary(L"DynamicLib.dll");
                    typedef float(*mult) (float, float);
                    mult Mult = (mult)GetProcAddress(load, "Mult");
                    std::cout << "\nРезультат: " << Mult(a, b) << std::endl;
                    FreeLibrary(load);
                }
                else
                {
                    std::cout << "Э?" << std::endl;
                    exit(b);
                }
                break;
            case '/':
                std::cout << "Введите второе число: ";
                if (std::cin >> b)
                {
                    if (b == 0)
                    {
                        std::cout << "\nДелить на 0 нельзя!\n";
                    }
                    else
                    {
                        HINSTANCE load;
                        load = LoadLibrary(L"DynamicLib.dll");
                        typedef float(*div) (float, float);
                        div Div = (div)GetProcAddress(load, "Div");
                        std::cout << "\nРезультат: " << Div(a, b) << std::endl;
                        FreeLibrary(load);
                    }
                }
                else
                {
                    std::cout << "Э?" << std::endl;
                    exit(b);
                }
                break;
            default:
                std::cout << "\nТакой операции не предусмотрено.\n";
                break;
            }
        }
        else
        {
            std::cout << "\nЭ, я так не играю..." << std::endl;
            exit(a);
        }

        std::cout << "Продолжить работу калькулятора? 1. да \t2. нет \n";
        std::cin >> opt;
        std::cout << std::endl;
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
            std::cout << "Звиняйте, я устал, поэтому решил, что работать не буду :)" << std::endl;
            break;
        }
    }
}

