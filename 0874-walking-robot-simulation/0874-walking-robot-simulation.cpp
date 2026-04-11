#define NUMOFDIR 4
class Solution {
public:

   vector<char> dir  = {'N', 'E', 'S', 'W'};
   long long make_key(int x, int y, bool swapped = false) {
    int a = swapped ? y : x;
    int b = swapped ? x : y;

    long long key = ((long long) a << 32) | (b & 0xffffffffLL);
    return key;
}


   void mover(int &point,int & point2, bool swapped, const int &k,int dir,unordered_map<long long, int> &umap){

    for(int i = 1;i <= k; i++){
        int tmpPoint = point + ((dir == 1) ? 1 : -1);
        if(umap.find(make_key(tmpPoint, point2, swapped)) != umap.end()) break;
        point = tmpPoint;
    }
     
   }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        unordered_map<long long, int> umap;
        for(auto &x: obstacles){
            umap[( ((long long)x[0] << 32) | (x[1] & 0xffffffffLL) )] = 1;
        }
        int currDir = 0;
        int ans = 0;
        int x = 0, y = 0;
        for(auto c: commands){
            if(c == -1){
                currDir = (currDir + 1) % NUMOFDIR;
            }
            else if(c == -2){
                currDir = (currDir - 1 + NUMOFDIR) % NUMOFDIR;
            }
            else{
                switch(dir[currDir]){
                    case 'N':
                    mover(y,x,true,c,1,umap);
                    break;
                    case 'E':
                    mover(x,y, false, c,1,umap);
                    break;
                    case 'S':
                    mover(y,x, true, c,-1,umap);
                    break;
                    case 'W':
                    mover(x,y, false, c,-1,umap);
                    break;
                    default:
                    // cout<< "going in default\n";
                    break;
                }

                ans = max(ans, (x*x) + (y*y));

              
            }
            // cout << dir[currDir] <<endl;
            // cout << x << " " << y << endl;
        }

        return ans;
        
    }
};