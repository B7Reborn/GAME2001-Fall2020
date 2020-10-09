#pragma once
#include <cassert>
#include "Array.h"

template<class T>
class OrderedArray : public Array<T>
{
public:
	// Constructor
	OrderedArray(int size, int growBy = 1)
	{
		m_pArrayPTR = new Array<T>(size, growBy);
	}

	// Insertion
	int push(T val)
	{
		assert(m_pArrayPTR->GetArray() != NULL);

		// Don't allow duplicate data
		// The boolean is used so excess lines of text are not printed
		m_bDupeCheck = true;
		if (search(val) != -1)
		{
			std::cout << "The value " << val << " is already in this array!" << std::endl;
			m_bDupeCheck = false;
			return -1;
		}
		m_bDupeCheck = false;

		if (m_pArrayPTR->GetSize() >= m_pArrayPTR->GetMaxSize())
		{
			m_pArrayPTR->Expand();
		}

		int i, k;
		// Step 1: Find the index to insert val
		for (i = 0; i < m_pArrayPTR->GetSize(); i++)
		{
			if (m_pArrayPTR->GetArray()[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index forward by one
		for (k = m_pArrayPTR->GetSize(); k > i; k--) // Moving backwards through the array
		{
			m_pArrayPTR->GetArray()[k] = m_pArrayPTR->GetArray()[k - 1];
		}

		// Step 3: Insert val into index
		m_pArrayPTR->GetArray()[i] = val;

		m_pArrayPTR->SetSize(m_pArrayPTR->GetSize() + 1);

		return i;
	}

	// Searching (Binary Search) -- O(log N)
	int search(T searchKey)
	{
		assert(m_pArrayPTR->GetArray() != NULL);

		// Helper variables
		int lowerBound = 0;
		int upperBound = m_pArrayPTR->GetSize() - 1;
		int current = 0;

		while (true) // To be replaced by recursion
		{
			current = (lowerBound + upperBound) >> 1; // Preview of Bitwise operations. Divides by 2.

			// Binary search steps:
			// Step 1: Check if the middle is the value we are looking for
			if (m_pArrayPTR->GetArray()[current] == searchKey)
			{
				// Found the item in the middle of the array. Return the index.
				if (!m_bDupeCheck)
				{
					std::cout << "The value " << searchKey << " was found at index " << current + 1 << std::endl;
				}
				return current;
			}
			// Step 2: Check that we've exhausted all options already
			else if (lowerBound > upperBound)
			{
				if (!m_bDupeCheck)
				{
					std::cout << "The value " << searchKey << " was not found." << std::endl;
				}
				return -1;
			}
			else
			{
				// Step 3: check which half of the array the value is in
				if (m_pArrayPTR->GetArray()[current] < searchKey)
				{
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
			}
		}
		return -1;
	}
	
	// Overloaded [] operator
	const T& operator[](int index)
	{
		assert(m_pArrayPTR->GetArray() != NULL && index < m_pArrayPTR->GetSize());
		return m_pArrayPTR->GetArray()[index];
	}

	// Getter for array pointer
	Array<T>* GetArrayPTR()
	{
		return m_pArrayPTR;
	}
private:
	Array<T>* m_pArrayPTR;
	bool m_bDupeCheck = false;
};