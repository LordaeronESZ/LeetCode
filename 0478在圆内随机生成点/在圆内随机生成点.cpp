#include<iostream>
#include<vector>
#include<random>
using namespace std;

class Solution {
private:
    mt19937 gen{ random_device{}() };
    uniform_real_distribution<double> dis;
    double xc, yc, r;

public:
    Solution(double radius, double x_center, double y_center) : dis(-radius, radius), xc(x_center), yc(y_center), r(radius) {}

    vector<double> randPoint() {
        while (true) {
            double x = dis(gen), y = dis(gen);
            if (x * x + y * y <= r * r) {
                return { xc + x, yc + y };
            }
        }
    }
};

int main() {
    double radius = 1.0;
    double x_center = 0.0;
    double y_center = 0.0;
    Solution* solution = new Solution(1.0, 0.0, 0.0);
    while (cin.get()) { 
       auto res = solution->randPoint();
       cout << res[0] << " " << res[1] << endl;
    }
}