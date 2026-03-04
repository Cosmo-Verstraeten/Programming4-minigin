#pragma once
#include <vector>


class Week3Exercise1
{
public:
	Week3Exercise1();
	~Week3Exercise1();

	void FillArray();
	void TimedModifyArray(int loopAmount);
	std::vector<float>& ReturnResults();


private:
	int stepsize{};
	const int length{ 10000000 };
	int* arr = new int[length];
	std::vector<float> results;

	

};

