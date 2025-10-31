#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin >> t;
    while (t--) {
        int n,x; 
        cin >> n >>x;
        int ans =0;
        int prev = 0;

        int a;
        for (int i = 0; i < n; i++){
            cin >> a;
            ans = max(ans, a-prev);
            prev = a;
        }

        ans = max(ans, 2*(x - prev));
        cout << ans << endl;

        
    }
    return 0;

}
