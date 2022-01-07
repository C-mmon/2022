#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class cerner_testing
{
int acno;
string AccountHolderName, Account_Type;
double bal;  
public:
cerner_testing(int acc_no, string name, string acc_type, double Balance)  //Parameterized Constructor
{
acno=acc_no;
AccountHolderName=name;
Account_Type=acc_type;
bal=Balance;
}
void deposit();
void withdraw();
void Show();
};
void cerner_testing::deposit()   //depositing an amount
{
int DepositAmmount1;
cout<<" Enter Deposit Amount = "<<endl;
cin>>DepositAmmount1;
bal+=DepositAmmount1;
}
void cerner_testing::withdraw()  //withdrawing an amount
{
int WithdrawAmmount1;
cout<<" Enter Withdraw Amount = "<<endl;
cin>>WithdrawAmmount1;
if(WithdrawAmmount1>bal)
cout<<" Cannot Withdraw Amount"<<endl;
bal-=WithdrawAmmount1;
}
void cerner_testing::Show()  //Showing the details
{
cout<<" *****"<<endl;
cout<<" Accout No. : "<<acno;
cout<<" Name : "<<AccountHolderName;
cout<<" Account Type : "<<Account_Type;
cout<<" Balance : "<<bal;  
}
int main()
{
int acc_no;
string name, acc_type;
double Balance;
cout<<" Enter Details: "<<endl;
cout<<"*****"<<endl;
cout<<" Accout No. "<<endl;
cin>>acc_no;
cout<<" Name : "<<endl;
cin>>name;
cout<<" Account Type : "<<endl;
cin>>acc_type;
cout<<" Balance : "<<endl;
cin>>Balance;
cerner_testing b1(acc_no, name, acc_type, Balance);  //object is created

b1.deposit(); //
b1.withdraw(); 
b1.Show(); //
return 0;
}
