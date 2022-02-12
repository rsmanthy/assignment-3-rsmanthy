/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of building structs to      */
/*     represent communication paths between buildings             */
/****************************************************************/

#include "CUBuildingNetwork.hpp"
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
CUBuildingNetwork::CUBuildingNetwork() {
    // TODO

}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUBuildingNetwork::isEmpty()
{
    // TODO
    return true;

}

/*
 * Purpose: Add a new building to the network
 *   between the building *previous and the Building that follows it in the network.
 * @param previous - name of the Building that comes before the new Building
 * @param buildingName - name of the new Building
 * @param numOfroom - number of rooms in the building
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfroom) {
    // TODO

}


/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{
    // TODO

}

/*
 * Purpose: Search the network for the specified building and return a pointer to that node
 * @param buildingName - name of the building to look for in network
 * @return pointer to node of buildingName, or NULL if not found
 *
 */
CUBuilding* CUBuildingNetwork::searchForBuilding(string buildingName)
{
    // TODO
    return nullptr;
}


/*
 * Purpose:
 * @param string receiver
 * @return none
 */
void CUBuildingNetwork::transmitRoomInfo(string receiver) {
    // TODO

}

/*
 * Purpose: prints the current list nicely
 * @param none
 * @return none
 */
void CUBuildingNetwork::printNetwork() {
    // TODO

  }
