 string removeDups(string str) {
        // Your code goes here
        unordered_map<char,bool>mp;
        int n=str.length();
        string ans;
        
        for(int i=0;i<n;i++){
            if(mp[str[i]]==false){
                ans+=str[i];
                mp[str[i]]=true;
            }
        }
        return ans;
    }
