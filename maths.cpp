// BASIC MATH

#include <bits/stdc++.h>
using namespace std;

/*
1. digit concept
    extraction: %10 for last digit
    7789 to 778: /10

1. COUNT DIGITS
int countDigits(int n){
    int cnt=0;
    while(n>0){
        int lastDigit=n%10;
        cnt++;
        n=n/10;
    }
    return n;

    // int cnt = (int)(log10(n)+1);
    // string s = to_string(n);
    // return s.length();
}

2.A) REVERSE INTEGER
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
int reverse(int x){
    int rev = 0;
    while(x!=0){
        int pop = x%10;
        x/=10;
        if(rev>INT_MAX/10 || (rev==INT_MAX && pop>7)) return 0;
        if(rev<INT_MIN/10 || (rev==INT_MIN && pop<-8)) return 0;
        rev=rev*10+pop;
    }
    return rev;
}

2.B) REVERSE BITS
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
    while(temp){
        cnt++;
        temp/=10;
    }
    int temp2 = n;
    int sum = 0;
    while(temp2){
        int digit = temp2%10;
        sum += pow(digit,cnt);
        temp2/=10;
    }
    return (sum==n);
}

6.A) PRINT ALL DIVISORS
int printDivisors(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}

6.B) SUM OF DIVISORS
WRONG CODE 30/31 TEST CASES
int sumOfAllDivisors(int n){
    int sum = 0;
    for(int i=1;i*i<=n;i++){ // (or) i<=sqrt(n)
        if(n%i==0){
            if(n/i == i) sum+=i;
            else sum+=(i+n/i);
        }
    }
    return sum;
}

7. CHECK FOR PRIME: has exactly 2 factors (1 and itself)
*/
bool isPrime(int n)
{
    int cnt=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            break;
        }
    }
    if(cnt!=0 || n==1){
        return false;
    }
    else return true;
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
    cout<<"The digits in number "<<n<<" are: "<<count_digits(n)<<endl;

    int a, b;
    cin>> a>> b;
    cout <<"The GCD of the two numbers is "<<gcd(a, b);

    int n;
    cin>>n;
    printDivisors(n);
    */
    int num;
    cout << "Enter a number to check if it's prime: ";
    cin >> num;

    if (isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}