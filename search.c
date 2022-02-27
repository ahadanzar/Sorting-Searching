#include <stdio.h>

int linear(int arr[], int n, int key);
int binary(int arr[], int n, int key);
void sort(int arr[], int n);
void display(int arr[], int n);

int main(){
    int arr[50], o=0, i=0;
    while(o!=4){
        printf("\n1)Insert Element\n2)Linear Search\n3)Binary Search\n4)Exit\nEnter Operation : ");
        scanf("%d", &o);
        if(o==1){
            int val;
            printf("\nEnter value to insert : ");
            scanf("%d", &val);
            arr[i] = val;
            i++;
            display(arr, i);
        }
        else if(o==2 || o==3){
            int key, found;
            printf("\nEnter value to search : ");
            scanf("%d", &key);
            if(o==2)
                found=linear(arr, i+1, key);
            else{
                printf("\nArray has to be sorted for binary search");
                sort(arr, i+1);
                printf("\nSorted array : ");
                display(arr, i);
                found=binary(arr, i+1, key);
            }
            if(found>-1)
                printf("\nElement found at index %d\n", found);
            else{
                printf("\nElement not present in the array\n");
            }
        }
        else if(o==4){
            continue;
        }
    }
    return 0;
}

int linear(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binary(int arr[], int n, int key){
    int result=-1, low = 0, high = n - 1, mid;
    while(result == -1 && low <= high){
        mid = (low+high)/2; 
        if(arr[mid] == key)
            result = mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

void sort(int arr[], int n){
    for(int i=1;i<n;i++){
        int j=i-1, key=arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void display(int arr[], int n){
    printf("\nArray : ");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}