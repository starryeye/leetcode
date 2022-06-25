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
    
    ListNode* forward;
    bool answer = true;
    
    //재귀 함수를 통해.. inverse 포인터를 끝점으로 보내고 forward랑 값을 비교하며 크로스한다.
    void returnCheck(ListNode* inverse) {
        
        if(inverse->next != NULL) {
            returnCheck(inverse->next);
        }
        
        
        if(answer == false)
            return;
        
        //끝점에 오면 비교 시작
        if(forward->val != inverse->val) // 다르다
            answer = false;
        else { // 같다
            forward = forward->next;
        }
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        forward = head;
        
        returnCheck(head);
        
        return answer;
        
    }
};