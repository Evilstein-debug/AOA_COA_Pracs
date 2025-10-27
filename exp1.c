#include <stdio.h>

void display(int n, int arr[50]){
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

// void insertionSort(int n, int arr[50]) {     //this correctly sorts but follows technique similar to bubble sort and not insertion sort.
//     int i,j,key;
//     for(i=1; i<n; i++){
//         j=i-1;
//         key = arr[i];
//         while (j>=0 && key<=arr[j])
//         {
//             int temp = arr[j];
//             arr[j] = arr[j+1];
//             arr[j+1] = temp;
//             j--;
//         }
//     }
//     display(n, arr);
// }

void insertionSort(int n, int arr[50]){
    int i,j,key;
    for(i=1; i<n; i++){
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    display(n, arr);
}

void selectionSort(int n, int arr[50]){
    int i,j,k;
    for(i=0; i<n; i++){
        j=i;
        for(k=i+1; k<n; k++){
            if(arr[k]<arr[j]){
            j=k;
            }
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    display(n, arr);
}

int main(){
    int arr[50], n;
    printf("Enter size of the array: \n");
    scanf("%d", &n);
    printf("Enter elements of the array: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    insertionSort(n, arr);
    selectionSort(n,arr);
    return 0;
}