/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    unordered_set<ListNode *> seen;
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *current = head;

        while (current != nullptr) {
            
            if (seen.find(current) != seen.end()) {
                return current;
            }

            seen.insert(current);
            current = current->next;
        }

        return nullptr;
    }
};