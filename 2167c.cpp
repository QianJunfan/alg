/* codeforces 2167c - isamatdin and his magic wand!
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
        int n;
        cin >> n;
        
        int even = 0, odd = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
                if (a[i] % 2 == 0)
                        even = 1;
                else
                        odd = 1;
        }

        if (even && odd)
                sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) {
                cout << a[i];
                if (i == n - 1)
                        cout << "\n";
                else
                        cout << " ";
        }
}
