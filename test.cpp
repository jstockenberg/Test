#include <vector>
#include <string>
#include <iostream>
#include "Functions.hpp"
#include "Classes.hpp"

using namespace std;

int main () {
    vector<Location> Database;
    string userInput;
    cout << "Bitte geben sie die Postleitzahl ihrer gewünschten Stadt ein! \n";
    cin >> userInput;
    Database == parseMainData();
    cout << "Die Stadt/Städte mit zutreffenden Merkmalen ist/sind: \n";
    for(int i = 0; i < Database.size(); i++){
        if(Database[i].getPostcode() == userInput){
            cout << Database[i].getState() << "\t"; 
            cout << Database[i].getCity() << endl;
        }
    }

    //cout << std::regex_match("Teststring", std::regex("(.*?)(nss)(.*?)")) << endl;
}