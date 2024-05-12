class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        while(1){
            if(numExchange > numBottles)break;
            numBottles = numBottles - numExchange + 1;
            ans++;
            numExchange++;
        }
        return ans;
    }
};