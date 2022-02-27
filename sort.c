#include <stdio.h>

void bubblesort(int arr[], int n);
void insertionsort(int arr[], int n);
void selectionsort(int arr[], int n);
void quicksort(int arr[], int low, int high);
void mergesort(int arr[], int low, int high);
void heapsort(int arr[], int n);
void display(int arr[], int n);

int main(){
    int arr[50];
    int o=0, i=0;
    while(o!=8){
        printf("\n1)Insert Element\n2)Bubble Sort\n3)Insertion Sort\n4)Selection Sort\n5)Quick Sort\n6)Merge Sort\n7)Heap Sort\n8)Exit\nEnter Operation : ");
        scanf("%d", &o);
        if(o==1){
            int val;
            printf("\nEnter value to insert : ");
            scanf("%d", &val);
            arr[i] = val;
            i++;
        }
        else if(o==2){
            bubblesort(arr, i);
        }
        else if(o==3){
            insertionsort(arr, i);
        }
        else if(o==4){
            selectionsort(arr, i);
        }
        else if(o==5){
            quicksort(arr, 0, i-1);
        }
        else if(o==6){
            mergesort(arr, 0, i-1);
        }
        else if(o==7){
            heapsort(arr, i);
        }
        else if(o==8){
            continue;
        }
        display(arr, i);
    }
    return 0;
}

void swap(int arr[], int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void bubblesort(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
}

void insertionsort(int arr[], int n){
    for(int i=1;i<n;i++){
        int j=i-1, key=arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionsort(int arr[], int n){
    int min, temp;
    for(int i = 0; i<n-1; i++) {
        min = i;
        for(int j=i+1;j<n;j++)
            if(arr[j] < arr[min])
                min = j;
            swap(arr, i, min);
    }
}

int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i = low-1, temp;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, high);
    return i+1;
}

void quicksort(int arr[], int low, int high){
    if(low<high){
        int location = partition(arr, low, high);
        quicksort(arr, low, location-1);
        quicksort(arr, location+1, high);
    }
}

void merge(int arr[], int low, int mid, int high){
    int i, j, k;
    int n1 = mid-low+1;
    int n2 = high-mid;
    int L[n1], R[n2];
    for(i=0;i<n1;i++)
        L[i]=arr[low+i];
    for(j=0;j<n2;j++)
        R[j]=arr[mid+1+j];
    i=0, j=0, k=low;
    while(i<n1 && j<n2){
        if(L[i] <= R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }
    while(i<n1)
        arr[k++] = L[i++];
    while(j<n2)
        arr[k++] = R[j++];
}

void mergesort(int arr[], int low, int high){
    if(low<high){
        int mid = low + (high-low)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void heap(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[largest])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr, i, largest);
        heap(arr, n, largest);
    }
}
 
void heapsort(int arr[], int n){
    for(int i = n/2-1; i >= 0; i--)
        heap(arr, n, i);
    for(int i=n-1; i > 0; i--) {
        swap(arr, 0, i);
        heap(arr, i, 0);
    }
}

void display(int arr[], int n){
    printf("\nArray : ");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}