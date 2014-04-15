/*
 * insertionSort.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: tynguyen
 */
#include <iostream>

void Merge(int* ipA, int iEnd1, int iEnd2) {
    int i = 0;
    int j = iEnd1;
    int k = 0;
    int* ipTemp = new int[iEnd2];
    // Take each next smallest element
    while (i < iEnd1 && j < iEnd2) {
        if (ipA[i] < ipA[j]) {
            ipTemp[k] = ipA[i];
            ++i;
        } else {
            ipTemp[k] = ipA[j];
            ++j;
        }
        ++k;
    }
    // Copy any remaining elements of the 1st array
    while (i < iEnd1) {
        ipTemp[k] = ipA[i];
        ++i;
        ++k;
    }
    // Copy any remaining elements of the 2nd array
    while (j < iEnd2) {
        ipTemp[k] = ipA[j];
        ++j;
        ++k;
    }
    // Copy the merged array back to the original
    for (int iIndex = 0; iIndex < iEnd2; ++iIndex) {
        ipA[iIndex] = ipTemp[iIndex];
    }
    delete [] ipTemp;
}

int main() {
    using namespace std;

    int iaArray[] = {24, 5, 3, 35, 14, 23, 19};
    int iSize = 7;

    // Merge Sort
    for (int i = 1; i < iSize; i *= 2) { //The depth level of merging (lgn)
        for (int j = 0; j < iSize - i; j += 2*i) { //Each depth level of merging, this executes n/(2*i) merges.
            int iEnd2 = (2*i < iSize - j) ? 2*i : iSize - j;
            Merge(&(iaArray[j]), i, iEnd2);
        }
    }

    // Output sorted array
    for (int i = 0; i < iSize; i++){
        cout << iaArray[i] << "  ";
    }
    cout << endl;

    return 0;
}




