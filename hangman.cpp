#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

class Highscore
{
    //Kod för Highscore
};

class Player
{
    //Kod för Player
};

void instructions()
{
    cout << "Dessa instruktioner & reglergäller för Hänga Gubbe" << endl << endl
    << "Spelet handlar om att gissa ett slumpmäsigt utvalt ord" << endl
    << "Ordet är dolt och anges med understräck som visar hur många bokstäver ordet innehåller" << endl
    << "Du har 10 gissningar innan gubben hängs, för varje felaktigt gissat bokstav förlorar du en gissning " << endl
    << "För varje bokstav du gissar rätt visas bokstaven i ordet" << endl
    << "Du kan gissa på hela ordet när som helst, men gissar du fel kommer omgången att avslutas." << endl
    << "Under din spelomgång kommer ett slumpmässig bokstav att räkna som 2 gissningar. Du får inte veta vilken bokstav detat är." << endl << endl
    << "Lycka till!" << endl << endl;
}

void endGame(bool& gameIsRunning) {
    gameIsRunning = false;
}

void showMenu(vector<string>& words) {
    int choice;
    bool gameIsRunning = true;
    cout <<"Välkommen till spelet Hänga Gubbe!" << endl << endl << endl;
    do
    {
        cout << "Huvudmeny" << endl << endl
        <<"Välj ett alternativ: " << endl
        << "1. Spela" << endl
        << "2. Highscorelista" << endl
        << "3. Instruktioner" << endl
        << "4. Avsluta" << endl
        << "Ditt val: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout <<"Spela" << endl;
                break;
            case 2:
                cout <<"Highscorelista" << endl;
                break;
            case 3:
                cout << endl << "Instruktioner" << endl << endl;
                instructions();
                break;
            case 4:
                endGame(gameIsRunning);
                break;
            default:
                cout <<"Felaktigt val, försök igen!" << endl;
                break;
        }
    } while (gameIsRunning);
    cout <<"Tack för att du spelade!" << endl;
}

vector<string> loadWordsFromFile(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open the file " << filename << "\n";
        return words;
    }

    string word;
    while (getline(file, word)) {
        if (!word.empty()) {
            words.push_back(word);
        }
    }
    return words;
}

int main ()
{
    vector<string>words = loadWordsFromFile("words.txt");
    showMenu(words);
    
    return 0;
}
