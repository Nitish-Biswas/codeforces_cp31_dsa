#include <bits/stdc++.h>
using namespace std;

int t;

bool check3(vector<vector<char>>& g, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 2; j++) {

            if (g[i][j] == '#' && g[i][j + 1] == '#' && g[i][j + 2] == '#')


                return true;
        }
    }


    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n; j++) {


            if (g[i][j] == '#' && g[i + 1][j] == '#' && g[i + 2][j] == '#')
                return true;
        }
    }
    return false;
}

vector<pair<int, int>> get_b(vector<vector<char>>& g, int n) {
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {


            if (g[i][j] == '#')
                b.push_back({i, j});
        }
    }
    return b;
}

vector<vector<pair<int, int>>> get_c(vector<pair<int, int>>& b, int n) {
    set<pair<int, int>> bs(b.begin(), b.end());
    set<pair<int, int>> v;
    vector<vector<pair<int, int>>> c;



    for (auto st : b) {
        if (v.count(st)) continue;

        vector<pair<int, int>> comp;
        queue<pair<int, int>> q;
        q.push(st);
        v.insert(st);

        while (!q.empty()) {


            auto [i, j] = q.front(); q.pop();

            comp.push_back({i, j});
            vector<pair<int, int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
            for (auto [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;


                if (bs.count({ni, nj}) && !v.count({ni, nj})) {
                    v.insert({ni, nj});
                    q.push({ni, nj});
                }
            }
        }
        c.push_back(comp);
    }
    return c;
}

bool solve_bfs(vector<vector<char>>& g, int n, vector<vector<pair<int, int>>>& c, set<pair<int, int>>& bs) {
    if ((int)c.size() <= 1) return true;

    set<pair<int, int>> sc(c[0].begin(), c[0].end());
    queue<set<pair<int, int>>> q;
    q.push(sc);

    set<set<pair<int, int>>> vs;


    vs.insert(sc);

    vector<pair<int, int>> deltas = {{0,1},{0,-1},{1,0},{-1,0}};
    const int LIMIT = 100000;

    while (!q.empty()) {
        auto cb_set = q.front(); q.pop();

        bool all_present = true;
        for (auto p : bs) {
            if (!cb_set.count(p)) { all_present = false; break; }
        }
        if (all_present) return true;

        if ((int)vs.size() >= LIMIT) continue;

        for (auto [i, j] : cb_set) {
            for (auto [di, dj] : deltas) {
                int ni = i + di, nj = j + dj;

                if (ni < 0 || nj < 0 || ni >= n || nj >= n || cb_set.count({ni, nj})) continue;

                bool violate = false;
                if (g[ni][nj] == '#') {
                    // do nothing
                } else {
                    if (nj >= 2 && ((g[ni][nj-2] == '#' || cb_set.count({ni, nj-2})) && (g[ni][nj-1] == '#' || cb_set.count({ni, nj-1}))))
                        violate = true;
                    if (nj >= 1 && nj < n - 1 && ((g[ni][nj-1] == '#' || cb_set.count({ni, nj-1})) && (g[ni][nj+1] == '#' || cb_set.count({ni, nj+1}))))
                        violate = true;



                    if (nj < n - 2 && ((g[ni][nj+1] == '#' || cb_set.count({ni, nj+1})) && (g[ni][nj+2] == '#' || cb_set.count({ni, nj+2}))))
                        violate = true;
                    if (ni >= 2 && ((g[ni-2][nj] == '#' || cb_set.count({ni-2, nj})) && (g[ni-1][nj] == '#' || cb_set.count({ni-1, nj}))))
                        violate = true;
                    if (ni >= 1 && ni < n - 1 && ((g[ni-1][nj] == '#' || cb_set.count({ni-1, nj})) && (g[ni+1][nj] == '#' || cb_set.count({ni+1, nj}))))
                        violate = true;


                    if (ni < n - 2 && ((g[ni+1][nj] == '#' || cb_set.count({ni+1, nj})) && (g[ni+2][nj] == '#' || cb_set.count({ni+2, nj}))))
                        violate = true;

                    if (violate) continue;
                }

                auto nb_set = cb_set;

                nb_set.insert({ni, nj});

                if (!vs.count(nb_set)) {


                    vs.insert(nb_set);
                    q.push(nb_set);
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<vector<char>> g(n, vector<char>(n));


        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> g[i][j];

        auto b = get_b(g, n);

        if (b.empty()) {
            cout << "YES\n";
            continue;
        }
        if (check3(g, n)) {
            cout << "NO\n";

            continue;
        }

        auto c = get_c(b, n);
        set<pair<int, int>> bs_set;

        
        for (auto& comp : c)
            for (auto p : comp)
                bs_set.insert(p);

        if (solve_bfs(g, n, c, bs_set))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
