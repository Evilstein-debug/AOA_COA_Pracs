#include <stdio.h>
#include <string.h>
#include <math.h>

#define d 256
#define q 101

void rabinKarp(char *text, char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);
    int i,j;
    int p=0;
    int t=0; 
    int h=1;

    for(i=0; i<m; i++){
        p = (d*p+pattern[i] % q);
    }
}