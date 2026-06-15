#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    BankAccount() {
        accountNumber = 0;
        holderName = "";
        balance = 0;
    }

    void createAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    virtual void display() {
        cout << "\nAccount Number : " << accountNumber << endl;
        cout << "Account Holder : " << holderName << endl;
        cout << "Balance : " << balance << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    void addInterest() {
        balance += balance * interestRate / 100;
        cout << "Interest Added Successfully!\n";
    }

    void display() override {
        BankAccount::display();
        cout << "Interest Rate : " << interestRate << "%\n";
    }
};

int main() {
    SavingsAccount accounts[100];
    int totalAccounts = 0;
    int choice;

    do {
        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Accounts\n";
        cout << "5. Add Interest\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            int accNo;
            string name;
            double balance, rate;

            cout << "Enter Account Number: ";
            cin >> accNo;
            cin.ignore();

            cout << "Enter Holder Name: ";
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            cin >> balance;

            cout << "Enter Interest Rate: ";
            cin >> rate;

            accounts[totalAccounts].createAccount(accNo, name, balance);
            accounts[totalAccounts].setInterestRate(rate);
            totalAccounts++;

            cout << "Account Created Successfully!\n";
        }

        else if (choice == 2) {
            int accNo;
            double amount;

            cout << "Enter Account Number: ";
            cin >> accNo;

            cout << "Enter Amount: ";
            cin >> amount;

            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i].getAccountNumber() == accNo) {
                    accounts[i].deposit(amount);
                }
            }
        }

        else if (choice == 3) {
            int accNo;
            double amount;

            cout << "Enter Account Number: ";
            cin >> accNo;

            cout << "Enter Amount: ";
            cin >> amount;

            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i].getAccountNumber() == accNo) {
                    accounts[i].withdraw(amount);
                }
            }
        }

        else if (choice == 4) {
            for (int i = 0; i < totalAccounts; i++) {
                accounts[i].display();
            }
        }

        else if (choice == 5) {
            int accNo;

            cout << "Enter Account Number: ";
            cin >> accNo;

            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i].getAccountNumber() == accNo) {
                    accounts[i].addInterest();
                }
            }
        }

    } while (choice != 0);

    cout << "\nThank You for Using Bank Management System!\n";
    return 0;
}
