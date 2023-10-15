#pragma once

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <new>

class Grid
{
private:
	char* arr;
	short size;

	void deleteArr();
	void copyArr(char* arr, short size);
	void createArr(short size);

public:
#pragma region constructors
	Grid() : arr{}, size{} {}

	Grid(short size) : size{size}
	{
		createArr(this->size);
	}

	Grid(char* arr, short size) : size{size}
	{
		copyArr(arr, this->size);
	}

	Grid(const Grid& copy) {
		copyArr(copy.arr, copy.size);
	}

	Grid(Grid&& move) noexcept
	{
		this->arr = move.arr;
		this->size = move.size;
		move.size = 0;
		move.arr = nullptr;
	}

	~Grid() {
		deleteArr();
	}
#pragma endregion

#pragma region operators
	Grid& operator=(Grid& copy) {
		copyArr(copy.arr, copy.size);
		return *this;
	}

	Grid& operator=(Grid&& move) noexcept
	{
		if (&move == this)
			return *this;

		deleteArr();
		this->arr = move.arr;
		this->size = move.size;

		move.size = 0;
		move.arr = nullptr;

		return *this;
	}

	bool operator==(bool flag) 
	{
		return(this->arr == nullptr && this->size == 0);
	}
	
	bool operator==(const Grid& grid) 
	{
		return(this->arr == grid.arr && this->size == grid.size);
	}
#pragma endregion
}
;
#endif