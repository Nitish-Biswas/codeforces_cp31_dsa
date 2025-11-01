#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >>n;

        map<int, int> mp;
        int x;
        for (int i=0; i<n; i++){
            cin >> x;
            mp[x]++;
        }

        if (mp.size() >2) cout << "NO" << endl;
        else if (mp.size() ==2){
            int f1 = mp.begin()->second;
            int f2= mp.rbegin()->second;
            if (f1==f2) cout << "YES" << endl;
            else if (abs(f1 - f2) !=1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else{
            cout << "YES" << endl;
        }






    }
    return 0;
}