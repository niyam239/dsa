/** 
	Problem : Maximum Twin Sum of a Linked List
	topics : linked list
	time complexitiy: O(n)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
**/

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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        
        ListNode* sec = reverse(slow);
        ListNode* first = head;
        
        int mx = 0;
        while(first != NULL && sec != NULL) {
            int x = first->val + sec->val;
            mx = max(mx, x);
            first = first->next;
            sec = sec->next;
        }
        return mx;
    }
};
