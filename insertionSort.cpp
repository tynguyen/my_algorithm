/*
 * insertionSort.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: tynguyen
 */

#include <ctime>
#include <stdlib.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::swap
#include <vector>       // std::vector

using namespace std;
void insertionSort(vector<int>&v)
{
	int size = v.size();
	for(int j=1; j<size; j++)
	{
		int key = v[j];
		int i = j-1;
		while(i>=0 && v[i]>key )
		{
			v[i+1] = v[i];
			i --;
		}
		v[i+1] = key;
	}
}



int main()
{
    int A[] = {9,5,7,5,10,2,3};
    vector<int> v(&A[0], &A[0] + 7);

    cout<<"Before sorting: \n"<<endl;
        for(int i=0; i<v.size(); i++)
        	cout<<v[i]<<" ";
    cout<<endl;
    insertionSort(v);
    cout<<"After sorting: \n"<<endl;
    for(int i=0; i<v.size(); i++)
    	cout<<v[i]<<" ";
    return 0;
}






