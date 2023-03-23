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

    switch (type)
    {
    // jos tyyppi on 0, tehdään case 0
    case 0:
        while (getline(fileStream, line))
        {
            // haetaan rivejä sisällöllä tiedostosta loopin sisällä ja tulostetaan löydetyt rivit
            if (regex_search(line, regex(pattern)))
            {
                cout << line << endl;
            }
        }
        break;

    // jos tyyppi on 1, tehdään case 1
    case 1:
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
        break;

    // jos tyyppi on 2, tehdään case 2
    case 2:
        while (getline(fileStream, line))
        {
            if (regex_search(line, regex(pattern)))
            {
                // tulostetaan haettu sana/sisältö loopin sisällä niin moneen kertaan, kuin se tiedostosta löytyy
                cout << pattern << endl;
            }
            lineNum++;
        }
        break;

    // jos tyyppi on 3, tehdään case 3
    case 3:
        while (getline(fileStream, line))
        {
            if (regex_search(line, regex(pattern)))
            {
                // tulostetaan haetun sisällön rivinumero
                cout << " :" << lineNum << endl;
            }
            lineNum++;
        }
        break;

    // jos tyyppi on 4, tehdään case 4
    case 4:
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
        break;

    // jos tyyppi on 5, tehdään case 5
    case 5:
        while (getline(fileStream, line))
        {
            if (!regex_search(line, regex(pattern)))
            {
                // tulostetaan kaikki rivit, jotka eivät sisällä haettua sisältöä
                cout << line << endl;
            }
            lineNum++;
        }
        break;

    // jos tyyppi on 6, tehdään case 6
    case 6:
        while (getline(fileStream, line))
        {
            if (regex_search(line, regex(pattern, regex_constants::icase)))
            {
                // tulostetaan haettu rivi, riippumaton isoista / pienistä kirjaimista
                cout << line << endl;
            }
            lineNum++;
        }
        break;

    // jos tyyppi on 7, tehdään case 7
    case 7:

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
        break;
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
    switch (argc == 1)
    {

    // jos komentoriviargumenttien määrä on 1, käytetään ensimmäisen inkrementin funktiota
    case 1:

        string from;
        string search;

        searchFromString(from, search);

        break;

        // jos komentoriviargumenttien määrä on 3, käytetään funktiota tyypillä 0
    case 3:

        string fileName = argv[2];
        string pattern = argv[1];
        int type = 0;
        searchFileForPattern(fileName, pattern, type);

        break;

    case 4:

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

        break;
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
