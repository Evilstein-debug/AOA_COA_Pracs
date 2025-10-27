#include <stdio.h>

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d", arr[i]);
    printf(" ");
}
void decimalToBinary(int num, int bin[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        bin[i] = num % 2;
        num /= 2;
    }
}
void leftShift(int A[], int Q[], int Q_1[], int n) {
    int i;
    for (i = 0; i < n - 1; i++)
        A[i] = A[i + 1];
    A[n - 1] = Q[0];
    for (i = 0; i < n - 1; i++)
        Q[i] = Q[i + 1];
    Q[n - 1] = Q_1[0];
}

void twosComplement(int M[], int negM[], int n) {
    int i, carry = 1;
    for (i = 0; i < n; i++)
        negM[i] = M[i] == 0 ? 1 : 0;
    for (i = n - 1; i >= 0; i--) {
        int sum = negM[i] + carry;
        negM[i] = sum % 2;
        carry = sum / 2;
    }
}
void add(int A[], int B[], int n) {
    int i, carry = 0;

    for (i = n - 1; i >= 0; i--) {
        int sum = A[i] + B[i] + carry;
        A[i] = sum % 2;
        carry = sum / 2;
    }
}

void nonRestoringDivision(int Q[], int M[], int n) {
    int A[10] = {0};
    int Q_1[1] = {0};
    int negM[10];
    int step;

    twosComplement(M, negM, n);

    printf("Step\tA\t\tQ\tQ-1\tOperation\n");
    printf("Init\t");
    display(A, n);
    display(Q, n);
    printf("%d\tInitial Values\n", Q_1[0]);

    for (step = 1; step <= n; step++) {
        printf("%d\t", step);
        leftShift(A, Q, Q_1, n);
        if (A[0] == 0) {
            add(A, negM, n);
        } else {
            add(A, M, n);
        }

        if (A[0] == 0)
            Q[n - 1] = 1;
        else
            Q[n - 1] = 0;

        display(A, n);
        display(Q, n);
        printf("%d\t", Q_1[0]);
        if (A[0] == 0)
            printf("A >= 0 -> Q0 = 1\n");
        else
            printf("A < 0 -> Q0 = 0\n");
    }

    if (A[0] == 1)
        add(A, M, n);

    printf("\nFinal Quotient:  ");
    display(Q, n);
    printf("\nFinal Remainder: ");
    display(A, n);
    printf("\n");
}

int main() {
    int n = 4;
    int Q[10] = {0};
    int M[10] = {0};
    int dividend, divisor;
    printf("Tejas Pathak\nC23\n2403119\n");

    printf("Enter Dividend (Decimal): ");
    scanf("%d", &dividend);

    printf("Enter Divisor (Decimal): ");
    scanf("%d", &divisor);

    if (dividend >= (1 << n) || divisor >= (1 << n)) {
        printf("Error: Inputs must be less than %d (4-bit limit).\n", 1 << n);
        return 1;
    }

    decimalToBinary(dividend, Q, n);
    decimalToBinary(divisor, M, n);

    printf("\nNon-Restoring Division Without Pointers:\n");
    nonRestoringDivision(Q, M, n);

    return 0;
}


/*
#include <stdio.h>

void display(int arr[], int n) {
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
    }
    printf(" ");
}

void decimalToBinary(int num, int bin[], int n) {
    if(num<0) {
        num = (1 << n) + num;
    }
    for(int i=n-1; i>=0; i--){
        bin[i] = num%2;
        num /= 2;
    }
}

void leftShift(int A[], int Q[], int Q_1[], int n) {
    for(int i=0; i<n-1; i++){
        A[i] = A[i+1];
    }
    A[n-1] = Q[0];
    for(int i=0; i<n-1; i++){
        Q[i] = Q[i+1];    
    }
    Q[n-1] = Q_1[0];
}

void twosComplement(int M[], int negM[], int n) {
    int i, carry = 1;
    for(i=0; i<n; i++){
        negM[i] = M[i] == 0 ? 1 : 0;
    }
    for(i=n-1; i>=0; i--){
        int sum = negM[i] + carry;
        negM[i] = sum%2;
        carry = sum/2;
    }
}

void add (int A[], int M[], int n){
    int carry=0;
    for(int i=n-1; i>=0; i--){
        int sum = A[i]+M[i]+carry;
        A[i] = sum%2;
        carry = sum/2;
    }
}

void nonRestoringDivision(int Q[], int M[], int n){
    int A[10] = {0};
    int Q_1[1] = {0};
    int negM[10];
    int step;
    
    twosComplement(M, negM, n);
    
    printf("Step\tA\tQ\tQ-1\tOperation\n");
    printf("Init\t");
    display(A, n);
    display(Q, n);
    printf("%d\tInitial values\n", Q_1[0]);
    
    for(step=1; step<=n; step++){
        printf("%d\t\t", step);
        leftShift(A, Q, Q_1, n);
        if(A[0] == 0) add(A, negM, n);
        else add(A, M, n);
        
        if(A[0] == 0) {
            Q[n-1] = 1;
        }
        else Q[n-1] = 0;
        
        display(A,n);
        display(Q,n);
        printf("%d\t", Q_1[0]);
        
        if(A[0] == 1){
            printf("A<0 -> Q0 = 0\n");
        }
        else printf("A>=0 -> Q0 = 1\n");
    }
    if(A[0] == 1) add(A,M,n);
        
        printf("\nFinal Quotient:  ");
        display(Q, n);
        printf("\nFinal Remainder: ");
        display(A, n);
        printf("\n");
}

int main() {
    int n=4;
    int Q[10] = {0};
    int M[10] = {0};
    int dividend, divisor;
    
    printf("Enter dividend (decimal): ");
    scanf("%d", &dividend);
    printf("Enter divisor (decimal): ");
    scanf("%d", &divisor);
    
    if (dividend >= (1 << n) || divisor >= (1 << n)) {
        printf("Error: Inputs must be less than %d (4-bit limit).\n", 1 << n);
        return 1;
    }
    
    decimalToBinary(dividend, Q, n);
    decimalToBinary(divisor, M, n);
    
    printf("Non restoring division: \n");
    nonRestoringDivision(Q,M,n);
    
}
*/