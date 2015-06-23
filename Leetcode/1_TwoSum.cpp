/*******************************************************
twoSum
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
********************************************************/

#include <iostream>
#include <vector>
#include <map>
//#include <algorithm>

using namespace std;

/*
keep a hashmap, number value (target - number value) as key and index as value
travese array if we cannot find key in hasmap(for now no number can match sum with it), 
insert it.
otherwise, put its index and item's value in hashmap in output array
*/ 



class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target){
		vector<int> output;
		//vector<int>::iterator itr;
		unordered_map<int,int> myMap;  //<key, value>: value,index
		int findValue;
		//map<int,int>::iterator mitr;
		int vectorLength=numbers.size();
		for(int i=0;i<vectorLength;i++){
			findValue=target-(numbers[i]);
			if(myMap.find(findValue)==myMap.end()){  //what is stored in map.end()??
				myMap[numbers[i]]=i;
			}else{
				output.push_back(myMap[findValue]+1);
				output.push_back(i+1);								
			}
		}
		//sort(output.begin(),output.end());
		return output;
	}
};



int main(){
	vector<int> numbers;

	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(4);
	

	int target=6;

	Solution s;
	s.twoSum(numbers,target);

	return 0;
}