#include<iostream>
#include<vector>
using namespace std;
class Bank {
private:
    vector<long long> Account;
public:
    Bank(vector<long long>& balance) {
        Account = balance;
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 - 1 >= Account.size() || account2 - 1 >= Account.size())
            return false;
        if (Account[account1 - 1] < money)
            return false;
        else {
            Account[account1 - 1] -= money;
            Account[account2 - 1] += money;
            return true;
        }
    }

    bool deposit(int account, long long money) {
        if (account - 1 >= Account.size())
            return false;
        Account[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account - 1 >= Account.size())
            return false;
        if (Account[account - 1] < money)
            return false;
        else {
            Account[account - 1] -= money;
            return true;
        }
    }
};
int main() {
    vector<long long> blance = { 10,100,20,50,30 };
    Bank bank(blance);
    bank.withdraw(3, 10);
    bank.transfer(5, 1, 20);
    bank.deposit(5, 20);
    bank.transfer(3, 4, 15);
    bank.withdraw(10, 50);
    return true;
}