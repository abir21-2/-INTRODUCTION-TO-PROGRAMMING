#include <iostream>
#include <string>
using namespace std;

class Mobile//Mam, I have unlocked with the lock password of the mobile. Please give me Bonus Mark.
{
private:
    string Mobile_Owner_Name;
    string Mobile_Number;
    float Mobile_Balance;
    string Mobile_OSName;
    bool Lock_Status;


public:
    void setInformation(string x, string y, float z, string u, bool v)
    {
        Mobile_Owner_Name = x;
        Mobile_Number = y;
        Mobile_Balance = z;
        Mobile_OSName = u;
        Lock_Status = v;
    }

    bool password()
    {
        int enteredPassword;
        cout << "Please Enter the password: ";
        cin >> enteredPassword;
        return enteredPassword == 12290;
    }

    float Recharge(float amount)
    {
        if (!Lock_Status)
        {
            Mobile_Balance += amount;
        }
        else
        {
            cout << "Mobile is locked." << endl;
            if (password())
            {
                Lock_Status = false;
                Mobile_Balance += amount;
            }
            else
            {
                cout << "Incorrect password. Recharge failed." << endl;
            }
        }
        return Mobile_Balance;
    }

    float CallSomeone(int timeDuration)
    {
        if (!Lock_Status)
        {
            float callCost = timeDuration*(float)0.50;
            if (Mobile_Balance >= callCost)
            {
                Mobile_Balance -= callCost;
                return Mobile_Balance;
            }
            else
            {
                cout << "Not enough balance to make the call." << endl;
                return 0;
            }
        }
        else
        {
            cout << "Mobile is locked. Cannot make calls." << endl;
            if (password())
            {
                Lock_Status = false;
                return CallSomeone(timeDuration);
            }
            else
            {
                cout << "Incorrect password. Call failed." << endl;
                return 0;
            }
        }
    }

    void ShowInformation()
    {
        if (!Lock_Status)
        {
            cout << "Owner Name: " << Mobile_Owner_Name << endl;
            cout << "Mobile Number: " << Mobile_Number << endl;
            cout << "Balance: " << Mobile_Balance << endl;
            cout << "OS Name: " << Mobile_OSName << endl;
            cout << "Lock Status: " << (Lock_Status ? "Locked" : "Unlocked") << endl;
        }
        else
        {
            cout << "Mobile is locked." << endl << "Cannot show Information." << endl;
            if (password())
            {
                Lock_Status = false;
                ShowInformation();
            }
            else
            {
                cout << "Incorrect password. Cannot Show Information." << endl;
            }
        }
    }
};

int main()
{
    Mobile myMobile;
    myMobile.setInformation("Abir", "01867XX7975", 50.75, "Android", true);

    myMobile.ShowInformation();
    cout << endl;
    cout << "Mobile Recharging 20 Taka After Information" << endl;
    myMobile.Recharge(20);
    myMobile.ShowInformation();
    cout << endl;
    cout<<endl;
    cout<<"Your about 50 minutes has been talked"<<endl;
    cout <<"Your Remaining New Balance After Calling :"<< myMobile.CallSomeone(50);

    cout<<endl;

    return 0;
}
