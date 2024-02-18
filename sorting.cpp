#include<bits/stdc++.h>
using namespace std;

/* Selection Sort - select the minimum and swap with i
13 4 7 9 -> (1) 4 13 7 9 -> (2) 4 7 13 9 -> (3) 4 7 9 13 : 4 elements sorted in 3 steps 

Bubble Sort - compare adjacent elements and swap

Insertion Sort - insert the element in the correct position in the sorted array
*/

void selectionSort(int arr[], int n){
    for(int i=0;i<=n-2;i++){
        int min = i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

void bubbleSort(int arr[], int n){
    for(int i=n-1;i>=1;i++){
        int didSwap = 0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didSwap = 1;
            }
        }
        if(didSwap==1){
            break;
        }
    }
}

void insertionSort(int arr[], int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}