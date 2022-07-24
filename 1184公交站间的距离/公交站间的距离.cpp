#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int disSum = 0, dis1 = 0;
        for (int i = 0; i < distance.size(); ++i) {
            disSum += distance[i];
            if (start <= destination) {
                if (i >= start && i < destination) {
                    dis1 += distance[i];
                }
            }
            else {
                if (i < destination || i >= start) {
                    dis1 += distance[i];
                }
            }
        }
        return min(dis1, disSum - dis1);
    }
};

int main() {
    Solution S;
    vector<int> distance = { 7,10,1,12,11,14,5,0 };
    int start = 7, destination = 2;
    auto res = S.distanceBetweenBusStops(distance, start, destination);
    cout << res << endl;
}