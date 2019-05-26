#include "pch.h"
#include <iostream>
#include <string>
#include "List.h"

int main()
{
	List<int> list;
	list.push_back(8);
	list.push_front(4);
	list.push_back(2);
	list.insert(0, 1);
	std::cout << list << std::endl; // 4 0 8 2
	list.clear();
	list << 0 << 2 << 4 << 8;
	std::cout << list << std::endl; // 0 2 4 8
	std::cout << list.at(1) << std::endl; // 2
	std::cout << list[3] << std::endl; // 8
	list[2] = 16;
	list.remove(0);
	std::cout << list.pop_front() << std::endl; // 2
	std::cout << list.pop_back() << std::endl; // 8
	list.insert(32, 0);
	std::cout << list.size() << "\t" << list.first() << "\t" << list.last() << std::endl; // 2 32 16
	list.push_front(16);
	list.remove(1);
	list.print(); // 16 16
	list.removeByValue(16);
	std::cout << (list.isEmpty() ? "list is empty" : "list is not empty") << std::endl; // list is empty
	list.clear();
	list << 1 << 2 << 3 << 4 << 5;
	std::cout << list << std::endl; // 1 2 3 4 5
	List<int>* listPtr = new List<int>(list);
	listPtr->print(); // 1 2 3 4 5
	List<int> list2;
	list2 = *listPtr;
	delete listPtr;
	std::cout << list2 << std::endl; // 1 2 3 4 5
	list2.reverse();
	list2.print(); // 5 4 3 2 1

	try
	{
		list.push_front(100);
		std::cout << list.at(0) << std::endl; // 100
		std::cout << list.at(100) << std::endl; /* exception should be thrown */
	}
	catch (const std::out_of_range& exp)
	{
		std::cout << exp.what() << std::endl; // index out of range
	}
	return 0;
}

