class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long int l=1,h=n,m=0,count;
        while(l<=h)
        {
            m=(l+h)/2;
            if(m*m==n)
            return m;
            else if(m*m<n)
            {
                count=m;
                l=m+1;
            }
            else
            h=m-1;
        }
        return count;
    }
};
