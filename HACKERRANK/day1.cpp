#include<iostream> //input-ouput
#include<bits/stdc++.h>
using namespace std;

void plusMinus(vector<int> arr) {
    double pos,neg,zer;
    pos=neg=zer=0;
    double ans = 1.0/arr.size();
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            neg+=ans;
        }
        else if(arr[i]>0){
            pos+=ans;
        }
        else{
            zer+=ans;
        }
    }
    cout << setprecision(6) << fixed;
    cout<<pos<<endl;
    cout<<neg<<endl;
    cout<<zer<<endl;
}

void miniMaxSum(vector<int> arr) {
    long min = 0, max = 0;
    sort(arr.begin(),arr.end());
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        min+=arr[i];
    }
    for(int i=n;i>0;i--){
        max+=arr[i];
    }
    cout<<min<<" "<<max;
}

string timeConversion(string s) {
    // hh:mm:ssAM
    // 0123456789
    int n = s.size();
    if(s[n-2]=='A'){
        if(s[0]=='1' && s[1]=='2'){
            s[0]=s[1]='0';
        }
    }
    else if(s[n-2]=='P'){
        if(s[1]=='8'){
            s[0]='2';
            s[1]='0';
        }
        else if(s[1]=='9'){
            s[0]='2';
            s[1]='1';
        }
        else if(!(s[0]=='1' && s[1]=='2')){
            s[0]+=1;
            s[1]+=2;
        }
    }
    s.erase(n - 2, 2);
    return s;
}

double findMedian(vector<int> &arr) {
    sort(arr.begin(),arr.end());
    int n = arr.size();
    // 1 2 5 7 8 9 : median is 6, n=6, median is at n/2 and (n/2)-1 pos
    // 0 1 2 3 4 5 
    if(n%2==0){ //even
        double res = (arr[n/2]+ arr[(n/2)-1])/2.0;
        return res;
    }
    // 2 6 7 8 9 : median is 7, n=5, median at (n-1)/2 pos
    // 0 1 2 3 4
    else{ // odd
        double res = arr[(n-1)/2];
        return res;
    }
}  

int main(){
    vector<int> test1 = {5, 2, 7, 1, 9, 3}; 
    cout << "Median of test1: " << findMedian(test1) << endl;

    vector<int> test2 = {4, 2, 7, 1}; 
    cout << "Median of test2: " << findMedian(test2) << endl;

    vector<int> test3 = {3, 8, 1}; 
    cout << "Median of test3: " << findMedian(test3) << endl;

    vector<int> test4 = {6, 4, 2}; 
    cout << "Median of test4: " << findMedian(test4) << endl;
    return 0;
}