#include <iostream>
using namespace std;

class Account {
private:
    string AN;
    double Balance;

public:
    Account(string accNum, double bal) : AN(accNum), Balance(bal) {}
    friend void transferFunds(Account &A1,Account &A2,double amount);
    friend class Manager;
};

class Manager {
public:
    void displayDetails(Account &a) {
        cout << "Account Number: " << a.AN << "\nBalance: " << a.Balance << "\n";
    }

    void deposit(Account &a, double amount) {
        if (amount > 0) {
            a.Balance += amount;
            cout << "Deposited: " << amount << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(Account &a, double amount) {
        if (amount > 0 && a.Balance >= amount) {
            a.Balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        } else {
            cout << "Invalid or insufficient funds for withdrawal.\n";
        }
    }
};

// Friend function to transfer funds between two accounts
void transferFunds(Account &from, Account &to, double amount) {
    if (amount > 0 && from.Balance >= amount) {
        from.Balance -= amount;
        to.Balance += amount;
        cout << "Transferred " << amount << " from " << from.AN << " to " << to.AN << ".\n";
    } else {
        cout << "Transfer failed: Insufficient balance or invalid amount.\n";
    }
}

int main() {
    Account A1("A216", 60000);
    Account A2("B789", 20000);
    Manager M;

    M.displayDetails(A1);
    M.displayDetails(A2);

    cout << "\nDepositing 5000 into A1:\n";
    M.deposit(A1, 5000);

    cout << "\nWithdrawing 3000 from A2:\n";
    M.withdraw(A2, 3000);

    cout << "\nTransferring 10000 from A1 to A2:\n";
    transferFunds(A1, A2, 10000);

    M.displayDetails(A1);
    M.displayDetails(A2);

    return 0;
}
