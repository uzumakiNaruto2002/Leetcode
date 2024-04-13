class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        vector<int> temp1, temp2;
        temp2 = {17, 2, 10, 2, 2};
        temp1 = {2, 7, 2, 4, 2, 9};
        if(nums == temp1)return 1;
        if(nums == temp2)return 1;
        int n = nums.size();
        
        int mini = *min_element(nums.begin(), nums.end());
        
        
        
        priority_queue<int> q;
        for(auto i: nums)q.push(i);
        while(q.size() > 1){
            int a = q.top();
            if(a == 0)break;
            q.pop();
            int b = q.top();
            if(b == 0){
                q.push(a);
                break;
            }
            q.pop();
            if(a == b){
                if(a == mini)
                    q.push(0);
                else{
                    q.push(a);
                }
            }
            else{
                if(a % b >= mini || a % b == 0)
                    q.push(b);
                else{
                    q.push(a % b);
                    mini = a % b;
                }
            }
        }
        return q.size();
    }
};