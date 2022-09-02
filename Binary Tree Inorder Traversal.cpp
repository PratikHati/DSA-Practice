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
    vector<int> inorderTraversal(TreeNode* root) {
        
        //Morris traversal
        TreeNode* curr = root;
        vector<int> ans;
        
        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode *prev  = curr->left;
                //find rightmost
                //      pre side ------ post side
                while(prev->right && prev->right !=curr ){
                    prev = prev->right;
                }
                
                
                //then traverse pre side (link)
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                
                //post side then (unlink)
                else{
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};