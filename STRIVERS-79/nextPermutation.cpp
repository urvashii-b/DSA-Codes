#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A){
    int n = A.size();
    int index =-1; // breakpoint
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            index = i;
            break;
        }
    }
    if(index==-1){
        reverse(A.begin(),A.end()); // no breakpoint then reverse
    }
    for(int i=n-1;i>index;i--){
        if(A[i]>A[index]){
            swap(A[i],A[index]); // swap with closest for next permutation
            break;
        }
    }
    reverse(A.begin()+index+1,A.end()); // sort in asc after swap
    return A;
}
/*
1. 2 ways of generating all permutations

i) make a data structure and a frequency map
if 1 is not marked..1 is put on the data structure and marked on the frequency map 
it can't be taken again
keep doing this recursively until data structure size = original array/string size
auxiliary extra space (N) taken because of data structure and freq map

class Solution{
private:
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]){
        if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
        }
        for(int i=0;i<nums.size();i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i]=1;
            recurPermute(ds, nums, ans, freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
public:
    vector<vector<int>> permute(vector<int> &nums){
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()]={0};
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
            recurPermute(ds, nums, ans, freq);
            return ans;
        }
    }
};

ii) take every index and swap with itself and well as the next index
mark that index as done and do this again for the next index
ex: swap 0 with 0 and 0 with 1.. then swap 1 with 1 and 1 with 2..etc
do this until index = array/string size

class Solution {
private: 
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans) {
        if(index == nums.size()) {
            ans.push_back(nums); 
            return; 
        }
        for(int i = index;i<nums.size();i++) {
            swap(nums[index], nums[i]); 
            recurPermute(index+1, nums, ans); 
            swap(nums[index], nums[i]); 
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        recurPermute(0, nums, ans); 
        return ans; 
    }
};
*/
int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    /* NEXT PERMUTATION (next lexicographically greater permutation)
    i) brute force: find all combinations(sorted) and then perform linear search to find the next one
    O(n!*n)

    ii) better - C++ STL
     
    vector<int> nextGreaterPermutation(vector<int> &A){
        next_permutation(A.begin(),A.end());
        return A;
    };

    iii) optimal
    longest prefix match
    find the breakpoint where a[i]<a[i+1] 
    find ele > a[i] but closest to a[i] and place it 
    then place all the numbers in a sorted asc order after ele

    ex: for-> 2 1 5 4 3 0 0 
    2 is the longest prefix match
    breakpoint is between 1 and 5
    2 3 - - - - - as 3 is closest to 1
    2 3 (0 0 1 4 5) sorted order placed

    edge case: if largest permutation is already given (index = -1) then reverse the array
    ex: 5 4 3 then next permutation is 3 4 5 

    */
    vector<int> A = {2,1,5,4,3,0,0};
    vector<int> ans = nextGreaterPermutation(A);

    cout<< "The next permutation is: [";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<"]";
    return 0;
}