#include "whatever.hpp"
#include <iostream>

// int	main(void)
// {
// 	//SWAP
// 	{
// 		std::cout << "\nTEST 01 - SWAP\n";

// 		int a = 42;
// 		int b = 21;

// 		swap(a, b);

// 		std::cout << "a: " << a << std::endl;
// 		std::cout << "b: " << b << std::endl;
// 	}
// 	{
// 		std::cout << "\nTEST 02 - SWAP\n";
 
// 		std::string a = "42";
// 		std::string b = "21";

// 		swap(a, b);

// 		std::cout << "a: " << a << std::endl;
// 		std::cout << "b: " << b << std::endl;
// 	}
// 	// MIN
// 	{
// 		std::cout << "\nTEST 01 - MIN\n";

// 		int a = 42;
// 		int b = 21;

// 		std::cout << "min: " << min(a, b) << std::endl;
// 	}
// 	{
// 		std::cout << "\nTEST 02 - MIN\n";
 
// 		float a = 42.0f;
// 		float b = 21.0f;

// 		std::cout << "min: " << min(a, b) << std::endl;
// 	}
// 	{
// 		std::cout << "\nTEST 03 - MIN\n";
 
// 		float a = 42.0f;
// 		float b = 42.0f;

// 		std::cout << "min: " << min(a, b) << std::endl;
// 	}
// 	//MAX
// 	{
// 		std::cout << "\nTEST 01 - MAX\n";

// 		int a = 42;
// 		int b = 21;

// 		std::cout << "min: " << max(a, b) << std::endl;
// 	}
// 	{
// 		std::cout << "\nTEST 02 - MAX\n";
 
// 		float a = 42.0f;
// 		float b = 21.0f;

// 		std::cout << "min: " << max(a, b) << std::endl;
// 	}
// 	{
// 		std::cout << "\nTEST 03 - MAX\n";
 
// 		float a = 42.0f;
// 		float b = 42.0f;

// 		std::cout << "min: " << max(a, b) << std::endl;
// 	}
// 	return (0);
// }

int main( void )
{
	int a = 2;
	int b = 3;

	::swap( a, b );

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}