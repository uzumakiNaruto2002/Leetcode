class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int size = s.size();
        int x = startPos[0], y = startPos[1];
        vector<int> ans;
        for(int i = 0; i < size; i++){
            int count = 0;
            queue<pair<pair<int, int>, int>> q;
            q.push({{x, y}, i});
            while(!q.empty()){
                int row = q.front().first.first;
                int col = q.front().first.second;
                int ind = q.front().second;
                q.pop();
                count = max(count, ind - i);
                int r = row, c = col;
                if(ind >= size)break;
                if(s[ind] == 'R'){
                    c = col + 1;
                }
                else if(s[ind] == 'L'){
                    c = col - 1;
                }
                else if(s[ind] == 'U'){
                    r = row - 1;
                }
                else if(s[ind] == 'D'){
                    r = row + 1;
                }
                if(r >= 0 && r < n && c >= 0 && c < n){
                    // cout<<r<<' ';
                    q.push({{r, c}, ind + 1});
                }
                else{
                    break;
                }
            }
            // cout<<endl;
            ans.push_back(count);
        }
        return ans;
    }
};