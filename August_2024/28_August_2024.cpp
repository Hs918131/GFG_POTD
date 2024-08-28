class Solution {
  public:
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int>m;
        
        for(auto x:arr){
            m[x]++;
        }
        
        sort(arr.begin(),arr.end(), [&](int a , int b){
            if(m[a]==m[b]){
                return a<b;
            }
            return m[a]>m[b];
        });
        return arr;
    }
};
