#ifndef STRINGMAP_HPP
#define STRINGMAP_HPP

#include <iostream>
#include <string> 
using namespace std; 

struct HashNode{
	string key;
	string value;
	HashNode *link; 
	
    //Creates a Node of a chain
	HashNode(string key, string value){
		this->key = key;
		this->value = value;
		this->link = NULL;
	}

};

class StringMap{
private:
	HashNode **hashArray; 
	const int MAXSIZE = 32; //Maximum size of the hash table array 
	int PairsNum = 0; //The number of key-value pairs (elements) stored in Map
	
public:
	
   /**
    * Default constructor.
    * @post 
	*	An array of size MAXSIZE is created.
	* 	Each box in the array is set to NULL.
    */
	StringMap();
	
   /**
    * Copy constructor.
    * @post 
	*	A deep copy of otherStringMap is made. 
	* 	The number of key-value pairs (elements) is the same in both. 
    */
	StringMap(const StringMap& otherStringMap);
	
   /**
    * Overloaded assignment operator
    * @post 
	*	A deep copy of otherStringMap is made. 
	* 	The number of key-value pairs (elements) is the same in both. 
    */
	StringMap& operator=(const StringMap& otherStringMap);
	
   /**
    * Destructor 
	* @post Frees all dynamically allocated memory
    */
	virtual ~StringMap();
	
   /**
    * Checks if Map is empty
    * @post 
	*	If Map contains no elements, return true;
    * 	Otherwise, returns false.
    */
	bool isEmpty();
	
   /**
    * Hash Function 
	* @post Returns (sum of ASCII values of each letter in string key) % MAXSIZE
	* I read about this function in Absolute C++ 5th ed. by Savitch 
    */
	int HashFx(string key);
	
   /**
    * Gets the number of key-value pairs (elements) stored in the Map
    * @return Maximum number of elements in Map
    */
	int getSize();


   /**
    * Stores valid key-value pair
    * @post If the key AND value is valid, stores the valid key-value pair
    * @return 
    *   If the key AND value is valid, returns true
	*   If key or value is invalid (empty string), returns false
    */
	bool addValue(string key, string value);

   /**
    * Returns value associated with given key
    * @return 
	*   If a value associated with the given key exists, returns it;
    *   Otherwise, throws an exception.
    */
	string getValue(string key);
	
   /**
    * Removes value associated with the given key
    * @post
	*	If a value associated with given key exists, removes it,
    *  	PairsNum (number of key-value pairs) is decremented. 
    * @return 	
	*	True if an element was actually removed;
    *  	Otherwise, returns false.
    */
	bool deleteValue(string key);
	
   /**
    * Removes all elements
    * @post
	* 	Subsequent call to isEmpty() should yield true.
	* 	PaisNum (number of key-value pairs) should be 0. 
    */
	void clear();
	
   /**
    * Returns true if value associated with given key exists
    * @return 
	*   If a value associated with the given key exists, returns true;
    *   Otherwise, returns false.
    */
	bool contains(string key);
	
};

#endif
#include "StringMap.cpp"
