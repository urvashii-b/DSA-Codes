#include<bits/stdc++.h>
using namespace std;

//BASIC MATH

/*
1. digit concept
    extraction: %10 for last digit
    7789 to 778: /10

1. COUNT DIGITS
int count_digits(int n )
{   
    int cnt = 0;
    while(n){
        n/=10;
        cnt++;
    } 
    return cnt;
    
    //string s = to_string(n);
    //return s.length();
}

2. REVERSE BITS
long reverseBits(long n){
    long reverse = 0;
    for(int i=0;i<32;i++){
        int digit=n%2;
        n=n/2;
        reverse = reverse + ((long)1<<(31-i));
    }
}

3. PALINDROME
bool isPalindrome(int x) {
    if(x<0) return false;
    long long rev = 0;
    long long temp = x;
    while(temp){
        int digit = temp%10;
        temp/=10;
        rev = rev*10 + digit;
    }
    return (rev == x);
}

4. GCD
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b); // Euclidean’s theorem
}

5. ARMSTRONG NUMBER
bool checkArmstrong(int n){
	if(n==0 || n==1) return true;
	int temp = n;
	int cnt = 0;
	int temp2 = n;
	while(temp){
		cnt++;
		temp/=10;
	}
	int sum = 0;
	while(temp2){
		int digit = temp2%10;
		sum += pow(digit,cnt);
		temp2/=10;
	}
	return (sum==n);
}

6. SUM OF DIVISORS
WRONG CODE 30/31 TEST CASES  
int sumOfAllDivisors(int n){
    int sum = 0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i == i) sum+=i;
            else sum+=(i+n/i);
        }
    }
    return sum;
}

7.
*/
int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    /*
    int n;
    cin>>n;
    cout<<"The digits in number "<<n<<" are: "<<count_digits(n)<<endl;
    
    int a, b;
    cin>> a>> b;
	cout <<"The GCD of the two numbers is "<<gcd(a, b);
    */
}