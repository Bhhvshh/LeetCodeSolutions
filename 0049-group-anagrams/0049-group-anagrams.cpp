class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<int>> umap;
        
        for(int i =  0;i<n;i++){
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            umap[tmp].push_back(i);

        }

        vector<vector<string>> ans;

        for(auto &x:umap){
            vector<string> tmp;
            for(auto y:x.second){
                tmp.push_back(strs[y]);

            }
            ans.push_back(tmp);
        }

        return ans;
    }

};