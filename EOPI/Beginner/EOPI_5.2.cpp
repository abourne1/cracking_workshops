//  Implement code that takes as input a 64-bit integer x and 
// swaps the bits at indices i and j. 

// TO RUN:
// _________________________________________
// >> g++ -o 5.2 EOPI_5.2.cpp
// >> ./5.2
// _________________________________________

#include <stdint.h>
#include <iostream>
#include <bitset>

 long swap_bits(long x, const int &i, const int &j) 
 { 
 	// only if the bits are actually different
 	// should we change it
	if(((x>>i)&1) != ((x>>j)&1)) {
		x^=(1<< i)| (1<<j); 
	}

 	return x;
}

int main()
{
	long a = 57; //00111001 
	long b = swap_bits(a, 1, 3);
	std::bitset<10> A(a); std::bitset<10> B(b); // to print a in binary
	std::cout<<"For i =1 and j = 3"<<std::endl;
	std::cout<<"a = "<<A.to_string()<<"\nb = "<<B.to_string()<<std::endl;

	return 0;
}