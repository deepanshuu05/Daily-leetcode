class Solution {
public:
    string reverseWords(string s) {

        string ans = "";
        int i = s.size() - 1;

        while (i >= 0) {

            // Skip extra spaces
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            int j = i;

            // Find beginning of current word
            while (j >= 0 && s[j] != ' ')
                j--;

            // Add one space before next word
            if (!ans.empty())
                ans += " ";

            // Copy word
            ans += s.substr(j + 1, i - j);

            i = j;
        }

        return ans;
    }
};