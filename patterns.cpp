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

/* Pattern 1
* * * * 
* * * * 
* * * * 
* * * * 
*/
void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/* Pattern 2
* 
* * 
* * * 
* * * * 
*/
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/* Pattern 3
1 
1 2 
1 2 3 
1 2 3 4 
*/
void pattern3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

/* Pattern 4
1 
2 2 
3 3 3 
4 4 4 4 
*/
void pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

/* Pattern 5
* * * * 
* * * 
* * 
* 
*/
void pattern5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/* Pattern 6
1 2 3 4 
1 2 3 
1 2 
1 
*/
void pattern6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

/* Pattern 7
   *   
  ***  
 ***** 
*******
*/
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

/* Pattern 8
*******
 ***** 
  ***  
   *   
*/
void pattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 0; j < 2 * (n - i) - 1; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

/* Pattern 9 - Diamond
   *   
  ***  
 ***** 
*******
*******
 ***** 
  ***  
   *   
*/
void pattern9(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 0; j < 2 * (n - i) - 1; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

/* Pattern 10
*
**
***
****
***
**
*
*/
void pattern10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
        {
            stars = 2 * n - i;
        }
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

/* Pattern 11
1 
0 1 
1 0 1 
0 1 0 1 
*/
void pattern11(int n)
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            start = 1;
        }
        else
        {
            start = 0;
        }
        for (int j = 0; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}

/* Pattern 12
1      1
12    21
123  321
12344321
*/
void pattern12(int n)
{
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        // num
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        // space
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        // num
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        space -= 2;
    }
}

/* Pattern 13
1 
2 3 
4 5 6 
7 8 9 10 
*/
void pattern13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num = num + 1;
        }
        cout << endl;
    }
}

/* Pattern 14
A 
A B 
A B C 
A B C D
*/
void pattern14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

/* Pattern 15
A B C D 
A B C 
A B 
A
*/
void pattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + n - i - 1; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

/* Pattern 16
A 
B B 
C C C 
D D D D 
*/
void pattern16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

/* Pattern 17
   A   
  ABA  
 ABCBA 
ABCDCBA
*/
void pattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // character
        char ch = 'A';
        int breakpt = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpt)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

/* Pattern 18
E 
D E 
C D E 
B C D E 
*/
void pattern18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

/* Pattern 19
********
***  ***
**    **
*      *
*      *
**    **
***  ***
********
*/
void pattern19(int n)
{
    int inis = 0;
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 0; j < inis; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        inis = inis + 2;
        cout << endl;
    }
    inis = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {
        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 0; j < inis; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        inis -= 2;
        cout << endl;
    }
}

/*Pattern 20
*      *
**    **
***  ***
********
***  ***
**    **
*      *
*/ 
void pattern20(int n)
{
    int spaces = 2*n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        // stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout<<endl;
        if(i<n) spaces -=2;
        else spaces +=2;
    }
}

/* Pattern 21 - square 
****
*  *
*  *
****
*/
void pattern21(int n){
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            if(i==0 || j==0 || i==n-1 || j==n-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

/* Pattern 22 
4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
*/
void pattern22(int n){
    for (int i = 0; i < 2 * n - 1; i++){
        for (int j = 0; j < 2 * n - 1; j++){
            int top = i;
            int left = j;
            int right = 2*n-2-j;
            int bottom = 2*n-2-i;
            cout<<(n-min(min(top,bottom),min(left,right)))<<" ";
        }
        cout<<endl;
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    pattern1(n);
    return 0;
}
