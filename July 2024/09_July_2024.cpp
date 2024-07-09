class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int diff=INT_MAX , ans=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int s=i+1, e=arr.size()-1;
            while(s<e){
                int sum = arr[i]+arr[s]+arr[e];
                if(sum==target){
                    return sum;
                }else if(sum>target)
                e--;
                else
                s++;
                if(abs(sum-target)<diff){
                    diff=abs(sum-target);
                    ans=sum;
                }else if(abs(sum-target)==diff)
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};
