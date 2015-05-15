#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class SavingsAccount{  ///存储账户类
private:
	int id;//帐号
	double balance;//余额
	double rate;//存款的年利率
	int lastDate;//上次变更余额的时间
	double accumulation;//余额按日累加之和
	static double total;//所有账户的总金额

	//记录一笔帐，date为日期，amount为金额
	void record(int date, double amount);
	//获得指定日期为止的存款金额按日累计值
	double accumulate(int date) const{
		return accumulation + balance*(date-lastDate);
	}
public:
	SavingsAccount(int date, int id, double rate);
	int getId()const {return id;}
	double getBalance()const {return balance;}
	double getRate()const {return rate;}
	static double getTotal() {return total;}
	void deposit(int date, double amount); ///存入现金
	void withdraw(int date, double amount);///取出现金
	void settle(int date);///结算利息，每年1月1日调用一次该函数.
	void show() const ;///显示账户信息
};
#endif //_ACCOUNT_H_