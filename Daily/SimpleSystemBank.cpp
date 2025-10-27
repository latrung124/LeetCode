#include <vector>
using namespace std;

class Bank {
private:
    int customers;
    vector<long long>bal;

    bool isValid(int acc){
        return (acc>=1 && acc<=customers);
    }

    bool moneyValid(int acc, long long money){
        return (bal[acc-1]>=money);
    }

public:
    Bank(vector<long long>& balance) {
        customers = balance.size();
        bal.resize(customers);
        for(int i=0;i<customers;++i)bal[i] = balance[i];
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!isValid(account1) || !isValid(account2))return false;
        if(!moneyValid(account1,money))return false;
        bal[account1-1]-=money;
        bal[account2-1]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!isValid(account))return false;
        bal[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isValid(account))return false;
        if(!moneyValid(account, money))return false;
        bal[account-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */