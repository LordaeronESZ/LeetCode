#include<iostream>
#include<vector>
using namespace std;

class Bank {
private:
    vector<long long> accounts;
public:
    Bank(vector<long long>& balance) : accounts(balance) {}

    bool transfer(int account1, int account2, long long money) {
        int n = accounts.size();
        if (account1 <= 0 || account1 > n || account2 <= 0 || account2 > n || accounts[account1 - 1] < money)
            return false;
        accounts[account1 - 1] -= money;
        accounts[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        int n = accounts.size();
        if (account <= 0 || account > n)
            return false;
        accounts[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        int n = accounts.size();
        if (account <= 0 || account > n || accounts[account - 1] < money)
            return false;
        accounts[account - 1] -= money;
        return true;
    }
};
int main() {
    vector<long long> balance = { 10, 100, 20, 50, 30 };
    Bank bank(balance);
    bank.withdraw(3, 10);    // 返回 true ，账户 3 的余额是 $20 ，所以可以取款 $10 。
                             // 账户 3 余额为 $20 - $10 = $10 。
    bank.transfer(5, 1, 20); // 返回 true ，账户 5 的余额是 $30 ，所以可以转账 $20 。
                             // 账户 5 的余额为 $30 - $20 = $10 ，账户 1 的余额为 $10 + $20 = $30 。
    bank.deposit(5, 20);     // 返回 true ，可以向账户 5 存款 $20 。
                             // 账户 5 的余额为 $10 + $20 = $30 。
    bank.transfer(3, 4, 15); // 返回 false ，账户 3 的当前余额是 $10 。
                             // 所以无法转账 $15 。
    bank.withdraw(10, 50);   // 返回 false ，交易无效，因为账户 10 并不存在。
    return 0;
}