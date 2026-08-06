class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n)
            return ans;

        vector<int> pFreq(26, 0);
        vector<int> window(26, 0);

        // Frequency of pattern
        for (char ch : p)
            pFreq[ch - 'a']++;

        // First window frequency
        for (int i = 0; i < m; i++)
            window[s[i] - 'a']++;

        // Check first window
        if (window == pFreq)
            ans.push_back(0);

        // Sliding Window
        for (int i = m; i < n; i++) {

            // Add new character
            window[s[i] - 'a']++;

            // Remove leftmost character
            window[s[i - m] - 'a']--;

            // Compare frequencies
            if (window == pFreq)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};