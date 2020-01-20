#include <vector>
#include <string>

using namespace std;

class Latlon {
    private:

        string lat;
        string lon;
    
    public:

        string getLat();
        void setLat(string);
        string getLon();
        void setLon(string); 
};

class Location {
    private:

        string postcode;
        string city;
        string state;
        vector<Latlon> latlon; 

    public:

        string getPostcode(); 
        void setPostcode(string);
        string getCity();
        void setCity(string);
        string getState();
        void setState(string);
        vector <Latlon> getLatlon();
        void setLatlon(vector<Latlon>);

};