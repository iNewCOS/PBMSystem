#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "date.h"
#include <string>

class SavingsAccount{  ///�洢�˻���
private:
	std::string id;//�ʺ�
	double balance;//���
	double rate;//����������
	Date lastDate;//�ϴα������ʱ��
	double accumulation;//�����ۼ�֮��
	static double total;//�����˻����ܽ��

	//��¼һ���ʣ�dateΪ���ڣ�amountΪ���
	void record(const Date &date, double amount, const std::string &desc);

	void error(const std::string &msg) const;
	//���ָ������Ϊֹ�Ĵ������ۼ�ֵ
	double accumulate(const Date &date) const{
		return accumulation + balance*date.distance(lastDate);
	}
public:
	SavingsAccount(const Date &date, const std::string &id, double rate);
	const std::string &getId()const {return id;}
	double getBalance()const {return balance;}
	double getRate()const {return rate;}
	static double getTotal() {return total;}
	void deposit (const Date &date, double amount, const std::string &desc);
	void withdraw(const Date &date, double amount, const std::string &desc);///ȡ���ֽ�
	void settle(const Date &date);///������Ϣ��ÿ��1��1�յ���һ�θú���.
	void show() const; ///��ʾ�˻���Ϣ
};
#endif //_ACCOUNT_H_