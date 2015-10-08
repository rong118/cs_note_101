/*
Bitwise AND of Numbers Range 
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/


/* find m and n's common left header*/

#include <iostream>
using namespace std;


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count=0;
        while(m!=n){
            m=m>>1;
            n=n>>1;
            count++;
        }
        
        return m<<count;
    }
};

int main(){

  Solution s;
  cout<<s.rangeBitwiseAnd(5,7)<<endl;


	return 0;
}