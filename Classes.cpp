#include <vector>
#include <string>

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

