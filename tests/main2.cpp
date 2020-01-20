#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string input) {
    size_t pos = 0;
    string token;
    string delimiter = "\t";
    vector <string> data;
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        data.push_back(token);
        //cout << token << endl;
        input.erase(0, pos + delimiter.length());
    }     
    data.push_back(input);
    //cout << input << endl;
    //data = token;
    return data;
}

int main() {
    string test = "Hallo\tHALLO\ttest";
    vector<string> data = split(test);
    int i;
    for (i=0;i<data.size();i++) {
        cout << data[1];
    }
    
}