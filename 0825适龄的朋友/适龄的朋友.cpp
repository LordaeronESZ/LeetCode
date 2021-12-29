#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end(), less<int>());
    }
};
int main() {
    return 0;
}