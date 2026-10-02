
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;

        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int target = count - n;

        if (target == 0) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        for (int i = 1; i < target; i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;

        return head;
    }
};