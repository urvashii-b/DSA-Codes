#include<bits/stdc++.h>
using namespace std;

/* 1. Maximum and minimum of an array using minimum number of comparisons
BEST APPROACH - COMPARE IN PAIRS
BRUTE FORCE - SORT IN ASC ORDER AND RETURN FIRST,LAST ELE AS MIN,MAX



struct Pair{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int n){
    struct Pair minmax;
    int i;
    if(n%2==0){ // even - the larger one:max and smaller one:min
        if(arr[0]>arr[1]){
            minmax.max=arr[0];
            minmax.min=arr[1];
        }
        else{
            minmax.min=arr[0];
            minmax.max=arr[1];
        }
        i = 2;
    }
    else{ // odd - both are labeled min and max
        minmax.max=arr[0];
        minmax.min=arr[0];
        i=1;
    }

    while(i<n-1){ // compare adjacents in pairs
        if(arr[i]<arr[i+1]){
            if(arr[i+1]>minmax.max){
                minmax.max=arr[i+1];
            }
            if(arr[i]<minmax.min){
                minmax.min=arr[i];
            }
        }else{
            if(arr[i]>minmax.max){
                minmax.max=arr[i];
            }
            if(arr[i+1]<minmax.min){
                minmax.min=arr[i+1];
            }
        }
        i+=2;
    }
    return minmax;
};
2. Reverse an array or string
using the two pointer technique -> place 1 at the start and the other at the end

void revArr(int arr[], int start, int end){
    while(start<end){
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void printArr(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

3. Maximum Subarray
*/
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int currSum = 0;
    for(int i=0;i<nums.size();i++){
        currSum = max(nums[i],nums[i]+currSum);
        maxSum = max(maxSum,currSum);
    } 
    return maxSum;  
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int arr[] = { 1000, 11, 445, 
                1, 330, 3000, 500000, 50}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    /*
    Pair minmax = getMinMax(arr, size); 
    cout << "Minimum element is "
        << minmax.min << endl; 
    cout << "Maximum element is "
        << minmax.max; 
    
    printArr(arr, size);
    revArr(arr,0,size-1);
    cout<<endl;
    cout<<"After reversing: ";
    printArr(arr, size);
    */
    return 0;
}