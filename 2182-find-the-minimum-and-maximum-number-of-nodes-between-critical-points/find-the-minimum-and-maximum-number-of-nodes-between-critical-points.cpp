class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* prev = head;
        ListNode* curr = head->next;

        int i = 1;  // position of current node

        int prevcriticalpos = 0;
        int firstcriticalpos = 0;

        int minDist = INT_MAX;

        while (curr->next != NULL) {

            // Check if curr is a critical point
            // Local minimum
            // OR
            // Local maximum
            if ((curr->val < prev->val && curr->val < curr->next->val) ||
                (curr->val > prev->val && curr->val > curr->next->val)) {

                // First critical point
                if (prevcriticalpos == 0) {
                    prevcriticalpos = i;
                    firstcriticalpos = i;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, i - prevcriticalpos);

                    // Current critical point becomes previous
                    prevcriticalpos = i;
                }
            }

            i++;
            prev = curr;
            curr = curr->next;
        }

        // Fewer than 2 critical points
        if (minDist == INT_MAX) {
            return {-1, -1};
        }

        // min distance, max distance
        return {minDist, prevcriticalpos - firstcriticalpos};
    }
};