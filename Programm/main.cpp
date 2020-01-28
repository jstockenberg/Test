#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>

using namespace std;


class Location {
    private:

        string postcode;
        string city;
        string state;
        string lat;
        string lon; 

    public:

        string getPostcode() {
            return this->postcode;
        } 
        void setPostcode(string postcode) {
            this->postcode = postcode;
        }
        string getCity() {
            return this->city;
        }
        void setCity(string city) {
            this->city = city;
        }
        string getState() {
            return this->state;
        }
        void setState(string state) {
            this->state = state;
        }
        string getLat() {
            return this->lat;
        }
        void setLat(string lat) {
            this->lat = lat;
        }
        string getLon() {
            return this->lon;
        }
        void setLon(string lon) {
            this->lon = lon;
        }

};

class Searcher {

    private:
        string userInput, data, origin, destination, lat1, lat2, lon1, lon2;
        int i;
        vector <string> duplicates;
        double originLon, originLat, destinationLon, destinationLat, d, lat, dx, dy;

    public:
        void search(vector <Location> Database, string userInput) {
            if (isdigit(userInput[1])) {
            for(i = 0; i < Database.size(); i++){
                if(Database[i].getPostcode() == userInput){
                    cout << Database[i].getState() << "\t"; 
                    cout << Database[i].getCity() << endl;
                }
            }
            }
            else {
                for (i = 0; i < Database.size(); i++){
                    data = Database[i].getCity();
                    if (std::regex_match(data, std::regex("(.*?)"+userInput+"(.*?)"))) {
                        duplicates.push_back(data);
                    }
                }
                duplicates.erase(unique( duplicates.begin(), duplicates.end()), duplicates.end());
                for (i = 0; i < duplicates.size(); i++){
                    cout << duplicates[i] << endl;
                }
            }
        }
        double distance(vector <Location> Database, string origin, string destination) {
            for(i = 0; i < Database.size(); i++){
                if(Database[i].getPostcode() == origin || Database[i].getCity() == origin){
                    lon1 = Database[i].getLon();
                    lat1 = Database[i].getLat();
                    originLon = stod(lon1);
                    originLat = stod(lat1);
                }
                if(Database[i].getPostcode() == destination || Database[i].getCity() == destination) {
                    lon2 = Database[i].getLon();
                    lat2 = Database[i].getLat();
                    destinationLon = stod(lon2);
                    destinationLat = stod(lat2);
                }
            }
            d = distanceCalc(originLat, destinationLat, originLon, destinationLon);
            return d;
        }
        double distanceCalc(double originLat, double destinationLat, double originLon, double destinationLon) {
            lat = (originLat+destinationLat)/2*0.01745;
            dy = 111.3*(originLat-destinationLat);
            dx = 111.3*cos(lat)*(originLon-destinationLon);
            d = sqrt((dx*dx)+(dy*dy));

            return d;
        }       
};
/*
class Parser {

    private:
        string input;
        vector<Location> locations;
        vector<string> vRes, v;
        int i;
    
    public:
        vector<Location> parseMainData() {
            ifstream file("./bundesland_plz_ort_de.txt");
            while (getline(file,input)) {
                vRes = split(input, '\t');
                
                Location location;
                location.setState(vRes[0]);
                location.setPostcode(vRes[1]);
                location.setCity(vRes[2]);

                locations.push_back(location);
            }
            return locations;
        }
        vector<Location> parseSideData() {
            ifstream file("./plz-location.txt");
            locations = parseMainData();
            while (getline(file,input)) {
                vRes = split(input, '\t');                     
                for (i = 0; i < locations.size(); i++) {
                    if(locations[i].getPostcode() == vRes[0]){
                        locations[i].setLon(vRes[1]);
                        locations[i].setLat(vRes[2]);
                    }
                }
            }
            return locations;
        }
        vector<string> split(const string s, char c) {
            string::size_type i = 0;
            string::size_type j = s.find(c);

            while (j != string::npos) {
                v.push_back(s.substr(i, j-i));
                i = ++j;
                j = s.find(c, j);
                if (j == string::npos)
                    v.push_back(s.substr(i, s.length()));
            }
            return v;
        }
};
*/
/**
 * Diese Funktion teilt einen ihr übergebenen String in mehrere Strings auf.
 * Dabei sucht sie nach einem delimiter (in diesem Falle \t) und teilt den String an dieser Stelle.
 * Am Ende werden die 3 Strings einzeln einem Vector hinzugefügt und dieser wird dann wieder übergeben.
 * */

vector<string> split(const string s, char c) {
    vector<string> v;
    string::size_type i = 0;
    string::size_type j = s.find(c);

    while (j != string::npos) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);

        if (j == string::npos)
            v.push_back(s.substr(i, s.length()));
    }
    return v;
}
/**
 * Diese Funktion analysiert die Einträger der gegebenen Datei, ruft die split Funktion auf und weist den Dateieinträgen
 * ein Objekt der Klasse Location zu
 * Das Resultat der Funktion ist ein Vektor, dessen Einträge in verschieden Location Objekte unterteilt sind
 * */


vector<Location> parseMainData() {
    ifstream file("./bundesland_plz_ort_de.txt");
    string input;
    vector<Location> locations;
    vector<string> vRes;
    while (getline(file,input)) {
        vRes = split(input, '\t');
        
        Location location;
        location.setState(vRes[0]);
        location.setPostcode(vRes[1]);
        location.setCity(vRes[2]);

        locations.push_back(location);
    }
    return locations;
    }

 vector<Location> parseSideData() {
     ifstream file("./plz-location.txt");
     string input;
     vector<string> vRes;
     vector<Location> locations = parseMainData();
     while (getline(file,input)) {
         vRes = split(input, '\t');
                   
         for (int i = 0; i < locations.size(); i++) {
            if(locations[i].getPostcode() == vRes[0]){
                locations[i].setLon(vRes[1]);
                locations[i].setLat(vRes[2]);
            }
         }
     }

     return locations;
 }


double distanceCalc(double originLat, double destinationLat, double originLon, double destinationLon) {
    double lat, dx, dy, d;
    lat = (originLat+destinationLat)/2*0.01745;
    dy = 111.3*(originLat-destinationLat);
    dx = 111.3*cos(lat)*(originLon-destinationLon);
	d = sqrt((dx*dx)+(dy*dy));

    return d;
}

/*void search(vector <Location> Database) {
        string userInput, data;
        int i;
        vector <string> duplicates;
        cout << "Bitte geben sie eine gültige Postleitzahl oder einen Städtenamen an!\n";
        cin >> userInput;
        cout << "Die Stadt/Städte mit zutreffenden Merkmalen ist/sind: \n";

        if (isdigit(userInput[1])) {
            for(i = 0; i < Database.size(); i++){
                if(Database[i].getPostcode() == userInput){
                    cout << Database[i].getState() << "\t"; 
                    cout << Database[i].getCity() << endl;
                }
            }
        }
        else {
            for (i = 0; i < Database.size(); i++){
                data = Database[i].getCity();
                if (std::regex_match(data, std::regex("(.*?)"+userInput+"(.*?)"))) {
                    duplicates.push_back(data);
                }
            }
            duplicates.erase(unique( duplicates.begin(), duplicates.end()), duplicates.end());
            for (i = 0; i < duplicates.size(); i++){
                cout << duplicates[i] << endl;
            }
        } 
}
*/
/*void distance(vector <Location> Database) {
        
        string origin, destination;
        string lat1, lat2, lon1, lon2;
        double originLon, originLat, destinationLon, destinationLat, d;
        int i;
        cout << "Bitte geben sie eine Postleitzahl oder einen Städtenamen an!\n";
        cin >> origin;
        cout << "Bitte geben sie eine weitere Postleitzahl oder Stadt an!\n";
        cin >> destination;
        for(i = 0; i < Database.size(); i++){
            if(Database[i].getPostcode() == origin || Database[i].getCity() == origin){
                lon1 = Database[i].getLon();
                lat1 = Database[i].getLat();
                originLon = stod(lon1);
                originLat = stod(lat1);
            }
            if(Database[i].getPostcode() == destination || Database[i].getCity() == destination) {
                lon2 = Database[i].getLon();
                lat2 = Database[i].getLat();
                destinationLon = stod(lon2);
                destinationLat = stod(lat2);
            }
        }
        d = distanceCalc(originLat, destinationLat, originLon, destinationLon);
        cout << "Die ungefähre Distanz in km beträgt " << d <<"km.\n";
}*/

/**
 * Diese Funktion erkennt, ob es sich beim User Input um eine Postleitzahl oder eine Stadt(bzw. Teile eines Städtenamen)
 * handelt.
 * Sie überprüft die Übereinstimmung des Inputs mit Datensätzen aus der Database und gibt die gewünschten Teile
 * der korrekten Einträge aus.
 * Außerdem löscht sie Duplikate innerhalb des Vektors, der am Ende ausgegeben wird.
 * */
/*
 void PosOrCity () {
    string choice, userInput, origin, destination;
    vector <Location> Database;
    //Parser parse;
    Searcher function;
    double d;
    Database = parseSideData();//parse.parseSideData();
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

    
 }*/

int main () {
   // PosOrCity();
    string choice, userInput, origin, destination;
    vector <Location> Database;
    //Parser parse;
    Searcher function;
    double d;
    Database = parseSideData();//parse.parseSideData();
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
