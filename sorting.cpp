#include<bits/stdc++.h>
using namespace std;

/* Selection Sort - select the minimum and swap with i
13 4 7 9 -> (1) 4 13 7 9 -> (2) 4 7 13 9 -> (3) 4 7 9 13 : 4 elements sorted in 3 steps 

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
int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}