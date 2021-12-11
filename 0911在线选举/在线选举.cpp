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
        //���ֲ��ң������ǵݼ����� times �е�һ������ t ��ֵ
        int index = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return table[index];
    }
};
int main() {
    vector<int> persons = { 0, 1, 1, 0, 0, 1, 0 };
    vector<int> times = { 0, 5, 10, 15, 20, 25, 30 };
    TopVotedCandidate* topVotedCandidate = new TopVotedCandidate(persons, times);
    cout << topVotedCandidate->q(3) << endl; // ���� 0 ����ʱ�� 3 ��Ʊ���ֲ�Ϊ [0] �����Ϊ 0 �ĺ�ѡ�����ȡ�
    cout << topVotedCandidate->q(12) << endl; // ���� 1 ����ʱ�� 12 ��Ʊ���ֲ�Ϊ [0,1,1] �����Ϊ 1 �ĺ�ѡ�����ȡ�
    cout << topVotedCandidate->q(25) << endl; // ���� 1 ����ʱ�� 25 ��Ʊ���ֲ�Ϊ [0,1,1,0,0,1] �����Ϊ 1 �ĺ�ѡ�����ȡ�����ƽ�ֵ�����£�1 ��������ͶƱ�ĺ�ѡ�ˣ���
    cout << topVotedCandidate->q(15) << endl; // ���� 0
    cout << topVotedCandidate->q(24) << endl; // ���� 0
    cout << topVotedCandidate->q(8) << endl; // ���� 1
    return 0;
}