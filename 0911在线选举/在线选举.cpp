#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class TopVotedCandidate {
private:
    vector<int> times;
    vector<int> table;
    unordered_map<int, int> voteMap;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        this->table.assign(persons.size(), 0);
        int maxVotes = 0;
        for (int i = 0; i < persons.size(); i++) {
            voteMap[persons[i]]++;
            if (voteMap[persons[i]] >= maxVotes) {
                maxVotes = voteMap[persons[i]];
                table[i] = persons[i];
            }
            else if (i > 0) {
                table[i] = table[i - 1];
            }
        }
    }

    int q(int t) {
        //二分查找，搜索非递减序列 times 中第一个大于 t 的值
        int index = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return table[index];
    }
};
int main() {
    vector<int> persons = { 0, 1, 1, 0, 0, 1, 0 };
    vector<int> times = { 0, 5, 10, 15, 20, 25, 30 };
    TopVotedCandidate* topVotedCandidate = new TopVotedCandidate(persons, times);
    cout << topVotedCandidate->q(3) << endl; // 返回 0 ，在时刻 3 ，票数分布为 [0] ，编号为 0 的候选人领先。
    cout << topVotedCandidate->q(12) << endl; // 返回 1 ，在时刻 12 ，票数分布为 [0,1,1] ，编号为 1 的候选人领先。
    cout << topVotedCandidate->q(25) << endl; // 返回 1 ，在时刻 25 ，票数分布为 [0,1,1,0,0,1] ，编号为 1 的候选人领先。（在平局的情况下，1 是最近获得投票的候选人）。
    cout << topVotedCandidate->q(15) << endl; // 返回 0
    cout << topVotedCandidate->q(24) << endl; // 返回 0
    cout << topVotedCandidate->q(8) << endl; // 返回 1
    return 0;
}