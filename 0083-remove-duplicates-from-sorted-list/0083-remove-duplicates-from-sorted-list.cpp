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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *first, *last;
        first = last = NULL;
        int value = 200;
        while(head != NULL){
            if(head->val != value){
                value = head->val;
                ListNode *newNode = new ListNode;
                newNode->val = value;
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