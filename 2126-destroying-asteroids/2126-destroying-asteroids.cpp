class Solution {
public:
    bool asteroidsDestroyed(int mas, vector<int>& asteroids) {
        int n = asteroids.size();
        long long mass = mas;
        sort(asteroids.begin(), asteroids.end());
        for(int i = 0; i < n; i++){
            if(asteroids[i] <= mass){
                mass += (long long)asteroids[i];
            }
            else return false;
        }
        return true;
    }
};