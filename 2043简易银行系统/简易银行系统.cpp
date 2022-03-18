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
    bank.withdraw(3, 10);    // ���� true ���˻� 3 ������� $20 �����Կ���ȡ�� $10 ��
                             // �˻� 3 ���Ϊ $20 - $10 = $10 ��
    bank.transfer(5, 1, 20); // ���� true ���˻� 5 ������� $30 �����Կ���ת�� $20 ��
                             // �˻� 5 �����Ϊ $30 - $20 = $10 ���˻� 1 �����Ϊ $10 + $20 = $30 ��
    bank.deposit(5, 20);     // ���� true ���������˻� 5 ��� $20 ��
                             // �˻� 5 �����Ϊ $10 + $20 = $30 ��
    bank.transfer(3, 4, 15); // ���� false ���˻� 3 �ĵ�ǰ����� $10 ��
                             // �����޷�ת�� $15 ��
    bank.withdraw(10, 50);   // ���� false ��������Ч����Ϊ�˻� 10 �������ڡ�
    return 0;
}