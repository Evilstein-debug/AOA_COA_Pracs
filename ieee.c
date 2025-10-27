#include <stdio.h>
#include <math.h>
void printBinaryInteger(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int bits[32], i = 0;
    while (n > 0) {
        bits[i++] = n % 2;
        n /= 2;
    }
    for (int j = i - 1; j >= 0; j--) printf("%d", bits[j]);
}
void printBinaryFraction(float frac, int precision) {
    for (int i = 0; i < precision; i++) {
        frac *= 2;
        if (frac >= 1.0) {
            printf("1");
            frac -= 1.0;
        } else {
            printf("0");
        }
    }
}
int main() {
    float num;
    printf("Tejas Pathak\nC23\n2403119\n");
    printf("Enter a floating-point number: ");
    scanf("%f", &num);
    int sign = (num < 0) ? 1 : 0;
    float absNum = fabs(num);
    int intPart = (int)absNum;
    float fracPart = absNum - intPart;
    printf("Binary of %f = ", absNum);
    printBinaryInteger(intPart);
    if (fracPart > 0) {
        printf(".");
        printBinaryFraction(fracPart, 23);
    }
    printf("\n");
    float frac = absNum;
    int exponent = 0;
    if (frac >= 2.0) {
        while (frac >= 2.0) {
            frac /= 2.0;
            exponent++;
        }
    } else if (frac < 1.0 && frac != 0.0) {
        while (frac < 1.0) {
            frac *= 2.0;
            exponent--;
        }
    }
    int biasedExp = exponent + 127;
    frac -= 1.0;
    unsigned int mantissa = 0;
    for (int i = 0; i < 23; i++) {
        frac *= 2;
        if (frac >= 1.0) {
            mantissa |= (1 << (22 - i));
            frac -= 1.0;
        }
    }
    unsigned int ieee754 = (sign << 31) | (biasedExp << 23) | mantissa;
    printf("\n Detailed Components:\n");
    printf("Sign bit     : %d\n", sign);
    printf("Exponent     : %d (biased) = ", biasedExp);
    for (int i = 7; i >= 0; i--) printf("%d", (biasedExp >> i) & 1);
    printf("\nMantissa     : ");
    for (int i = 22; i >= 0; i--) printf("%d", (mantissa >> i) & 1);
    printf("\n");
     printf("\n IEEE 754 Representation:\n");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (ieee754 >> i) & 1);
        if (i == 31 || i == 23) printf(" ");
    }
    printf("\n");
    return 0;
}
