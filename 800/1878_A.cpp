#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        bool flag = false;
        int x;

        for(int i=0; i<n; i++){
            cin >> x;
            if (x==k) flag = true;
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;

        
        
    }
    return 0;
}