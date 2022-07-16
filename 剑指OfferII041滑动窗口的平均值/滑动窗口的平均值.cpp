#include<iostream>
#include<vector>
using namespace std;

class MovingAverage {
private:
    vector<int> nums;
    int p, q;
    int windSize;
    double sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        p = -1;
        q = -1;
        windSize = size;
        sum = 0;
    }

    double next(int val) {
        nums.emplace_back(val);
        ++q;
        if (nums.size() == 1) {
            p = 0;
        }
        else if (q - p >= windSize) {
            sum -= nums[p];
            ++p;
        }
        sum += nums[q];
        return q - p + 1 > windSize ? sum / windSize : sum / (q - p + 1);
    }
};

int main() {
    MovingAverage movingAverage(3);
    cout << movingAverage.next(1) << endl; // 返回 1.0 = 1 / 1
    cout << movingAverage.next(10) << endl; // 返回 5.5 = (1 + 10) / 2
    cout << movingAverage.next(3) << endl; // 返回 4.66667 = (1 + 10 + 3) / 3
    cout << movingAverage.next(5) << endl; // 返回 6.0 = (10 + 3 + 5) / 3
}