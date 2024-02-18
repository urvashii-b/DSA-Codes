#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&arr) {
    int n=arr.size();
    for(int i=0;i<=n-2;i++){
        int min = i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i]=arr[min];
        arr[min]= temp;
    }
}

void bubbleSort(vector<int>& arr, int n) 
{
    for(int i=n-1;i>=0;i--){
        int didSwap=0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                didSwap=1;
            }
        }
        if(didSwap==1){
            break;
        }
    }
}

void insertionSort(int arr[], int n)
{
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main(){
    
    return 0;
}