class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
         string str;
        string t = s;
        while(r--){
            str="";
            for(auto i:s){
                if(i=='0') str+="01";
                else str+="10";
                if(str.size()>= t.size()) break;
            }
            s=str;
        }
        return s[n];
    }
};
