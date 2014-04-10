//Written by Ty Nguyen
//2014.04.10
//QuickSort implemented following book's instruction.
#include <ctime>
#include <stdlib.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::swap
#include <vector>       // std::vector
using namespace std;
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
      		swap(ipA[i],ipA[j]);

    	}
    swap(ipA[right],ipA[i+1]);
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

    int iaArray[] = {24, 5, 5, 35, 14, 23, 2, 23, 19};
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
