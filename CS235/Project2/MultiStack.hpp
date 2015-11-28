#ifndef MULTISTACK_HPP
#define MULTISTACK_HPP

#include <iostream> 
using namespace std; 

struct Node{
	char item;
	Node *link; 
	
};

class MultiStack{
private: 
	Node *head; //Pointer to first node
	char c; 
	int counter; 
	int sizeCount; //Size of Stack regardless of repeated characters
	
public: 
	//Default constructor
	MultiStack();
	
	//Copy constructor
	MultiStack(const MultiStack& anotherMultiStack);
	
	//You should implement this properly SHOULD IT BE VIRTUAL?
	//Destructor
	virtual ~MultiStack();
	
	//You should implement this properly		
	MultiStack& operator=(const MultiStack& anotherMultiStack); //previouc: MultiStack& operator=(const MultiStack& anotherMultiStack);
	
	//Pushes a character c into the stack. 	
	void push(char c);
	
	//Pops off the last character from the stack and remove it from the stack. Throws an exception if the stack is empty.	
	void pop();
	
	//Pops off the last character from the stack, and remove all instances of that  character from the entire stack. 
	//The order of the other characters in the stack should remain intact. Throws an exception if the stack is empty
	char multiPop();
	
	//Returns a count of the number of times the last character in the stack appears. Returns 0 if the stack is empty.
	int getRepeatCounts();
	
	//Returns true if the stack is empty; false otherwise
	bool isEmpty();
	
	//Returns the total number of characters in the stack, irrespective of repeats. Returns 0 if the stack is empty.
	int getSize();
	
	//Returns the unique number of characters in the stack. 
	//So if the current stack has the following [b a z z z a c ], this should return 4. 
	int getUniqueCount();
	
};

#endif
