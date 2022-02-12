# CSCI 2275 – Data Structures - Assignment 3: Pass by Reference and Linked Lists 

## Objectives

1. Creating a geometric progression series.
2. Create, traverse, add nodes to a linked list
3. Get practice implementing classes

## Instructions

Write code to complete Parts 1 and 2. Implement the solution for each part as a separate program. To receive credit for your code, you will need to pass the necessary test cases. Use the following steps to test your code as you work on the assignment:

 1. Open up your Linux terminal, navigate to the build directory of this assignment (e.g. `cd build`).
 2. Run the `cmake ..` command.
 3. Run the `make` command.
 4. If there are no compilation errors, three executables will be generated within the build directory: `run_app_1`, `run_app_2`, and `run_tests`.
 5. If you would like to run your program including your app implementation in the `main` function, execute `run_app_2` from the terminal by typing `./run_app_2`.
 6. To run the grading tests, execute `run_tests` from the terminal by typing `./run_tests`. 

 **NOTE: Make sure to run your program `./run_app_2` WITHOUT command line arguments.**

## Part 1 - Creating a geometric progression series: Append to an array

**Overview:** A sequence of numbers is called a Geometric progression if the ratio of any two consecutive terms is always same. In simple terms, it means that next number in the series is calculated by multiplying a fixed number to the previous number in the series.For example, 2, 4, 8, 16 is a GP because ratio of any two consecutive terms in the series (common difference) is same (4 / 2 = 8 / 4 = 16 / 8 = 2).

 Here we need to form a geometric series by appending to an array .A reference-to-array pointer will be passed to your function `generateSeries`, so that you can modify the pointer to the array itself. 

**NOTE: You do not need to implement the `main` function. It can however be used to test your code out. The *main_1.cpp* is not being graded for this assignment.**
 
Use the function prototype provided below:
```
void generateSeries(int* ​&arr​, int ​&n​, int ​&m, int ​&arraySize​);
```

**INPUT PARAMETERS​:**

+ **arr**  ​is an empty array of type int in which you insert elements. A reference to this array pointer is passed to your function.
+ **n**  ​is starting element of the series array.
+ **m**  is the ratio between a number and its previous number.
+ **arraySize​**  variable stores the size of your array.


**EXAMPLE​:**
```
n = 3, m = 4, arraySize​ = 4
arr = [3, 12, 48, 192]
```

Here the starting element is `n` and `arr[i]/arr[i - 1]  = m`. Total size of the array is `arraySize​`


## Part 2 - Linked Lists: Communication Between Buildings

### Background

In the Lord of the Rings trilogy, there is a scene where a warning beacon is lit in the towers of Minas Tirith, which is seen by a second beacon, prompting them to light their own fire which a third beacon sees, and so forth. This was a rapid means of communication in the days before telegraphs were invented. 

In this problem, you’re going to model and simulate a similar communications network using a linked list. Each node in the list will represent a country and you need to be able to send a message between nodes from one side of the world to the other. 

### Building your own communications network

Implement a class to simulate a linear communication network between CU Buildings. You 
will have to complete the TODOs in both the class implementation in ​`CUBuildingNetwork.cpp​` and 
the driver file ​`main_2.cpp​`. ​Do not modify the header file! 

**NOTE: Make sure to run your program `./run_app_2` WITHOUT command line arguments.**

The linked list itself will be implemented using the following node struct: 

```
struct CUBuilding
{
    string name;         // name of the building
    string message;      // message this building has received
    int numberMessages;  // no. of messages passed through this building
    CUBuilding *next;       // pointer to the next building
    int totalRoom;

};
```

### Class Specifications

The ​**CUBuildingNetwork** class definition is provided in the file `CUBuildingNetwork.hpp​`. ​Do 
not modify this file!​ ​Fill in the file ​`CUBuildingNetwork.cpp​` according to the following specifications. 

**CUBuilding\* head;** 
+ Points to the first node in the linked list 

**CUBuildingNetwork();** 
+ Class constructor; set the head pointer to NULL 

**bool isEmpty();** 
+ Return *true* if the head is NULL, *false* otherwise 

**void addBuildingInfo(CUBuilding\* previous, string buildingName, int totalRoom);** 
+ Insert a new building with name `buildingName` in the linked list after the building pointed 
to by `​previous​`. 
+ If `​previous​` is NULL, then add the new building to the beginning of the list. 
+ Print the name of the building you added according to the following format: 

```
// If you are adding at the beginning use this: 
cout << ​"adding: "​ << countryName << ​" (HEAD)"​ << endl; 
 
// Otherwise use this: 
cout << ​"adding: "​ << countryName << ​" (prev: "​ << previous->name << ")"​ << endl;
```

**void loadDefaultSetup();** 
+ Add the following six buildings, in order, to the network with `addBuildingInfo`: 

"FLMG", "DLC", "ECOT", "CASE", "AERO", "RGNT" 

**CUBuilding\* searchForBuilding(string buildingName);** 
+ Return a pointer to the node with name `buildingName`. If `buildingName` ​cannot be found, return NULL 

**void transmitRoomInfo(string receiver);** 
+ Traverse the linked list from the head to the node with name ​receiver​. For each node in 
this path (including the head), set the node’s ​message​ to `"available room at "+ buildingName + " is " + totalRoom` and increment the node’s `numberMessages​` field. If the list is empty, `print "Empty list"` and exit the function. If the node is not present, `print “Building not found”`. 
+ As you traverse the list, at each node report the message received and the number of messages received using the following cout: (See the end of this document for example output) 

```
cout << node->name << ​" [# messages received: "​ << node->numberMessages << ​"] received: "​ << node->message << endl;
```

**void printNetwork();** 
+ Print the names of each node in the linked list. Below is an example of correct output using the default setup. (Note that you will ​`cout << “NULL”` ​at the end of the path) 

```
== CURRENT PATH == 
FLMG(2) -> DLC(10) -> ECOT(6) -> CASE(5) -> AERO(4) -> RGNT(9) -> NULL
=== 
```

+ If the network is empty then `print ​"nothing in path"`

### Instructions for main file

Your program will start by displaying a menu by calling the `​displayMenu​` function included in main.cpp. The user will select an option from the menu to decide what the program will do, after which, the menu will be displayed again. The specifics of each menu option are described below.

**Option 1: Build Network**

This option calls the `​loadDefaultSetup​` function, then calls the `printNetwork` ​function. You should get the following output: 

```
adding: FLMG (HEAD)
adding: DLC (prev: FLMG)
adding: ECOT (prev: DLC)
adding: CASE (prev: ECOT)
adding: AERO (prev: CASE)
adding: RGNT (prev: AERO)
== CURRENT PATH ==
FLMG(2) -> DLC(10) -> ECOT(6) -> CASE(5) -> AERO(4) -> RGNT(9) -> NULL
===
```

**Option 2: Print Network Path**

Calls the `printNetwork` function. Output should be in the format below: 

```
// Output for the default setup 
== CURRENT PATH == 
FLMG(2) -> DLC(10) -> ECOT(6) -> CASE(5) -> AERO(4) -> RGNT(9) -> NULL
=== 
 
// Output when the linked list is empty 
== CURRENT PATH == 
nothing in path 
===
```

**Option 3: Broadcast Room Info**

Prompt the user to enter the name of a building to receive the broadcast. Pass the building name to the `transmitRoomInfo` function. ​Don’t forget to add a newline before the output is printed. This is done for better readability.

For example, the following should be the output if the linked list contains the default setup from option (1) and the broadcast is sent to "ECOT": 

```
Example 1: 
Enter name of the recipient to receive the message: 
ECOT

FLMG [# messages received: 1] received: available room at FLMG is 2
DLC [# messages received: 1] received: available room at DLC is 10
ECOT [# messages received: 1] received: available room at ECOT is 6
```

If the user then decides to broadcast the message to "AERO", the output will be: 

```
Example 2: 
Enter name of the country to receive the message:  
AERO

FLMG [# messages received: 2] received: available room at FLMG is 2
DLC [# messages received: 2] received: available room at DLC is 10
ECOT [# messages received: 2] received: available room at ECOT is 6
CASE [# messages received: 1] received: available room at CASE is 5
AERO [# messages received: 1] received: available room at AERO is 4
```

If the user then decides to broadcast the message to “MARS”, the output when the building is not present will be: 

```
Example 3: 
Enter name of the country to receive the message: 
MARS
 
Building not found
```

**Option 4: Add Building**

Prompt the user for three inputs: the name of a new building to add to the network, `​newBuilding`, the total number of rooms in the building, `totalRoom`, and the name of a building already in the network, `​previous​`, which will precede the new building. Use the member functions `searchForBuilding` and `addBuildingInfo` to insert `​newBuilding` info into the linked list right after ​previous​. 

* If the user wants to add the new building to the head of the network then they should enter “First” instead of a previous building name. 
* If the user enters an invalid previous building (not present in the linked list), then you need to prompt the user with the following error message and collect input again until they enter a valid previous building name or “First”: 

```
cout << ​"INVALID(previous building name)...Please enter a VALID building name!"​ << endl;
```

* Once a valid previous building name is passed and the new building is added, call the function `printNetwork` to demonstrate the new linked-list.
* All letters of the country to be added should be ​Uppercase ​(sentence case) e.g. If you want to add “ecce, it should be stored as “​ECCE​” in linked list.

For example, the following should be the output if the linked list contains the default setup from option (1) and the user wants to add ECCE after ECOT: 

```
Enter a new building name: ECCE
Enter total room number: 13
Enter the previous building name (or First): ECOT
adding: ECCE (ECOT)
== CURRENT PATH ==
NORLIN(10) -> FLMG(2) -> DLC(10) -> ECOT(6) -> ECCE(13) -> CASE(5) -> AERO(4) -> RGNT(9) -> NULL
===
```

**Option 5: Quit** 

Print the following message: 

```
cout << ​"Quitting..."​ << endl;
```

Finally, print the following before exiting the program: 

```
cout << ​"Goodbye!"​ << endl;
```

### Example run for Part 2

```
Select a numerical option: 
+=====Main Menu=========+
 1. Build Network 
 2. Print Network Path 
 3. Broadcast Room Info 
 4. Add Building 
 5. Quit 
+-----------------------+
#> 2
== CURRENT PATH ==
nothing in path
===
Select a numerical option: 
+=====Main Menu=========+
 1. Build Network 
 2. Print Network Path 
 3. Broadcast Room Info 
 4. Add Building 
 5. Quit 
+-----------------------+
#> 3
Enter name of the recipient to receive the message: 
NORLIN

Empty list
Select a numerical option: 
+=====Main Menu=========+
 1. Build Network 
 2. Print Network Path 
 3. Broadcast Room Info 
 4. Add Building 
 5. Quit 
+-----------------------+
#> 1
adding: FLMG (HEAD)
adding: DLC (prev: FLMG)
adding: ECOT (prev: DLC)
adding: CASE (prev: ECOT)
adding: AERO (prev: CASE)
adding: RGNT (prev: AERO)
== CURRENT PATH ==
FLMG(2) -> DLC(10) -> ECOT(6) -> CASE(5) -> AERO(4) -> RGNT(9) -> NULL
===
Select a numerical option: 
+=====Main Menu=========+
 1. Build Network 
 2. Print Network Path 
 3. Broadcast Room Info 
 4. Add Building 
 5. Quit 
+-----------------------+
#> 4
Enter a new building name: NORLIN
Enter total room number: 10
Enter the previous building name (or First): First
adding: NORLIN (HEAD)
== CURRENT PATH ==
NORLIN(10) -> FLMG(2) -> DLC(10) -> ECOT(6) -> CASE(5) -> AERO(4) -> RGNT(9) -> NULL
===
Select a numerical option: 
+=====Main Menu=========+
 1. Build Network 
 2. Print Network Path 
 3. Broadcast Room Info 
 4. Add Building 
 5. Quit 
+-----------------------+
#> 3
Enter name of the recipient to receive the message: 
RGNT

NORLIN [# messages received: 1] received: available room at NORLIN is 10
FLMG [# messages received: 1] received: available room at FLMG is 2
DLC [# messages received: 1] received: available room at DLC is 10
ECOT [# messages received: 1] received: available room at ECOT is 6
CASE [# messages received: 1] received: available room at CASE is 5
AERO [# messages received: 1] received: available room at AERO is 4
RGNT [# messages received: 1] received: available room at RGNT is 9
Select a numerical option: 
+=====Main Menu=========+
 1. Build Network 
 2. Print Network Path 
 3. Broadcast Room Info 
 4. Add Building 
 5. Quit 
+-----------------------+
#> 3
Enter name of the recipient to receive the message: 
FLMG

NORLIN [# messages received: 2] received: available room at NORLIN is 10
FLMG [# messages received: 2] received: available room at FLMG is 2
Select a numerical option: 
+=====Main Menu=========+
 1. Build Network 
 2. Print Network Path 
 3. Broadcast Room Info 
 4. Add Building 
 5. Quit 
+-----------------------+
#> 3
Enter name of the recipient to receive the message: 
AERO

NORLIN [# messages received: 3] received: available room at NORLIN is 10
FLMG [# messages received: 3] received: available room at FLMG is 2
DLC [# messages received: 2] received: available room at DLC is 10
ECOT [# messages received: 2] received: available room at ECOT is 6
CASE [# messages received: 2] received: available room at CASE is 5
AERO [# messages received: 2] received: available room at AERO is 4
Select a numerical option: 
+=====Main Menu=========+
 1. Build Network 
 2. Print Network Path 
 3. Broadcast Room Info 
 4. Add Building 
 5. Quit 
+-----------------------+
#> 4
Enter a new building name: AERO2
Enter total room number: 40
Enter the previous building name (or First): AERO
adding: AERO2 (prev: AERO)
== CURRENT PATH ==
NORLIN(10) -> FLMG(2) -> DLC(10) -> ECOT(6) -> CASE(5) -> AERO(4) -> AERO2(40) -> RGNT(9) -> NULL
===
Select a numerical option: 
+=====Main Menu=========+
 1. Build Network 
 2. Print Network Path 
 3. Broadcast Room Info 
 4. Add Building 
 5. Quit 
+-----------------------+
#> 5
Quitting...
Goodbye!
```

### Appendix

* CUBuildingNetwork::addBuildingInfo()
    * cout << "adding: " << buildingName << " (HEAD)" << endl;
    * cout << "adding: " << buildingName << " (prev: " << previous->name << ")" << endl;
* CUBuildingNetwork::transmitRoomInfo()
    * cout << "Empty list" << endl;
    * cout << "Building not found" << endl;
    * cout << sender->name << " [# messages received: " << sender->numberMessages << "] received: " << sender->message << endl;
* CUBuildingNetwork::printNetwork()
    * cout << "== CURRENT PATH ==" << endl;
    * cout << "nothing in path" << endl;
    * cout << ptr->name << "(" << ptr->totalRoom << ")" <<" -> ";
    * cout << "NULL" << endl;
    * cout << "===" << endl;
* main()
    * cout << "Enter name of the recipient to receive the message: "<< endl;
    * cout << endl;
    * cout << "Enter a new building name: " << endl;
    * cout << "Enter total room number: " << endl;
    * cout << "Enter the previous building name (or First): " << endl;
    * cout << "INVALID(previous building name)...Please enter a VALID building name!" << endl;
    * cout << "Quitting..." << endl;
    * cout << "Goodbye!" << endl;
* displayMenu()
    * cout << "Select a numerical option: " << endl;
    * cout << "+=====Main Menu=========+" << endl;
    * cout << " 1. Build Network " << endl;
    * cout << " 2. Print Network Path " << endl;
    * cout << " 3. Broadcast Room Info " << endl;
    * cout << " 4. Add Building " << endl;
    * cout << " 5. Quit " << endl;
    * cout << "+-----------------------+" << endl;
    * cout << "#> ";
