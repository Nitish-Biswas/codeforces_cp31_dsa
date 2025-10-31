#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin >> t;
    while (t--) {
        int n,k; 
        cin >> n >>k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (k >= 2) {
            cout << "YES\n";
            continue;
        }else{
            bool check = true;

            for(int i=0; i<n-1;i++){
                if(a[i]>a[i+1]){
                    check = false;
                    break;
                }
            }

            if (check){
                cout << "YES\n";
            }else{ 
                cout << "NO\n";
            }
        }
    }
    return 0;

}
