/*
Prateek wants to give a party to his N friends on his birthday, where each friend is numbered from 1 to N. 
His friends are asking for a gift to come to the party, instead of giving him one. 
The cost of the gifts are given in the array Value where ith friend asks for a gift which has a cost Costi.

But, Prateek has only X amount of money to spend on gifts and he wants to invite his friends which are in continuous 
range such that sum of the cost of the gifts of those friends will be exactly equal to X.

If he can invite his friends, who can satisfy the above condition then, print YES otherwise print NO.

Input:
The first line contains a single integer T, denoting the number of test cases. 
In each test case, the following input will be present: - The next line contains two space-separated integers N and X, 
where N represents the number of friends and X represents amount of money which Prateek can spend on gifts. 
- Next N line contains N integers, where ith line contains ith integer, which represents the Costi .

Ouput
Output exactly T lines, each containing the answer to the corresponding test case .

Constraints:
1 <= T <= 10
1 <= N , Costi <= 10^6
1 <= X <= 10^12

Sample Input(Plaintext Link)
1
5 12
1
3
4
5
2

Sample Output(Plaintext Link)
YES


Explanation
In the sample input, T is equal to 1. So, accordingly, in next line, values of N and X are given which are 5 and 12 respectively. 
In the next 5 lines, you have costi asked by ith friend. As friends numbered from 2 to 4 (inclusively) have gifts value 
which are {3, 4, 5}, and their sum equals to 12 - that is, the given value of X. So, the answer is YES.

*/
#include <iostream>
using namespace std;

int main() {
	long int N, X;
	int T, i, t;
	cin >> T;


	if(T < 1 || T > 10){
		return -1;
	}

	for(t=0; t<T; t++) {
		cin >> N; cin >> X;
		int arr[N], temp, sum = 0, flag = 1, turn, flag2 = 1;

		for(i=0; i<N; i++) {
			cin >> arr[i];
			if(arr[i] > X) {
				flag2 = 0;
			}
			sum = sum + arr[i];
		}
		/*cout << "sum: " << sum << endl;*/
		temp = X;
		i = 0;
		turn = 0;
		if(sum < X) {
			flag = 0;
		} else {
			while(temp!=0) {
				if(!flag2) {
					flag = 0;
					break;
				}
				temp = temp - arr[i];
				/*cout << "temp: " << temp << endl;*/
				if(temp == 0) {
					flag = 1;
					break;
				} else if(temp < 0) {
					turn ++;
					i = turn;
					temp = X;
					continue;
				}
				i++;
				/*cout << "i: " << i << endl;*/
				if(i == N) {
					turn ++;
					i = turn;
					temp = X;
					/*cout << "turn: " << turn << endl << "i: " << i << endl;*/
					continue;
				} else if(turn == N) {
					flag = 0;
				} else if (temp < 0) {
					temp = X;
					continue;
				}
			}
		}

		

		if(flag == 0) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}

	return 0;
}