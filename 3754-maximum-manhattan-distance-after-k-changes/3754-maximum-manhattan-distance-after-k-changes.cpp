class Solution {
public:
    int maxDistance(string s, int k) {
         int len = s.length();
        //dir
    int up = 0, down =0, right = 0, left = 0;
    int max_dist = 0;
     ///logic
    for (int idx = 0; idx < len; idx++) {
        if (s[idx] == 'N') up++;
         else if (s[idx] == 'S') down++;//every dir
         else if (s[idx]== 'E') right++;
        else if (s[idx] == 'W') left++;


        
         int vert_shift = abs(up - down);
         int hori_shift = abs(right - left);
         int base_dist = vert_shift + hori_shift;

        
        int inter_moves = min(up, down) + min(right, left);
        int max_poss_dist = base_dist + min(k, inter_moves) * 2;

               max_dist = max(max_dist, min(idx + 1, max_poss_dist));
 }

              return max_dist;
}
        
    
};