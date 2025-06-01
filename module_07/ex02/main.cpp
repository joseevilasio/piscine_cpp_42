#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Array.hpp>

int main(void)
{
	{
		std::cout << "\n --  TEST 01 - Empty  -- \n";

		Array<int> empty;
		std::cout << "Size: " << empty.size() << std::endl;

		try
		{
			empty[0] = 42;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception expected: " << e.what() << '\n';
		}
	}

	{
		std::cout << "\n --  TEST 02 - N elements  -- \n";

		Array<int> numbers(5);
		std::cout << "Size: " << numbers.size() << std::endl;

		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			numbers[i] = i * 1;
			std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
		}

		std::cout << "\n --  TEST 03 - Copy  -- \n";

		Array<int> copy = numbers;

		copy[0] = 42;

		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			std::cout << "numbers[" << i << "] = " << numbers[i] << " | ";
			std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
		}

		std::cout << "\n --  TEST 04 - Exception  -- \n";

		try
		{
			numbers[-1] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception expected [-1]: " << e.what() << '\n';

		}

		try
		{
			numbers[5] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception expected [5]: " << e.what() << '\n';
		}
	}
	{
		std::cout << "\n --  TEST 05 - std::string  -- \n";

		Array<std::string> words(3);

		words[0] = "Hello";
		words[1] = "World";
		words[2] = "!";

		for (unsigned int i = 0; i < words.size(); i++)
		{
			std::cout << "words[" << i << "] = " << words[i] << std::endl;
		}

		std::cout << "\n --  TEST 06 - operator=  -- \n";

		Array<std::string> other;
		other = words;

		other[1] = "42";

		std::cout << "words[1] = " << words[1] << std::endl;
		std::cout << "other[1] = " << other[1] << std::endl;
	}
	return (0);
}

// #define MAX_VAL 750

// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;//
// 	return 0;
// }