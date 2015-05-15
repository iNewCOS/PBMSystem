#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class SavingsAccount{  ///�洢�˻���
private:
	int id;//�ʺ�
	double balance;//���
	double rate;//����������
	int lastDate;//�ϴα������ʱ��
	double accumulation;//�����ۼ�֮��
	static double total;//�����˻����ܽ��

	//��¼һ���ʣ�dateΪ���ڣ�amountΪ���
	void record(int date, double amount);
	//���ָ������Ϊֹ�Ĵ������ۼ�ֵ
	double accumulate(int date) const{
		return accumulation + balance*(date-lastDate);
	}
public:
	SavingsAccount(int date, int id, double rate);
	int getId()const {return id;}
	double getBalance()const {return balance;}
	double getRate()const {return rate;}
	static double getTotal() {return total;}
	void deposit(int date, double amount); ///�����ֽ�
	void withdraw(int date, double amount);///ȡ���ֽ�
	void settle(int date);///������Ϣ��ÿ��1��1�յ���һ�θú���.
	void show() const ;///��ʾ�˻���Ϣ
};
#endif //_ACCOUNT_H_