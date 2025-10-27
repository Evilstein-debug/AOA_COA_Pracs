#include <stdio.h>
#define SIZE 4
int A[SIZE] = {0}, Q[SIZE], M[SIZE], Qn = 0;

void decimalToBinary(int bin[], int num) {
    if (num < 0)
        num = (1 << SIZE) + num;
    for (int i = SIZE - 1; i >= 0; i--) {
        bin[i] = num % 2;
        num /= 2;
    }
}

void displayBinary(int bin[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d", bin[i]);
}

void add(int x[], int y[]) {
    int carry = 0;
    for (int i = SIZE - 1; i >= 0; i--) {
        int sum = x[i] + y[i] + carry;
        x[i] = sum % 2;
        carry = sum / 2;
    }
}

void twosComplement(int x[]) {
    for (int i = 0; i < SIZE; i++)
        x[i] = x[i] == 0 ? 1 : 0;
    int one[SIZE] = {0, 0, 0, 1};
    add(x, one);
}

void ARS() {
    Qn = Q[SIZE - 1];
    int msbA = A[0];
    for (int i = SIZE - 1; i > 0; i--) Q[i] = Q[i - 1];
    Q[0] = A[SIZE - 1];
    for (int i = SIZE - 1; i > 0; i--) A[i] = A[i - 1];
    A[0] = msbA;
}

void booths(int m_dec, int q_dec) {
    decimalToBinary(M, m_dec);
    decimalToBinary(Q, q_dec);
    int negM[SIZE];
    for (int i = 0; i < SIZE; i++)
        negM[i] = M[i];
    twosComplement(negM);
    for (int i = 0; i < SIZE; i++) {
        if (Q[SIZE - 1] == 1 && Qn == 0)
            add(A, negM);
        else if (Q[SIZE - 1] == 0 && Qn == 1)
            add(A, M);
        ARS();
    }
    int result[2 * SIZE];
    for (int i = 0; i < SIZE; i++) result[i] = A[i];
    for (int i = 0; i < SIZE; i++) result[i + SIZE] = Q[i];

    printf("\nBinary Result (AQ): ");
    displayBinary(result, 2 * SIZE);

    int value = 0;
    int sign = (result[0] == 1) ? -1 : 1;
    if (sign == 1) {
        for (int i = 0; i < 2 * SIZE; i++)
            value = (value << 1) | result[i];
    } else {
        int temp[2 * SIZE];
        for (int i = 0; i < 2 * SIZE; i++)
            temp[i] = result[i];
        for (int i = 0; i < 2 * SIZE; i++)
            temp[i] = temp[i] == 0 ? 1 : 0;
        int one[2 * SIZE] = {0};
        one[2 * SIZE - 1] = 1;
        int carry = 0;
        for (int i = 2 * SIZE - 1; i >= 0; i--) {
            int sum = temp[i] + one[i] + carry;
            temp[i] = sum % 2;
            carry = sum / 2;
        }
        for (int i = 0; i < 2 * SIZE; i++)
            value = (value << 1) | temp[i];
    }

    printf("\nDecimal Result: %d\n", sign * value);
}

int main() {
    int m, q;
    printf("Tejas Pathak\nC23\n2403119\n");
    printf("Enter multiplicand (-8 to 7): ");
    scanf("%d", &m);
    printf("Enter multiplier (-8 to 7): ");
    scanf("%d", &q);
    booths(m, q);
    return 0;
}
