#include <bits/stdc++.h> 
#include <stack>
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    stack<int> stack;
    stack.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
    stack.push(22);
    stack.push(24);
    stack.push(25);
    int num;
    cin>>num;
    stack.push(num);

    /* SUM OF STACK
    int sum =0;
    while(!stack.empty()){
        sum=sum+stack.top();
        stack.pop();
    }
    cout<<"The sum is: "<<sum<<endl;

    IS EMPTY?
    if (stack.empty()) {
        cout << "True"<<endl;
    }
    else {
        cout << "False"<<endl;
    }

    PRINT
    while (!stack.empty()) {
        cout << stack.top() <<" ";
        stack.pop();
    }
    */
}