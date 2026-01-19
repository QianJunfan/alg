/* leetcode l3 - longest substring without repeating characters
 * Jan 20, 2026
 */

/* sw */
int lengthOfLongestSubstring(string s)
{
        vector<int> p(128, 0);
        int m = 0;
        int l = 0;

        for (int i = 0; i < s.length(); ++i) {
                char c = s[i];

                if (p[c] > l)
                        l = p[c];

                p[c] = i + 1;

                m = max(m, i - l + 1);
        }

        return m;
}
