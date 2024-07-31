class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        
        string smin = *min_element(arr.begin(), arr.end(), 
                     [] (const string& s1, const string& s2) { 
                         return s1.length() < s2.length(); }
                     );
                     
        string str= "";
        
        for(int i=0; i<smin.size(); i++){
            char ch = smin[i];

            for(int j=0; j<arr.size(); j++){
                string temp = arr[j];

                if(ch == temp[i])
                    continue;
                else{
                    if(str == "") return "-1";
                    else return str;
                }
            }
            
            str += ch;
        }
        return str;
    }
};
