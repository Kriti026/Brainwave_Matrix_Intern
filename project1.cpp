//atm interface
#include<iostream>
#include<string>
using namespace std;
class ATM {
    private:
    int accountnumber;
    int pin;
    double balance;

    public:
    ATM(int accountnumber,int pin,double balance){
        this->accountnumber=accountnumber;
        this->pin=pin;
        this->balance=balance;
    }
    // welcome
    void greetings(){
        cout<<"hello user"<<endl;
    }
    
    //withdraw amount
    void withdraw(double amount){
        if(amount<=balance){
            balance=balance-amount;
            cout<<"withdrawal successful ,your new balance is"<<balance<<endl;
        }
        else{
            cout<<"insufficient balance"<<endl;
        }
    }
    //deposite amount
    void deposite(double amount){
        balance=balance+amount;
        cout<<"deposite successful, your new balance is"<<balance<<endl;
    }
    double getbalance(){
        return balance;
    }

    //display menue
    void displaymenu(){
        cout<<"1.withdraw"<<endl;
        cout<<"2.deposite"<<endl;
        cout<<"3.check balance"<<endl;
        cout<<"4.exit"<<endl;

    }
    //process
    void processtransaction(){
        int choice;
        double amount;

        displaymenu();
        cout<<"enter your choice"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"enter the amount"<<endl;
            cin>>amount;
            withdraw(amount);
            break;

             case 2:
            cout<<"your balance"<<endl;
            cin>>amount;
            deposite(amount);
            break;

             case 3:
            cout<<"your balance is"<<balance<<endl;
            break;
            
            

             case 4:
             exit(0);
            break;
            default:
            cout<<"invalid choice"<<endl;
        }
    }


};
int main(){
    int accountnumber;
    cout<<"enter acc no"<<endl;
    cin>>accountnumber;
    double balance=10000;

    int pin;
    cout<<"enter pin"<<endl;
    cin>>pin;


    ATM atm(accountnumber,pin,balance);
    atm.processtransaction();
    return 0;
}

