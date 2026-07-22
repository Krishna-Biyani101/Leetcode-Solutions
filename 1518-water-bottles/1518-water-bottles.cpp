class Solution {
public:
    int numWaterBottles(int n, int c) {
        return n + (n-1)/(c-1);
    }
};