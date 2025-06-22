class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> fr(26);
        for(auto x:word) fr[x-'a']++;

        sort(fr.begin(),fr.end());

        vector<int>pre(26);
        for(int i =0;i<26;i++) {pre[i] = (i>0) ? fr[i]+pre[i-1]:fr[i];}
        int ans = INT_MAX;

        int total =0;
        for(int i =0;i<26;i++){
            if(i>0 && fr[i]==fr[i-1]) {total+=fr[i];continue;}

            int maxpossibleID = i;
            for(int j = 25;j>=i;j--)
             if(fr[j]<=(fr[i]+k)){
                    maxpossibleID = j;
                    break;
                }
            
            ans = min(ans,total + ((pre[25] - pre[maxpossibleID]) - (fr[i]+k)*(25-maxpossibleID)));
            total+=fr[i];

        }

        return ans;
        
    }
};