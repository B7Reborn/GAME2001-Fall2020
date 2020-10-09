#pragma once
#include <cassert>
#include "Array.h"

template<class T>
class UnorderedArray : public Array<T>
{
public:
	// Constructor
	UnorderedArray(int size, int growBy = 1)
	{
		m_pArrayPTR = new Array<T>(size, growBy);
	}
	
	// Insertions
	// Fast insertion for UnorderedArray -- O(1)
	void push(T val)
	{
		assert(m_pArrayPTR->GetArray() != NULL);	// Debugging purposes

		if (m_pArrayPTR->GetSize() >= m_pArrayPTR->GetMaxSize())
		{
			m_pArrayPTR->Expand();
		}

		// My array has space for the new value
		m_pArrayPTR->GetArray()[m_pArrayPTR->GetSize()] = val;
		m_pArrayPTR->SetSize(m_pArrayPTR->GetSize() + 1);
	}

	// Searching (Linear search) -- O()
	int search(T val)
	{
		assert(m_pArrayPTR->GetArray() != NULL);

		// Brute-force search
		for (int i = 0; i < m_pArrayPTR->GetSize(); i++)
		{
			if (m_pArrayPTR->GetArray()[i] == val)
			{
				std::cout << "The value " << val << " was found at entry " << i + 1 << std::endl;
				return i;
			}
		}

		std::cout << "The value was not found" << std::endl;
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
};