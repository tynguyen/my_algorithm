//Written by Ty Nguyen
//2014.04.10
//QuickSort implemented following book's instruction.
#include <iostream>
#include <ctime>
#include <stdlib.h>

template<class T>
void Partition(T* ipA, int left, int right) {

    // Partitions of size 0 or 1 are already sorted
    if ((right-left +1) <= 1) {
        return;
    }

    // Select a pivot from the array randomly
    T iPivot = ipA[right];

    // Indices of the entries to be swapped
    int i = left-1;
    // Partition array into sections above and below the pivot
    for(int j=left;j<right; j++)
      	if (ipA[j]<= iPivot)
    	{
      		i = i+1;
    		T iTemp  = ipA[i];
    		ipA[i]     = ipA[j];
			ipA[j]     = iTemp;

    	}
    ipA[right] = ipA[i+1];
	ipA[i+1]     = iPivot;
    // Recursively call partition on each partition.

    Partition(ipA, left, i);
    Partition(ipA, i+2,right);
}
template<class T>
void Quicksort(T* ipA, int left, int right) {
    // Seed the random number generator
    srand((unsigned int)time(0));
    Partition(ipA, left, right);
}

int main() {
    using namespace std;

    int iaArray[] = {24, 5, 3, 35, 14, 23, 2, 43, 19};
    int iSize = 9;

    Quicksort(iaArray, 0, 8);

    // Output sorted array
    for (int i = 0; i < iSize; i++){
        cout << iaArray[i] << "  ";
    }
    cout << endl;
    cout<<"TEST"<<endl;

    return 0;
}
