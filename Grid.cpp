#include "Grid.h"

void Grid::deleteArr()
{
	if (size != 0) {
		delete[] arr;
		arr = nullptr;
		size = 0;
	}
}
;
void Grid::copyArr(char* arr, short size)
{
	deleteArr();

	try {
		this->arr = new char[size];
		for (short i = 0; i < size; i++)
			this->arr[i] = arr[i];
	}
	catch(std::bad_alloc e)
	{
		std::cout << "!\n" << e.what() << "!\n";
	}
}
void Grid::createArr(short size)
{
	try {
		this->arr = new char[this->size];
		for (short i = 0; i < this->size; i++)
			this->arr[i] = '*';
	}
	catch (std::bad_alloc e)
	{
		std::cout << "!\n" << e.what() << "!\n";
	}
}
;