/*
 * randomizedSelect.cpp
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
int random_partition(vector<int>& arr, int start, int end)
{
    srand(time(NULL));
    int pivotIdx = start + rand() % (end-start+1);
    int pivot = arr[pivotIdx];
    swap(arr[pivotIdx], arr[end]); // move pivot element to the end
    pivotIdx = end;
    int i = start -1;

    for(int j=start; j<=end-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i = i+1;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[pivotIdx]);
    return i+1;
}

int random_selection(vector<int>& arr, int start, int end, int k)
{
    int i;
	if(start == end)
        return arr[start];
    if(!(k<=(end+1) && k>=(start+1)))
    	return -1;
    if(k ==0) return -1;

    if(start < end)
    {

    int mid = random_partition(arr, start, end);
    i = mid - start + 1;
    if(i == k)
        return arr[mid];
    else if(k < i)
        return random_selection(arr, start, mid-1, k);
    else
        return random_selection(arr, mid+1, end, k-i);
    }

}
int main()
{
    int A[] = {9,5,7,5,10,2,3};
    vector<int> v(&A[0], &A[0] + 9);
    int loc = random_selection(v, 0,6,3);
    cout<<loc<<endl;
    return 0;
}
//using namespace std;
//template<class T>
//int Partition(vector<T>&ipA, int left, int right) {
//	// Seed the random number generator
//	    srand((unsigned int)time(0));
//    int size = right - left + 1;
//    // Partitions of size 0 or 1 are already sorted
////    if (size <= 1) {
////        return left;
////    }
//
//    // Select a pivot from the array randomly
//    T iPivot = left + rand()%size;
//    swap(ipA[iPivot],ipA[right]);
//    iPivot = right;
//    // Indices of the entries to be swapped
//    int i = left-1;
//    // Partition array into sections above and below the pivot
//    for(int j=left;j<right-1; j++)
//      	if (ipA[j]<= ipA[iPivot])
//    	{
//      		i = i+1;
//      		swap(ipA[i],ipA[j]);
//
//    	}
//    swap(ipA[right],ipA[i+1]);
//    // Recursively call partition on each partition.
//
//    return (i+1);
//}
//template<class T>
//int randomizedSelect(vector<T>&ipA, int left, int right, int order) {
//    if (left == right)
//    	return left;
//
//    int q = Partition(ipA, left, right);
//    int k = q - left + 1;
//    if(k==order)
//    	return ipA[q];
//    else if (order<k) return randomizedSelect(ipA, left, q -1, order);
//    else return randomizedSelect(ipA, q+1, right, order-k);
//}
//
//int main() {
//	int ray[] = {24, 6, 5, 35, 14, 23, 2, 23, 19};
//    vector<int> iaArray(&ray[0], &ray[0] + 9);
//
//    int selectedN = randomizedSelect(iaArray, 0, 8, 2);
////
//    //Output
//        cout << selectedN;
//        cout <<endl;
//
//    return 0;
//}







