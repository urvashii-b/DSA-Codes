#include<bits/stdc++.h>
using namespace std;

// 1. Largest element in an array
int largestElement(vector<int> &arr, int n) {
    int largest = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}

// 2. Second largest element in an array
int secondLargest(vector<int> &arr, int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}
int secondSmallest(vector<int> &arr, int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i]<smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i]>smallest && arr[i]<ssmallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int slargest = secondLargest(a, n);
    int ssmallest = secondSmallest(a, n);
    return {slargest, ssmallest};
}

// 3. Check if the array is sorted
int isSorted(int n, vector<int> arr) {
   for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){

        }
        else{
            return false;
        }
   }
   return true;
}
// 4. Check if array is sorted and rotated
bool check(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;
    for(int i=1;i<n;i++){
        if(nums[i-1]>nums[i]){
            cnt++;
        }
    }
    if(nums[n-1]>nums[0]){
        cnt++;
    }
    return cnt<=1;
}

// 5. Remove duplicates from sorted array
int removeDuplicates(vector<int>& nums) {
    int i=0;
    int n=nums.size();
    for(int j=1;j<n;j++){
        if(nums[i]!=nums[j]){
            nums[i+1]=nums[j];
            i++;
        }
    }
    return (i+1);
}
int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    vector<int> numbers = {5, 8, 15, 20, 49};
    /*
    1.
    int result = largestElement(numbers, numbers.size());
    cout << "The largest element in the array is: " << result << endl;
    
    2.
    vector<int> result = getSecondOrderElements(numbers.size(), numbers);
    cout << "Second Largest Element: " << result[0] << endl;
    cout << "Second Smallest Element: " << result[1] << endl;
    
    3.
    bool result1 = isSorted(numbers.size(),numbers);
    cout<< "A sorted array? "<< boolalpha<<result1;
    
    4.
    vector<int> nums2 = {3,4,5,1,2};  // rotated sorted array
    bool result2 = check(nums2);
    cout << "Is nums2 a rotated sorted array? " << boolalpha << result2 << endl;
    
    5.
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int newSize = removeDuplicates(nums);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    */
    return 0;
}