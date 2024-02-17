// CONTAINS ONLY THE OPTIMAL SOLUTIONS 
#include<bits/stdc++.h>
using namespace std;

// 217. Contains Duplicate - HashSet
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> freq;
    for(int i:nums){
        if(freq.count(i)>0){
            return true;
        }
        freq.insert(i);
    }
    return false;
}

// 242. Valid Anagram - HashMap
bool isAnagram(string s, string t) {
    unordered_map<char,int> mpp;
    for(auto i:s){
        mpp[i]++;
    }
    for(auto i:t){
        mpp[i]--;
    }
    for(auto i:mpp){
        if(i.second!=0){
            return false;
        }
    }
    return true;
}

// 1. Two Sum - HashMap(HashTable)
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> freq;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int complement = target - nums[i];
        if(freq.count(complement)){
            return {freq[complement],i};
        }
        freq[nums[i]]=i;
    }
    return {};
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    

    return 0;
}