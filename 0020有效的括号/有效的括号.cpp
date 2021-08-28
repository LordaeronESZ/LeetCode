#include<iostream>
#include<string>
#include<regex>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
		regex* reg1 = new regex("\\(\\)");
		regex* reg2 = new regex("\\[\\]");
		regex* reg3 = new regex("\\{\\}");
		while (!s.empty())
		{
			if (regex_search(s, *reg1))
				s = regex_replace(s, *reg1, "");
			else if (regex_search(s, *reg2))
				s = regex_replace(s, *reg2, "");
			else if (regex_search(s, *reg3))
				s = regex_replace(s, *reg3, "");
			else
				return false;
		}
		return true;
    }
};
int main() {
	Solution S;
	string s = "([)]";
	cout << S.isValid(s) << endl;
}