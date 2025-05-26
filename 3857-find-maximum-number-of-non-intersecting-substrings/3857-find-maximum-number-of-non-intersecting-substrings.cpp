class Solution {
public:
    int maxSubstrings(string word) {

        int last = 0;
        int n = word.size();
        int ans = 0;
        unordered_map<char,int> umap;

        for(int i = 0;i<n;i++){
            if(i-3>=0) umap[word[i-3]] =  i - 2;
            if(umap[word[i]]>last){
                ans++;
                last = i+1;
            }
           

        }


        return ans;
        
    }
};