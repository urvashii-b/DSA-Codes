#include <bits/stdc++.h>

using namespace std;

// Because we know all the elements are given in pairs except for the one we're looking for, the most efficient approach to this problem uses exclusive OR (XOR).
int lonelyinteger(vector<int> a) {
    sort(a.begin(),a.end());
    int n = a.size();
    for(int i=0;i<n;i++){
        if(a[i]!=a[i+1] && a[i+1]!=a[i+2]){
            return a[i+1];
        }
    }
    return 1;
}

int diagonalDifference(vector<vector<int>> arr) {
   int n=arr.size();
   int l=0;
   int r=0;
   for(int i=0;i<n;i++){
       l+=arr[i][i];
       r+=arr[i][n-i-1];
   }
   return abs(l-r);
}
  

int main(){
    int lonely = lonelyinteger({2,3,5,34,3,2,34});
    cout<<lonely<<endl;
    return 0;
}