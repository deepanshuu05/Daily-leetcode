class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int ans = 0;

        for (int i = 0; i < fruits.size(); i++) {

            bool placed = false;

            // Find the leftmost suitable basket
            for (int j = 0; j < baskets.size(); j++) {

                if (baskets[j] >= fruits[i]) {

                    // Use this basket
                    baskets[j] = -1;

                    placed = true;
                    break;
                }
            }

            // No suitable basket found
            if (!placed) {
                ans++;
            }
        }

        return ans;
    }
};