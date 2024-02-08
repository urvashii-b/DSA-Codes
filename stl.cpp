// C++ STL: Algorithms, Containers, Functions, Iterators
#include <bits/stdc++.h>
#include<math.h>
#include<string.h>

using namespace std;

void print()
{ //-> returns nothing
    cout << "Urvashi";
}

int sum(int a, int b)
{ //-> has to return integer
    return a + b;
}

// 1. PAIRS - lies inside utility library
void explainPair()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, float>> q = {8, {7, 5.2}};
    cout << q.first << " " << q.second.second << " " << q.second.first << endl;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].second;
}

// 2. VECTORS - can be modified unlike arrays (dynamic arrays basically)
void explainVector()
{
    vector<int> v;
    // dynamic in nature unlike arrays
    v.push_back(1);
    v.emplace_back(2); // faster

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    vector<int> v1(5, 100); // {100,100,100,100,100}
    vector<int> v2(5);      // {0,0,0,0,0} or some garbage values based on compiler
    vector<int> v3(v1);     // copy of v

    vector<int> v4;
    v4.push_back(20);
    v4.emplace_back(10);
    v4.emplace_back(15);
    v4.emplace_back(6);
    v4.emplace_back(7);
    // access values using v[i] or iterator
    vector<int>::iterator it = v4.begin(); // points to memory address 20
    it++;
    cout << *(it) << " ";
    it = it + 2;
    cout << *(it) << " ";
    // vector<int>::iterator it = v4.end(); // for {20,10,15} it points to the memory after 15
    // vector<int>::iterator it = v4.rend(); // reverse end: for {20,10,15} it points to the memory before 20
    // vector<int>::iterator it = v4.rbegin(); // reverse begin: for {20,10,15} it points to the memory at 15
    cout << v4[0] << " " << v4.at(0) << " ";
    cout << v4.back() << " " << endl;

    cout << "using iterator (for loop): ";
    for (vector<int>::iterator it = v4.begin(); it != v4.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    cout << "without defining type of iterator: "; // auto assignment
    for (auto it = v4.begin(); it != v4.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    cout << "no pointer to memory: "; // for each
    for (auto it : v4)
    {
        cout << it << " ";
    }

    // deletion:
    cout << endl;
    cout << "deletion using v.erase(iterator): ";
    v4.erase(v4.begin() + 1);
    for (auto it : v4)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "deletion using v.erase(start,end+1): ";
    v4.erase(v4.begin() + 1, v4.begin() + 3);
    for (auto it : v4)
    {
        cout << it << " ";
    }

    // insertion:
    cout << endl
         << "after insertion: ";
    vector<int> v5(2, 100);         //{100,100}
    v5.insert(v5.begin() + 1, 200); //{100,200,100}
    v5.insert(v5.begin(), 2, 300);  //{300,300,100,200,100}
    for (auto it : v5)
    {
        cout << it << " ";
    }

    cout << endl;
    v5.pop_back(); // removes last element
    v5.clear();    // erase entire vector
    cout << "here (1-> False, 0-> True)" << v5.empty();
    cout << endl;
    for (auto it : v5)
    {
        cout << it << " ";
    }
}

// 3. LISTS - similar to vectors but can push front too
void explainList()
{
    list<int> ls;
    ls.push_back(2);    //{2}
    ls.emplace_back(1); //{2,1}

    ls.push_front(0); //{0,2,1}
    ls.emplace_front(3); //{3,0,2,1}
}

// 4. DEQUE - double ended queue
void explainDeque()
{
    deque<int> dq;
    dq.push_back(1);      //{1}
    dq.emplace_back(2);   //{1,2}
    dq.push_front(10);    //{10,1,2}
    dq.emplace_front(20); //{20,10,1,2}

    dq.pop_back();  //{20,10,1}
    dq.pop_front(); //{1,2}

    dq.back();
    dq.front();
}

// 5. STACK - LIFO: all operations are O(1)-> push,pop,top
void explainStack()
{
    stack<int> st;
    st.push(1);      //{1}
    st.push(5);      //{5,1}
    st.push(20);     //{20,5,1}
    st.emplace(100); //{100,20,5,1}

    // there is no indexing here
    cout << st.top() << endl; // prints 100
    st.pop();
    cout << "After removal of top ele: " << st.top() << endl;
    cout << "Sixe of stack: " << st.size() << endl;
    cout << "Is stack empty: " << st.empty() << endl;

    stack<int> st1, st1copy;
    st1copy.swap(st1);
}

// 6. QUEUE - FIFO: O(1) time
void explainQueue()
{
    queue<int> q;
    q.push(16);   //{16}
    q.push(29);   //{16,29}
    q.emplace(5); //{16,29,5}

    q.back() += 5; // adds 5 to last ele in queue
    //{16,29,10}
    cout << q.back() << endl;  //{10}
    cout << q.front() << endl; //{16}

    q.pop();                   //{29,10}
    cout << q.front() << endl; //{29}
}

// 7. PRIORITY QUEUE - largest ele has max priority OR the lexicographically largest string
// tree is maintained (not a linear data structure)
// push,pop - O(log(n)), top - O(1)
void explainPQ()
{
    // max heap
    priority_queue<int> pq;
    pq.push(1);     //{1}
    pq.push(11);    //{11,1}
    pq.push(5);     //{11,5,1}
    pq.emplace(28); //{28,11,5,1}
    cout << "Largest element(at the top): " << pq.top() << endl;
    pq.pop();
    cout << "Second Largest element: " << pq.top() << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(1);     //{1}
    minpq.push(11);    //{1,11}
    minpq.push(5);     //{1,5,11}
    minpq.emplace(28); //{1,5,11,28}

    cout << "Min heap/priority queue top ele(smallest): " << minpq.top() << endl;
}

// 8. SETS - sorted + unique
// all functions: O(log(n))
void explainSet()
{
    set<int> s;
    s.insert(1);  //{1}
    s.insert(3);  //{1,3}
    s.emplace(1); //{1,3}
    s.insert(2);  //{1,2,3}

    // auto it = s.find(2); //iterator at 2
    // auto it = s.find(9); // as value is not in set it points to the memory after the end(3)

    s.erase(2); // takes logarithmic time
    auto it = s.find(3);
    s.erase(it); // takes constant time
    int cnt = s.count(3);
    cout << cnt;


}

// 9. MULTISET - sorted but not unique(stores multiple occurences)
void explainMultiSet()
{
    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.insert(1); //{1,1,1}
    ms.insert(2); //{1,1,1,2}

    // ms.erase(1); // deletes all 1s
    int cnt = ms.count(1);
    cout << cnt << endl;

    ms.erase(ms.find(1)); // deletes only one occurence of 1
    int cnt2 = ms.count(1);
    cout << cnt2 << endl;
}

// 10. UNORDERED SET - not sorted(any random order) + unique
void explainUSet()
{
    unordered_set<int> st;
    // lower_bound and upper_bound doesn't work
    // mostly all func:O(1) but sometimes might go to O(n)
}

// 11. MAP - key:value pairs (keys:unique+sorted)
void explainMap()
{
    map<int, int> mp;
    map<int, pair<int, int>> mp1;
    map<pair<int, int>, int> mp2;

    mp[1] = 2;
    mp.insert({3, 1});
    mp.emplace(2,4);

    mp2[{2, 3}] = 5;

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mp[2] << endl; // no key 2
    cout << mp[3] << endl; // stores 1 at key 3
    cout << mp[1] << endl; // stores 2 at key 1
}

// 12. MULTIMAP - duplicate keys in sorted order
void explainMultiMap()
{
}

// 13. UNORDERED MAP - NOT SORTED and unique
void explainUnorderedMap()
{
    // mostly all func:O(1) but sometimes might go to O(n)
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    // now they'll be same if left
    if (p1.first > p2.first)
        return true;
    return false;
}
// ALGORITHMS
void explainExtra()
{
    /*sort(a,a+n); //sorting array
    sort(v.begin(),v.end()); //sorting vector

    sort(a,a+n,greater<int>); //sort in descending order
    */
    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    int n = 3;
    sort(a, a + n, comp);
    // comp sorts in my way: second ele should be sorted in asc but if eq then sort first ele in desc
    cout << "{" << a[0].first << " " << a[0].second << "},";
    cout << "{" << a[1].first << " " << a[1].second << "},";
    cout << "{" << a[2].first << " " << a[2].second << "}" << endl;

    int num = 7;
    int cnt = __builtin_popcount(num);
    cout << cnt << endl; // prints the numbers of 1 present, ex: 7 - 111 so prints 3

    long long num2 = 165786578687;
    int cnt2 = __builtin_popcountll(num2);
    cout << cnt2 << endl;

    cout << "Permutations of 123: ";
    string s = "123";
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    // int maxi = *max_element(a,a+n);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    int s = sum(1,5);
    cout<<s;
    // Time complexity: The rate at which the time, required to run a code, changes with respect to the input size
    // Space complexity: Auxiliary space + Input space
    // 1 second = 10^8

    explainPair();

    explainVector();

    explainList();

    explainStack();

    explainQueue();

    explainPQ();

    explainSet();

    explainMultiSet();

    explainMap();
    
    explainExtra();

    int arr[] = {1, 4, 5, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool res = binary_search(arr, arr + n, 5); // prints 1 as it exists
    cout <<"Array contains 5: YES(1) OR NO(0)-> " <<res;

    int ind = lower_bound(arr, arr + n, 5) - arr; // prints 2 (index of first occurence of 5)
    int ind1 = lower_bound(arr, arr + n, 10) - arr; // prints 5 (index of first occurence of 10 but no occurence here so after last element)

    int ind2 = upper_bound(arr, arr + n, 5) - arr; // prints 3 ((index of first occurence of 5)+1)
    
    // Q.1) find first occurence of X in a sorted array(lower_bound). If it doesn't occur, print -1
    int arr[]={1,4,4,4,4,9,9,10,11};
    cout<<"Enter the number to be searched: "<<endl;
    int X;
    cin>>X;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ind = lower_bound(arr,arr+n,X)-arr;
    if(ind!=n && arr[ind]==X) cout<<ind;
    else cout<<"-1";
    
    // Q.2) find last occurence of X in a sorted array(upper_bound). If it doesn't occur, print -1
    int arr[]={1,4,4,4,4,9,9,10,11};
    cout<<"Enter the number to be searched: "<<endl;
    int X;
    cin>>X;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ind = upper_bound(arr,arr+n,X)-arr;
    ind--;
    if(ind>=0 && arr[ind]==X) cout<<ind;
    else cout<<"-1";
    */
    // Q.3) 
    return 0;
}