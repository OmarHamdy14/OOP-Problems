#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
* Problem Statement
Develop a class that contains an internal helper. The helper should do something important, 
and the main class should rely on it to complete a task.
*/
class Helper {
public:
	int sum(vector<int>& v) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) sum += v[i];
		return sum;
	}
};
class Average {
	vector<int> numbers;
	Helper& helper; // how to use "const" here ?
public:
	Average(Helper& hlp) {       // why error here ??
		helper = hlp;
	}
	void AddNum(int& x) { // will it make a copy if i dont use "&" ?
		numbers.push_back(x);
	}
	void CalcAverage() {
		int sum = helper.sum(numbers);
		cout << sum / numbers.size() << endl;
	}
};