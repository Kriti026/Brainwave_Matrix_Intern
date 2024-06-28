#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Account {
public:
  string name;
  double balance;

  
  Account(const string& name, double balance) {
    this->name = name;
    this->balance = balance;
  }

  
  void displayInfo() {
    cout << "Name: " << name << endl;
    cout << "Balance: $" << balance << endl;
  }

  
  void deposit(double amount) {
    balance += amount;
    cout << "Deposit successful! New balance: $" << balance << endl;
  }

  
  void withdraw(double amount) {
    balance -= amount;
    cout << "Withdrawal successful! New balance: $" << balance << endl;
  }
};


int main() {
  vector<Account> accounts;

  int choice;

  
  do {
    cout << "\nWelcome to Online Banking!" << endl;
    cout << "1. Create a new account" << endl;
    cout << "2. Login to your account" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); 

    switch (choice) {
      case 1:
        
        {
          string name;
          double balance;

          cout << "\nCreate a New Account" << endl;
          cout << "Enter your name: ";
          getline(cin, name);

          cout << "Enter initial deposit amount: ";
          cin >> balance;
          cin.ignore(); 

          accounts.push_back(Account(name, balance));
          cout << "Account created successfully!" << endl;
        }
        break;
      case 2:
        
        {
          string username;

          cout << "\nLogin to Your Account" << endl;
          cout << "Enter username: ";
          getline(cin, username);

          int foundIndex = -1;
          for (int i = 0; i < accounts.size(); ++i) {
            if (accounts[i].name == username) {
              foundIndex = i;
              break;
            }
          }

          if (foundIndex != -1) {
            
            accounts[foundIndex].displayInfo();

            int innerChoice;
            do {
              cout << "\n1. Deposit funds" << endl;
              cout << "2. Withdraw funds" << endl;
              cout << "3. Back to main menu" << endl;
              cout << "Enter your choice: ";
              cin >> innerChoice;
              cin.ignore(); 

              switch (innerChoice) {
                case 1:
                  cout << "Enter amount to deposit: ";
                  double depositAmount;
                  cin >> depositAmount;
                  cin.ignore();
                  accounts[foundIndex].deposit(depositAmount);
                  break;
                case 2:
                  cout << "Enter amount to withdraw: ";
                  double withdrawAmount;
                  cin >> withdrawAmount;
                  cin.ignore();
                  accounts[foundIndex].withdraw(withdrawAmount);
                  break;
                case 3:
                  break;
                default:
                  cout << "Invalid choice. Please try again." << endl;
              }
            } while (innerChoice != 3);
          } else {
            cout << "Username not found." << endl;
          }
        }
        break;
      case 3:
        cout << "\nThank you for using Online Banking! Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 3); 

  return 0;
}
