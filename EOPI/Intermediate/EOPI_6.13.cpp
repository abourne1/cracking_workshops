// Design a O(n) algorithm for rotating an array A of n elements to the right by i positions. 
// You are allowed 0(1) additional storage.
// For example:
// vector = [1, 2, 3, 4, 5] and i = 2, then
// answer is [4, 5, 1, 2, 3]

#include <iostream>
#include <vector>

// TO RUN
// >> g++ -o 6.13 EOPI_6.13.cpp
// >> ./6.13

template <typename T>
void printVector(std::vector<T> given)
{
	for (unsigned i=0; i<given.size(); i++) {
		std::cout << given.at(i) << ' ';
	}
	
	std::cout << '\n';
}

// tricky version =D
template <typename T>
std::vector<T> rotate(std::vector<T> given, int i)
{	
	// HINT (solution)
	// the idea here is that there are always two parts
	// subarray that is just shifted to the right
	// and subarray that "overflowed" ie shifter to the beginning of the array
	// consider [1, 2, 3, 4, a, b] and i = 2
	// then there is a subarray that is just shifted [1, 2, 3, 4] without overflow
	// and second subarray shifted to the beggining
	// so that the result is [a, b, 1, 2, 3, 4]
	// remember the requirement however is to use constant amount of additional space
	// so now the trick is to notice that we can reverse in place
	// that would allow us to get second subarray to the beginning of the array
	// [b, a, 4, 3, 2, 1]
	// now note that we just need to reverse the subarrays
	// [a, b, 1, 2, 3, 4]
	// done
	i %= given.size();
	if(i != 0) {
		reverse(given.begin(), given.end());
		reverse(given.begin(), given.begin()+i);
		reverse(given.begin()+i, given.end());
	}

	return given;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
  	std::vector<int> given(arr, (arr + sizeof(arr) / sizeof(int)));
  	printVector(given);
  	std::cout<<"After rotation i = 2: "<< std::endl;
  	printVector(rotate(given, 2));

  	std::cout<<"After rotation i = 4: "<< std::endl;
  	printVector(rotate(given, 4));
	return 0;
}

