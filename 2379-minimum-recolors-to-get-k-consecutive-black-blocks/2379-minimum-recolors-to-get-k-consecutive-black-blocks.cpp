class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int white = 0;

        // First window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                white++;
            }
        }

        int ans = white;

        // Sliding window
        for (int right = k; right < blocks.size(); right++) {

            // Add new element
            if (blocks[right] == 'W') {
                white++;
            }

            // Remove left element
            if (blocks[right - k] == 'W') {
                white--;
            }

            ans = min(ans, white);
        }

        return ans;
    }
};