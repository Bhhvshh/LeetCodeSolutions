struct TrieNode{
        TrieNode* child[27];
        bool isEnd = false;

        TrieNode(){
            for(int i = 0 ;i<27;i++){
                child[i] = nullptr;

            }
        }
      };
class Trie {
    private:
      
   public:
      TrieNode* root;

     

      Trie(){
        root = new TrieNode();
      }

      void insert(string &s){
        TrieNode* node = root;
        for(auto x:s){
            int id = (x=='/') ?  26 : (x-'a');
            if(!node->child[id])
               node->child[id] = new TrieNode();
            node = node ->child[id];
        }
        node->isEnd = true;
      }

     
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());

        vector<string> ans;
        

        Trie t;
        for(auto &x:folder){
            t.insert(x);
        }

       
        string s = "";
        dfs(ans,t.root,s,false);


        return ans;
        
    }

    void dfs(vector<string> & ans, TrieNode* root, string &s,bool flag){
        
        if(!flag && root->isEnd){ ans.push_back(s); dfs(ans,root,s,true); return;}
        
        for(int i = 0;i<27;i++){
            char c = (i<26) ? 'a'+i : '/';
            if(flag && i==26) continue;
            if(root->child[i]){
                s.push_back(c);
                dfs(ans,root->child[i],s,false);
                s.pop_back();
            }

        }
    }
};