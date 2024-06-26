// prime number in a range
// Sieve of Eratosthenes 
/*
 * Count of prime numbers below 10: 4
Count of prime numbers below 100: 25
Count of prime numbers below 1,000: 168
Count of prime numbers below 10,000: 1,229
Count of prime numbers below 100,000: 9,592
Count of prime numbers below 1,000,000: 78,498
Count of prime numbers below 10,000,000: 664,579
 */
#include<iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	long long  range;
        long long  multiple;
        long long  count;
        long long int prime;
        long long inc;
        range = 1000000;
        bool arr[range+1]={true};
        arr[1]=true;
        arr[2]=true;
        arr[0]=true;
        count = 1 ;
        for(multiple = 2; multiple < range ; multiple+=2)
        {
            arr [ multiple ] = true;
            count++;
        }
        prime = 3;
        // prime * prime < range not only ( prime < range ) 
        while(prime * prime < range)
        {
            if(!arr[prime]){
                inc = prime * 2;
                for(multiple = prime * prime ; multiple < range; multiple += inc )
                {
                    if( ! arr [ multiple ]) count++;
                    arr [ multiple ] = true ;
                    
                }
            }
            prime+=2;

        }
		cout << "Count : " << (range - count);

	return EXIT_SUCCESS;
}

