#pragma once
#include <vector>

struct transformAlt
{
	float matrix[16] =

	{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1,
	};
};

class gameobjectAlt
{
public:
	transformAlt* local;

	int id;
};

class Week3Exercise2Alt
{
public:
	Week3Exercise2Alt();
	~Week3Exercise2Alt();

	void FillArray();
	void TimedModifyArray(int loopAmount);
	std::vector<float>& ReturnResults();


private:
	int stepsize{};
	const int length{ 10000000 };
	gameobjectAlt* arr = new gameobjectAlt[length];
	std::vector<float> results;

	

};

