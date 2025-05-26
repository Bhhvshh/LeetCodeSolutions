class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        unordered_map<string,int> umap;
        int ans = 0;

        for(auto x:words){

            string rev = x;
            reverse(rev.begin(),rev.end());

            if(umap[rev]){
                ans+=4;
                umap[rev]--;
            }
            else umap[x]++;
        }

        for(char c ='a';c<='z';c++){
            string  s(2,c);
            if(umap[s]){
                ans+=2;
                break;
            }

        }

        return ans;
        
    }
};