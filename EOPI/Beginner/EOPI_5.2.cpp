 long swap_bits(long x, const int &i, const int &j) 
 { 
	if((x>>i)&1) != ((x>>j)&1) {
		x^=(1<< i)| (1<<j); 
	}
 	return x;
}