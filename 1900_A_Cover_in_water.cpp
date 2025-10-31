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
        int ans =0;
        int count = 0;

        string a;
        cin >> a;
        bool flag = false;
        for (int i = 0; i < n; i++){
            if (a[i]=='#'){
                if (count>0){
                    if (count >2){
                        flag = true;
                        break;
                    }
                    if (count >1){
                        ans += 2;
                    }
                    else{
                        ans +=1;
                    }
                }
                
                count=0;
                
            }
            else{
                count++;
            }
        }
        if (count>0){
            if (count >2){
                flag = true;
            }
            if (count >1){
                ans += 2;
            }
            else{
                ans +=1;
            }
        }

        if (flag){
            cout << 2 << endl;
        }else 
            cout << ans << endl;

        
    }
    return 0;

}
