/* codeforces 2167a - square?
 * Jan 18, 2026
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define _YES cout << "YES" << "\n"
#define _NO  cout << "NO"  << "\n"

int main(void)
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        int t;
        cin >> t;

        while (t--) {
                int a, b, c, d;
                cin >> a >> b >> c >> d;

                if (a == b && b == c && c== d)
                        _YES;
                else
                        _NO;
        }

        return 0;
}
