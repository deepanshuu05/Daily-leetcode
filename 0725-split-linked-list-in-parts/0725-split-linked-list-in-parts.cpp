class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> ans;

        // Step 1: Count total number of nodes
        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        // Minimum number of nodes in each part
        int size = n / k;

        // Number of parts that will get one extra node
        int extra = n % k;

        ListNode* curr = head;

        // Create k parts
        for (int i = 0; i < k; i++) {

            // Current part's size
            int partSize = size;

            // Give one extra node to the first 'extra' parts
            if (extra > 0) {
                partSize++;
                extra--;
            }

            // This will be the head of current part
            ListNode* partHead = curr;

            // Move curr to the last node of current part
            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }

            // If current part is not empty
            if (partHead != NULL) {

                // Save next part's starting node
                ListNode* nextPart = curr->next;

                // Break the current part from remaining list
                curr->next = NULL;

                // Move curr to next part
                curr = nextPart;
            }

            // Store current part
            ans.push_back(partHead);
        }

        return ans;
    }
};