#include<iostream>

using namespace std;

void duplicateReplace(char str[], int i) {

	if (str[i] == '\0') {
		return;
	}
	if (str[i] != str[i+1]) {
		duplicateReplace(str, i+1);
	}

		// perform shifting of all elements by 1 space in the array
		int j=i;
		while(str[j] != '\0'){
			j++;
		}

		while (j>=i+1) {
			str[j+1] = str[j];
			j--;
		}
		// add a * in between consecutive elements
		str[i+1] = '*';
		duplicateReplace(str, i+2);
		return;
}

int main() {
	char str[1000];
	cin>>str;
	duplicateReplace(str,0);
	cout<<str;
	return 0;
}
