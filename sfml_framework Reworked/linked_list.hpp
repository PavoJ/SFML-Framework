#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include"stdafx.hpp"

namespace sff
{
	template<typename T>
	class linked_list
	{
	private:
		struct data_list{
			T val;
			data_list* next;
		} *start, *end;

		int length;
	public:
		linked_list();

		//insertion functions
		void insert(int position, T data);
		void append(T data);

		//get the linked list's length
		int getLength();
	};
}

#endif //LINKED_LIST_HPP