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
