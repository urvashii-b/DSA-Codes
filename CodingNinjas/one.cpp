#include<bits/stdc++.h>
using namespace std;

// 1. Check if the character is upper case, lower case or special character
int dataTypes(string type) {
	if(type=="Long"|| type=="Double"){
		return 8;
	}
	else if(type=="Integer"|| type=="Float"){
		return 4;
	}
	else if(type=="Character"){
		return 1;
	}
	return 0;
}

// 2. Compare two numbers
string compareIfElse(int a, int b) {
	if(a>b){
		return "greater";
	}
	else if(a<b){
		return "smaller";
	}
	else if (a=b){
		return "equal";
	}
}

// 3. Calculate the area of a circle or rectangle
double areaSwitchCase(int ch, vector<double> a) {
	switch(ch){
		case 1: //circle
			return M_PI*a[0]*a[0];
			break;
		case 2: //rectangle
			return a[0]*a[1];
			break;
	}
}

// 4. swap two numbers
void Swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

// 5. Maximum of two numbers
int Maximum(int x, int y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}

// 6. count the number of digits in a number
int countDigits(int n){
	int cnt=0;
	int num = n;
	while(n>0){
		int rem = n%10;
		if(rem>0 && num%rem==0){
			cnt++;
		}
		n=n/10;
	}
	return cnt;
}

// 7. Reverse the bits of a number
long reverseBits(long n) {
    long ans = 0;
    for(int i=0;i<32;i++){
        ans <<= 1;
        ans |= n&1;
        n >>=1;
    }
    return ans;
}

// 8. Check if a number is palindrome
bool palindrome(int n)
{
    int rev = 0;
    int num = n;
    while(num>0){
        int last = num%10;
        rev = (rev*10) + last;
        num/=10;
    }
    if(rev==n) return true;
    return false;
}

// 9. Calculate the GCD of two numbers
int calcGCD(int n, int m){
    /*if(m==0) return n;
    return calcGCD(m,n%m);*/
    while(n>0 && m>0){
        if(n>m) n=n%m;
        else m=m%n;
    }
    if(n==0) return m;
    return n;
}

// 10. Check if a number is Armstrong number
bool checkArmstrong(int n){
	if(n==0 || n==1) return true;
	int temp = n;
	int cnt = 0;
	while(temp>0){
		cnt++;
		temp/=10;
	}
	int temp2 = n;
	int sum = 0;
	while(temp2>0){
		int last = temp2%10;
		sum+= pow(last,cnt);
		temp2/=10;
	}
	return (sum==n);
}

// 11. Check if a number is prime
bool isPrime(int n)
{
	int cnt = 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			cnt++;
			break;
		}
	}
	if(n==1 || cnt!=0){
		return false;
	}
	return true;
}

// 12. print the first n numbers using recursion
void printNum(vector<int> &ans, int i, int x){
    if(i>x) return;
    ans.push_back(i);
    printNum(ans,i+1,x); 
}

vector<int> printNos1(int x) {
    vector<int> ans;
    printNum(ans, 1, x);
    return ans;
}

// 13. print the first n strings using recursion
void printString(vector<string> &ans, int i, int n){
	if(i>n) return;
	string s="Coding Ninjas";
	ans.push_back(s);
	printString(ans,i+1,n);
}

vector<string> printNTimes(int n) {
	vector<string> ans;
	printString(ans,1,n);
	return ans;
}

// 14. print the first n numbers in reverse order using recursion
void printrevNum(vector<int> &ans,int i, int n){
    if(i<=0) return;
    ans.push_back(i);
    printrevNum(ans,i-1,n);
    
}

vector<int> printNos(int x) {
    vector<int> ans;
    printrevNum(ans,x,x);
    return ans;
}

// 15. Sum of first n numbers 
long long sumFirstN(long long n) {
    long long sum=(n*(n+1))/2;
    return sum;
}

// 16. Factorial Numbers Not Greater Than N
long long fact(long long i){
    if(i==0 || i==1) return 1;
    else{
        return i*fact(i-1);
    }
}

vector<long long> factorialNumbers(long long n) {
    vector<long long> ans;

    for(int j=1;fact(j)<=n;j++){
        ans.push_back(fact(j));
    }
    return ans;
}

// 17. Reverse array using recursion
void rev(vector<int> &nums, int i, int n){
    if(i>=n/2) return;
    else {
      swap(nums[i], nums[n - i - 1]);
      rev(nums, i + 1, n);
    }
}

vector<int> reverseArray(int n, vector<int> &nums)
{
    rev(nums,0,n);
    return nums;
}

// 18. Palindromic string
bool ispalin(int i,string &str){
    int n = str.length();
    if(i>=n/2) return true;
    if(str[i]!=str[n-1-i]) return false;
    else return ispalin(i+1,str);
}

bool isPalindrome(string& str) {
    bool ans = ispalin(0,str);
    return ans;
}

// 19. Generate Fibonacci Series
vector<int> generateFibonacciNumbers(int n) {
    vector<int> ans;
    if(n==1){
        ans.push_back(0);
        return ans;
    }
    if(n==2){
        ans = generateFibonacciNumbers(n-1);
        ans.push_back(1);
        return ans;
    }
    else{
        ans = generateFibonacciNumbers(n-1);
        ans.push_back(ans[n-2]+ans[n-3]); 
    }
    return ans;
}

// 20. Count frequency of elements using hashing
vector<int> countFrequency(int n, int x, vector<int> &nums){
    vector<int> ans(x,0);
    for(int i=0;i<n;i++){
        ans[nums[i]-1]++;
    }
    ans.resize(n);
    return ans;
}

// Highest / Lowest Frequency Elements
vector<int> getFrequencies(vector<int>& v) {
    int m = v.size();
    unordered_map<int,int> freq;
    for(int i=0;i<m;i++){
        freq[v[i]]++;
    }

    int maxEle, maxFreq = 0;
    int minEle = (int)1e9 + 1;
    int minFreq = m;
    for(auto it: freq){
        int ele = it.first;
        int cnt = it.second;

        if(cnt > maxFreq){
            maxFreq = cnt;
            maxEle = ele;
        }
        else if(cnt == maxFreq){
            maxEle = min(maxEle,ele);
        }
        if(cnt < minFreq){
            minFreq = cnt;
            minEle = ele;
        }
        else if(cnt == minFreq){
            minEle = min(ele,minEle);
        }
    }
    vector<int> ans = {maxEle, minEle};
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    /*
	char ch;
	cin>>ch;
	if(ch>='A' && ch<='Z'){
		cout<<"1";
	}
	else if(ch>='a' && ch<='z'){
		cout<<"0";
	}
	else{
		cout<<"-1";
	}

    cout<<"Enter the value of n for nth fibonacci number: ";
    int n;
        cin>>n;
        int dp[n+1]; 
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2];
        }
        cout<<dp[n]<<endl;

    cout<<"Enter the number for even and odd sum: ";
    int n;
	cin>>n;
	int even=0, odd=0;
	while(n>0){
		int last = n%10;
		if(last%2==0){ //even
			even=even+last;
		}
		else{
			odd = odd+last;
		}
		n = n/10;
	}
	cout<<even<<" "<<odd;
    */
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> result = getFrequencies(v);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
