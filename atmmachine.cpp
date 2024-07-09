#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string pin;
    double balance;

public:
    BankAccount(const string &accNumber, const string &pinCode, double bal = 0.0)
        : accountNumber(accNumber), pin(pinCode), balance(bal) {}

    const string &getAccountNumber() const {
        return accountNumber;
    }

    const string &getPin() const {
        return pin;
    }

    double getBalance() const {
        return balance;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
};


bool readAccountsFromFile(const string& filename, const string& accNumber, const string& pin, BankAccount& account) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return false;
    }

    string fileAccNumber, filePin;
    double balance;
    while (file >> fileAccNumber >> filePin >> balance) {
        if (fileAccNumber == accNumber && filePin == pin) {
            account = BankAccount(fileAccNumber, filePin, balance);
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}


void writeAccountToFile(const string& filename, const BankAccount& account) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    file << account.getAccountNumber() << " " << account.getPin() << " " << account.getBalance() << endl;
    file.close();
}

bool login(BankAccount &account) {
    string enteredAccountNumber, enteredPIN;
    cout << "Enter account number: ";
    cin >> enteredAccountNumber;
    cout << "Enter PIN: ";
    cin >> enteredPIN;

    if (readAccountsFromFile("file.txt", enteredAccountNumber, enteredPIN, account)) {
        cout << "Login successful.\n********************************\n";
        return true;
    } else {
        cout << "Login failed. Incorrect account number or PIN.\n";
        return false;
    }
}

void displayMenu() {
    cout << "1. Check Balance\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Exit\n";
}

void performTransaction(BankAccount &account) {
    int choice;
    do {
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Balance: " << account.getBalance() << "\n";
                break;
            case 2: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                cout << "Deposit successful. New balance: " << account.getBalance() << "\n";
                break;
            }
            case 3: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (account.withdraw(amount)) {
                    cout << "Withdrawal successful. New balance: " << account.getBalance() << "\n";
                } else {
                    cout << "Insufficient funds.\n";
                }
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);
}

int main() {
    BankAccount account("", "", 0.0); 

    bool loggedIn = false;
    do {
        loggedIn = login(account);
    } while (!loggedIn);

    performTransaction(account);

    return 0;
}
