#include <iostream>
using namespace std;

class thnum
{
	private:
	int a;
	int b;
	int c;
	
	public:
	void seta(int num)
	{
		a=num;
    }
    void setb(int num)
    {
    	b=num;
	}
	void setc(int num)
	{
		c=num;
	}
	int geta()
	{
		return a;
	}
	int getb()
	{
		return b;
	}
	int getc()
	{
		return c;
	}
};

int main()
{
	thnum num1;
	int num;
	cin >> num;
	
	num1.seta(num/100);
	num%=100;
	num1.setb(num/10); 
	num%=10;
	num1.setc(num);
	
	cout << num1.geta() + num1.getb() + num1.getc();  
}
