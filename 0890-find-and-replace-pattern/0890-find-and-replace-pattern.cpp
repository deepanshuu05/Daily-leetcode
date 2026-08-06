class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        for (string word : words) {
            unordered_map<char, char> pToW;
            unordered_map<char, char> wToP;

            bool valid = true;

            for (int i = 0; i < pattern.size(); i++) {
                char p = pattern[i];
                char w = word[i];

                // Pattern -> Word mapping
                if (pToW.count(p)) {
                    if (pToW[p] != w) {
                        valid = false;
                        break;
                    }
                } else {
                    pToW[p] = w;
                }

                // Word -> Pattern mapping
                if (wToP.count(w)) {
                    if (wToP[w] != p) {
                        valid = false;
                        break;
                    }
                } else {
                    wToP[w] = p;
                }
            }

            if (valid)
                ans.push_back(word);
        }

        return ans;
    }
};