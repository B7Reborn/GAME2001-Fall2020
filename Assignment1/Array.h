#pragma once
#include <cassert>

template<class T>
class Array
{
public:
	// Default Constructor
	Array()
	{
		m_array = new T[0];
	}
	// Constructor
	Array(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; // Dynamically allocating an array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize); // Explicitly allocating memory based on the type T

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	// Destructor
	~Array()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;			// Good programming practice to set unused pointers to NULL
		}
	}

	// Insertions
	// These will be different for each array type and therefore be defined in the appropriate classes

	// Deletion (2 ways)
	// Remove the last item inserted into the array
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}
	
	// Remove an item given an index
	// (Almost) Brute-force execution -- O(N)
	void remove(int index)
	{
		assert(m_array != NULL);

		if (index >= m_numElements)
		{
			std::cout << "Index out of bounds!" << std::endl;
			return;
		}

		for (int i = index; i < m_numElements; i++)
		{
			if ((i + 1) < m_numElements)
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}

	// Searching
	// Will be different for each array

	// Overloaded [] operator
	const T& operator[](int index)
	{
		assert(m_array != NULL && index < m_numElements);
		return m_array[index];
	}

	// Clear -- O(1)
	void clear()
	{
		m_numElements = 0;
	}

	// Gets and Sets
	int GetSize()
	{
		return m_numElements;
	}
	void SetSize(int size)
	{
		m_numElements = size;
	}
	int GetMaxSize()
	{
		return m_maxSize;
	}
	void SetMaxSize(int maxSize)
	{
		m_maxSize = maxSize;
	}
	int GetGrowSize()
	{
		return m_growSize;
	}
	void SetGrowSize(int val)
	{
		assert(val >= 0);

		m_growSize = val;
	}
	T* GetArray()
	{
		return m_array;
	}

//private:
	// Expansion, changed to be public so it is accessible from other array classes
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		// Create the new array
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);

		// Copy contents of old array into new array
		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		// Delete the old array
		delete[] m_array;

		// Clean up variable assignments
		m_array = temp;
		temp = NULL;

		m_maxSize += m_growSize;

		// Double the rate at which the array grows each time
		m_growSize *= 2;

		// Print a statement to acknowledge the expansion
		std::cout << "Array is expanded. New max size: " << m_maxSize << std::endl;

		return true;
	}
	
private:
	// Variables
	T* m_array;			// Pointer to the beginning of the array

	int m_maxSize;		// Maximum number of items the array can hold
	int m_growSize;		// How large will the array grow by
	int m_numElements;	// Number of elements currently in the array
};