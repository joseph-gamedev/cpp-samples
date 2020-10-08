#pragma once

namespace Sorting
{
	template <class T>
	struct less 
	{
		constexpr bool operator()(const T& left, const T& right) const
		{
			return left < right;
		}
	};

	template <class T>
	struct greater 
	{
		constexpr bool operator()(const T& left, const T& right) const 
		{
			return left > right;
		}
	};

	template<class RandomIt>
	void QuickSort(RandomIt first, RandomIt last)
	{
		QuickSort(first, last, less<RandomIt>{});
	}


	template<class RandomIt, class Compare>
	void QuickSort(RandomIt first, RandomIt last, Compare comp)
	{
		//Pick a pivot
		RandomIt pivot = last;

		if (first < last)
		{

		}
	}

};
