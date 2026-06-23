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

        /*vector<int> ans;

        if(root== NULL) return ans;

        stack<TreeNode*> st;
        TreeNode* curr= root;

        while (curr!=NULL || !st.empty()){

            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }            


            curr= st.top();
            st.pop();

            
            ans.push_back(curr->val);
           

           curr= curr->right;
        }

        return ans;

        */

        vector<int> ans;
        TreeNode* curr = root;

    while (curr != NULL) {

        if (curr->left == NULL) {
            ans.push_back(curr->val);
            curr = curr->right;
        } 
        else {
            TreeNode* IP = curr->left;

            // find rightmost node
            while (IP->right != NULL && IP->right != curr) {
                IP = IP->right;
            }

            if (IP->right == NULL) {
                // create thread
                IP->right = curr;
                curr = curr->left;
            } 
            else {
                // remove thread
                IP->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return ans;
}
};