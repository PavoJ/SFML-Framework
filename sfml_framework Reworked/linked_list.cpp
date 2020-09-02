#pragma once

#include"stdafx.hpp"
#include"linked_list.hpp"

namespace sff
{
	template<typename T>
	linked_list<T>::linked_list()
	{
		length = 0;
		start = nullptr;
		end = nullptr;
	}

	template<typename T>
	void linked_list<T>::insert(int position, T data)
	{
		if (start == nullptr)
		{
			start = new data_list<T>;
			start->next = nullptr;
		}
		else
		{
			data_list* tmpPnt = start, prevPnt = nullptr;
			int i = 0;
			while ((i < position) && (tmpPnt->next != nullptr))
			{
				prevPnt = tmpPnt;
				tmpPnt = tmpPnt->next;

				i++;
			}

			if (prevPnt == nullptr)
			{
				prevPnt = new data_list<T>;
				prevPnt->next = start;

				start = prevPnt;
			}
			else {
				prevPnt->next = new data_list<T>;
				prevPnt = prevPnt->next;

				prevPnt->val = data;
				prevPnt->next = tmpPnt;
			}
		}

		length++;
	}

	template<typename T>
	void linked_list<T>::append(T data)
	{
		if (start == nullptr)
		{
			start = new data_list<T>;
			end = start;
		}
		else {
			end->next = new data_list<T>;
			end = end->next;
		}

		end->val = data;
		end->next = nullptr;
	}

	template<typename T>
	int linked_list<T>::getLength()
	{
		return length;
	}

}//sff