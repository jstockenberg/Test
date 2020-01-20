#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>


using namespace std;

void dateienEinlesen()
{


  std::ifstream dateibdl("C:\\Users\\Jan\\Desktop\\Anw. Programmierung\\project\\bundesland_plz_ort_de.txt");
  std::string line;
  std::vector <vector<std::string>> vectorbdl;
  std::string buf;

    if(dateibdl.is_open())
    {
      std::cout <<"File ist geoeffnet!" <<std::endl;
      for (int i = 0; i < 999; i++)
      {
        vector<string>temp;
        for (int j = 0; j <9; j++)
        {
          temp.push_back(i);
          ++i;
        }
        vectorbdl.push_back(temp);
      }
    }
    else
    {
      std::cout << '\n' << "Fehler ! Datei konnte nicht gelesen werden" << '\n';
    }








    }


/*
      if (dateibdl.eof())
      {
        std::cout << '\n' << "Ende der Datei erreicht!" << '\n';
        dateibdl.close();
      }
      else
      {
        std::cout << '\n' << "Datei ist nicht geoeffnet!" << '\n';
      }
*/





































/*
  ifstream dateibrlae;
  dateibrlae.open("C:\\Users\\Jan\\Desktop\\Anw. Programmierung\\project\\plz-location.txt");


    if (dateibrlae.is_open())
    {
      cout << "Datei ist geöffnet!" <<endl;
    }

    else
    {
      cout << "Fehler ! Datei nicht geöffnet!";
    }


}*/







void datensatzSuchen()
{
  string zeile3;
  size_t pos;

  pos = zeile3.find("72461");
    if(pos!=string::npos)
    {

      cout << "Gefunden: " << zeile3 ;
    }

    else
    {
      cout << "Nicht in der Datenbank!";

    }


}


int main()
{
  cout << "Programm zum Einlesen der Datei PLZ-Ort-Bundesland :" << endl;
  dateienEinlesen();
}
