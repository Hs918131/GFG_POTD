class Solution {
  public:
    
    void cntNodes(Node* root, int &nodes){
        if(!root) return;
        cntNodes(root->left,nodes);
        nodes++;
        cntNodes(root->right,nodes);
    }
    void createGraph(Node* root, vector<vector<int>> &adjL){
        if(!root) return;
        if(root->left) {
            adjL[root->data].push_back(root->left->data);
            adjL[root->left->data].push_back(root->data);
            createGraph(root->left, adjL);
        }
        if(root->right){
            adjL[root->data].push_back(root->right->data);
            adjL[root->right->data].push_back(root->data);
            createGraph(root->right, adjL);
        }
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int nodes = 0;
        cntNodes(root, nodes);
        
        vector<vector<int>> adjL(nodes+1);
        createGraph(root,adjL);
        
        queue<pair<int,int>> q;
        q.push({target,0});
        
        vector<int> vis(nodes+1,0);
        vis[target] = 1;
        int ans = 0;
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            ans = curr.second;
            
            for(int elem : adjL[curr.first]){
                if(!vis[elem]){
                    q.push({elem,curr.second+1});
                    vis[elem] = 1;
                }
            }
        }
        return ans;
        
    }
};
