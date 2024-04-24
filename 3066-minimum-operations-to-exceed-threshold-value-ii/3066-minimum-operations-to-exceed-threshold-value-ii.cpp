class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto i: nums)pq.push(i);
        while(1){
            long long a = pq.top();
            if(a >= k)return count;
            pq.pop();
            long long b;
            if(pq.size() > 0){
                b = pq.top();
                pq.pop();
                pq.push(2 * min(a, b) + max(a, b));
                count++;
            }
        }
        return count;
    }
};