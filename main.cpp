#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>

using namespace std;

class Account{
public:
    //Constructor with argument list of int, string and double
    Account(int AN,string AO,double AB){
        accountNumber = AN;
        accountOwner = AO;

        if(AB<0){
            accountBalance=0;
            cout << "Initial balance was invalid";
        }else{
            accountBalance = AB;
        }

    }

    void credit(double amnt){
        accountBalance = accountBalance + amnt;
    }

    void debit(double withdraw){
        if(withdraw>accountBalance){
            cout << "Debit amount exceeded account balance.";
        }else{
            accountBalance = accountBalance - withdraw;
        }
    }

    const double getBalance(){
        cout << accountBalance;
        return accountBalance;

    }

private:
    int accountNumber;
    string accountOwner;

protected:
    double accountBalance;
};

class SavingsAccount : public Account{
public:
    SavingsAccount(int AN,string AO,double AB,double IR) : Account(AN, AO, AB) {
        interestRate = IR;
    }

    double calculateInterest(){
        return interestRate * accountBalance;

    }

private:
    double interestRate;
};

class CheckingAccount : public Account{
public:
    CheckingAccount(int AN,string AO,double AB,double f) : Account(AN, AO, AB){
        fee = f;
    }
    void credit(double amnt){
        accountBalance = accountBalance + amnt - fee;
    }

    //Case not considered in assignemnt: Sum of withdraw amount and fee exceeds the accountBalance
    void debit(double withdraw){
        if(withdraw>accountBalance){
            cout << "Debit amount exceeded account balance.";
        }else{
            accountBalance = accountBalance - withdraw - fee;
        }
    }
private:
    double fee;
};
int main(){
    vector<Account*>accounts(5);
    accounts[0] = new SavingsAccount(1010, "Owner_1", 10000, .03);
    accounts[1] = new SavingsAccount(4949, "Owner_2", 15000, .03);
    accounts[2] = new SavingsAccount(2222, "Owner_3", 20000, .03);
    accounts[3] = new CheckingAccount(3060, "Owner_4", 17500, .05);
    accounts[4] = new CheckingAccount(4040, "Owner_5", 12500, .05);
    for(size_t i=0;i<accounts.size(); i++){
        cout << "Account number " << i+1 << " Currently has a blance of:$ " << accounts[i]->getBalance() << endl;
    }
    accounts[3]->debit(100);
    cout << "After applying debit value of 100 the balance for the 4th account is " << accounts[3]->getBalance() << endl;
}
