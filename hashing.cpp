#include <bits/stdc++.h>
using namespace std;

/* 'a' - 97 , 'z' - 122... ch-'a' gives the index of the character in the hash array

Hashing methods:
1. Division method (linear chaining)
2. Folding method
3. Mid square method

Collision - when elements have same hash value (worst case)
*/
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    1. NUMBER HASHING
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // precompute
    int hash[13]={0}; // as max is 12
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }

    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        // fetch
        cout<<hash[num]<<endl;
    }

    2. CHARACTER HASHING (max - 256)
    string s;
    cin>>s;

    int hash[26] = {0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }

    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;

    cout<<hash[c-'a']<<" ";
    }

    3. MAP STORES IN SORTED ORDER - O(logn) where n is no of elements
    */
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++; // precompute
    }

    // iterating in map
    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        // fetch
        cout << mpp[num] << " ";
    }
    return 0;
}
