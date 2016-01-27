/*
Chandu's girlfriend loves arrays that are sorted in non-increasing order. Today is her birthday. Chandu wants to give her some sorted arrays on her birthday. But the shop has only unsorted arrays. So, Chandu bought T unsorted arrays and is trying to sort them. But, he doesn't have much time to sort the arrays manually as he is getting late for the birthday party. So, he asked you to write a program to sort the T arrays in non-increasing order. Help him, or his girlfriend will kill him.

Input:
First line contains an integer T, denoting the number of test cases.
First line of each test case contains an integer N, denoting the size of the array.
Second line contains N space separated integers, denoting the array elements Ai.

Output: 
For each test case, print the sorted array in non-increasing order.

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= Ai <= 109

Sample Input(Plaintext Link)
2
5
2 5 2 4 3
5
5 4 2 3 1

Sample Output(Plaintext Link)
5 4 3 2 2
5 4 3 2 1


*/

#include <iostream>
using namespace std;

void merge (int A[], int start, int mid, int end);
void mergesort(int A[], int start, int end);

int main() {

	int T, i, t, N;

	cin >> T; 

	for(t=0; t<T; t++) {
		cin >> N;
		int A[N];
		for(i=0; i<N; i++) {
			cin >> A[i];
		}
		mergesort(A, 0, N-1);
		for(i=N-1; i>=0; i--) {
			cout << A[i] << " ";
		}
		cout << endl;

	}

	return 0;
}



void merge(int A[], int start, int mid, int end) {

	//stores the starting position of both parts in temporary variables.
	int p = start ,q = mid+1;

    int Arr[end-start+1] , k=0;

    for(int i = start ;i <= end ;i++) {
        if(p > mid)      //checks if first part comes to an end or not .
           Arr[ k++ ] = A[ q++] ;

       else if ( q > end)   //checks if second part comes to an end or not
           Arr[ k++ ] = A[ p++ ];

       else if( A[ p ] < A[ q ])     //checks which part has smaller element.
          Arr[ k++ ] = A[ p++ ];

       else
          Arr[ k++ ] = A[ q++];
   }
   for (int p=0 ; p< k ;p ++) {
     /* Now the real array has elements in sorted manner including both 
            parts.*/
       A[ start++ ] = Arr[ p ] ;                          
   }
}

void mergesort(int A[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(A, start, mid);
		mergesort(A, mid+1, end);

		merge(A, start, mid, end);
	}
}