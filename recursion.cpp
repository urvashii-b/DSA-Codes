// Recursion: when a function calls itself directly or indirectly until a specific (base) condition is met.

// stack overflow when there are numerous function calls and the stack size is limited.
#include <bits/stdc++.h>
using namespace std;

// 1. Print name n times
#include <iostream>
#include <string> // Add this line to include the <string> library

void printName(int i, int n){
    if(i > n) return;
    cout << "Urvashi " + to_string(i) + " times\n"; 
    printName(i + 1, n);
}

// 2. Print linearly from 1 to n
void printNumbers(int i,int n){
    if(i>n) return;
    cout << i << " ";
    printNumbers(i+1,n);
}

// 3. Print linearly from n to 1
void printNumbersRev(int i,int n){
    if(i<1) return;
    cout << i << " ";
    printNumbersRev(i-1,n);
}

// 4. Print linearly from 1 to n using backtracking
void printNumbersBack(int i,int n){
    if(i<1) return;
    printNumbersBack(i-1,n);
    cout << i << " ";
    
}

// 5. Print linearly from n to 1 using backtracking
void printNumbersRevBack(int i,int n){
    if(i>n) return;
    printNumbersRevBack(i+1,n);
    cout << i << " ";
    
}

// 6. Sum of first n numbers - parameterised and functional recursion
int sum(int n){
    if(n==0) return 0;
    else return n+sum(n-1);
}

// 7. Factorial of a number
int fact(int n){
    if(n==0) return 1;
    else return n*fact(n-1);
}

// 8. Reverse array using recursion
void revArr(int i, int arr[], int n){
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    revArr(i+1,arr,n);
}

// 9. Palindromic string
bool isPalin(int i, string &s){
    int n = s.length();
    if(i>=n/2) return true;
    if(s[i]!=s[n-i-1]) return false;
    return isPalin(i+1,s);
}

// 10. Fibonacci series
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1)+fib(n-2);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    /*
    int n;
    cin>>n;
    printName(1, n);
    
    printNumbersRev(n,n);
    
    printNumbersBack(n,n);
    
    printNumbersRevBack(1,9);
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    revArr(0,arr,n);
    cout<<"Reversed array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    string s = "madam";
    cout<<isPalin(0,s);
    */
    cout<<fib(5);
    return 0;
}