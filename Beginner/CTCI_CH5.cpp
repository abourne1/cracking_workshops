// TO RUN:
// _________________________________________
// >> g++ -o ch5 CTCI_CH5.cpp
// >> ./ch5
// _________________________________________

#include <stdint.h>
#include <iostream>
#include <bitset>
typedef int32_t int32;

// 5.1
// You are given a 32-bit numbers N and M and two bit positions i and j
// Write a method to insert M into N such that M starts at bit j and ends at bit i.
// You can assume that the bits j through i have enough space to fit all of M.
// That is, if M = 10011, you can assume that there are at least 5 bits between j and i.
// EXAMPLE:
// Input: N = 10000000000, M = 10011, i = 2, j = 6
// Output: N = 10001001100
int32 InsertM(int32 N, int32 M, int i, int j)
{
	int len = j-i+1;
	// the mask is to clear the bits of N
	int mask = (1<<(len+1))-1; // will be of the form 00001...1 with len 1's
	mask = ~(mask<<i); // this will shift it by i positions to get 00..011.110..0
	// and then negate it to get the mask 11..10...01...1
	// clear N, OR with shifted M and return
	return (N &mask) | (M<<i);
}

// 5.3
// Given a positive integer, print the next largest number
// that has the same number of 1 bits in its binary representation
int32 NextLargest(int32 num)
{
	// count sequence of intial 0's (c0) followed by 1's (c1) in num 
	int32 temp = num, c0 =0, c1 = 0, next = num;
	while((temp & 1) == 0 && (temp != 0)) {
		temp >>= 1; 
		c0++;
	}

	while((temp & 1) == 1) {
		temp >>= 1; 
		c1++;
	}
	// check for wrong inputs
	if ((c0+c1==32) || (c0+c1 == 0)) {
		return -1;
	}
	// that means at the position c0+c1 is 0
	// flip it to 1 (that makes our number to be larger than given)
	next |= (1<<(c0+c1));
	// we should put 1 there and redistribute all other 1's to the most right
	int mask = (1<<(c0+c1)) - 1;
	next &= ~mask;
	int ones = (1<<(c1-1))-1;
	next = (next | ones);

	return next;
}

// 5.4
// We have done tricks like (n-1) in previous exercises
// so it shouldnt it be too hard to understand what it going on
// Suggestion: just take any number in binary and see what happens

// 5.5
// First idea is to compare the two bit by bit
// Hint: we just however need to now the number of bits that are different 
// (not so much the position)
// So think of an operation that results in a number of different bits
int bitDiffCount(int a, int b)
{
	int count = 0;
	// so this is the trick part
	// use xor operation
	// c = a ^ b which contains number of bits that are different
	for(int c= a ^ b; c != 0; c = c & (c-1)) {
		count++;
	}

	return count;
}

// 5.6
// HINT:
// It can be done in one line of code

// 5.7
// An array A contains all integers from 0 to n except for one number
// which is missing. The elements of A are represented in binary and the only opertaion 
// we can use to access them is "fetch the jth bit of A[i]," which takes constant time. 
// Write code to find the missing integer.
// Can you do it in O(n) time?
int FindMissingNumber(int arr[], int n) {
	// n is the size of the array
	return FindMissingNumberHelper(arr, n, 0);
}

int FindMissingNumberHelper(int arr[], int n, int bitPosition)
{
	if (bitPosition > 64) {
		// normally you would want to make it generic
		// instead of hard coded 64 value
		return;
	}

	int num;
	int oneBits[n/2], c1 = 0;
	int zeroBits[n/2], c0 = 0;
	bool hasEvenNums = false;
	for(int i = 0; i < n; i++) {
		// fetchBit is provided by the task
		// so we assume its existence
		if(fetchBit(arr[i]) == 0) {
			zeroBits[c0++] = arr[i];
		}
		else {
			oneBits[c1++] = arr[i];
		}
	}

	if(c0 <= c1) {
		num = FindMissingNumberHelper(zeroBits, c0-1, ++bitPosition);
		return (num << 1) | 0;
	} else {
		num = FindMissingNumberHelper(oneBits, c1-1, ++bitPosition);
		return (num << 1) | 1;
	}
}

int main()
{
	std::cout<<"Testing 5.1\n";
	int32 N = 1024;
	int32 M = 19; // which is 10011 (base 2)
	std::cout<<"For i=2 and j = 6: "<<InsertM(N, M, 2, 6)<<std::endl;
	// OUTPUT: 1100
	// Note that 10001001100 (base 2) is 1100 (base 10)	
	std::cout<<"For i=1 and j = 5: "<<InsertM(N, M, 1, 5)<<std::endl;
	// OUTPUT: 1062
	// Note that 10000100110 (base 2) is 1062 (base 10)	
	std::cout<<"For i=1 and j = 5: "<<InsertM(N, M, 1, 5)<<std::endl;
	// OUTPUT: 1062
	// Note that 10000100110 (base 2) is 1062 (base 10)	

	//_______________________________________________________________
	std::cout<<"\nTesting 5.3\n";
	int32 num = 2; // 0010
	std::cout<<"NextLargest of num=2: "<<NextLargest(num)<<std::endl;
	//output: 4
	num = 5; // 0101
	std::cout<<"NextLargest of num=5: "<<NextLargest(num)<<std::endl;
	// should be 0110
	// output: 6

	//_______________________________________________________________
	std::cout<<"\nTesting 5.5\n";
	int a = 57; //00111001 
	int b = 123; // 01111011
	std::bitset<10> A(a); std::bitset<10> B(b); // to print a, b in binary
	std::cout<<"It would require to flip "<<bitDiffCount(a, b)<<" bits for ";
	std::cout<<"a = "<<A.to_string()<<" and b = "<<B.to_string()<<std::endl;
	//second test
	a = 57; //00111001 
	b = 12; // 00001100
	std::bitset<10> B2(b); // to print a, b in binary
	std::cout<<"It would require to flip "<<bitDiffCount(a, b)<<" bits for ";
	std::cout<<"a = "<<A.to_string()<<" and b = "<<B2.to_string()<<std::endl;

	//_______________________________________________________________
	// No test for 5.7 since we assumed existence of fetchBit
	// (though you can also write up that function)

	return 0;
}