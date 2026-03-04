#pragma once
#include <vector>

struct transform
{
	float matrix[16] =

	{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1,
	};
};

class gameobject
{
public:
	transform local;

	int id;
};

class Week3Exercise2
{
public:
	Week3Exercise2();
	~Week3Exercise2();

	void FillArray();
	void TimedModifyArray(int loopAmount);
	std::vector<float>& ReturnResults();


private:
	int stepsize{};
	const int length{ 10000000 };
	gameobject* arr = new gameobject[length];
	std::vector<float> results;

	

};

