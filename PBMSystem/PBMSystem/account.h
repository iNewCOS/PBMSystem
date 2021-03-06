//account.h
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "date.h"
#include "Accumulator.h"
#include <string>

class Account {
private:
	std::string id;
	double balance;
	static double total;
protected:
	Account(const Date& date, const std::string &id);
	void record(const Date& date, double amount, const std::string &desc);
	void error(const std::string &msg) const;
public:
	const std::string &getid() const {return id;}
	double getBalance() const {return balance;}
	static double getTotal() {return total;}

	virtual void deposit(const Date& date, double amount, const std::string& desc)=0;
	//取出现金
	virtual void withdraw(const Date& date, double amount, const std::string& desc)=0;
	virtual void settle(const Date& date)=0; //解算利息和年费
	virtual void show()const;
};

class SavingsAccount:public Account {  ///存储账户类
private:
	Accumulator acc;
	double rate;//存款的年利率
public:
	SavingsAccount(const Date &date, const std::string &id, double rate);
	double getRate()const {return rate;}
	void deposit(const Date &date, double amount, const std::string &desc);
	void withdraw(const Date &date, double amount, const std::string &desc);///取出现金
	void settle(const Date &date);///结算利息，每年1月1日调用一次该函数.
};

class CreditAccount : public Account { // 信用卡
private:
	Accumulator acc;
	double credit;
	double rate;
	double fee;
	double getDebt() const {
		double balance = getBalance();
		return (balance<0? balance : 0);
	}
public:
	CreditAccount(const Date& date, const std::string& id, 
		double credit, double rate, double fee);
	double getCredit() const {return credit;}
	double getRate() const {return rate;}
	double getFee() const {return fee;}
	double getAvailableCredit() const {
		if(getBalance()<0)
			return credit+getBalance();
		else
			return credit;
	}
	//存入现金
	void deposit(const Date& date, double amount, const std::string& desc);
	//取出现金
	void withdraw(const Date& date, double amount, const std::string& desc);
	void settle(const Date& date); //解算利息和年费
	void show()const;
};
#endif //_ACCOUNT_H_