class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // If the list is empty or only one node needs to be reversed
        if (head == NULL || left == right)
            return head;

        // Create a dummy node to handle the case when left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Move prev to the node just before the left position
        ListNode* prev = dummy;
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr points to the first node of the sublist to be reversed
        ListNode* curr = prev->next;

        // Reverse the sublist using the head insertion technique
        for (int i = 0; i < right - left; i++) {

            // Node that will be moved to the front of the reversed part
            ListNode* next = curr->next;

            // Remove 'next' from its current position
            curr->next = next->next;

            // Insert 'next' immediately after prev
            next->next = prev->next;
            prev->next = next;
        }

        // Return the new head of the list
        return dummy->next;
    }
};