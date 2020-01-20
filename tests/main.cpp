#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

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
 * 0 => object
 * postcode
 * city
 * state
 * lat
 * long
 * 
*/

string split(string input) {
    size_t pos = 0;
    string token;
    string delimiter = "\t";
    string data;
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        //cout << token << endl;
        input.erase(0, pos + delimiter.length());
    } 
    //cout << input << endl;
    return data;
}

vector<Location> parseMainData() {
    ifstream file("./bundesland_plz_ort_de.txt");
    string input;
    Location location;
    vector <string> splitoutput;
    vector <Location> locationCollection;
    string splitted;
    int i;
    while (getline(file,input)) {
        splitted = split(input);
        splitoutput.push_back(splitted);
        location.setState(splitoutput[0]);
        location.setPostcode(splitoutput[1]);
        location.setCity(splitoutput[2]);
    }    
    locationCollection.push_back(location);
    return locationCollection;
}







vector<string> parsePostcodeLocation(vector<string> &data1) {
    ifstream file("./plz-location.txt");
    string input;
    
    while (getline(file,input)) {
         //cout << input << "\n";
         data1.push_back(input); 
    }    
    return data1;
}

void search(vector<string> &data1) {
    
    string in;
    cout << "Wonach suchen Sie? \n";
    cin >> in;
    vector <string>::iterator it;

    it = find (data1.begin(), data1.end(), in);
    if (it != data1.end()) {
        cout << "1";
    }
    else {
        cout << "0";
    }

}



int main (){
    //vector <string> start;
    //vector <string> data;
    parseMainData();
    //int i;
   // string test = "Hallo\tLeute\tHeute";
    //vector <string> data; ?
    //parseMainData(data);
    //parsePostcodeLocation(data);
    //cout << data.size();
    //search(data);
    

/*
    for (i = 0; i<data.size(); i++) {
        cout << data[i];
    }
    */
}