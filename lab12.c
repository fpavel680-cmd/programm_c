#include <stdio.h>
#include <math.h>
#include <windows.h>

#define LMAX 1000

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    int n, i, k, p, count;
    double x, h, a;
    double r[LMAX], maxPositive, sum, sr;
    int hasPositive;

    printf("Лабораторная работа №1\n");
    printf("Вариант 27 (7, 1, 8)\n\n");

    do {
        printf("Введите длину массива R от 1 до %d: ", LMAX);
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n') { }
            n = 0;
            printf("Ошибка: необходимо ввести целое число.\n");
        }
    } while (n <= 0 || n > LMAX);

    do {
        printf("Введите x, h, a: ");
        if (scanf("%lf%lf%lf", &x, &h, &a) != 3 ||
            !isfinite(x) || !isfinite(h) || !isfinite(a)) {
            while (getchar() != '\n') { }
            printf("Ошибка: введите три конечных вещественных числа.\n");
        } else {
            break;
        }
    } while (1);

    /* Задание №1 */
    printf("\nЗадание №1\n");
    for (i = 1; i <= n; ++i) {
        r[i - 1] = 0.8 * cos(8.0 * a * x - i * h);
    }

    printf("Массив R из %d элементов:\n", n);
    for (i = 0; i < n; ++i) {
        printf("%8.3f ", r[i]);
    }
    printf("\n");

    /* Задание №2: удаление сдвигом, один цикл, без нового массива */
    printf("\nЗадание №2\n");
    k = 0;
    for (i = 0; i < n; ++i) {
        if (fabs(r[i]) >= 0.7) {
            r[k] = r[i];
            ++k;
        }
    }

    if (k == 0) {
        printf("Полное удаление массива.\n");
        return 0;
    }

    if (k == n) {
        printf("Удалений не было. Массив не изменился.\n");
    } else {
        printf("Массив R после удаления:\n");
    }

    for (i = 0; i < k; ++i) {
        printf("%8.3f ", r[i]);
    }
    printf("\n");

    /* Задание №3 */
    printf("\nЗадание №3\n");
    hasPositive = 0;
    p = -1;
    maxPositive = 0.0;

    for (i = 0; i < k; ++i) {
        if (r[i] > 0.0) {
            if (!hasPositive || r[i] >= maxPositive) {
                maxPositive = r[i];
                p = i;
                hasPositive = 1;
            }
        }
    }

    if (!hasPositive) {
        printf("Нет среднего значения, так как положительных элементов нет.\n");
        return 0;
    }

    if (p == k - 1) {
        printf("Нет среднего значения, так как после последнего максимального\n");
        printf("положительного элемента нет элементов.\n");
        return 0;
    }

    sum = 0.0;
    count = 0;
    for (i = p + 1; i < k; ++i) {
        sum += r[i];
        ++count;
    }

    sr = sum / count;
    printf("Среднее значение = %8.3f\n", sr);

    return 0;
}
