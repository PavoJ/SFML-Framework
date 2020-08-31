#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include"stdafx.hpp"

namespace sff
{
	template<typename T>
	class linked_list
	{
	private:
		struct data{
			T val;
			data* next;
		} *start, *end;
		int count;
	public:
		//insertion functions
		bool insert(int position, T data);
		bool append(T data);

		//get the linked list's length
		int getCount();
	};
}

#endif //LINKED_LIST_HPP