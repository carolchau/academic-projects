/**
 * @file   TestChain.cpp
 * @Author Carol Chau
 * @date   18 February 2016
 * @brief  Main file to test Chain class
 */

#include "Chain.h"
#include <iostream>
#include <string>
using namespace std;

void TestPart1();
void TestPart2();

// Sample main for testing Chain class
int
main(int argc, char **argv) {
	TestPart1();
	TestPart2();
    
	return 0;
}

void TestPart1() {
	Chain<int> a, b; // Two empty Chains are created
	cout << a.Size() << " " << b.Size() << endl; // yields 0 0
	
	Chain<int> d{7}; // A chain containing 7 should be created. 
	//d.print(cout);
	cout << d; // Should just print [7]
	
	a.ReadChain(); // User enters a chain, for example [10 30 -1 2] 
	
	cout << a; // Output should be what user entered.
	
	b.ReadChain(); //Same for b.
	
	cout << b;
	
	Chain<int> c{a}; //Calls copy constructor for c
	cout << c;
	cout << a;
	
	a=b; //Should call the copy assignment operator for a.
	cout << a; 
	
	Chain<int> e = std::move(c); //Move constructor for d.
	cout << e;
	cout << c; 
	
	a = std::move(e); //Move assignment operator for a. 
	cout << a; 
	cout << e; 

} // Destructors will be called.

void TestPart2() {
    
	Chain<string> a, b;
	
	a.ReadChain(); // User provides input for Chain a.
	cout << a << endl;
	
	
	b.ReadChain(); // User provides input for Chain b. 
	cout << b << endl;
	
	cout << a + b << endl; // Concatenates the two Chains.
	
	Chain<string> d = a + b;
	cout << d;
	
	
	cout << d + "hi_there"; // Adds an element to the end.
	
	cout << a[2] << endl; // Should print the 3rd element.
						  // Throw an exception (or even abort()) if is out of
						  // range.
	
	b[1] = "b_string"; // Should change the 2nd element to “b_string”
	cout << b;
	b[0] = "a_string"; 
 	cout << b;

	

} // End of TestPart2






