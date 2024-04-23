class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0, n = bottomLeft.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                long long x1 = max(bottomLeft[i][0], bottomLeft[j][0]), y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long x2 = min(topRight[i][0], topRight[j][0]), y2 = min(topRight[i][1], topRight[j][1]);
                if(x1 < x2 && y1 < y2){
                    long long res = min(y2 - y1, x2 - x1);
                    res = res*res;
                    // cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};