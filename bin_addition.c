#include <stdio.h>

void convertToBinary(int bin[], int num, int n) {
    for(int i=n-1; i>=0; i--){
        bin[i] = num%2;
        num /= 2;
    }
}

int add(int A[], int B[], int result[], int n){
    int carry = 0;
    for(int i=n-1; i>=0; i--){
        int sum = A[i]+B[i]+carry;
        result[i+1] = sum%2;
        carry = sum/2;
    }
    result[0] = carry;
    return carry;
}

void display(int arr[], int n) {
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int n=4;
    int A[4];
    int B[4];
    int result[5];
    int first, second;

    printf("Enter the first number: \n");
    scanf("%d", &first);

    printf("Enter second number: \n");
    scanf("%d", &second);

    convertToBinary(A, first, n);
    convertToBinary(B, second, n);

    printf("First number:\n");
    display(A, n);
    printf("Second number:\n");
    display(B, n);

    int carry = add(A, B, result, n);
    printf("final binary addition answer: \n");
    display(result, n+1);
}