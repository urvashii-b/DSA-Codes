// Patterns: nested loops
#include <bits/stdc++.h>
using namespace std;
/* 
4 STEPS INVOLVED:
    1. Outer loop: count the number of lines (rows)
    2. Inner loop: focus on the columns and try to connect them with the rows
    3. Print "*" inside the inner for loop
    4. Symmetry: try to find the pattern and then try to replicate it (optional)
*/

// Pattern 1
void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

// Pattern 2
void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif

    int testcases;
    cin>>testcases;
    for(int i=0;i<testcases;i++){
        int n;
        cin>>n;
        pattern1(n);
    }
    return 0;
}

