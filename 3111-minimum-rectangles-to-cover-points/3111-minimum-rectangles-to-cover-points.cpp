class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n = points.size(), ans = 1;
        sort(points.begin(), points.end());
        int a = points[0][0] + w;
        for(int i = 1; i < n; i++){
            if(points[i][0] <= a){
                continue;
            }
            else{
                ans++;
                a = points[i][0] + w;
            }
        }
        return ans;
    }
};