/**
 * @file   Chain.h
 * @Author Carol Chau
 * @date   18 February 2016
 * @brief  Contains the Chain class and its functions
 */

#ifndef CS335_HW1_CHAIN_H_
#define CS335_HW1_CHAIN_H_

#include <iostream>
#include <cstddef>
using namespace std;

/**
 * A class Chain that creates a "chain" (a series of items)
 */
template <typename Object>
class Chain {
	public:
    // Default Constructor
    Chain(): array_{nullptr}, size_{0}{}

    // Parameterized Constructor
		Chain(const Object & val) {
			array_ = new Object[1];
			array_[0] = val;
			size_ = 1;
		}

    // Copy Constructor
    Chain(const Chain &rhs) {
      size_ = rhs.size_;
      array_ = new Object[size_];

      for (int i; i < size_; ++i) {
        array_[i] = rhs.array_[i];
      }
    }

    // Move Constructor
    Chain(Chain &&rhs) {
      array_ = nullptr;
      size_ = 0;

      //setting current Chain to rhs Chain
      array_ = rhs.array_;
      size_ = rhs.size_;

      //reset rhs Chain
      rhs.array_ = nullptr;
      rhs.size_ = 0;
    }

    // Copy Assignment Operator
    Chain& operator=(const Chain &rhs) {
      delete[] array_;

      size_ = rhs.size_;
      array_ = new Object[size_];

      for (int i = 0; i < size_; ++i) {
        array_[i] = rhs.array_[i];
      }

      return *this;
    }

    // Move Assignment Operator
	 	Chain& operator=(Chain &&rhs) {
			std::swap(array_, rhs.array_);
			std::swap(size_, rhs.size_);

	 		return *this;
	 	}

    // Destructor
    ~Chain() {
      delete[] array_;
    }

    // Get Size
	 	int Size() {
	 		return size_;
	 	}

    // Gets & Creates User Chain Input
	 	void ReadChain() {
			Object input;
			cout << "Input array size: ";
			cin >> size_;

			//makes sure the user inputs a valid integer for the array size
			while (cin.fail()) {
        if (cin.get)
			    cout << "Not an integer. Try inputting array size again: ";
				cin.clear();
				cin.ignore(256,'\n');
				cin >> size_;
			}

			array_ = new Object[size_];

			for (int i = 0; i < size_; ++i) {
				cout << "item " << i << ":";
				cin >> input;
				array_[i] = input;
			}
	  }

    // Prints Chain
    void Print(ostream & out) const {
     out << "[ ";

     if (size_ != 0) {
       for (int i = 0; i < size_; i++) {
         out << array_[i] << " ";
       }
     }
    	 out << "]" << endl;
    }

    // Overloaded Output << Operator
    friend ostream& operator<<(ostream &out, const Chain &rhs) {
      rhs.Print(out);
      return out;
    }

    // Overloaded + Operator
    Chain operator+(const Chain &rhs) {
    	int totalSize =  size_ + rhs.size_;

    	Chain<Object> c;
    	c.array_ =new Object[totalSize];
    	c.size_ =totalSize;

    	for (int i = 0; i < size_; i++) {
    		c.array_[i] = array_[i];
    	}

    	for (int i = 0; i < rhs.size_; i++) {
    		c.array_[i+size_] = rhs.array_[i];
    	}

    	return c;
    }

    // Overloaded + Operator for String Concatenation
    Chain operator+(const Object &s) {
    	int totalSize =  size_ +1;

    	Chain<Object> c;
    	c.array_ =new Object[totalSize];
    	c.size_ =totalSize;

    	for (int i = 0; i < size_; i++) {
    		c.array_[i] = array_[i];
    	}

    	c.array_[totalSize-1] = s;

    	return c;
    }

    // Overloaded [] Subscript Operators
    // @return the item of the calling Chain object at index
    Object& operator[](const int i) {
    	//if index i is out of range, throw and exception
    	try {
    		if (i >= size_) {
    			throw runtime_error("Index value is out of range.");
    		}
    	} catch (std::runtime_error e) {
    		cerr << "Index value is out of range." << endl;
    	}

    	return array_[i];
    }

	private:
		size_t size_;
		Object *array_;
};

#endif //CS335_HW1_CHAIN_H_
