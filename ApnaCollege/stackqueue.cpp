#include <bits/stdc++.h> 
using namespace std;

/*
1. TWO STACKS IN AN ARRAY
divide the array: 
    use arr[0] to arr[n/2] for stack1, 
    and arr[(n/2) + 1] to arr[n-1] for stack2

// problem: stack1 maybe full but not stack2 so array has empty space which is still not utilised
class twoStacks{
    int* arr;
    int size;
    int top1, top2;

    public:
        twoStacks(int n){
            size = n;
            arr = new int[n];
            top1 = n/2+1; // points to middle + 1 of the array and moves to the start <------
            top2 = n/2; // points to middle of the array and moves to the end ------>
        }

        void push1(int x){
            if(top1>0){
                top1--;
                arr[top1]=x;
            }else{
                cout<<"Stack Overflow "<<endl;
                return;
            }
        }

        void push2(int x){
            if(top2<size-1){
                top2++;
                arr[top2]=x;
            }else{
                cout<<"Stack Overflow "<<endl;
                return;
            }
        }

        int pop1(){
            if(top1<=size/2){
                int x = arr[top1];
                top1++;
                return x;
            }else{
                cout<<"Stack Underflow "<<endl;
                exit(1);
            }
        }

        int pop2(){
            if(top2>=size/2+1){
                int x = arr[top2];
                top2--;
                return x;
            }else{
                cout<<"Stack Underflow "<<endl;
                exit(1);
            }
        }
};
*/
// for overflow check for availability of space b/w top1 and top2?.. for underflow check top1 and top2 values b/w 0 and (n-1)?
class bettertwoStacks{
    int* arr;
    int size;
    int top1,top2;

    public:
        bettertwoStacks(int n){
            size = n;
            arr = new int[n];
            top1=-1;
            top2=size;
        }

        void push1(int x){
            if(top1<top2-1){
                top1++;
                arr[top1]=x;
            }else{
                cout<<"Stack Overflow "<<endl;
                exit(1);
            }
        }

        void push2(int x){
            if(top1<top2-1){
                top2--;
                arr[top2]=x; 
            }else{
                cout<<"Stack Overflow "<<endl;
                exit(1);
            }
        }

        int pop1(){
            if(top1>=0){
                int x = arr[top1];
                top1--;
                return x;
            }else{
                cout<<"Stack Underflow "<<endl;
                exit(1);
            }
        }

        int pop2(){
            if(top2<size){
                int x = arr[top2];
                top2++;
                return x;
            }else{
                cout<<"Stack Underflow "<<endl;
                exit(1);
            }
        }       
};

vector<string> buildArray(vector<int>& target, int n) {
            vector<string> ans;
            int i=0;

            for(int num:target){
                while(i<num-1){
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    i++;
                }
                ans.push_back("Push");
                i++;
            }
            return ans;
        }

// 2. EVALUATION OF POSTFIX EXPRESSION

int evaluatePostfix(string exp){
    stack<int> st;
    for(int i=0;i<exp.size();++i){
        if(isdigit(exp[i])){
            st.push(exp[i]-'0');
        }
        else{
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch(exp[i]){
                case '+':
                    st.push(val1+val2);
                    break;
                case '-':
                    st.push(val2-val1);
                    break;
                case '*':
                    st.push(val1*val2);
                    break;
                case '/':
                    st.push(val2/val1);
                    break;
            }
        }
    }
    return st.top();
}

// 3. IMPLEMENTATION OF STACK USING 2 QUEUES

class MyStack {
private:
    queue<int> q1,q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int topele=q1.front();
        q1.pop();
        swap(q1,q2);
        return topele;
    }
    
    int top() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int topele = q1.front();
        q2.push(topele);
        q1.pop();
        swap(q1,q2);
        return topele;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// reverse polish notation
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(int i=0;i<tokens.size();i++){
        if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
            st.push(stoi(tokens[i]));
        }
        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            char op = tokens[i][0];
            switch(op){
                case '+':
                    st.push(b+a);
                    break;
                case '-':
                    st.push(b-a);
                    break;
                case '*':
                    st.push(b*a);
                    break;
                case '/':
                    st.push(b/a);
                    break;
            }
        }
    }
    return st.top();
}

// valid parenthesis
bool isValid(string s) {
    stack<char> st;
    for(char c: s){
        if(c=='('||c=='{'||c=='['){
            st.push(c);
        }else{
            if(st.empty()||(c=='}'&& st.top()!='{')||(c==')'&& st.top()!='(')||(c==']'&& st.top()!='[')){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    /*
    string exp = "231*+9-";
    cout << "postfix evaluation: " << evaluatePostfix(exp)<<endl;

    twoStacks ts(5);
    bettertwoStacks ts(5);
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is " << ts.pop1(); 
    ts.push2(40); 
    cout << "\nPopped element from stack2 is " << ts.pop2(); 
    
    vector<string> token1 = {"2","1","+","3","*"};
    cout<<evalRPN(token1);
    */
    return 0;

}