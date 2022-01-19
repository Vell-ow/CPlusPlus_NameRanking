#include <iomanip>
#include <cstdlib>
#include <fstream>
// 
// Programmer:    Andrew Coviello
// Homework 9
// Project 1
// Problem Statement: Write a program that prompts the user for a name to 
// rank, for example "Ethan" or "Maria".  Then loop through code that 
// searches both of the files looking for that name.
// 
// 1. Establish string values for the name that the user will
// be entering to look for in the databases, and the filenames.
// 2. Establish file streams.
// 3. Initialize a large while loop to keep track of a sentinel value,
// quit, which will exit the program if entered(the program would 
// otherwise run forever).
// 4. Prompt the user for the name.
// 5. Use an outer loop first to search the file with girl names, then on 
// the second pass search the file with boy names.
// 6. Within the outer loop:
// Open the appropriate file (either with girl names or boy names).
// Use an inner loop to scan the file looking for the specified name.  
// Use the cin object and the stream extraction operator >> to read 
// each name a number of births.
// If the name is found, then show the user the rank and number or 
// registered births for that name.
// If the name isn't found in the file, tell the user that it isn't one 
// of the ranked names.
// Close the file. 
// 7. Once both files have been processed, go back and prompt for another 
// name. Stop the program when the user enters "quit".
//
#include <iostream>
using namespace std;

int main() {

  // file input streams to receive inputs
  ifstream infile1, infile2;
  int count, ranking;
  // strings used in reading process are initialized, with nameStr being
  // the string given by the user and currentName being the string which is
  // parsed at the current interval
  string nameStr, currentBoyName,currentGirlName;
  // constants to properly access the files
  const string FILE_NAME_1 = "BoyNames2020.txt", FILE_NAME_2 = "GirlNames2020.txt";

  // beginning display prompts user for baby name  
  cout << setw(30) << "****** You Named Me What? ******\n" << endl;
  // if the sentinel value is entered, exit the program
  // otherwise, prompt the user for the name they'd like to rank
  while(nameStr != "quit")
  {
    infile1.open(FILE_NAME_1);
    infile2.open(FILE_NAME_2);    
    // prompt user for name to rank
    cout << setw(30) << "Enter the name you'd like to see ranked: " << endl;
    // read in the name to rank(console, not file reader)
    cin >> nameStr;
    // check for sentinel
    if(nameStr == "quit")
    {
      // quit if sentinel
      exit(0);
    }
    
    // loop through both lists, this loop kind of merges the routes of the 
    // data in the two files using infile1 -> boy and infile2 -> girl
    for(int i = 1; i < 1001; i++)
    {
      // file reads in currentName
      infile1 >> currentBoyName;
      // file reads in ranking next to currentName
      infile1 >> ranking;
      // ignore(to clear buffer and \ns, it's good housekeeping)
      infile1.ignore();
      // if the string in this line of the file matches the input of the
      // user
      infile2 >> currentGirlName;
      infile2 >> ranking;
      infile2.ignore();      
      if(currentBoyName == nameStr)
      {
        // the given name is ranked in this position out of 1000 among
        // boys with the ranking being the number of registered births
        cout << nameStr << " is ranked " << i << " out of 1000 among boys with " << ranking << " registered births." << endl; 
        // end the current iteration safely
        break;
      }
      else if(currentGirlName == nameStr)
      {
        // the given name is ranked in this position out of 1000 among
        // boys with the ranking being the number of registered births
        cout << nameStr << " is ranked " << i << " out of 1000 among girls with " << ranking << " registered births." << endl; 
        // end the current iteration safely
        break;
      }      
    }

    // if it does not match
    if(currentBoyName != nameStr)
    {
      // print "does not exist"  
      cout << nameStr << " is not ranked among the top 1000 boy names." << endl;
    }   

    // if it does not match
    if(currentGirlName != nameStr)
    {
      // print "does not exist"  
      cout << nameStr << " is not ranked among the top 1000 girl names." << endl;
    }
    infile1.close();
    infile2.close();
  }
}
