class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long n = s.size(), hash = 0, mul = 1, start = 0;
        for(int i = n - 1; i >= 0; i--){
            hash = (hash * power + (s[i] - 'a' + 1)) % modulo;
            if(i + k >= n){
                mul = (mul * power) % modulo;
            }
            else{
                hash = (hash - (s[i + k] - 'a' + 1)*mul % modulo + modulo) % modulo;
            }
            if(hash == hashValue){
                start = i;
            }
        }
        return s.substr(start, k);
    }
};