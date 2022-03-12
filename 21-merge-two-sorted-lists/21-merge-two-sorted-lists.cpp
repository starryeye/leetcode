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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* ans;
        ListNode* point;
        
        if(!list1)
            return list2;
        else if(!list2)
            return list1;
        
        //최초 1회
        if(list1->val <= list2->val)
        {
            ans = list1;
            list1 = list1->next;
            point = ans;
        }
        else
        {
            ans = list2;
            list2 = list2->next;
            point = ans;
        }
        
        //그 이후
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                point->next = list1;
                list1 = list1->next;
                point = point->next;
            }
            else
            {
                point->next = list2;
                list2 = list2->next;
                point = point->next;
            }
        }
        
        //끝에..
        if(list1)
            point->next = list1;
        else
            point->next = list2;
        
        
        return ans;
        
    }
};