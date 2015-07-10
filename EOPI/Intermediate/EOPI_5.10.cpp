//Design an algorithmfor computing the GCD of two numbers 
// without using multiplication, division or the modulus operators

#include <stdint.h>
#include <iostream>
#include <bitset>
#include <limits.h>
#include <limits>
// BEFORE READING
// HINT
// just use recursion
// base case is gcd of the number and 0

// TO RUN:
// _________________________________________
// >> g++ -o 5.10 EOPI_5.10.cpp
// >> ./5.10
// _________________________________________


bool isOdd(unsigned int x)
{
	// check the last bit
	return (x & 0x1) == 1;
}

// right shift bits by one
unsigned int rightShift(unsigned int x)
{
	unsigned int temp = 1 << ((sizeof(unsigned int) * 8) - 1);

	return (x>>1) & ~temp;
}

unsigned int GCD(unsigned int x, unsigned int y)
{
	if(x == 0) {
		return y;
	}
	if(y == 0) {
		return x;
	}
	// both are even
	// that means we can divide both numbers by 2, and thus their gcd is twice the result
	if(!isOdd(x) && !isOdd(y)) {
		// note this assumes that right shifting that 0's are shifted
		// that is why rightShift function is used
		// if that is not the case
		// write a separate function to do r-shifitng
		return 2 * GCD(rightShift(x), rightShift(y));
	}

	if(isOdd(x) && !isOdd(y)) {
		return GCD(x,rightShift(y));
	}

	if(!isOdd(x) && isOdd(y)) {
		return GCD(rightShift(x), y);
	}

	return (x > y) ? GCD(x-y, y) : GCD(x, y-x);
}

int main()
{
	unsigned int x, y;
	unsigned int temp = rightShift(55);
	std::bitset<64> A(temp);
	std::cout<<A.to_string();

	while(1)
	{
		std::cout<<"x: "; std::cin>>x; 
		std::cout<<"y: "; std::cin>>y; 
		// std::bitset<10> A(x); std::bitset<10> B(y);
	    // std::cout<<"x = "<<A.to_string()<<"\ny = "<<B.to_string()<<std::endl; 
		unsigned int ans = GCD(x, y);
		std::cout<<"gcd = "<<ans<<std::endl;
	}


	return 0;
}