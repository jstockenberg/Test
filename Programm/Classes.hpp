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

        string getPostcode(); 
        void setPostcode(string postcode);
        string getCity();
        void setCity(string city);
        string getState();
        void setState(string state);
        string getLat();
        void setLat(string lat);
        string getLon();
        void setLon(string lon);

};

class Searcher {

    private:
        string userInput, data, origin, destination, lat1, lat2, lon1, lon2;
        int i;
        vector <string> duplicates;
        double originLon, originLat, destinationLon, destinationLat, d, lat, dx, dy;

    public:
        void search(vector <Location> Database, string userInput);
        double distance(vector <Location> Database, string origin, string destination);
        double distanceCalc(double originLat, double destinationLat, double originLon, double destinationLon);       
};

class Parser {

    private:
        string input;
        vector<Location> locations;
        vector<string> vRes, v;
        int i;
    
    public:
        vector<Location> parseMainData();
        vector<Location> parseSideData();
        vector<string> split(const string s, char c);
};