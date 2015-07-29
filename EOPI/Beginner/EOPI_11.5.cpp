// Design an O(logn) algorithm for finding the position of the smallest element 
// in a cyclicallysorted array. Assume all elements are distinct. 
// For example, for the array in Figure 11.3,your algorithm should return 4.

// TO RUN:
// _________________________________________
// >> g++ -o 11.5 EOPI_11.5.cpp
// >> ./11.5
// _________________________________________

#include <iostream>
#include <vector>

template <typename T>
int findSmallestElement(const std::vector<T> A)
{
	int l = 0, r = A.size() - 1;
	while (l < r )
	{
		int mid = l + ((r-l) >> 1);
		if (A[mid] > A[r]) {
			// then thats a decreasing section
			// the min should be first on the increasing section
			// so explore left half
			l = mid+1;
		} else {
			// otherwise thats an increasing section
			// limit right edge but include m yet
			// since it might be the smallest element
			r = mid;
		}

	}

	return l;
}

int main()
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(12);
	v.push_back(17);
	v.push_back(3);
	v.push_back(5);
	// 10 12 17 3 5
	int res = findSmallestElement(v);
	std::cout<<"position: "<<res<<std::endl;
	std::cout<<"element: "<<v[res]<<std::endl;
	return 0;
}