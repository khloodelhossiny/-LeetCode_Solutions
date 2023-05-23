/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int c = 0;
        while(head != NULL && c < 10002){
            c++;
            head = head->next;
        }
        return !(head == NULL);
    }
};