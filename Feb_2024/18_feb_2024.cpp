class Solution
{
    public:
        /*You are required to complete below method */
        int sumOfLeafNodes(Node *root ){
             /*Your code here */
            if(root==NULL){
                return 0;
            }if(root->left==NULL && root->right==NULL){
                return root->data;
            }return sumOfLeafNodes(root->left)+sumOfLeafNodes(root->right);
             
        }
};
