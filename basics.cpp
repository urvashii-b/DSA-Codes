// This file contains the basics of C++ programming language

#include<iostream> //input output stream
#include<string> 
#include<math.h> 
#include<bits/stdc++.h> // all header files
using namespace std; // standard namespace

int sum(int a, int b){
    int c = a+b;
    return c;
}

void changeName(string s){ //pass by value
    s[0]='N';
    cout<<s<<'\n';
}

void changeNameReally(string &s){ //pass by reference - changes original
    s[0]='N';
    cout<<s<<'\n';
}

int main(){
    // cout: console output, cin: console input
    // competitive programming type input/output
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif

    // 1. INPUT/OUPUT
    cout<<"Hey Urvashi"<<"\n";
    cout<<"this is on a new line"<<endl;
    // input: cin>>
    int x, y;
    cin>>x>>y;
    // output: cout<<
    cout<<"X is: "<<x<<" and Y is: "<<y<<endl;

    // 2. DATATYPES
    // int: (-10^9) - 10^9, long: (-10^12) - 10^12, long long: (-10^18) - 10^18
    // float, double
    double a = 0.5;
    cout<<a<<"\n";
    //string and getline
    string s;
    getline(cin,s); // for one whole line
    cout<<s<<"\n";
    // char - one alphabet
    char ch;
    cin>>ch;
    cout<<ch<<"\n";
    // use " " for string and ' ' for char

    // 3. IF-ELSE
    int age;
    cin>>age;
    if(age>=18 && age!=-1){
        cout<<"Adult";
    }
    else if(age<18 && age!=-1){
        cout<<"NOT an adult";
    }
    else{
        cout<<"invalid age";
    }
   
    // grades of students according to marks
    cout<<"\n";
    int marks;
    cin>>marks;
    if(marks<25){
        cout<<"F";
    }
    else if(marks<45){
        cout<<"E";
    }
    else if(marks<50){
        cout<<"D";
    }
    else if(marks<60){
        cout<<"C";
    }
    else if(marks<80){
        cout<<"B";
    }
    else{
        cout<<"A";
    }
    cout<<"\n";

    // 4. SWITCH
    int day;
    cin>>day;
    switch(day){
        case 1:
            cout<<"Mon";
            break;
        case 2:
            cout<<"Tues";
            break;
        case 3:
            cout<<"Wed";
            break;
        case 4:
            cout<<"Thurs";
            break;
        case 5:
            cout<<"Fri";
            break;
        case 6:
            cout<<"Sat";
            break;
        case 7:
            cout<<"Sun";
            break;
        default:
            cout<<"Enter the right day!!";
            break;
    }
    cout<<"\n";

    // 5. ARRAYS - similar data together
    int arr[3][5]; //3 5boxes: i->row, j->col
    
    // 6. STRINGS - stores at index
    string s2 = "Urvashh";
    int len = s2.size();
    s2[len-1] = 'i';
    cout<<s2<<endl;
    // a string is made up of chracters
    
    // 7. FOR LOOP
    for(int i=0; i<5; i++){
        cout<<"Hi"<<" "<<i<<endl;
    }
    
    // 8. WHILE LOOP
    int i=0;
    while(i<5){
        cout<<"Hii"<<" "<<i<<endl;
        i=i+1;
    }

    int num1, num2;
    cin>>num1>>num2;
    int res = sum(num1, num2);
    cout<<res<<endl;

    // 9. FUNCTIONS - reusable pieces of code
    // can be parameterised-> void print(int n) or non-parameterised-> void print()
    // pass by reference(original value is changed) or by value(copy->original remains same before function)
    
    string s1 = "Urvashi";
    changeName(s1);
    cout<<s1<<endl;
    return 0;
}