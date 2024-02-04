/* Time complexity != Time taken, It is the rate at which time taken increases wrt input size
Big O notation (upper-bound) is used to represent time complexity (worst) -> O(n)
Theta notation (average) -> θ(n)
Omega notation (best, lower-boundn) -> Ω(n)
1. Compute worst case TC, 2. Ignore constants, 3. Ignore lower order terms

Space complexity = Auxiliary space (to solve problem) + Input space (to store input)
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << i << " " << j << endl; // O(n^2)
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            cout << i << " " << j << endl; // O(n^2/2 + n/2)
        }
    }
    return 0;
}