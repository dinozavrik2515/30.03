#include <Windows.h> 
#include <cstdlib> 
#include <iostream> 
#include <time.h> 
int minsum(int numbers[], int &num, int &min, int position)
{
    num++;
    int sum = 0;

    for (int i = num; i < num + 10; i++)
    {
        sum += numbers[i];
    }
    if (sum < min)
    {
        min = sum;
        position = num;
    }

    if (num < 10)
    {
        minsum(numbers, num, min, position);
    }

    else
    {
        return position;
    }
}

int FindMax(int numbers1[], int size)
{
    int max = numbers1[0];

    for (int i = 0; i < size; i++)
    {
        if (numbers1[i] > max)
        {
            max = numbers1[i];
        }
    }

    return max;
}
int FindMax(int numbers2[10][10])
{
    int max = numbers2[0][0];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (numbers2[i][j] > max) 
            {
                max = numbers2[i][j];
            }
        }
    }

    return max;
}

int FindMax(int numbers3[10][10][10])
{
    int max = numbers3[0][0][0];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int l = 0; l < 10; l++)
            {
                if (numbers3[i][j][i] > max)
                {
                    max = numbers3[i][j][i];
                }
            }
        }
    }

    return max;
}

int FindMax(int num1, int num2)
{
    int max = num1;

    if (num1 < num2)
    {
        max = num2;
    }

    return max;
}

int FindMax(int num1, int num2, int num3)
{
    int max = num1;

    if (num2 > max && num2 > num3)
    {
        max = num2;
    }
    else if (num3 > max && num3 > num2)
    {
        max = num3;
    }

    return max;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    std::cout << "1)\n";
    int numbers[20];
    int sum = 0;
    int min = 0;
    int num = -1;
    int position = 0;

    for (int i = 0; i < 20; i++)
    {
        numbers[i] = rand() % 10;
    }

    for (int i = 0; i < 20; i++)
    {
        std::cout << numbers[i] << " ";
    }

    for (int i = 0; i < 10; i++)
    {
        min += numbers[i];
    }

    std::cout << "\nПозиция числа: " << minsum(numbers, num, min, position);

    //2

    std::cout << "\n\n2)\n";
    const int size = 10;
    int numbers1[size];
    int numbers2[10][10];
    int numbers3[10][10][10];
    int num1 = 5, num2 = - 3, num3 = 9;
    
    for (int i = 0; i < size; i++) //заполнение одномерного массива
    {
        numbers1[i] = rand() % 10;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << numbers1[i] << " ";
    }

    std::cout << "\n\n";

    for (int i = 0; i < 10; i++) //заполнение двумерного массива
    {
        for (int j = 0; j < 10; j++)
        {
            numbers2[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << numbers2[i][j] << " ";
        }

        std::cout << "\n";
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int l = 0; l < 10; l++)
            {
                numbers3[i][j][l] = rand() % 10;
            }
        }
    }

    std::cout << "\n" << "Максимальное значение одномерного массива: " << FindMax(numbers1, size);
    std::cout << "\n" << "Двумерного массива: " << FindMax(numbers2);
    std::cout << "\n" << "Трёхмерного массива: " << FindMax(numbers3);
    std::cout << "\n" << "Двух целых: " << FindMax(num1, num2);
    std::cout << "\n" << "Трёх целых: " << FindMax(num1, num2, num3);

    return 0;
}
