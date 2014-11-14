#include<bitset>
#include<iostream>
#include<vector>
using namespace std;

#define MAX 20

struct clause{
    bitset<MAX> x;
    bitset<MAX> nx; //not x
    bool test(bitset<MAX> v){
	return ( v & x | ~v & nx).any(); // returns true if the clause is satisfiable
    }
    bool test(int v){
	return test(bitset<MAX>(v));
    }
};

