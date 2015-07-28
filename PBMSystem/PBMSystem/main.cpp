#include <iostream>
#include "account.h"

using namespace std;

int main(){
	Date date(2014, 11 ,1);
	///建立几个账户
	SavingsAccount accounts[] = {
		SavingsAccount(date, "03755217", 0.015),
		SavingsAccount(date, "02342342", 0.015)
	};
	const int n = sizeof(accounts)/sizeof(SavingsAccount);
		///几笔账目
	accounts[0].deposit(Date(2014,11,5),5000,"salary");
	accounts[1].deposit(Date(2014,11,25),10000,"sell stock 0232");
	accounts[0].deposit(Date(2014,12,5),5500,"salary");
	accounts[1].withdraw(Date(2014,12,20),4000,"buy a laptop");
	cout << endl;

	for (int i=0; i<n; i++){
		accounts[i].settle(Date(2015,1,1));
		accounts[i].show();
		cout << endl;
	}

	cout << "Total: " << SavingsAccount::getTotal() << endl;
	return 0;
}


