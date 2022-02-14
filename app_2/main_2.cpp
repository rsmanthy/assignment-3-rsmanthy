#include "../code_2/CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{

    CUSatelliteNetwork bob;

     // DO NOT MODIFY THIS.
    if(argc>1) 
    {
        freopen(argv[1],"r",stdin);
    }
     // DO NOT MODIFY ABOVE.

    //variables 
    int decision; 

    // TODO
    //calling the menu
    

    //while loop to keep menu running
    while(true)
    {
        displayMenu();
        cin >> decision;
        //cout << "OSDUGHFSDOUGHSOGDHOSUDGHUHGS" << endl;
        //start of switch case to give the different menu options
        switch(decision)
        {
            case 1: 
            {
                bob.loadDefaultSetup();
                bob.printNetwork();
                break;
            }
            case 2:
            {
                bob.printNetwork();
                break;
            }
            case 3:
            {
                string input;
                cout<< "Enter name of the recipient to receive the message: ";
                //cout << print;
                cin >> input;
                input = bob.bobTheDiggityDog(input);

                cout << endl;
                cout << endl;
                //making sure that everuthing is upper case
                //input = bob.bobTheDiggityDog(input);

                if(bob.searchForSatellite(bob.bobTheDiggityDog(input)) != NULL)
                {
                    bob.transmitInfo(bob.bobTheDiggityDog(input));
                }

                //taking care of if it is null - wont take care of this inside of transmitionInfo 
                else if(bob.isBobNull())
                {
                    cout << "Empty list" << endl;
                }

                else
                {
                    cout << "Satellite not found" << endl; 
                }
                break;
            }
            case 4:
            {
                string input;
                int dist;
                string prev;

                //prompts for user 
                cout << "Enter a new satellite name: " << endl;
                cin >> input;
                //making everyting upper case
                input = bob.bobTheDiggityDog(input);

                //cout statement
                cout << "Enter distance of satellite from earth: " << endl;
                cin >> dist;

                //cout statement
                cout << "Enter the previous satellite name (or First): " << endl;
                cin >> prev;
                //making everyting upper case
                prev = bob.bobTheDiggityDog(prev);

                //use the search to see if the one that the user is looking for is even there and then call the other functions that are necceary 
                //searching to see if prec=v ******* this is where my error is (this should be OR not AND but it)
                //TODO: fix this so it is or and takes care of this looping 
                while(bob.searchForSatellite(prev) == NULL && prev != "FIRST")
                {
                    cout << "INVALID(previous satellite name)...Please enter a VALID satellite name!" << endl;
                    cin >> prev;
                    prev = bob.bobTheDiggityDog(prev);
                }

                //taking care of it is FIRST
                if(prev == "FIRST")
                {
                    bob.addSatelliteInfo("", input, dist);
                }

                //taking care of the else statement
                else
                {
                    bob.addSatelliteInfo(prev, input, dist);
                }
                bob.printNetwork();
                break;
            }
            case 5:
            {
                cout << "Quitting..." << endl;
                cout << "Goodbye!" << endl;
                //returning to stop there if they want to quit 
                return 0;
            }            
         }
     }
    return 0;
}




/************************************************
           Definitions for main_2.cpp
************************************************/
void displayMenu()
{
    // COMPLETE
    cout << "Select a numerical option: " << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Broadcast Info " << endl;
    cout << " 4. Add Satellite " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
