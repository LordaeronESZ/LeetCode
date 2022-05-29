#include<iostream>
#include<string>
using namespace std;

class Solution {
private:
    bool isIPv4(const string& ip) {
        int start = 0, pointCnt = 0;
        for (int i = 0; i < ip.size(); ++i) {
            pointCnt += ip[i] == '.';
            if (!isdigit(ip[i]) && ip[i] != '.')
                return false;
            if (ip[i] == '.' || i == ip.size() - 1) {
                string temp = ip.substr(start, i - start);
                start = i + 1;
                if (temp.size() > 1 && temp[0] == '0')
                    return false;
                int tempi = stoi(temp);
                if (tempi < 0 || tempi > 255)
                    return false;
            }
        }
        return pointCnt == 3;
    }
    bool isIPv6(const string& ip) {
        int start = 0, pointCnt = 0;
        for (int i = 0; i < ip.size(); ++i) {
            pointCnt += ip[i] == ':';
            if (!isdigit(ip[i]) && ip[i] != ':' && !(tolower(ip[i]) >= 'a' && tolower(ip[i]) <= 'f'))
                return false;
            if (ip[i] == ':' || i == ip.size() - 1) {
                string temp = ip.substr(start, i - start);
                start = i + 1;
                if (temp.size() > 4)
                    return false;
            }
        }
        return pointCnt == 7;
    }
public:
    string validIPAddress(string queryIP) {
        if (isIPv4(queryIP)) return "IPv4";
        else if (isIPv6(queryIP)) return "IPv6";
        else return "Neither";
    }
};

int main() {
    Solution S;
    string queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    auto res = S.validIPAddress(queryIP);
    cout << res << endl;
}