#include <iostream>
#include <string>
using namespace std;

char mapping[27] = {'\0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void solve (string str, int i, int j, char* output) {
    // base case
    if (i == str.length()) {
        output[j]='\0';
        cout<<output<<endl;
        return;
    }

    // rec case
    // if we pick the first character
    int digit = str[i] - '0';
    output[j] = mapping[digit];
    solve (str, i+1, j+1, output);

    // if we pick 2 digits at a time
    if (i < str.length() -1) {
        int twoDigits = stoi(str.substr(i, 2));
        if (twoDigits <= 26) {
            output[j] = mapping[twoDigits];
            solve(str, i+2, j+1, output);
        }
    }
}

int main() {
    string str;
    char output[str.length()+1];
    cin>>str;
    solve (str, 0, 0, output);
}
