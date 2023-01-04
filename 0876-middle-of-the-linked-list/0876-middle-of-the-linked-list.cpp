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


//1 1 1 1 null
//  s f
//    s    f


//1 1 1 null
//  s f


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        
        while (fast && fast->next) { //fast는 node수가 짝수일때, fast->next는 node수가 홀수일때.. 스톱....... null도 node로 본다면..?
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};