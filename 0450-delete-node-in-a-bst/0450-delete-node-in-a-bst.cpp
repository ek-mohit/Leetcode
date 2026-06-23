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

TreeNode* getinordersuccessor (TreeNode* root ){
    while (root!= NULL && root->left != NULL){
        root= root->left;
    }
    return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==NULL) return NULL;

        //key exist in left subtree
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        
        // key exist in right subtree
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }

        // key == ho chuki root ke 
        else{

            //case1 && case 2 0 children of root ya 1 childern of root

            if(root-> left ==NULL){ //ya to right null hoga ya val rkhega 
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }

            else if( root-> right ==NULL){
                 TreeNode* temp = root->left;
                delete(root);
                return temp;


            }
            else{ // root has 2 child 
                 
                TreeNode* IS = getinordersuccessor(root->right);
                root->val = IS->val;
                root->right = deleteNode(root->right, IS->val);


            }

        }
       return root;
        
    }
};