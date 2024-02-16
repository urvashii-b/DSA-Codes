#include<bits/stdc++.h>
using namespace std;

/* 1. Length of Longest Substring without any Repeating Character

i) Brute force: 
outer loop for traversing the string
inner loop for finding different strings starting with s[i] 

int bruteLongestSubstr(string s){
    if(s.size()==0) return 0;
    int maxans=INT_MIN;
    for(int i=0;i<s.length();i++){
        unordered_set<int> set;
        for(int j=i;j<s.length();j++){
            if(set.find(s[j])!=set.end()){
                maxans = max(maxans, j-i);
                break;
            }
            set.insert(s[j]);
        }
    }
    return maxans;
}
 
ii) Better:

Time Complexity: O(2*N) (sometimes left and right both have to travel a complete array)
int betterLongestSubstr(string s){
    if(s.size()==0) return 0;
    int maxans = INT_MIN;
    unordered_set<int> set;
    int l=0;
    for(int r=0;r<s.length();r++){
        if(set.find(s[r])!=set.end()){
            while(l<r && set.find(s[r])!=set.end()){
                set.erase(s[l]);
                l++;
            }
        }
        set.insert(s[r]);
        maxans = max(maxans,r-l+1);
    }
    return maxans;
}

iii) Optimal
*/
int bestLongestSubstr(string s){
    vector<int> mpp(256,-1);
    int left=0, right=0;
    int n=s.size();
    int len=0;
    while(right<n){
        if(mpp[s[right]]!=-1){
            left = max(mpp[s[right]]+1,left);
        }
        mpp[s[right]] = right;
        len =max(len,right-left+1);
        right++;
    }
    return len;
}

int main(){
    string str = "takeUforward";
    cout << "The length of the longest substring without repeating characters is " << 
    bestLongestSubstr(str);
    return 0;
}