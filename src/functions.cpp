#include "..\include\functions.h"
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <ctime>



using Sec = std::chrono::seconds;
void foodOrder() noexcept
{
	std::srand(std::time(nullptr));
	std::string food;

	while (counter <= 10)
	{
		std::this_thread::sleep_for(Sec(5 + rand() % 6));

		food = vFoods[rand() % vFoods.size()];

		std::unique_lock<std::mutex> ul1(order_mtx);
		qOrderedFood.push(food);
		std::unique_lock<std::mutex> ul2(print_mtx);
		std::cout << food << " is ordered\n";
	}
}

//-----------------------------------------------------------------

void cooking() noexcept
{
	std::srand(std::time(nullptr));

	std::string food = "";

	while (counter <= 10)
	{
		std::unique_lock<std::mutex> ul1(order_mtx);
		if (!qOrderedFood.empty())
		{
			food = qOrderedFood.front();
			qOrderedFood.pop();
		}
		ul1.unlock();

		if (!food.empty())
		{
			std::this_thread::sleep_for(Sec(5 + rand() % 11));

			std::unique_lock<std::mutex> ul2(ready_mtx);
			qReadyFood.push(food);
			std::unique_lock<std::mutex> ul3(print_mtx);
			std::cout << food << " is ready\n";
			ul3.unlock();
			ul2.unlock();
			food = "";
		}
	}
}

//-----------------------------------------------------------------

void delivery() noexcept
{
	std::string food;
	while (counter < 10)
	{
		std::this_thread::sleep_for(Sec(30));

		std::unique_lock<std::mutex> ul1(ready_mtx);
		while (!qReadyFood.empty())
		{
			food = qReadyFood.front();
			qReadyFood.pop();
			std::unique_lock<std::mutex> ul2(print_mtx);
			std::cout << ++counter << " " << food << " is dilivered\n";
		}
	}
}
