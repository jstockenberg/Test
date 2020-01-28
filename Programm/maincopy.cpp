#include <iostream>
#include <vector>
#include "Classes.hpp"

using namespace std;


int main () {

    string choice, userInput, origin, destination;
    vector <Location> Database;
    Parser parse;
    Searcher function;
    double d;
    Database = parse.parseSideData();
    cout << "Möchten sie etwas suchen oder eine Distanz berechnen? (s/d) \n";
    cin >> choice;


    if(choice == "s") {
        cout << "Bitte geben sie eine gültige Postleitzahl oder einen Städtenamen an!\n";
        cin >> userInput;
        cout << "Die Stadt/Städte mit zutreffenden Merkmalen ist/sind: \n";
        function.search(Database,userInput);   
    }
    if (choice == "d") {
        cout << "Bitte geben sie eine Postleitzahl oder einen Städtenamen an!\n";
        cin >> origin;
        cout << "Bitte geben sie eine weitere Postleitzahl oder Stadt an!\n";
        cin >> destination;
        d = function.distance(Database, origin, destination);
        cout << "Die ungefähre Distanz in km beträgt " << d <<"km.\n";
    }
}
