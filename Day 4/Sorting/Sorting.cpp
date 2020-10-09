// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sorting.h"
#include <array>
#include <vector>

template<class T >
std::vector<T> Merge(std::vector<T>& leftItems, std::vector<T>& rightItems)
{
	std::vector<T> mergedItems;

	while (!leftItems.empty() && !rightItems.empty())
	{
		if (leftItems[0] <= rightItems[0])
		{
			mergedItems.push_back(leftItems[0]);
			leftItems.erase(leftItems.begin());
		}
		else
		{
			mergedItems.push_back(rightItems[0]);
			rightItems.erase(rightItems.begin());
		}
	}

	while (!leftItems.empty())
	{
		mergedItems.push_back(leftItems[0]);
		leftItems.erase(leftItems.begin());
	}

	while (!rightItems.empty())
	{
		mergedItems.push_back(rightItems[0]);
		rightItems.erase(rightItems.begin());
	}

	return mergedItems;
}

template<class T >
std::vector<T> MergeSort(std::vector<T>& items)
{
	size_t length = items.size();
	if (length <= 1)
		return items;

	std::vector<T> leftItems;
	std::vector<T> rightItems;

	size_t halfLength = length / 2;

	for (size_t index = 0; index < length; index++)
	{
		if (index < halfLength)
		{
			leftItems.push_back(items[index]);
		}
		else
		{
			rightItems.push_back(items[index]);
		}
	}
	leftItems = MergeSort(leftItems);
	rightItems = MergeSort(rightItems);

	return Merge(leftItems, rightItems);
}




template<class T >
void BubbleSort(std::vector<T>& items)
{
	size_t length = items.size();
	while (length >= 1)
	{
		size_t newLength = 0;

		for (size_t index = 1; index < length; index++)
		{
			if (items[index - 1] > items[index])
			{
				std::swap(items[index - 1], items[index]);
				newLength = index;
			}
		}
		length = newLength;
	}
}


template<class T >
void InsertionSort(std::vector<T>& items)
{
	T selElement;

	int j = 0;
	size_t length = items.size();

	//Iterater from i to size of array
	for (size_t index = 1; index < length; index++)
	{
		//while iterating  
		selElement = items[index];
		j = index - 1; // predecessor index

		//Compare the current element to its predecessor 
		//if current element is smaller ,compare to elements before
		while (j >= 0 && items[j] > selElement)
		{
			//Shift  position to the right to make way for inserting selElement
			items[j +1]  = items[j]; 
			j = j - 1;
		}
		//Selected Element is inserted in its final position
		items[j + 1] = selElement;
	}
};

int main()
{
	std::vector<int> arr = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 , 100, 97, 98};
	//Sorting::QuickSort(arr.begin(), arr.end());
	//arr = 
		InsertionSort(arr);

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
