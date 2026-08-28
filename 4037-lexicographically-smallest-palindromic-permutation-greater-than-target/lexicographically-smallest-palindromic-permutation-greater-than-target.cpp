class Solution {
public:
    string makePal(string &half, char mid) {
        string ans = half;
        if (mid != '#')
            ans += mid;
        reverse(half.begin(), half.end());
        ans += half;
        return ans;
    }
    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        int odd = 0;
        char mid = '#';
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }
        if (odd > 1)
            return "";

        int n = s.size();
        int m = n / 2;

        vector<int> halfFreq(26, 0);
        for (int i = 0; i < 26; i++)
            halfFreq[i] = freq[i] / 2;
        string pref;
        int i = 0;
        while (i < m) {
            int x = target[i] - 'a';
            if (halfFreq[x] == 0)
                break;
            halfFreq[x]--;
            pref += target[i];
            i++;
        }
        if (i == m) {
            string half = pref;
            string cand = makePal(half, mid);
            if (cand > target)
                return cand;
        }
        int pos = (i == m ? m - 1 : i);
        while (pos >= 0) {
            if (pos < i) {
                int x = target[pos] - 'a';
                halfFreq[x]++;
                pref.pop_back();
            }
            int x = target[pos] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (halfFreq[c] == 0)
                    continue;
                halfFreq[c]--;

                string half = pref;
                half += char('a' + c);

                for (int j = 0; j < 26; j++) {
                    half += string(halfFreq[j], char('a' + j));
                }
                return makePal(half, mid);
            }
            pos--;
        }
        return "";
    }
};