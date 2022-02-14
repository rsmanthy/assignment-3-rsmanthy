/********************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/********************************************************************/
/* TODO: Implement the member functions of class CUSatelliteNetwork */
/*     This class uses a linked-list of satellite structs to        */
/*     represent communication paths between satellites             */
/********************************************************************/

#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUSatelliteNetwork::CUSatelliteNetwork() 
{
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

/*
 * Purpose: Add a new satellite to the network
 *   between the satellite *previous and the satellite that follows it in the network.
 * @param previous - name of the satellite that comes before the new satellite
 * @param satelliteName - name of the new satellite
 * @param distance - distance of satellite from earth
 * @return none
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) 
{
    // TODO
    //while loop to traverse the linked list 
    //start with a temp 
    CUSatellite* temp = new CUSatellite;
    temp->name = satelliteName;
    temp->ditanceFromEarth = distance;
    temp->numberMessages = 0;

    //checking to see if the previous is empty 
    if(previous == "")
    {
        temp->next = head;
        head = temp;
        cout << "adding: " << satelliteName << " (HEAD)" << endl;

        //breaking out
        return;
    }

    CUSatellite* tempHead = new CUSatellite;
    tempHead = head;

    //here is the while loop to itterate through 
    while(tempHead != NULL && tempHead->name != previous)
    {
        //traversing the head
        tempHead = tempHead->next;
        if(tempHead ==NULL)
        {
            //taking care of if it is never found 
            cout << "Cannot add new node; previous node not found\n" << endl;
            return;
        }
    }

    //doing my addition 
    if(tempHead != NULL)
    {
        //adding after previous
        //setting temps next to what previous 
        temp->next = tempHead->next;
        //previous is now pointing to my temp (what I am adding)
        tempHead->next = temp;
        cout << "adding: " << satelliteName << " (prev: " << tempHead->name << ")" << endl;
    }
}


/*
 * Purpose: populates the network with the predetermined satellites
 * @param none
 * @return none
 */

void CUSatelliteNetwork::loadDefaultSetup()
{
    //calling the add satellite satilight
    addSatelliteInfo("", "MAVEN", 9); 
    addSatelliteInfo("", "JUNO", 4); 
    addSatelliteInfo("", "PIONEER", 5); 
    addSatelliteInfo("", "GALILEO", 6); 
    addSatelliteInfo("", "KEPLER", 10); 
    addSatelliteInfo("", "TESS", 2);
}


/*
 * Purpose: Search the network for the specified satellite and return a pointer to that node
 * @param satelliteName - name of the satellite to look for in network
 * @return pointer to node of satelliteName, or NULL if not found
 *
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName)
{
    //initializng variables
    CUSatellite* temp = head;

    // TODO
    while(temp != NULL)
    {
        //checking to see if it is the satellite 
        if(temp->name == satelliteName)
        {
            return temp;
        }
        //traverse 
        temp = temp->next;
    }
    return nullptr;
}


/*
 * Purpose:
 * @param string receiver
 * @return none
 */
void CUSatelliteNetwork::transmitInfo(string receiver) 
{  
    //initializng variables
    CUSatellite* temp = head;

    //checking to see if it is empty
    if(temp == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    //if its not found
    if(searchForSatellite(receiver) == NULL)
    {
        cout << "Satellite not found" << endl; 
        return;
    }

    // Traversing and stopping once it hits reciever
    while(temp != NULL)
    {
        //setting the current nodes message 
        temp->message = "distance of "+ temp->name + " from earth is " + to_string(temp->ditanceFromEarth);
        temp->numberMessages++;
        cout << temp->name << " [# messages received: " << temp->numberMessages << "] received: " << temp->message << endl;
        
        //check if it is here
        if(temp->name == receiver)
        {
            return;
        }
        //traverse 
        temp = temp->next;
    }
}

/*
 * Purpose: prints the current list nicely
 * @param none
 * @return none
 */
void CUSatelliteNetwork::printNetwork() 
{
     /*
    DO NOT MODIFY THIS FUNCTION
    This function is already complete and is used for testing of other functions. 
    */
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    CUSatellite* ptr = head;
    if (ptr == NULL) {
        cout << "nothing in path" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->name << "(" << ptr->ditanceFromEarth << ")" <<" -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}


string CUSatelliteNetwork::bobTheDiggityDog(string bobthedog)
{
    int fish = bobthedog.length();
    for(int i = 0; i < fish; i++)
    {
        bobthedog[i] = toupper(bobthedog[i]);
    }
    return bobthedog;
}

//doing the check for null head
bool CUSatelliteNetwork::isBobNull()
{
    if(head == NULL)
    {
        return true;
    }
    return false;
}