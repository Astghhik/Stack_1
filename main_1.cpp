#include <iostream>
#include <cassert>
#include "list_1.hpp"


int main()


{
	Stack stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	std::cout<<"Elements: "<<stack.top()<<std::endl;

        stack.push(4);
	stack.push(5);
	std::cout<<"Size: "<<stack.get_size()<<std::endl;

	stack.pop();
	std::cout<<"Elements: "<<stack.top()<<std::endl;
	std::cout<<"Size: "<<stack.get_size()<<std::endl;


	return 0;
}
