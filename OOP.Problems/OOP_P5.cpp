#include "OOP_P5.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
/*
* Problem Statement
Develop a class that contains an internal helper. The helper should do something important, and the main class should rely on it to complete a task.
*/
class Helper {
public:
	int sum(vector<int> v) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) sum += v[i];
		return sum;
	}
};
class Average {
public:
	vector<int> numbers;
	Helper helper;
	Average(vector<int>& v) {
		numbers = v;
	}
	void CalcAverage() {
		int sum = helper.sum(numbers);
		cout << sum / numbers.size() << endl;
	}
};
/*
int main() {
	vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	Average average(v);
	average.CalcAverage();
}
*/