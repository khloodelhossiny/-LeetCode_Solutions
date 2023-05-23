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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* first, *last;
        first = last = NULL;
        while(head != NULL){
            if(head->val != val){
                ListNode *newNode = new ListNode;
                newNode->val = head->val;
                if(first == NULL){
                    first = last = newNode;
                    newNode->next = NULL;
                }
                else{
                   last->next = newNode;
		            newNode->next = NULL;
		            last = newNode;
                }
            }
            head = head->next;
        }
        return first;
    }
};