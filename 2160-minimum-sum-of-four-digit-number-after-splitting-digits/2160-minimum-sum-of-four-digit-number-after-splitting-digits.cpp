class Solution {
public:
    int minimumSum(int num) {
        int n = num;
        vector<int> temp;
        while(n > 0){
            temp.push_back(n%10);
            n/=10;
        }
        sort(temp.begin(), temp.end());
        int i = 0, new1 = 0, new2 = 0;
        while(i < temp.size()){
            if(i % 2 == 0){
                new1 *= 10;
                new1 += temp[i];
            }
            else{
                new2 *= 10;
                new2 += temp[i];
            }
            i++;
        }
        return new1 + new2;
    }
};