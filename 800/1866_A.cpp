#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;

    cin >> n;

    long long ans = 1e18;
    long long x;
    for(int i=0; i<n; i++){
        cin >> x;
        ans = min(ans, abs(x));
    }

    cout << ans << endl;
        

        


        
        
    
    return 0;
}