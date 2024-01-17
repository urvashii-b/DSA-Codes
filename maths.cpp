//BASIC MATH

/*
1. digit concept
    extraction: %10 for last digit
    7789 to 778: /10

*/ 
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    while(n>0){
        int lastDigit = n%10;
        cout<<lastDigit<<" ";
        n = n/10;
    }
}