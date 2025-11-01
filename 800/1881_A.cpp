#include <bits/stdc++.h>
using namespace std;

bool check(string &x, string &s, int m){
    if (x.size() < m) return false;
    for (int i=0; i<= x.size()-m; i++){
        if (x.substr(i,m) == s){
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin >> t;
    while (t--) {
        int n,m ;
        cin >> n >> m;
        string x;
        string s;
        cin >> x;
        cin >> s;
        int ans = -1;
        int count = 6;
        bool flag = false;



        while (count--){
            if (check(x,s,m)){
                ans++;
                flag = true;
                break;
            }
            ans++;
            x += x;
            
        }

        if (!flag) ans = -1;

        cout << ans << endl;






    }
    return 0;
}