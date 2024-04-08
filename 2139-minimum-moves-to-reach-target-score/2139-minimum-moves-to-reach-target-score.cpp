class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int total = 0;
        while(target > 1){
            if(target % 2 == 1){
                total++;
                target--;
            }
            else{
                if(maxDoubles > 0){
                    total++;
                    target/= 2;
                    maxDoubles--;
                }
                else{
                    break;
                }
            }
        }
        return total + target - 1;
    }
};