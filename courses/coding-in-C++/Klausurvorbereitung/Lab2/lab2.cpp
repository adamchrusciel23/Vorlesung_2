#include <iostream>
#include <string>

class BankAccount {
    private:
        std::string owner;
        double balance = 0;

    public:
        void setOwner(const std::string& owner) {
            this->owner = owner;
        }

        std::string getOwner() const {
            return owner;
        }

        void deposit(double amount) {
            if(amount > 0) {
                balance +=amount;
            }
            else {
                std::cout << "Amount has to be a positive Number\n";
            }
        }

        void withdraw(double amount) {
            if (amount > 0 && balance >= amount) {
                balance -= amount;
            }
            else {
                std::cout << "Entweder keine Positive Zahl oder zu viel versucht abzuheben\n";
            }
        }

        double getBalance() const;

        void getAccountInfo() const;
};

double BankAccount::getBalance() const {
    return balance;
}
void BankAccount::getAccountInfo() const {
    std::cout << "Inhaber: " << owner << "\nKontostand: " << balance << "\n";
} 

class Note {
    private: 
        std::string* text;
    
    public:
        Note(std::string text) {
            this->text = new std::string(text);
        }

        Note(const Note& note) {
            this->text = new std::string(*note.text);
        }

        ~Note() {
            delete text;
            text = nullptr;
            std::cout << "Memory released\n";
        }

        void display() {
            std::cout << *text << "\n";
        }
}; 

int main() {
    Note note1 = Note("123");
    Note note2 = note1;
    note1.display();
    note2.display();
}