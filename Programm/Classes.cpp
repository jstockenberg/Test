#include "Classes.hpp"

string Location::getPostcode() {
    return this->postcode;
} 
void Location::setPostcode(string postcode) {
    this->postcode = postcode;
}
string Location::getCity() {
    return this->city;
}
void Location::setCity(string city) {
    this->city = city;
}
string Location::getState() {
    return this->state;
}
void Location::setState(string state) {
    this->state = state;
}
string Location::getLat() {
    return this->lat;
}
void Location::setLat(string lat) {
    this->lat = lat;
}
string Location::getLon() {
    return this->lon;
}
void Location::setLon(string lon) {
    this->lon = lon;
}

void Searcher::search(vector <Location> Database, string userInput) {
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
double Searcher::distance(vector <Location> Database, string origin, string destination) {
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
double Searcher::distanceCalc(double originLat, double destinationLat, double originLon, double destinationLon) {
    lat = (originLat+destinationLat)/2*0.01745;
    dy = 111.3*(originLat-destinationLat);
    dx = 111.3*cos(lat)*(originLon-destinationLon);
    d = sqrt((dx*dx)+(dy*dy));

    return d;
}

vector<Location> Parser::parseMainData() {
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
vector<Location> Parser::parseSideData() {
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
vector<string> Parser::split(const string s, char c) {
    string::size_type i = 0;
    string::size_type j = s.find(c);

    while (j != string::npos) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);
        if (j == string::npos) {
            v.push_back(s.substr(i, s.length()));
        }
    }
    return v;
}

