#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>


template<class TYPE>
class Stack
{

private:

	TYPE *data;
	unsigned int allocated_memory;
	unsigned int num_elements;

	void reallocate(unsigned int new_memory)
	{
		allocated_memory = new_memory;

		// You will never reduce the memory of the Stack;
		/*if (num_elements > allocated_memory)
			num_elements = allocated_memory;*/

		if (data != NULL)
		{
			TYPE *tmp = new TYPE[allocated_memory];

			for (unsigned int i = 0; i < num_elements; i++)
				tmp[i] = data[i];

			delete[] data;
			data = tmp;
		}
		else
		{
			data = new TYPE[allocated_memory];
		}		
	}

public:

	Stack() : data(NULL), allocated_memory(0), num_elements(0)
	{}

	Stack(unsigned int new_memory) : data(NULL), num_elements(0)
	{
		reallocate(new_memory);
	}
	
	~Stack()
	{
		if (data != NULL) delete[] data;
	}

	void push(const TYPE &new_data)
	{
		if (num_elements == allocated_memory)
			reallocate(++allocated_memory);

		data[num_elements++] = new_data;
	}

	bool pop(TYPE &data_pop)
	{
		if (data != NULL && num_elements != 0)
		{
			data_pop = data[--num_elements];
			return true;
		}
		return false;
	}

	const TYPE *peek(unsigned int position) const
	{
		//Maybe it is not correct.

		TYPE *ret = NULL;

		if (data != NULL && position < num_elements)
			ret = &data[position];

		return ret;
	}

	void clear()
	{
		num_elements = 0;
	}

	unsigned int getElements() const
	{
		return num_elements;
	}

	unsigned int getMemory() const
	{
		return allocated_memory;
	}

};

#endif // __STACK_H__