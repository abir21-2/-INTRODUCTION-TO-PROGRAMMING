#include<iostream>
#include<string>
using namespace std;

class Account
{
private:
    string Account_Name;
    int Account_No;
    float Balance;
    string Account_Type;

public:
    void setInformation(string x, int y, float z, string w)
    {
        Account_Name = x;
        Account_No = y;
        Balance = z;
        Account_Type = w;
    }
    void showAccountDetails()
    {
        cout << "Account Name: " << Account_Name << endl;
        cout << "Account No: " << Account_No << endl;
        cout << "Balance : " << Balance << endl;
        cout << "Account Type: " << Account_Type << endl;
    }

    float deposit(int amount)
    {
        Balance += amount;
        return Balance;
    }
    float withdraw(int amount)
    {
        if (Balance >= amount)
        {
            Balance -= amount;
            return Balance;
        }
        else
        {
            cout << "Insufficient Balance " << endl;
            return Balance;
        }
    }
    void transfer(int amount, Account &receiver )
    {
        if (Balance >= amount)
        {
            withdraw(amount);
            receiver.deposit(amount );
            cout << "Transfer Successful " << endl;
        }
        else
        {
            cout << "Insufficient Balance for Transfer" << endl;
        }
    }
};

int main()
{
    Account person1, person2;

    person1.setInformation("Abir",111, 18000.0, "Student");
    person2.setInformation("Hasan",222, 15000.0, "Business");
    cout << "***********Initial Account Details***********" << endl;
    person1.showAccountDetails();
    cout<<endl;
    person2.showAccountDetails();
    cout<<endl;
    cout << "1st Person Deposit In The Bank" << endl;
    cout << "Balance: " << person1.deposit(1500) << endl;

    cout << "2nd Person withdraw In The Bank" << endl;
    cout << "Balance: " << person2.withdraw(1000) << endl;

    cout << "1st Person Transfer To 2nd Person" << endl;
    person1.transfer(2000,person2 );

    cout << "********Updated Account Details********" << endl;
    cout<<endl;
    person1.showAccountDetails();
    cout<<endl;
    person2.showAccountDetails();

    return 0;
}
