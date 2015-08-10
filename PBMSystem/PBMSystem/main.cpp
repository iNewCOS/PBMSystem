#include <iostream>
#include "account.h"

using namespace std;

int main(){
	Date date(2008, 11 ,1);
	///建立几个账户
	SavingsAccount sa1(date, "S3755217", 0.015);
	SavingsAccount sa2(date, "02342342", 0.015);
	CreditAccount  ca(date,  "C3752357", 10000, 0.0005, 50);
	///几笔账目
	sa1.deposit(Date(2008,11,5),5000,"salary");
	ca.withdraw(Date(2008,11,15), 2000, "buy a cell");
	sa2.deposit(Date(2008,11,25),10000,"sell stock 0232");
	//结算信用卡
	ca.settle(Date(2008,12,1));
	//12月份几笔账目
	ca.deposit(Date(2008,12,1),2016,"repay the credit");
	sa1.deposit(Date(2008,12,5),5500,"salary");

	//结算所以帐户
	sa1.settle(Date(2009,1,1));
	sa2.settle(Date(2009,1,1));
	ca.settle(Date(2009,1,1));
	cout << endl;

	sa1.show();cout<<endl;
	sa2.show();cout<<endl;
	ca.show();cout<<endl;

	cout << "Total: " << SavingsAccount::getTotal() << endl;
	return 0;
}


