#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
	int reverse(int x)
	{
		long result = 0;
		while (x)
		{
			result = result * 10 + x % 10;
			x /= 10;
		}
		if (abs(result) > INT_MAX)
			return 0;
		return result;
	}
};
int main() {
    int x;
    cin >> x;
    Solution S;
    int result = S.reverse(x);
    cout << result << endl;
    return 0;
}