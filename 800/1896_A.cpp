#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        int x; 
        bool flag = false;

        for(int i=0; i<n; i++){
            cin >> x;
            if ((i==0) && (x==1)) flag = true;
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}