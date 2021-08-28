#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
		string roman = "";
		while (num >= 1000) {
			roman += "M";
			num -= 1000;
			continue;
		}
		while (num >= 500) {
			if (num / 100 == 9) {
				roman += "CM";
				num -= 900;
				continue;
			}
			roman += "D";
			num -= 500;
		}
		while (num >= 100) {
			if (num / 100 == 4) {
				roman += "CD";
				num -= 400;
				continue;
			}
			roman += "C";
			num -= 100;
		}
		while (num >= 50) {
			if (num / 10 == 9) {
				roman += "XC";
				num -= 90;
				continue;
			}
			roman += "L";
			num -= 50;
		}
		while (num >= 10) {
			if (num / 10 == 4) {
				roman += "XL";
				num -= 40;
				continue;
			}
			roman += "X";
			num -= 10;
		}
		while (num >= 5) {
			if (num == 9) {
				roman += "IX";
				num -= 9;
				continue;
			}
			roman += "V";
			num -= 5;
		}
		while (num >= 1) {
			if (num == 4) {
				roman += "IV";
				num -= 4;
				continue;
			}
			roman += "I";
			num--;
		}
		return roman;
    }
};
int main() {
	int num;
	Solution S;
	while (true) {
		cin >> num;
		if (!num)
			break;
		string roman = S.intToRoman(num);
		cout << roman << endl;
	}
	return 0;
}