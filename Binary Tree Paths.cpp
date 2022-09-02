class Solution {
public:
    void myfunc(TreeNode* root, vector<string> &ans,string curr){
        
        if(root == NULL){
            return;
        }
        
        string now = curr+to_string(root->val);
        if(root->left){
            myfunc(root->left,ans, now+"->");        
        }
        
        if(root->right){
            myfunc(root->right,ans, now+"->");        
        }
        
        if(root->left == NULL && root->right ==NULL){
            ans.push_back(now);
        }
        
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        string curr = "";
        myfunc(root,ans,curr);
        
        return ans;
    }
};