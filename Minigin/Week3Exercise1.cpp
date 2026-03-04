
#include "Week3Exercise1.h"
#include <chrono>

Week3Exercise1::Week3Exercise1()
{
	FillArray();
}

Week3Exercise1::~Week3Exercise1()
{
	delete[] arr;
}

void Week3Exercise1::FillArray()
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = i;
	}
}

void Week3Exercise1::TimedModifyArray( int loopAmount)
{
	for (stepsize = 1; stepsize <= 1024; stepsize *= 2)
	{
		float totalTime = 0.0f;

		for (int amount = 0; amount < loopAmount; amount++)
		{
			const auto start = std::chrono::high_resolution_clock::now();

			for (int i = 0; i < length; i += stepsize)
			{
				arr[i] *= 2;

			}

			const auto end = std::chrono::high_resolution_clock::now();
			totalTime += (float)std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		}

		results.push_back(totalTime / loopAmount);

	}
}

std::vector<float>& Week3Exercise1::ReturnResults()
{
	return results;
}
