#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin >> t;
    while (t--) {
        int r;
        int ans=0;
        int a[10][10];
        for(int i=0; i<10; i++){
            r = i;
            if (i>4) r = 9-i;
            string tar;
            cin >> tar;
            for(int j=0; j<10; j++){
                if (tar[j]=='X'){
                    if ((j>=r) && (j<10-r)) ans+=r+1;
                    else{
                        if (j<r) ans+=j+1;
                        else ans+= 10-j;
                    }

                }
            }


        }

        
        cout << ans <<endl;
        

        


        
        
    }
    return 0;
}