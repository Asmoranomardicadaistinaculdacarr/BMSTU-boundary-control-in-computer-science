8.5
#include <iostream>
#include <string>
#include <iomanip> 
#include <stdexcept> 
using namespace std

class BankAccount {
public:
    BankAccount(long long accountNumber, const string& ownerName, double balance)
        : accountNumber_(accountNumber), ownerName_(ownerName), balance_(balance) {
        if (balance_ < 0) {
            throw runtime_error("Initial balance cannot be negative.");
        }
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw runtime_error("Deposit amount must be positive.");
        }
        balance_ += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw runtime_error("Withdrawal amount must be positive.");
        }
        if (balance_ < amount) {
            throw runtime_error("Insufficient funds.");
        }
        balance_ -= amount;
    }

    double getBalance() const { return balance_; }

    long long getAccountNumber() const { return accountNumber_; }

    const string& getOwnerName() const { return ownerName_; }

    virtual void printInfo() const { 
        cout << "Номер счета: " << accountNumber_ << endl;
        cout << "Владелец: " << ownerName_ << endl;
        cout << "Баланс: " << std::fixed << setprecision(2) << balance_ << endl;
    }

protected:
    long long accountNumber_;
    string ownerName_;
    double balance_;
};


class SavingsAccount : public BankAccount {
public:
    SavingsAccount(long long accountNumber, const string& ownerName, double balance, double interestRate)
        : BankAccount(accountNumber, ownerName, balance), interestRate_(interestRate) {
        if (interestRate_ < 0) {
            throw runtime_error("Interest rate cannot be negative.");
        }
    }

    void accrueInterest() {
        double interest = balance_ * interestRate_;
        deposit(interest);
    }

    void printInfo() const override {
        BankAccount::printInfo();
        cout << "Процентная ставка: " << fixed << setprecision(2) << interestRate_ * 100 << "%" << endl;
    }

private:
    double interestRate_;
};


int main() {
    setlocale(LC_ALL, "Russian");
    try {
        BankAccount checkingAccount(1234567890, "Alice", 1000);
        SavingsAccount savingsAccount(9876543210, "Bob", 5000, 0.05);

        checkingAccount.deposit(500);
        checkingAccount.withdraw(200);
        savingsAccount.deposit(1000);
        savingsAccount.accrueInterest();
        savingsAccount.withdraw(500);

        cout << "Информация о счете checkingAccount:\n";
        checkingAccount.printInfo();
        cout << "\nИнформация о счете savingsAccount:\n";
        savingsAccount.printInfo();

    }
    catch (const runtime_error& error) {
        cerr << "Ошибка: " << error.what() << endl;
    }

    return 0;
}
