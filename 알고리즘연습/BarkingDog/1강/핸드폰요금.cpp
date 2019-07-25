#include <iostream>
using namespace std;

class Telecom
{
protected:
	int sec, unit;
public:
	Telecom(int _sec, int _unit) :sec(_sec), unit(_unit) {};
	virtual int getCharge(int use) {
		int total = ((use / sec) + 1) * unit;
		return total;
	};
};

class Minsik : public Telecom
{
public:
	Minsik(int _sec, int _unit) :Telecom(_sec, _unit) {};
};

class Yungsik : public Telecom
{
public:
	Yungsik(int _sec, int _unit) : Telecom(_sec, _unit) {};
};

int main() {
	int n;
	cin >> n;
	Minsik minsik(60, 15);
	Yungsik yungsik(30, 10);
	int m_total = 0, y_total = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		m_total += minsik.getCharge(a);
		y_total += yungsik.getCharge(a);
		
	}
	if (y_total < m_total) {
		cout << "Y " << y_total << endl;
	}
	else if(y_total == m_total) {
		cout << "Y M " << m_total << endl;
	}
	else {
		cout << "M " << m_total << endl;
	}
	
}