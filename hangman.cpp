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

void endGame(bool& gameIsRunning);
int main ()
{
    bool gameIsRunning = true;
    cout <<"Välkommen till spelet Hänga Gubbe!" << endl <<endl;
    do
    {
        cout <<"Välj ett alternativ: " << endl
        << "1. Spela" << endl
        << "2. Highscorelista" << endl
        << "3. Instruktioner" << endl
        << "4. Avsluta" << endl
        << "Ditt val: ";
        int choice;
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
                cout <<"Instruktioner" << endl;
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
    return 0;
}

void endGame(bool& gameIsRunning)
{
    gameIsRunning = false;
}