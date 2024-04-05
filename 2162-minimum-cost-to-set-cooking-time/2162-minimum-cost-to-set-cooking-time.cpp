
void makeArray(vector<int> &first, int minute, int second){
    if(minute/10 > 0){
        // cout<<"1"<<endl;
        first.push_back(minute/10);
    }
    if(minute % 10 > 0){
        // cout<<"2"<<endl;
        first.push_back(minute % 10);
    }
    else{
        if(first.size() > 0){
            first.push_back(minute % 10);
        }
    }
    if(second/10 > 0){
        // cout<<"3"<<endl;
        first.push_back(second/10);
    }
    else{
        if(first.size() > 0){
            first.push_back(second/10);
        }
    }
    if(second % 10 > 0){
        // cout<<"4"<<endl;
        first.push_back(second % 10);
    }
    else{
        if(first.size() > 0){
            first.push_back(second % 10);
        }
    }
}

int findCost(vector<int> &temp, int startAt, int moveCost, int pushCost){
    int cost = 0;
    for(int i = 0; i < temp.size(); i++){
        if(startAt == temp[i]){
            cost += pushCost;
        }
        else{
            cost = cost + pushCost + moveCost;
            startAt = temp[i];
        }
    }
    return cost;
}

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        vector<int> first, secondd;
        int minute = targetSeconds/60, second = targetSeconds%60;
        if(minute == 100){
            minute = 99;
            second = second + 60;
        }
        makeArray(first, minute, second);
        // for(int i : first)cout<<i<<' ';
        int cost1 = findCost(first, startAt, moveCost, pushCost);
        if(minute == 0)return cost1;
        minute -= 1, second += 60;
        if(second > 99)return cost1; 
        makeArray(secondd, minute, second);
        int cost2 = findCost(secondd, startAt, moveCost, pushCost);
        return min(cost1, cost2);
    }
};