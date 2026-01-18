/* codeforces 2167b - your name
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
                int n;
                cin >> n;

                string s, t;
                cin >> s >> t;


                array<int, 26> as = {}; 
                array<int, 26> at = {};

                for (char c : s) as[c - 'a']++;
                for (char c : t) at[c - 'a']++;

                int f = 1;
                for (int i = 0; i < 26; i++) {
                        if (as[i] != at[i]) {
                                f = 0;
                                break;
                        }
                }

                if (f)
                        _YES;
                else
                        _NO;
        }
        return 0;
}
