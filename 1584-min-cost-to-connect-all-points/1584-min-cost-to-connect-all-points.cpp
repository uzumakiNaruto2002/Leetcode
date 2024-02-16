class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<pair<int,int>, int> vis;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        int sum = 0;
        q.push({0, {points[0][0], points[0][1]}});
        while(!q.empty()){
            int dist = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            if(vis[{x, y}] == 1)continue;
            vis[{x, y}] = 1;
            sum += dist;
            
            for(auto i: points){
                if(vis[{i[0], i[1]}] != 1){
                    q.push({abs(x - i[0]) + abs(y - i[1]), {i[0], i[1]}});
                }
            }
        }
        return sum;
    }
};