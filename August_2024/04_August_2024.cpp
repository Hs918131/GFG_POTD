int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int,int>> v;
        int count=1;
        for(int i=0;i<n;i++)
        {
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int last=v[0].first;
        for(int i=1;i<n;i++)
        {
            if(last<v[i].second)
            {
                count++;
                last=v[i].first;
            }
        }
        return count;
    }
