/** 
	Problem : Merge k Sorted Lists
	topics : Linked List, Merge Sort
	time complexitiy: O(N * log(K)) // N is for mergimg two LL &
									// log(K) for recursive calls mergeLL()
									// here k is no of recursive calls  
	space complexity: O(k) 	// auxiliary space
							//it is for recursive calls
	problem link: https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }
        
        return getMid(lists, 0, lists.size() - 1);
    }
    
    ListNode* getMid(vector<ListNode*> &lists, int st, int ed) {
        if(st == ed) return lists[st];
        
        int mid = st + (ed - st) / 2;
        
        ListNode* left = getMid(lists, st, mid);
        ListNode* right = getMid(lists, mid + 1, ed);
        
        return mergeLL(left, right);
    }
    
    ListNode* mergeLL(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(0);
        ListNode* node = root;
        
        while(l1 != NULL || l2 != NULL) {
            if(l1 == NULL) {
                node->next = l2;
                l2 = l2->next;
            } 
            else if(l2 == NULL) {
                node->next = l1;
                l1 = l1->next;
            }
            else if(l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            }
            else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        
        return root->next; //return next to avoid first dummy 0
    }
};
