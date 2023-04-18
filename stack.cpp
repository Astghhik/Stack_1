#include <iostream>
#include "stack.hpp"

//Constructor
Stack::Stack(int size)
{
	capacity = size;
	arr = new int[capacity];
	index = -1;
}
//Destructor
Stack::~Stack()
{
	delete[] arr;
}

//is_empty function is checking is the stack empty or not.

bool Stack::is_empty()
{
   return (index < 0);
}
//Size
int Stack::get_size()
{
        return index + 1;
}
//Push
void Stack::push(int x)
{
      if(is_full())
      {
              std::cout<<"Stack is full!"<<std::endl;
              return;
      }
      arr[++index] = x;
}
//Pop
int Stack::pop()
{
   if (index < 0) {
	   std::cout << "Stack Underflow!!";
      return 0;
   }
else {
       int item = arr[index--];
      return item;
   }
}
//Function is_full is checking is the stack full. 
bool Stack::is_full()
{
	return index == capacity - 1;
}


//Function is used to reference the top(or the newest) element of the stack.
int Stack::top()
{
	if(is_empty())
	{
		std::cout<<"Stack is empty"<<std::endl;
		return -1;
	}
	return arr[index];

}
