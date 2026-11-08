#include <stdio.h>
#include <math.h>
#include <windows.h>

#define lmax 1000

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n, i, k, p, count;
    float x, h, a;
    float r[lmax], max, sum, sr;
    int flag;

    printf("Лабораторная работа №1\n");
    printf("Вариант 27 (7, 1, 8)\n\n");

    do
    {
        printf("Введите длину массива R от 1 до %d: ", lmax);
        if (scanf("%d", &n) != 1)
        {
            while (getchar() != '\n') { }
            n = 0;
        }
    }
    while (n < 1 || n > lmax);

    do
    {
        printf("Введите x, h, a: ");
        if (scanf("%f%f%f", &x, &h, &a) != 3)
        {
            while (getchar() != '\n') { }
            printf("Ошибка ввода. Введите три числа через пробел.\n");
        }
        else
        {
            break;
        }
    }
    while (1);

    printf("\nЗадание №1\n");

    for (i = 1; i <= n; i++)
    {
        r[i - 1] = 0.8 * cos(8 * a * x - i * h);
    }

    printf("Массив R из %d элементов:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("%8.3f ", r[i]);
    }
    printf("\n");

    printf("\nЗадание №2\n");

    k = 0;
    for (i = 0; i < n; i++)
    {
        if (fabs(r[i]) >= 0.7)
        {
            r[k] = r[i];
            k++;
        }
    }

    if (k == 0)
    {
        printf("Полное удаление массива.\n");
        return 0;
    }

    if (k == n)
    {
        printf("Удалений не было. Массив не изменился.\n");
    }
    else
    {
        printf("Массив R после удаления:\n");
    }

    for (i = 0; i < k; i++)
    {
        printf("%8.3f ", r[i]);
    }
    printf("\n");

    printf("\nЗадание №3\n");

    flag = 0;
    p = -1;
    max = 0;

    for (i = 0; i < k; i++)
    {
        if (r[i] > 0)
        {
            if (flag == 0 || r[i] >= max)
            {
                max = r[i];
                p = i;
                flag = 1;
            }
        }
    }

    if (flag == 0)
    {
        printf("Нет среднего значения, так как положительных элементов нет.\n");
        return 0;
    }

    if (p == k - 1) 
    {
        printf("Нет среднего значения, так как после последнего максимального\n");
        printf("положительного элемента нет элементов.\n");
        return 0;
    }

    sum = 0;
    count = 0;

    for (i = p + 1; i < k; i++)
    {
        sum = sum + r[i];
        count++;
    }

    sr = sum / count;

    printf("Среднее значение = %8.3f\n", sr);

    return 0;
}
