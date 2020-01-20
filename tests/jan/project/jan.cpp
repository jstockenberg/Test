#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;




  vector<std::string> dateienEinlesen()
  {

    std::ifstream dateibdl("./bundesland_plz_ort_de.txt");
    vector <std::string> vectorbdl;
    string zeile;

      if(dateibdl.is_open())
      {
        std::cout << '\n' << "File ist geoeffnet!" << '\n';
        while(getline(dateibdl, zeile))
        {
          vectorbdl.push_back(zeile);
          //std::cout << zeile << '\n';
        }

      }
      else
      {
        std::cout << '\n' << "Datei ist nicht geoeffnet!" << '\n';
      }

      if (dateibdl.eof())
      {
        std::cout << '\n' << "Ende der Datei erreicht!" << '\n';
      }
      else
      {
        std::cout << '\n' << "Fehler ! Datei konnte nicht gelesen werden" << '\n';
      }

      dateibdl.close();
      return vectorbdl;
}


void datensatzSuchen(vector <string> bdl1)
{
std::vector<std::string>::iterator it = std::find(bdl1.begin(), bdl1.end(), "Thueringen\t99998\tWeinbergen");

    if ( it != bdl1.end())
    {

      cout << "Gefunden: " << '\n';

    }
    else
    {
      cout << "Nicht in der Datenbank!" << '\n';

    }


}



int main()
{
  int i;
  cout << "Programm zum Einlesen der Datei PLZ-Ort-Bundesland :" << endl;
  std::vector <string> bdl1 = dateienEinlesen();
  for (i = 0; i < bdl1.size(); i++)
  {
    cout << bdl1[i] << '\n';
  }
  datensatzSuchen(bdl1);
  //datensatzSuchen();
}




















/*  ifstream dateibrlae;
  dateibrlae.open("C:\\Users\\Jan\\Desktop\\Anw. Programmierung\\project\\plz-location.txt");


    if (dateibrlae.is_open())
    {
      cout << "Datei ist geöffnet!" <<endl;
    }

    else
    {
      cout << "Fehler ! Datei nicht geöffnet!";
    }


}
*/
