class Stack
{
	private:
		int capacity;
		int index;
		int* arr;
       public:
		//Constructor
		Stack(int size);
		
		//Destructor
		~Stack();

		bool is_empty();
		int get_size();
		bool is_full();
		void push(int x);
		int pop();
		int top();

};
