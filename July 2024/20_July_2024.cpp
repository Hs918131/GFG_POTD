class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
       
        //base case
        if(root==NULL){
            return NULL;
        }
        //recursive case
        root->left=RemoveHalfNodes(root->left);
        root->right=RemoveHalfNodes(root->right);
        
        if(root->left== NULL && root->right!=NULL){
           return root->right;
        }
        if(root->left!= NULL && root->right==NULL){
            return root->left;
        }
        return root;
    }
};
