// Given two strings s (the "search string") and t (the "text"), 
// find the first occurrence of 5 in t.

// TO RUN
// >> g++ -o 6.20 EOPI_6.20.cpp
// >> ./6.20


#include <iostream>
#include <string>
#include <math.h>

const int base = 26; // number of letters
const int mod = 997;

// return type is an index of the start of the match
// and -1 otherwise
int rabin_karp(const std::string &t, const std::string &s)
{
	if(s.size() > t.size()) {
		return -1; // no match found obviously
	}

	// idea here is to use haching
	// if two srtring of the same length have the same hash
	// then there might be a match
	// if not, then no need to check
	// this would reduce time complexity
	int t_hash = 0, s_hash = 0;
	// computer hash of string s 
	// and an initial hash to start with off for string t 
	// (we will be updating it later)
	for(int i = 0; i < s.size(); i++) {
		// nothing crazy here
		// just one of the ways to hash
		// so don't think this: goal is to avoid collissions
		t_hash = (t_hash * base + t[i]) % mod;
		s_hash = (s_hash * base + s[i]) % mod;
	}

	// since we computer initial hashes already
	// now we can start with index i = s.size()
	// and of course until we can in string t
	// note that we compare on each iteration of i
	// substring t from (i-s.size() until s.size())
	// to string s
	for(int i = s.size(); i < t.size(); i++) {
		// here if we found a collision
		// also check if the subsrings are actually equal
		if(t_hash == s_hash && t.compare(i-s.size(), s.size(), s) == 0) {
			// std::string::compare
			// int compare (size_t pos, size_t len, const string& str) const;
			return i - s.size(); // found a match!
		}

		// recompute the hash for next iteration
		t_hash -= (t[i-s.size()] * static_cast<int>(pow(base, s.size()-1))) % mod;
		if(t_hash < 0) {
			t_hash += mod;
		}

		t_hash = (t_hash * base + t[i]) % mod;
	}

	// last chance to get the match
	if(t_hash == s_hash && t.compare(t.size()-s.size(), s.size(), s) == 0) {
		return t.size() - s.size(); // found a match!
	}

	return -1;

}

void printResults(const std::string &t, const std::string &s)
{
	std::cout<<"Finding first occurrence of "<<s<<" in "<<t<<std::endl;
	std::cout<<"Match at index = "<<rabin_karp(t, s)<<std::endl;
	return;
}

int main()
{
	std::cout<<std::endl;
	printResults("Forth of July Weekend", "July");
	printResults("Elements of programming", "Element");
	printResults("Happily ever after", "happy"); // comparions are case sensitive
	printResults("Happily ever after", "app"); 
	std::cout<<std::endl;
	return 0;
}

// Time complexity O(|s|+|t|)
// see more about this algorithm on 
// https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm

