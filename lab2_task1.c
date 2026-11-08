#include <stdio.h>

#define LMAX 200

int main(void) {
    int n = 0, m = 0, k = 0;
    int A[LMAX][LMAX], B[LMAX];
    int i, j, s, temp;
    int min_b, found, found_rows, swaps, valid;
    char ch;

    printf("Лабораторная работа №2\n");
    printf("Задание 1 (Вариант 27, №11)\n\n");

    do {
        printf("Введите количество строк матрицы n (от 1 до %d): ", LMAX);
        valid = scanf("%d%c", &n, &ch);
        if (valid != 2 || (ch != '\n' && ch != ' ' && ch != '\t' && ch != '\r') || n <= 0 || n > LMAX) {
            printf("Ошибка ввода! Введите целое число от 1 до %d.\n", LMAX);
            if (valid != 2 || ch != '\n') {
                while (getchar() != '\n');
            }
            valid = 0;
        }
    } while (!valid);

    do {
        printf("Введите количество столбцов матрицы m (от 1 до %d): ", LMAX);
        valid = scanf("%d%c", &m, &ch);
        if (valid != 2 || (ch != '\n' && ch != ' ' && ch != '\t' && ch != '\r') || m <= 0 || m > LMAX) {
            printf("Ошибка ввода! Введите целое число от 1 до %d.\n", LMAX);
            if (valid != 2 || ch != '\n') {
                while (getchar() != '\n');
            }
            valid = 0;
        }
    } while (!valid);

    printf("Введите матрицу A из %d строк и %d столбцов:\n", n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            do {
                valid = scanf("%d%c", &A[i][j], &ch);
                if (valid != 2 || (ch != '\n' && ch != ' ' && ch != '\t' && ch != '\r')) {
                    printf("Ошибка ввода! Введите целое число для A[%d][%d]: ", i + 1, j + 1);
                    if (valid != 2 || ch != '\n') {
                        while (getchar() != '\n');
                    }
                    valid = 0;
                }
            } while (!valid);
        }
    }

    do {
        printf("Введите длину массива B k (от 1 до %d): ", LMAX);
        valid = scanf("%d%c", &k, &ch);
        if (valid != 2 || (ch != '\n' && ch != ' ' && ch != '\t' && ch != '\r') || k <= 0 || k > LMAX) {
            printf("Ошибка ввода! Введите целое число от 1 до %d.\n", LMAX);
            if (valid != 2 || ch != '\n') {
                while (getchar() != '\n');
            }
            valid = 0;
        }
    } while (!valid);

    printf("Введите массив B из %d элементов:\n", k);
    for (i = 0; i < k; i++) {
        do {
            valid = scanf("%d%c", &B[i], &ch);
            if (valid != 2 || (ch != '\n' && ch != ' ' && ch != '\t' && ch != '\r')) {
                printf("Ошибка ввода! Введите целое число для B[%d]: ", i + 1);
                if (valid != 2 || ch != '\n') {
                    while (getchar() != '\n');
                }
                valid = 0;
            }
        } while (!valid);
    }

    /* Поиск минимального элемента массива B */
    min_b = B[0];
    for (i = 1; i < k; i++) {
        if (B[i] < min_b) {
            min_b = B[i];
        }
    }

    printf("\nМинимальный элемент массива B: %d\n", min_b);

    /* Проверка строк с досрочным выходом из цикла и упорядочивание по возрастанию */
    found_rows = 0;
    swaps = 0;
    for (i = 0; i < n; i++) {
        j = 0;
        found = 0;
        while (j < m && !found) {
            if (A[i][j] == min_b) {
                found = 1;
            }
            j++;
        }

        if (found) {
            found_rows++;
            for (j = 0; j < m - 1; j++) {
                for (s = 0; s < m - 1 - j; s++) {
                    if (A[i][s] > A[i][s + 1]) {
                        temp = A[i][s];
                        A[i][s] = A[i][s + 1];
                        A[i][s + 1] = temp;
                        swaps++;
                    }
                }
            }
        }
    }

    if (found_rows == 0) {
        printf("Нет строк, содержащих минимальный элемент массива B.\n");
    } else if (swaps == 0) {
        printf("Строки, содержащие минимальный элемент массива B, уже упорядочены по возрастанию.\n");
    } else {
        printf("Новая матрица A:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                printf("%6d", A[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
