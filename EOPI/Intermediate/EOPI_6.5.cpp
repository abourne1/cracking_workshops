// Design an efficient algorithm for the 0 mod n-sum subset problem
// where n is also the size of the input array (non-distinct members are allowed)

#include <iostream>
#include <vector>
// for std::iota
#include <numeric>
// TO RUN
// >> g++ -o 6.5 EOPI_6.5.cpp
// >> ./6.5

template <typename T>
void printVector(std::vector<T> given)
{
	for (unsigned i=0; i<given.size(); i++) {
		std::cout << given.at(i) << ' ';
	}
	
	std::cout << '\n';
}

std::vector<int> nSumSubsetProblem(const std::vector<int> &v)
{
	int n = v.size();
	// let prefix_sum[j] denote the  (sum mod n)
	// where sum is the sum of elements of given array
	// from 0 up until j
	// prefix_sum[j] = sum{A[i] mod n} from i = 0 to j
	std::vector<int> prefix_sum(n);
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += v.at(i);
		prefix_sum[i] = sum % n;
	}
	// consider prefix_sum[j] = sum{A[i] mod n} from i = 0 to j
	// There are two possible cases:
	// 1) all prefix_sum's are different
	// 		for this to be true, there must be some c s.t.
	// 		prefix_sum[c] = 0
	// 		** why? because n has n different possible remainders
	// 		** so in the array of n elements, then one must be 0
	// 		so thats the answer: A[0:c]
	// 2) there is at least one pair a < b s.t. 
	// 		prefix_sum[a] = prefix_sum[b]
	// 		then the answer is: A[a+1:b]
	// 		** why? because that would mean two elements have the same remainder
	// 		** prefix_sum[a] =sum{A[i] mod n} from i = 0 to a
	// 		** prefix_sum[b] =sum{A[i] mod n} from i = 0 to b
	// 		** prefix_sum[b] - prefix_sum[a] = sum{A[i] mod n} from i = a+1 to b
	// 		** if two numbers have the same remainder, then their difference mod n must be 0
	// 		** basic example (18-1) mod 17 = 0 
	// 		** where both 18 mod 17 = 1 and 1 mod 17 = 1 

	// this vec will keep track of the nums we've seen before
	// to capture case 2 
	std::vector<int> rems(n, -1);
	for(int i = 0; i < n; i++) {
		// case 1
		if(prefix_sum[i] == 0) {
			std::vector<int> ans(i+1);
			// iota (def) Assigns to every element in the range [first,last) successive values of val, 
			// as if incremented with ++val after each element is written.
			// ie vector ans would look like  [ 0, 1, ..., i ] afterwards
			std::iota(ans.begin(), ans.end(), 0);
			return ans;
		} else if (rems[prefix_sum[i]] != -1) {
			// i.e. we have seen prefix_sum[k] for some k < i
			// such that prefix_sum[k] = prefix_sum[i]
			// i.e. this is case 2
			std::vector<int> ans(i-rems[prefix_sum[i]]);
			// now we start with val = rems[prefix_sum[i]]+1
			std::iota(ans.begin(), ans.end(), rems[prefix_sum[i]]+1);
			return ans;
		}
		// mark this entry
		rems[prefix_sum[i]] = i;
	}
	// should never reach here
	return v;
}

int printVectorByIndicesAndSum(std::vector<int> v, std::vector<int> indices)
{
	int sum = 0;
	for (unsigned i=indices[0]; i <= indices[indices.size()-1]; i++) {
		std::cout << v[i] << ' ';
		sum += v[i];
	}
	
	std::cout << '\n';

	return sum;
}

int main()
{
	int arr[] = {429, 334, 62, 711, 704, 763, 98, 733, 722, 995};
	std::vector<int> v(arr, arr+sizeof(arr)/sizeof(int));
	printVector(v);
	std::cout<<"Subset: ";
	std::vector<int> indices = nSumSubsetProblem(v);
	int sum = printVectorByIndicesAndSum(v, indices);
	std::cout<<" that sum to "<<sum<<" and mod n = "<< sum%v.size() <<std::endl;

	return 0;
}

