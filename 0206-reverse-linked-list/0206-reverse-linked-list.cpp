/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *first, *last;
        first = last = NULL;
        while(head != NULL){
            ListNode *newNode = new ListNode;
            newNode->val = head->val;
            if(last == NULL){
                last = first = newNode;
                newNode = NULL;
            }
            else{
                newNode->next = first;
                first = newNode;
            }
            head = head->next;
        }
        return first;
    }
};