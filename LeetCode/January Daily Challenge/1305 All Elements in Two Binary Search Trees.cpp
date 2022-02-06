/** 
	Problem : All Elements in Two Binary Search Trees
	topics : binary search tree
	time complexitiy: O(n+m)
	space complexity: O(n+m)
	problem link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
**/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans) {
        if(root == NULL) return ;
        
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> res1, res2;
        inorder(root1, res1);
        inorder(root2, res2);
        int i=0, j=0;
        while(i < res1.size() || j < res2.size()) {
            if(i < res1.size() && j < res2.size()) {
                if(res1[i] < res2[j]) {
                    ans.push_back(res1[i++]);
                }
                else{
                    ans.push_back(res2[j++]);
                }
            }
            else if(i < res1.size()) {
                ans.push_back(res1[i++]);
            }
            else {
                ans.push_back(res2[j++]);
            }
        }
        
        return ans;
    }
};
