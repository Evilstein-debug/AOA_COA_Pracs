#include <stdio.h>

int exponent[8];
int mantissa[23];

int bit_size(int num){
    int size=0;
    while (num>0)
    {
        num /= 2;
        size++;
    }
    return size;
}

void convert_int_to_binary(int num, int bin[], int size){
    for(int i=size-1; i>=0; i--){
        bin[i] = num%2;
        num /= 2;
    }
}

void convert_frac_to_binary(double num, int start){
    int i=start;
    while (i<23)
    {
        double temp = num*2;
        mantissa[i++] = (int)temp;
        num = temp - (int)temp;
    }
}

void fill_mantissa(int arr[], int end){
    for(int i=0; i<end; i++){
        mantissa[i] = arr[i+1];
    }
}

void fill_exponent(int exp){
    int num = 127 + exp;
    convert_int_to_binary(num, exponent, 8);
}

void ieee(int num, double frac){
    int size_of_num = bit_size(num);
    int exp = size_of_num-1;        //actual exponent
    int num_array[32];
    convert_int_to_binary(num, num_array, size_of_num);
    convert_frac_to_binary(frac, exp);
    fill_mantissa(num_array, exp);
    fill_exponent(exp);

    (num>0)?(printf("Sign: 0\n")):(printf("Sign: 1\n"));
    printf("Exponent: ");
    for(int i=0; i<8; i++){
        printf("%d", exponent[i]);
    }
    printf("\nMantissa: ");
    for(int i=0; i<27; i++){
        printf("%d", mantissa[i]);
    }
    printf("\n");
}

int main(){
    double num;
    printf("Enter the number: ");
    scanf("%lf", &num);
    int integer = (int)num;
    double fraction = num - integer;
    ieee(integer, fraction);
    return 0;
}