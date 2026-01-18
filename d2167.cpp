/* codeforces 2167d - yet another array problem
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

ll gcd(ll a, ll b)
{
        if (b == 0)
                return a;
        return gcd(b, a % b);
}

void solve(void)
{
        ll n;
        cin >> n;
        
        vector<ll> v(n);
        for (ll i = 0; i < n; ++i)
                cin >> v[i];
        
        vector<ll> p;
        for (ll i = 2; p.size() < 100; i++) {
                ll f = 1;
                for (ll j = 2; j * j <= i; j++) {
                        if (i % j == 0) {
                                f = 0;
                                break;
                        }
                }
                if (f) p.push_back(i);
        }
        
        ll x = -1;
        for (ll a : p) {
                for (ll i = 0; i < n; i++) {
                        if (gcd(v[i], a) == 1) {
                                x = a;
                                break;
                        }
                }
                if (x != -1) break;
        }
        
        cout << x << "\n";
}
