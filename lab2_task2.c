#include <stdio.h>

#define LMAX 200

int main(void) {
    int p = 0;
    int B[LMAX];
    int i, t, mult, valid;
    char ch;

    printf("Лабораторная работа №2\n");
    printf("Задание 2 (Вариант 27, №8)\n\n");

    do {
        printf("Введите длину массива от 1 до %d: ", LMAX);
        valid = scanf("%d%c", &p, &ch);
        if (valid != 2 || (ch != '\n' && ch != ' ' && ch != '\t' && ch != '\r') || p <= 0 || p > LMAX) {
            printf("Ошибка ввода! Введите целое число от 1 до %d.\n", LMAX);
            if (valid != 2 || ch != '\n') {
                while (getchar() != '\n');
            }
            valid = 0;
        }
    } while (!valid);

    printf("Введите массив B из %d целых положительных элементов:\n", p);
    for (i = 0; i < p; i++) {
        do {
            valid = scanf("%d%c", &B[i], &ch);
            if (valid != 2 || (ch != '\n' && ch != ' ' && ch != '\t' && ch != '\r') || B[i] <= 0) {
                printf("Ошибка ввода! Введите целое положительное число (> 0) для B[%d]: ", i + 1);
                if (valid != 2 || ch != '\n') {
                    while (getchar() != '\n');
                }
                valid = 0;
            }
        } while (!valid);
    }

    /* Циклическая перестановка цифр каждого элемента на одну цифру вправо */
    for (i = 0; i < p; i++) {
        t = B[i];
        mult = 1;
        while (t / 10 != 0) {
            mult = mult * 10;
            t = t / 10;
        }
        B[i] = (B[i] % 10) * mult + (B[i] / 10);
    }

    printf("Массив B:\n");
    for (i = 0; i < p; i++) {
        printf("%8d", B[i]);
    }
    printf("\n");

    return 0;
}
