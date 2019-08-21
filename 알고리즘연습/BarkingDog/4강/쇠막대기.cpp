#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Iron
{
private:
	string Data;
	stack<char> Stick;

public:
	Iron(){}
	int NumOfIron(string& Input);

private:
	bool IsLaser(char Prev, char Cur);
};

bool Iron::IsLaser(char Prev, char Cur)
{
	if (Prev == '(' && Cur == ')') return true;
	else return false;
}

int Iron::NumOfIron(string& Input)
{
	Data = Input;
	int TotalNum = 0;
	if (Data[0] == '(') {
		TotalNum++;
		Stick.push(Data[0]);
	}
	char Prev = Data[0], Cur;
	
	for (int i = 1; i < Data.size(); i++) {
		Cur = Data[i];
		if (Cur == '(') {
			TotalNum++;
			Stick.push(Cur);
		}
		else {
			//·¹ÀÌÀú
			if (IsLaser(Prev,Cur)) {
				Stick.pop();
				TotalNum += Stick.size() - 1;
			}
			else {
				Stick.pop();
			}
		}
		Prev = Cur;
	}

	return TotalNum;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string Input;
	cin >> Input;
	Iron iron;
	cout << iron.NumOfIron(Input) << "\n";
}