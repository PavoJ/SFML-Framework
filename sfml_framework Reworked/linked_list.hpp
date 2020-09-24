#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include"stdafx.hpp"

namespace sff
{
	template<typename T>
	class linked_list
	{
	private:
		template<typename T>
		struct data_list {
			T val;
			data_list* next;
		};

		data_list<T>* start;
		data_list<T>* end;

		int len;
	public:
		linked_list();

		//insertion functions
		void insert(int position, T data);
		void append(T data);

		//extraction functions
		T pop();

		//read functions
		T& operator[](int position);

		//get the linked list's length
		int length();
	};
}

#endif //LINKED_LIST_HPP 