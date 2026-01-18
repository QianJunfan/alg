/* codeforces 2167e - khba loves to sleep!
 * Jan 18, 2026
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define _YES cout << "YES" << "\n"
#define _NO  cout << "NO"  << "\n"

void solve(void);

int main(void)
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin >> t;

        while (t--) 
                solve();

        return 0;
}

void solve(void)
{
        int n, k, x;
        cin >> n >> k >> x;
        
        vector<int> a(n);

        for (auto &v : a)
                cin >> v;
        
        sort(a.begin(), a.end());

        vector<pair<int, int>> gaps;

        for (int i = 0; i + 1 < n; ++i) {
                int mid = (a[i] + a[i + 1]) / 2;
                int dist = min(mid - a[i], a[i + 1] - mid);
                gaps.push_back({dist, mid});
        }

        if (a[0] > 0)
                gaps.push_back({a[0], 0});

        if (a.back() < x)
                gaps.push_back({x - a.back(), x});


        vector<int> tele;

        for (int i = 0; i < min(k, (int)gaps.size()); i++)
                tele.push_back(gaps[i].second);

        while ((int)tele.size() < k) {
                for (int i = 0; i <= x && tele.size() < k; i++) {
                        if (find(tele.begin(), tele.end(), i) == tele.end())
                                tele.push_back(i);
                }
        }

        sort(tele.begin(), tele.end());

        for (auto v : tele) 
                cout << v << " ";

        cout << "\n";
}
