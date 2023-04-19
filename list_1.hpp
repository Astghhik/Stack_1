struct  Node

{


		int data;

		struct Node* next;

	        Node(int value);

};


class List

{

	public:

		int size;

		Node* first;
		Node* last;



                

		//Constructor

                List();


		//Return size

		int get_size();


		//Doing check if list is empty

		bool is_empty();

		//Function gives a new node at the end of a list

		void push_back(int data);

		void print();
		int& operator[] (int index);
		int pop_back();
		void remove_value(int value);
		void remove_index(int index);
		List(const List& object); 
		~List();
		void insert(int position, int data); 

};

class Stack
{
      public:
	        Node* index;
	        int size;
	      
	        Stack();
		~Stack();
		int get_size();
		bool is_empty();
	        void push(int value);
		int pop();
		int top();
};
