#include<bits/stdc++.h>
using namespace std;

/*
1) brute force
exceeds time limit as O(n^3+ log(unique triplets))
extra space of set datastructure too

vector<vector<int>> triplet(int n, vector<int> &nums){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k] == 0){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

2) optimal - hashset
vector<vector<int>> triplet(int n, vector<int> &nums){
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third = -(nums[i] =nums[j]);
            if(hashset.find(third)!= hashset.end()){
                vector<int> temp = {nums[i], nums[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

3) optimal - 2 pointer technique
sort the nums array in the beginning itself

*/
vector<vector<int>> triplet(int n, vector<int> &nums){
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue; // does i++ only
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> temp = {nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }
    return ans;
}
int main(){
    /* 3 SUM (unique triplets that add upto zero)

    i) brute force using 3 pointer technique

    ii) better : hashing (remove kth pointer)

    iii) optimal - 2 pointer technique
    */
    return 0;
}