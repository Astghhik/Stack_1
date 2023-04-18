#include <iostream>
#include <cassert>
#include "stack.hpp"

int main()
{
	Stack stack(5);

	stack.push(1);
	stack.push(2);
	stack.push(3);
	std::cout<<"Stack elements:"<<stack.top()<<std::endl;
         
        stack.push(4);
	stack.push(5);
	std::cout<<"Size:"<<stack.get_size()<<std::endl;

	stack.pop();
	std::cout<<"Stack elements: "<<stack.top()<<std::endl;	
	std::cout<<"Size:"<<stack.get_size()<<std::endl;


	return 0;
}
