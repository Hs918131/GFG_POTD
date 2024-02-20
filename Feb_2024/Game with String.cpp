class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char,int> umap;
        int ans = 0, count = 0;
        for(int i=0; i<s.size(); i++) umap[s[i]]++;
        vector<int> v;
        for(auto i: umap) v.push_back(i.second);
        sort(v.begin(), v.end(), greater<int>());
        while(count != k){
            v[0] -= 1;
            count++;
            sort(v.begin(), v.end(), greater<int>());
        }
        for(int i=0; i<v.size(); i++) ans += pow(v[i], 2);
        return ans;
    }
};


// another approach

//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        priority_queue<int>pq;
        for(auto it:mp){
            if(it.second!=0){
                pq.push(it.second);
            }
        }
        for(int i=0;i<k;i++){
            int a=pq.top(); pq.pop();
            a--;
            if(a>0){
                pq.push(a);
            }
        }
        int ans=0;
        while(!pq.empty()){
            ans=ans+ pq.top()*pq.top();
            pq.pop();
        }
        return ans;
    }
};
