
bool comp(vector<int> &a, vector<int> &b){
    if(a[0] != b[0])return a[0] < b[0];
    return a[1] > b[1];
}

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), comp);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int y = INT_MIN;
            for(int j = i + 1; j < n; j++){
                if(points[j][1] <= points[i][1] && y < points[j][1]){
                    ans++;
                    y = max(y, points[j][1]);
                }
            }
        }
        return ans;
    }
};