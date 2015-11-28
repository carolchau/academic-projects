#include<stdexcept>
#include<cassert>

#include "MultiStack.hpp"

//Default constructor
MultiStack::MultiStack(){
	head = NULL; 
	sizeCount = 0;
}

//Copy constructor
MultiStack::MultiStack(const MultiStack& anotherMultiStack){
	head = NULL;
	sizeCount = anotherMultiStack.sizeCount; 
	
	Node *iterator = anotherMultiStack.head; 
	
	//Copy first node
	head = new Node; 
	Node *copyiterator = head; 
	head->item = iterator->item; 

	iterator = iterator->link; 
	
	//Copy remaining nodes
	while(iterator != NULL){ 
		Node *current = new Node; 
		current->item = iterator->item;
		current->link = NULL;
		copyiterator->link = current;
		copyiterator = current;
		iterator = iterator->link;	
	}
	
}

//Destructor	
MultiStack::~MultiStack(){

	while (head!= NULL){
		Node *temp = head; 
		head = head->link;
		delete temp;  
		sizeCount --;
	}
	head = NULL;	
	
}

//Assignment operator	
MultiStack& MultiStack::operator=(const MultiStack& anotherMultiStack){
	/*
	//delete whatever is in the left side of the operator
	while (head!= NULL){
		Node *temp = head; 
		head = head->link;
		delete temp;  
		sizeCount --;
	}
	head = NULL;
	*/	
	
	sizeCount = anotherMultiStack.sizeCount; 
	
	Node *iterator = anotherMultiStack.head; 
	
	//Copy first node
	head = new Node; 
	Node *copyiterator = head; 
	head->item = iterator->item; 
	
	iterator = iterator->link; 
	
	//Copy remaining nodes
	while(iterator != NULL){ 
		Node *current = new Node; 
		current->item = iterator->item;
		current->link = NULL;
		copyiterator->link = current;
		copyiterator = current;
		iterator = iterator->link;	
	}
	
}

//Pushes a character c into the stack. 	
void MultiStack::push(char c){
	Node *temp; 
	temp = new Node; 
	
	if(temp == NULL){
		cout << "Stack is empty" << endl;
	}else{
		temp->item = c; 
		temp->link = head; 
		head = temp; 
		sizeCount++; //increased stack size counter by 1
	}
	
}

//Pops off the last character from the stack and remove it from the stack. Throws an exception if the stack is empty.	
void MultiStack::pop(){
   try {
		if (head == NULL){
			throw runtime_error("The stack is empty.");
		}
	} catch (std::runtime_error e){
		cerr << "Can't pop from nothing" << endl;
	}	
	
	Node *temp = head; 
	head = head->link; 
	delete temp; 
	sizeCount--; //decreased stack size counter by 1
	
}

char MultiStack::multiPop(){
	if (head==NULL){
		//THROW AN ERROR
	}

	char storage = head->item;
	pop(); 

	Node *iterator = head;
	Node *scout = NULL; //will eventually be at the Node previous to iterator
	Node *temp;
	 
	while (iterator != NULL){
		//If current item in node is the same as last character
		if (storage == iterator->item){
			if(iterator == head){
				pop();
				iterator = head; 
				scout = NULL; 
				
			} else {
				Node *temp = iterator;
				iterator = iterator->link; 

				scout->link = iterator; 
				delete temp; 
				sizeCount--; 
		
			}	
		}

		//If current item in node is not the same as the last character
		else{
				scout = iterator;
				iterator = iterator->link;
				
		}
	} //close while loop
	
	return storage;
}

//Returns a count of the number of times the last character in the stack appears. Returns 0 if the stack is empty.	
int MultiStack::getRepeatCounts(){
	if (head == NULL){
		return 0;
	} else {
		char lastchar = head->item;
		counter = 1; 
		Node *iterator = head->link; 
	
		while (iterator != NULL){
			if (lastchar == iterator->item){
				counter++; 
			}
			iterator = iterator->link;
		}
		return counter; 
	}
	
}

//Returns true if the stack is empty; false otherwise	
bool MultiStack::isEmpty(){
	if(head == NULL){
		return true;
	} else {
		return false; 
	}
}
	

//Returns the total number of characters in the stack, irrespective of repeats. Returns 0 if the stack is empty.	
int MultiStack::getSize(){
	return sizeCount;
}


//Returns the unique number of characters in the stack. 
//So if the current stack has the following [b a z z z a c ], this should return 4.	
int MultiStack::getUniqueCount(){
	int uniqueCount = 0; 
	bool unique = true;
	char storage; 
	 
	if (sizeCount != 0){
		//first node 
		Node *iterator = head; 
		Node *fetch = head; 
		uniqueCount++; 
		iterator = head->link; 
		
		while (iterator!= NULL){
			storage = iterator->item;
			
			while (fetch != iterator){
				if (fetch->item == storage){
					unique = false; 
				}
				fetch = fetch->link;
					
			}
			
			if (unique != false){
				uniqueCount++;
			}
			
			iterator = iterator->link;
			fetch = head;
			unique = true; 
			
		}
	}
	
	return uniqueCount;
}
