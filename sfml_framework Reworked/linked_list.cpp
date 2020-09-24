#pragma once

#include"stdafx.hpp"
#include"linked_list.hpp"

namespace sff
{
	template<typename T>
	linked_list<T>::linked_list()
	{
		len = 0;
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
			data_list<T>* tmpPnt = start;
			data_list<T>* prevPnt = nullptr;
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

		len++;
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

		len++;
	}

	template<typename T>
	T linked_list<T>::pop()
	{
		T ret = end->val;

		data_list* data_listP = start;
		while (data_listP->next != end)
			data_listP = data_listP->next;

		delete end;
		data_listP->next = nullptr;
		
		return ret;
	}

	template<typename T>
	T& linked_list<T>::operator[](int position)
	{
		bool validReq = position < len;
		T* retVal;

		data_list<T>* DLP = start;
		for (int a = 0; (a < position) && validReq; a++)
			DLP = DLP->next;
		
		if (!validReq)
			std::cerr << "linked list error: position " << position << " is out of range" << std::endl;

		return DLP->val;
	}

	template<typename T>
	int linked_list<T>::length()
	{
		return len;
	}

}//sff
