#include<bits/stdc++.h>
using namespace std;

/* Selection Sort - select the minimum and swap with i: O(n^2)
13 4 7 9 -> (1) 4 13 7 9 -> (2) 4 7 13 9 -> (3) 4 7 9 13 : 4 elements sorted in 3 steps 

Bubble Sort - compare adjacent elements and swap
worst - O(n^2), best - O(n)
accessing an index which is not present - runtime error

Insertion Sort - insert the element in the correct position in the sorted array
worst - O(n^2), best - O(n)
*/

void selectionSort(int arr[], int n){
    for(int i=0;i<=n-2;i++){
        int mini = i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        int temp = arr[i];
        arr[i]= arr[mini];
        arr[mini]= temp;
    }
}

void bubbleSort(int arr[], int n){
    for(int i=n-1;i>=0;i--){
        int didSwap = 0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1]= arr[j];
                arr[j]= temp;
                didSwap = 1;
            }
        }
        if(didSwap==0){
            break;
        }
    }
}

void insertionSort(int arr[], int n){
    for(int i=0;i<=n-1;i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1]= arr[j];
            arr[j]= temp;
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
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}