// tuodaan tarvittavat kirjastot
#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

// void funktio jolla voidaan etsiä haluttua sanaa/sisältöä halutusta tiedostosta
void searchFileForPattern(string fileName, string pattern, int type)
{
    // avataan tiedosto luettavaksi
    ifstream fileStream(fileName);

    // jos tiedosto ei ole avattavissa, tulostetaan virheilmoitus
    if (!fileStream)
    {
        cerr << "Error: Could not open file \"" << fileName << "\" for reading." << endl;
        return;
    }

    // luodaan tarvittavia muuttujia
    string line;
    int lineNum = 1;
    int containingLines = 0;

    // Jos ei mitään tyyppiä / tyyppi 0(vain 3 argumenttia)
    if (type == 0)
    {
        while (getline(fileStream, line))
        {
            // haetaan rivejä sisällöllä tiedostosta loopin sisällä ja tulostetaan löydetyt rivit
            if (regex_search(line, regex(pattern)))
            {
                cout << line << endl;
            }
        }
    }

    // Jos tyyppi on -olo / tyyppi 1
    if (type == 1)
    {
        while (getline(fileStream, line))
        {
            if (regex_search(line, regex(pattern)))
            {
                // tulostetaan haettu rivi ja sen rivinumero
                cout << "Found \"" << pattern << "\" on line " << lineNum << ": " << line << endl;
                containingLines++;
            }
            lineNum++;
        }
        // tulostetaan kuinka monta riviä löydettiin halutulla sisällöllä
        cout << "Occurences of lines containing \"" << pattern << "\": " << containingLines << endl;
    }

    // Jos tyyppi on -o / tyyppi 2
    else if (type == 2)
    {
        while (getline(fileStream, line))
        {
            if (regex_search(line, regex(pattern)))
            {
                // tulostetaan haettu sana/sisältö loopin sisällä niin moneen kertaan, kuin se tiedostosta löytyy
                cout << pattern << endl;
            }
            lineNum++;
        }
    }

    // Jos tyyppi on -ol / tyyppi 3
    else if (type == 3)
    {
        while (getline(fileStream, line))
        {
            if (regex_search(line, regex(pattern)))
            {
                // tulostetaan haetun sisällön rivinumero
                cout << " :" << lineNum << endl;
            }
            lineNum++;
        }
    }

    // Jos tyyppi on -oo / tyyppi 4
    else if (type == 4)
    {
        while (getline(fileStream, line))
        {
            if (regex_search(line, regex(pattern)))
            {
                // lasketaan yhteen haettujen rivien määrä
                containingLines++;
            }
            lineNum++;
        }
        // tulostetaan haettujen rivien määrä
        cout << "Occurences of lines containing \"" << pattern << "\": " << containingLines << endl;
    }

    // Jos tyyppi on -or / tyyppi 5
    else if (type == 5)
    {
        while (getline(fileStream, line))
        {
            if (!regex_search(line, regex(pattern)))
            {
                // tulostetaan kaikki rivit, jotka eivät sisällä haettua sisältöä
                cout << line << endl;
            }
            lineNum++;
        }
    }

    // Jos tyyppi on -oi / tyyppi 6
    else if (type == 6)
    {
        while (getline(fileStream, line))
        {
            if (regex_search(line, regex(pattern, regex_constants::icase)))
            {
                // tulostetaan haettu rivi, riippumaton isoista / pienistä kirjaimista
                cout << line << endl;
            }
            lineNum++;
        }
    }

    // Jos tyyppi on -olori / tyyppi 7
    else if (type == 7)
    {
        while (getline(fileStream, line))
        {
            // haetaan kaikki jotka eivät sisällä haettua sisältöä
            if (!regex_search(line, regex(pattern, regex_constants::icase)))
            {
                // tulostetaan rivinumero ja haettu rivi
                containingLines++;
                cout << lineNum << ": " << line << endl;
            }

            lineNum++;
        }

        // tulostetaan rivien määrä jotka eivät sisältäneet haettua sisältöä
        cout << "Occurences of lines NOT containing \"" << pattern << "\": " << containingLines << endl;
    }

    // suljetaan tiedosto
    fileStream.close();
}

// funktio ensimmäiselle inkrementille jossa haetaan omavalintainen sisältö, omavalintaiselta merkkijonolta
void searchFromString(string from, string search)
{

    // kysytään käyttäjältä merkkijonoa
    cout << "Give a string from which to search for: ";
    getline(cin, from);

    // kysytään käyttäjältä mitä etsitään aiemmalta merkkijonolta
    cout << "Give search string: ";
    getline(cin, search);

    // jos löytyy, tulostetaan ilmoitus ja paikka josta sisältö löytyy
    if (from.find(search) != string::npos)
    {
        cout << search << " found in " << from << ". Found from position: " << from.find(search);
    }

    // jos ei löydy, tulostetaan ilmoitus
    else
    {
        cout << search << " not found in " << from;
    }
}

int main(int argc, char *argv[])
{
    // jos komentoriviargumenttien määrä on 1, käytetään ensimmäisen inkrementin funktiota
    if (argc == 1)
    {
        string from;
        string search;

        searchFromString(from, search);
    }

    // jos komentoriviargumenttien määrä on 3, käytetään funktiota tyypillä 0
    else if (argc == 3)
    {
        // File name and pattern provided
        string fileName = argv[2];
        string pattern = argv[1];
        int type = 0;
        searchFileForPattern(fileName, pattern, type);
    }

    // jos komentoriviargumenttien määrä on 4
    else if (argc == 4)
    {
        // käytetään funktiota tyypillä 1
        if (strcmp(argv[1], "-olo") == 0)
        {
            string fileName = argv[3];
            string pattern = argv[2];
            int type = 1;
            searchFileForPattern(fileName, pattern, type);
        }

        // käytetään funktiota tyypillä 2
        else if (strcmp(argv[1], "-o") == 0)
        {
            string fileName = argv[3];
            string pattern = argv[2];
            int type = 2;
            searchFileForPattern(fileName, pattern, type);
        }

        // käytetään funktiota tyypillä 3
        else if (strcmp(argv[1], "-ol") == 0)
        {
            string fileName = argv[3];
            string pattern = argv[2];
            int type = 3;
            searchFileForPattern(fileName, pattern, type);
        }

        // käytetään funktiota tyypillä 4
        else if (strcmp(argv[1], "-oo") == 0)
        {
            string fileName = argv[3];
            string pattern = argv[2];
            int type = 4;
            searchFileForPattern(fileName, pattern, type);
        }

        // käytetään funktiota tyypillä 5
        else if (strcmp(argv[1], "-or") == 0)
        {
            string fileName = argv[3];
            string pattern = argv[2];
            int type = 5;
            searchFileForPattern(fileName, pattern, type);
        }

        // käytetään funktiota tyypillä 6
        else if (strcmp(argv[1], "-oi") == 0)
        {
            string fileName = argv[3];
            string pattern = argv[2];
            int type = 6;
            searchFileForPattern(fileName, pattern, type);
        }

        // käytetään funktiota tyypillä 7
        else if (strcmp(argv[1], "-olori") == 0)
        {
            string fileName = argv[3];
            string pattern = argv[2];
            int type = 7;
            searchFileForPattern(fileName, pattern, type);
        }

        else
        {
            // jos käyttäjä syöttää epäsopivia optioita, tulostetaan virheilmoitus ja käyttöohje
            cerr << "Error: Invalid type." << endl;
            cerr << "Usage: " << argv[0] << " (type) [pattern] <file>" << endl;
            cerr << "Types: -o , -oo, -ol, -olo, -or, -oi, -olori" << endl;
            return 1;
        }
    }

    else
    {
        // jos käyttäjä syöttää epäsopivan määrän argumentteja, tulostetaan virheilmoitus ja käyttöohje
        cerr << "Error: Invalid arguments." << endl;
        cerr << "Usage: " << argv[0] << " (type) [pattern] <file>" << endl;
        cerr << "Types: -o , -oo, -ol, -olo, -or, -oi, -olori" << endl;
        return 1;
    }

    return 0;
}
