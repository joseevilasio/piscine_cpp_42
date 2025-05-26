#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		try
		{
			Form("Alice", 0, 10);
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	return (0);
}