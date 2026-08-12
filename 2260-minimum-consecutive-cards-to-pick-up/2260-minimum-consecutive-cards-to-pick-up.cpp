class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        
        int ans = INT_MAX;

        for (int i = 0; i < cards.size(); i++) {

            // If this card appeared before
            if (mp.count(cards[i])) {
                // Distance between previous occurrence
                // and current occurrence
                int length = i - mp[cards[i]] + 1;

                ans = min(ans, length);
            }

            // Store/update latest position
            mp[cards[i]] = i;
        }

        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};