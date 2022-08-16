#include<iostream>
#include<vector>
#include<string>
using namespace std;

class OrderedStream {
private:
    vector<string> strs;
    int ptr;
public:
    OrderedStream(int n) {
        strs.assign(n, "");
        ptr = 1;
    }

    vector<string> insert(int idKey, string value) {
        vector<string> res;
        strs[idKey - 1] = value;
        if (idKey == ptr) {
            while (ptr - 1 < strs.size() && !strs[ptr - 1].empty()) {
                res.emplace_back(strs[ptr - 1]);
                ++ptr;
            }
        }
        return res;
    }
};

int main() {
    OrderedStream os(5);
    os.insert(3, "ccccc"); // ���� (3, "ccccc")������ []
    os.insert(1, "aaaaa"); // ���� (1, "aaaaa")������ ["aaaaa"]
    os.insert(2, "bbbbb"); // ���� (2, "bbbbb")������ ["bbbbb", "ccccc"]
    os.insert(5, "eeeee"); // ���� (5, "eeeee")������ []
    os.insert(4, "ddddd"); // ���� (4, "ddddd")������ ["ddddd", "eeeee"]
}