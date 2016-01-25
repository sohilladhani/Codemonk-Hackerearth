#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

/*
Problem Statement:
Chandu is a bad student. Once his teacher asked him to print the reverse of a given string. 
He took three hours to solve it. 
The teacher got agitated at Chandu and asked you the same question. Can you solve it?

Input:
The first line contains an integer T, denoting the number of test cases.
Each test case contains a string S, comprising of only lower case letters.

Output:
For each test case, print the reverse of the string S.

Constraints:

1 <= T <= 10
1 <= |S| <= 30
*/

int main() {
	int T, t, i, input_string_len;
	char input_string[30];
	cin >> T;
	if(T < 1 || T > 10){
		return -1;
	}
	for(t=0; t<T; t++) {
		scanf("%s", input_string);
		input_string_len = strlen(input_string);
		if(input_string_len < 1 || input_string_len > 30) {
			return -1;
		}
		for(i = input_string_len-1; i >= 0; i--) {
			cout << input_string[i];
		}
		cout << endl;
	}
	return 0;
}