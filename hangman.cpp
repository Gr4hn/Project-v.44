#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

int main ()
{
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



    } while (1);
    cout <<"Tack för att du spelade!" << endl;
    return 0;
}