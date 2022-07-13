#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> planetStack;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (planetStack.empty()) {
                planetStack.emplace(asteroids[i]);
            }
            else {
                while (!planetStack.empty()) {
                    int topPlanet = planetStack.top();
                    if (asteroids[i] < 0 && topPlanet > 0) {
                        if (abs(asteroids[i]) > abs(topPlanet)) {
                            planetStack.pop();
                            if (planetStack.empty()) {
                                planetStack.emplace(asteroids[i]);
                                break;
                            }
                        }
                        else if (abs(asteroids[i]) == abs(topPlanet)) {
                            planetStack.pop();
                            break;
                        }
                        else {
                            break;
                        }
                    }
                    else {
                        planetStack.emplace(asteroids[i]);
                        break;
                    }
                }
            }
        }
        vector<int> res;
        while (!planetStack.empty()) {
            res.emplace_back(planetStack.top());
            planetStack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution S;
    vector<int> asteroids = { 1,-2,-2,-2 };
    auto res = S.asteroidCollision(asteroids);
    for (const auto& re : res) {
        cout << re << " ";
    }
}