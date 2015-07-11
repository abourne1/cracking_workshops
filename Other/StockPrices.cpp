// The cost of a stock on each day is given in an array, 
// find the max profit that you can make by buying and selling in those days. 
// You are allowed to buy and sell only once.

// For example
// if the given array is {100, 180, 260, 310, 40, 535, 695}, 
// the maximum profit can earned by buying on day 4, selling on day 6. 
// Obviously, If the given array of prices is sorted in decreasing order, 
// then profit cannot be earned at all.

// TO RUN:
// >> g++ -o stock StockPrices.cpp
// >> ./stock
#include <iostream>
#include <algorithm> 

// HINT 1
// O(n) time
// ***************************
// HINT 2
// Divide and Conquet Approach
// ***************************
std::pair<int, int> Kadane(int prices[], int n);
void printArr(int arr[], int n);
void printResults(int StockPrices[], int prices[], std::pair<int, int> rel);
// HINT 3
// maximum subarray problem
// ***************************
// HINT 4
// Kadane's algorithm with modifications

int main()
{
	int StockPrices[] =
		{100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
	int n = sizeof(StockPrices)/sizeof(int);
	printArr(StockPrices, n);
	// find change in price from the previous day
	int prices[n-1];
	for(int i = 1; i <n; i++) {
		prices[i-1] = StockPrices[i] - StockPrices[i-1];
	}
	printArr(prices, n-1);
	// Should be {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	// the objective now is to maximize the sum of the consecutive
	// elements of the subarray
	// because that would mean the difference between the first ans last elements
	// of the subarray is maximum => max profit 
	// use modified version of Kadane's algorithm
	std::pair<int, int> result = Kadane(prices, 16);
	printResults(StockPrices, prices, result);

	return 0;
}


// To learn more, read the article
// https://en.wikipedia.org/wiki/Maximum_subarray_problem#CITEREFBentley1984
std::pair<int, int> Kadane(int prices[], int n)
{
	std::pair<int, int> ans(0,0);
	int max_ending_here = prices[0], max_so_far = prices[0];

	for(int i = 1; i < n; i++) {
		// choose the max between including current number and not
		max_ending_here = std::max(prices[i], max_ending_here+prices[i]);
		if(max_ending_here == prices[i]) {
			// means this number alone is better than previous subarray
			ans.first = i;
			ans.second = i;
		}
		// store max
		max_so_far = std::max(max_so_far, max_ending_here);
		if(max_so_far == max_ending_here) {
			// we updated max_so_far => update the pair
			ans.second = i;
		}
	}
	// since we  were taking the differences between days
	// the indices of the original array StockPrices are different
	// shift it
	ans.second += 1;
	return ans;
}

void printArr(int arr[], int n)
{
	for(int i = 0; i < n; i++) {
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;

	return;
}


void printResults(int StockPrices[], int prices[], std::pair<int, int> res)
{
	std::cout<<std::endl;
	std::cout<<"Best option is to buy on days "<<res.first;
	std::cout<<" and sell on "<<res.second<<std::endl;
	std::cout<<"Buying price "<<StockPrices[res.first]<<std::endl;
	std::cout<<"Selling price "<<StockPrices[res.second]<<std::endl;

	std::cout<<"Profit: "<<StockPrices[res.second] - StockPrices[res.first]<<std::endl;
	std::cout<<std::endl;
	return;
}

// time comlexity is O(n)
