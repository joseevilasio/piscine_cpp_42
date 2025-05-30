#include "iter.hpp"

int main(void)
{
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	iter(&arr, 10, &ft_print);
	return (0);
}