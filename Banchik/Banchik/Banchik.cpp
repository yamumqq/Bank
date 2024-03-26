#include <iostream>
#include <iomanip>

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNum, double initBalance) : accountNumber(accNum), balance(initBalance), interestRate(0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "На счет положено: " << std::fixed << std::setprecision(2) << amount << " успешно." << std::endl;
        }
        else {
            std::cout << "Неверная сумма пополнения." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Снятие со счета размером: " << std::fixed << std::setprecision(2) << amount << " прошло успешно." << std::endl;
        }
        else {
            std::cout << "Неправильное снятие или недостаточно средств." << std::endl;
        }
    }

    void transfer(BankAccount& toAccount, double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            toAccount.balance += amount;
            std::cout << "Перевод суммой: " << std::fixed << std::setprecision(2) << amount << " прошел успешно." << std::endl;
        }
        else {
            std::cout << "Неправильный перевод или недостаточно средств." << std::endl;
        }
    }

    double getBalance() {
        return balance;
    }

    void setInterestRate(double newRate) {
        interestRate = newRate;
        std::cout << "Процентная ставка: " << newRate * 100 << "%\n";
    }

    double getInterest() {
        return balance * interestRate * (1.0 / 12);
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    BankAccount account1(12345, 1000.0);
    BankAccount account2(54321, 500.0);
    setlocale(LC_ALL, "Russian");

    int accountChoice;
    double amount;

    while (true) {
        std::cout << "Выберите аккаунт с которым хотите взаимодействовать:\n";
        std::cout << "1. Аккаунт 1\n";
        std::cout << "2. Аккаунт 2\n";
        std::cout << "3. Выйти из программы\n";

        std::cin >> accountChoice;

        if (accountChoice == 1) {
            std::cout << "Баланс Аккаунта 1: " << account1.getBalance() << "\n";
        }
        else if (accountChoice == 2) {
            std::cout << "Баланс Аккаунта 2: " << account2.getBalance() << "\n";
        }
        else if (accountChoice == 3) {
            std::cout << "Программа прекращена.\n";
            break;
        }
        else {
            std::cout << "Неверный выбор аккаунта.\n";
            continue;
        }

        int choice;
        std::cout << "Выберите операцию:\n";
        std::cout << "1. Перевести средства\n";
        std::cout << "2. Положить средства\n";
        std::cout << "3. Вернуться в меню выбора аккаунтов\n";

        std::cin >> choice;

        if (choice == 1) {
            if (accountChoice == 1) {
                std::cout << "Введите сумму которую котите перевести на аккаунт 2: ";
                std::cin >> amount;
                account1.transfer(account2, amount);
            }
            else if (accountChoice == 2) {
                std::cout << "Введите сумму которую котите перевести на аккаунт 2: ";
                std::cin >> amount;
                account2.transfer(account1, amount);
            }
        }
        else if (choice == 2) {
            if (accountChoice == 1) {
                std::cout << "Введите сумму пополнения на аккаунт 1: ";
                std::cin >> amount;
                account1.deposit(amount);
            }
            else if (accountChoice == 2) {
                std::cout << "Введите сумму пополнения на аккаунт 2: ";
                std::cin >> amount;
                account2.deposit(amount);
            }
        }
        else if (choice == 3) {
            std::cout << "Возврат к выбору аккаунтов.\n";
        }
        else {
            std::cout << "Неверный выбор операции.\n";
        }
    }

    return 0;
}