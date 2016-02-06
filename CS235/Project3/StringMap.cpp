#include<stdexcept>
#include<cassert>
#include<string>

//Default constructor
StringMap::StringMap(){
	hashArray = new HashNode*[MAXSIZE];
	
	for (int i=0; i < MAXSIZE; i++){
		hashArray[i] = NULL;
	}
	
}

//Copy constructor
StringMap::StringMap(const StringMap& otherStringMap){
	hashArray = new HashNode*[MAXSIZE];
	PairsNum = otherStringMap.PairsNum;
	
	for (int i=0; i < MAXSIZE; i++){
		
		if (otherStringMap.hashArray[i] == NULL){
			hashArray[i] = NULL;	
			
		} else {
			HashNode *current = otherStringMap.hashArray[i];
			
			while (current != NULL){
				this->addValue(current->key, current->value);
				current = current->link;
			}	
		}
		
	}	

}

//Overloaded assignment operator
StringMap& StringMap::operator=(const StringMap& otherStringMap){
	hashArray = new HashNode*[MAXSIZE];
	PairsNum = otherStringMap.PairsNum;
	
	for (int i=0; i < MAXSIZE; i++){
		
		if (otherStringMap.hashArray[i] == NULL){
			hashArray[i] = NULL;	
			
		} else {
			HashNode *current = otherStringMap.hashArray[i];
			
			while (current != NULL){
				this->addValue(current->key, current->value);
				current = current->link;
			}
			
		}
		
	}
	
}

//Destructor
StringMap::~StringMap(){
	for (int i=0; i < MAXSIZE ; i++ ){
		HashNode *next = hashArray[i];
		
		while(next != NULL){
			HashNode *temp = next;
			next = next->link; 
			delete temp; 
			PairsNum --;	
		}	
	}
	delete[] hashArray;
}

//Checks if Map is empty
//If the Map contains no elements, this should return true; otherwise, returns false.
bool StringMap::isEmpty(){
	bool empty = true; 
	
	for (int i=0; i < MAXSIZE; i++){
		if (hashArray[i] != NULL){
			empty = false; 
		}
	}
	
	return empty; 
	
	/*
	//Might be an easier implementation:
	if (PairsNum > 0){
		return false; 
	} else {
		return true;
	}
	*/
}

//Hash function
int StringMap::HashFx(string key){
	int hash = 0;
	//sums the ASCII value of each letter in the key
	for (int i=0; i <key.length(); i++){
		hash = hash + key[i]; 
	}
	//returns the modulo of the sum by the maximum size of array
	return hash % MAXSIZE; 
}

//Returns the number of key-value pairs (elements) stored in the Map
int StringMap::getSize(){
	return PairsNum; 
	
}

//if the key AND value is valid, stores the valid key-value pair, and returns true
//if key or value is invalid (empty string), returns false
bool StringMap::addValue(string key, string value){
	bool added = false; 
	//checking to see if either key or value is empty (invalid)
	if (key.empty() == true || value.empty() == true){
		return added; //which should return false
	} else { 
		int hash = HashFx(key);
		//if nothing at that index, stores new key-value pair
		if (hashArray[hash] == NULL){
			hashArray[hash] = new HashNode(key, value);
			PairsNum++;
			added = true; 	
		} else {
			HashNode *current = hashArray[hash]; 
			
			//iterate until you reached same key or NULL
			while (current->link != NULL && current->key != key){
				current = current->link;
			} 
			
			//if key already exists, replace old value with new value
			//else add new HashNode with key-value pairs at the end of the chain
			if (current->key == key){
				current->value = value; 
			} else { 
				current->link = new HashNode(key, value);
				PairsNum ++; 
				added = true;
			}
		}
		
		return added; 
	}
}

//If a value associated with the given key exists, returns it; 
//otherwise throws an exception
string StringMap::getValue(string key){
	int hash = HashFx(key);
	
	//if array at key's index is empty, 
	//throw an exception
	try {
	 	if (hashArray[hash] == NULL){
	 		throw runtime_error("Array at key's index is empty.");
	 	}
	} catch (std::runtime_error e){
	 	cerr << "Can't find value associated with given key." << endl;
	}
		
		
	if (hashArray[hash] != NULL){
		HashNode *current = hashArray[hash]; 
		//iterate until key is found or end of chain is reached
		while (current != NULL && current->key != key){
			current = current->link; 
		}
		//if key is found, return respective value
		if (current->key == key){
			return current->value;		
		} else {
			//if current iterated through all of hash nodes in chain,
			//throw an exception
		    try {
		 		if (current == NULL){
		 			throw runtime_error("Chain at kay's index does not contain key");
		 		}
		 	} catch (std::runtime_error e){
		 		cerr << "Can't find value associated with given key." << endl;
		 	}	
		}
		
	}
	
}

//If a value associated with the given key exists, removes it, and returns true;
//otherwise, returns false.
bool StringMap::deleteValue(string key){	
    int hash = HashFx(key);
	bool removed = false; 
	
	if (hashArray[hash] == NULL){
		return removed; 
	}else {
		HashNode *current = hashArray[hash];
		HashNode *temp = NULL;
		//iterate until same key is found or end of chain
		while (current->link != NULL && current->key != key){
			temp = current; 
			current = current->link; 
		}
		//if key is found, check whether there's another Node behind it
		//decrement PairsNum as needed. 
		if (current->key == key){
			if(temp == NULL){
				HashNode *next = current->link; 
				delete current; 
				PairsNum --; 
				removed = true; 
				hashArray[hash] = next; 
			} else {
				HashNode *next = current->link;
				delete current; 
				PairsNum --; 
				removed = true;
				temp->link = next; 
			}
		}
		
		return removed;
	}
	
}

//Removes all elements. Subsequent call to isEmpty() should yield true
void StringMap::clear(){
	for (int i=0; i < MAXSIZE ; i++ ){
		HashNode *next = hashArray[i];
		
		while(next != NULL){
			if (hashArray[i] != NULL){
				hashArray[i] = NULL;
			}
			
			HashNode *temp = next;
			next = next->link; 
			delete temp; 	
			PairsNum --; //should eventually be 0; 
		}	
	}
}

//If a value associated with the given key exists, returns true; 
//otherwise, returns false.
bool StringMap::contains(string key){
	bool exist = false; 
	int hash = HashFx(key);
	
	if (hashArray[hash] == NULL){
		return exist; //returns false 
	} else {
		HashNode *current = hashArray[hash]; 
		
		while (current->link != NULL && current->key != key){
			current = current->link;
		}
		
		if (current == NULL){
			exist = false;
		} else {
			exist = true;
		}
		
		return exist; 
	}
}


