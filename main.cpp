#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>

using namespace std;

class Latlon {
    private:

        string lat;
        string lon;
    
    public:

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

class Location {
    private:

        string postcode;
        string city;
        string state;
        vector<Latlon> latlon; 

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
        vector <Latlon> getLatlon() {
            return this->latlon;
        }
        void setLatlon(vector<Latlon> latlon) {
            this->latlon = latlon;
        }

};

/**
 * this function will split a string into parts 
 * 
 * */
/*
vector <string> split(string input) {
    size_t pos = 0;
    string token;
    string delimiter = "\t";
    int i;
    vector <string> data;
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        cout << token << endl;

        // data.push_back(token);
        input.erase(0, pos + delimiter.length());
    } 
    //cout << input << endl;
    
    data.push_back(input);
    for (i=0;i<data.size();i++) {
        cout << data[1] <<"\n";
    }
    return data;
}
*/
vector<string> split(const string& s, char c) {
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

// 1 2 3 

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
   /*
    ifstream file("./bundesland_plz_ort_de.txt");
    string input;
    Location location;
    vector <string> splitoutput;
    vector <Location> locationCollection;
    vector <string> splitted;
    int i;
    while (getline(file,input)) {
        splitoutput = split(input);
        location.setState(splitoutput[0]);
        location.setPostcode(splitoutput[1]);
        location.setCity(splitoutput[2]);
    }    
    locationCollection.push_back(location);
    return locationCollection;
}
*/
int main () {
    vector<Location> Database;
    string userInput;
    cout << "Bitte geben sie die Postleitzahl ihrer gewünschten Stadt ein! \n";
    cin >> userInput;
    Database = parseMainData();
    cout << "Die Stadt/Städte mit zutreffenden Merkmalen ist/sind: \n";
    for(int i = 0; i < Database.size(); i++){
        if(Database[i].getPostcode() == userInput){
            cout << Database[i].getState() << "\t"; 
            cout << Database[i].getCity() << endl;
        }
    }

    //cout << std::regex_match("Teststring", std::regex("(.*?)(nss)(.*?)")) << endl;
}
