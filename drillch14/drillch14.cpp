#include <iostream>

using namespace std;
class pB1
{
public:
	virtual void pvf() = 0;

};
class B1:public pB1
{
public:
	virtual void vf()
	{
		cout<<"B1::vf()"<<endl;
	}
	void f()
	{
		cout << "B1::f()" << endl;
	}
	void pvf()
	{
		cout << "B1::pvf()" << endl;

	}
	
	
};

class D1:public B1
{
public:
	void vf()
	{
		cout << "D1::vf()" << endl;
	}
	void f()
	{
		cout << "D1::f()" << endl;

	}
	void pvf()
	{
		cout << "D1::pvf()" << endl;

	}
};
class D2 :public D1
{
public:
	
	void pvf()
	{
		cout << "D2::pvf()" << endl;

	}
};
class B2 
{
public:

	virtual void pvf() = 0;
	
};
class D21 :public B2
{
	string s = "nyaaa";
public:
	void pvf()
	{

		cout << s << endl;
	}

};
class D22 :public B2
{
	int i = 2;
public:
	void f(B2& qwe)
	{
		qwe.pvf();
		
	}
	void pvf()
	{
		cout << i << endl;
	}
};
int main()
{
	B1 asd;
	asd.vf();
	asd.f();
	D1 asd1;
	asd1.vf();
	asd1.f();
	B1& nya = asd1;
	nya.vf();
	nya.f();
	D2 nya1;
	nya1.vf();
	nya1.f();
	nya1.pvf();
	D21 qwert;
	D22 íyxc;
	íyxc.f(qwert);
	return 0;
}
