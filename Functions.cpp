#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>
#include "Classes.hpp"

using namespace std;

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