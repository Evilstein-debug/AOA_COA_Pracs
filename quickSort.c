#include <stdio.h>

void display(int arr[50], int n){
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>pivot && j>low){
            j--;
        }
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex);
        quickSort(arr, partitionIndex+1, high);
    }
}

int main(){
    int arr[50];
    int low, high, n;
    printf("Enter the length of array: \n");
    scanf("%d", &n);
    printf("Enter elements of the array: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    low = 0;
    high = n-1;
    quickSort(arr, low, high);
    display(arr, n);
}