#include <stdio.h>

void display(int arr[50], int n){
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
}

void merge(int arr[], int low, int mid, int high){
    int arr2[50];
    int left = low;
    int right = mid+1;
    int i=0;
    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            arr2[i++] = arr[left++];
        }
        else{
            arr2[i++] = arr[right++];
        }
    }
        while(left <= mid){
            arr2[i++] = arr[left++];
        }
        while(right <= high){
            arr2[i++] = arr[right++];
        }
        for(int j=low; j<=high; j++){
            arr[j] = arr2[j - low];
        }
}

void mergeSort(int arr[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    int arr[50];
    int arr2[50];
    int low, high, n;
    printf("Enter the length of array: \n");
    scanf("%d", &n);
    printf("Enter elements of the array: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    low = 0;
    high = n-1;
    mergeSort(arr, low, high);
    display(arr, n);
}