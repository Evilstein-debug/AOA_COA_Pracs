#include <stdio.h>
#include <string.h>

#define MAX 100


void printMatrix(int rows, int cols, int dp[rows][cols]) {
    printf("DP Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", dp[i][j]);
        }
        printf("\n");
    }
}


void printDirectionMatrix(int rows, int cols, char dir[rows][cols]) {
    printf("Direction Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %c  ", dir[i][j]);
        }
        printf("\n");
    }
}

void findLCS(char str1[], char str2[], int len1, int len2)
{
    int dp[len1 + 1][len2 + 1];
    char dir[len1 + 1][len2 + 1]; 

    
    for (int i = 0; i <= len1; i++) {
        dp[i][0] = 0;
        dir[i][0] = '-';
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = 0;
        dir[0][j] = '-';
    }

    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                dir[i][j] = 'd'; // diagonal (match)
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                dir[i][j] = 'u'; // up
            } else {
                dp[i][j] = dp[i][j - 1];
                dir[i][j] = 'l'; // left
            }
        }
    }

    
    printMatrix(len1 + 1, len2 + 1, dp);
    printDirectionMatrix(len1 + 1, len2 + 1, dir);

    
    int lcslength = dp[len1][len2];
    char lcs[lcslength + 1];
    lcs[lcslength] = '\0';

    int i = len1, j = len2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[--lcslength] = str1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s  (Length: %lu)\n", lcs, strlen(lcs));
}


int main() {
    char str1[MAX], str2[MAX];

    printf("Enter first string: ");
    fgets(str1, MAX, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, MAX, stdin);
    str2[strcspn(str2, "\n")] = '\0';  

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    printf("STRING1 : %s\n", str1);
    printf("STRING2 : %s\n", str2);

    findLCS(str1, str2, len1, len2);

    return 0;
}