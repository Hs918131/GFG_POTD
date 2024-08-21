class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> ans(N, -1);
        ans[src] = 0;
        
        vector<vector<int>> adj(N, vector<int>());
        for(auto i : edges) {
            int s = i[0], e = i[1];
            adj[s].push_back(e);
            adj[e].push_back(s);
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        
        while(!pq.empty()) {
            int curr = pq.top().second;
            int curr_weight = pq.top().first;
            pq.pop();
            
            for(auto i : adj[curr]) {
                if(ans[i] == -1 || ans[i] > curr_weight + 1) {
                    pq.push({curr_weight + 1, i});
                    ans[i] = curr_weight + 1;
                }
            }
        }
        
        return ans;
    }
};
