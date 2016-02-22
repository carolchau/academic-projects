/**
 * @file   Chain.h
 * @Author Carol Chau
 * @date   18 February 2016
 * @brief  Contains the Chain class and its functions
 */

#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_
#include <cstddef>
#include <iostream>
using namespace std;


/**
 *  A test class. A more elaborate class description.
 */

template<typename Object>
class Chain {
 public: 
     /**
     * Destructor
     * 
     */
 	 ~Chain(){
 	 	delete[] array_;
 	 }
	
     /**
     * Default Constructor
     * @brief Creates a Chain with size 0
     */
     Chain(){
		array_ = nullptr;
		size_ = 0; 
     }
	
     /**
     * Parameterized Constructor
     * @brief Creates a Chain with size 1, containing val
     */
	 Chain(const Object & val){
		 array_ = new Object[1];
		 array_[0] = val;
		 size_ = 1;
	 }
	
    /**
    * Copy Constructor
    */
  	Chain(const Chain<Object> &rhs){
		size_ = rhs.size_;
		array_ = new Object[size_];
		
		for (int i=0; i < size_; ++i){
			array_[i] = rhs.array_[i];
		}
 	}
	
    /**
    * Copy Assignment Operator
    */
    Chain& operator=(const Chain<Object> &rhs){
			delete[] array_;
		
			size_ = rhs.size_;
			array_ = new Object[size_];
	
			for (int i=0; i < size_; ++i){
				array_[i] = rhs.array_[i];
			}
			
		return *this;
  	}
   	
    /**
    * Move Constructor
    */
	Chain(Chain &&rhs){
		array_ = nullptr;
		size_ = 0;
	
		//setting current Chain to other Chain
		array_ = rhs.array_; 
		size_ = rhs.size_; 
	
		//reset other Chain
		rhs.array_ = nullptr; 
		rhs.size_ = 0; 
	}
   	
    /**
    * Move Assignment Operator
    */
 	Chain& operator=(Chain<Object> &&rhs){
		std::swap(array_, rhs.array_);
		std::swap(size_, rhs.size_);
	
 		return *this;
 	}
 
    /**
    * Size
	* @return the size of the Chain
    */
 	int Size(){
 		return size_; 
 	}
  	
    /**
    * ReadChain
    * @brief Enables user to set the size of the Chain 
	* 		 and fill it with items
    */
 	void ReadChain(){
		Object input; 
		cout << "Input array size: "; 
		cin >> size_; 
		
		array_ = new Object[size_];
		
		for (int i=0; i < size_; ++i){
			cout << "item " << i << ":"; 
			cin >> input; 
			array_[i] = input; 
		}	
   	}
	
    /**
    * Print()
    * @brief Outputs the items in the Chain
    */
 	void print(ostream & out) const {
 		out << "[ ";
		
		if (size_ != 0){
			
			for (int i=0; i < size_; i++){
 				out << array_[i] << " ";
 			}
 		}
		
		out << "]" << endl;
 	}
	
    /**
    * Output Stream << Operator
    * @return the items in the Chain
    */
	 friend ostream& operator<<(ostream &out, const Chain<Object> &rhs) {
		rhs.print(out);
	    return out; 
	 }
	
    /**
    * Overloading the + Operators. 
    * @brief Concatenates two Chains
	* @return Chain c, which contains the items from the calling 
	*		  object's array and the other array
    */
	Chain operator+(const Chain<Object> &rhs){
		int totalSize =  size_ + rhs.size_; 
		
		Chain<Object> c;
		c.array_ =new Object[totalSize];
		c.size_ =totalSize;
		
		for (int i = 0; i < size_; i++){
			c.array_[i] = array_[i]; 
		}
		
		for (int i = 0; i < rhs.size_; i++){
			c.array_[i+size_] = rhs.array_[i]; 
		}
		
		return c; 	
	}
	
    /**
    * Overloading the + Operators to concatenate with a string 
    * @brief Adds an element to the end of the Chain
	* @return Chain c, which contains the items in the calling
	*		  object's array and the element
    */
	Chain operator+(const Object &s){
		int totalSize =  size_ +1; 
		
		Chain<Object> c;
		c.array_ =new Object[totalSize];
		c.size_ =totalSize;
		
		for (int i = 0; i < size_; i++){
			c.array_[i] = array_[i]; 
		}

		c.array_[totalSize-1] = s;  
	
		return c; 
	}

    /**
    * Overloading the [] Subscript Operators. 
    * @return the item of the calling Chain object and index i
	* 		  throws an exception if the array cannot have that index       
    */
	Object& operator[](const int i){
		//if index i is out of range, throw and exception
		try {
				if (i >= size_){
					throw runtime_error("Index value is out of range.");
				}
			} catch (std::runtime_error e){
			 	cerr << "Index value is out of range." << endl;
			}
			
		return array_[i];
	}
	
 private:
 	size_t size_;
	Object *array_;
};

#endif // CSCI_335_HOMEWORK1_CHAIN_
