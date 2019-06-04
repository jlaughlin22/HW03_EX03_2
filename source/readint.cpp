#include "readint.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <ios>
#include <typeinfo>
using namespace std;

int read_int(const string &prompt, int low, int high) //read_int() function with three parameters
{
    cin.exceptions(ios_base::failbit | ios_base::badbit);
    int number_in_range = 0;
    if (low >= high)
    {
        throw invalid_argument("Lower integer is greater than or equal to higher integer.");
        //Throwing std::invalid_argument exception if range integer value is empty
    }
    while(true) {
        try 
        {
            cout << prompt;
            cin >> number_in_range;
            if ( !(number_in_range <= high && number_in_range >= low) ) //if number entered is not within range // was not grabbing numbers outside of range so i edited it
            {
                throw range_error("Number entered is outside of the range");
            }
            return number_in_range;
        } 
        catch(const range_error& e) 
        {
            cout << "The number that was entered was out of the range." << endl;
        }
        catch(ios_base::failure &ex) 
        {
            // When input is of invalid format; Stream rest, current input line is discarded, and user prompted to try again.
            cout << "Your input was of invalid format. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
        catch (exception &ex) {
            //Seems like a bug in MinGW g++ compiler (https://musteresel.github.io/posts/2017/05/g++-catch-std-ios_base-failure.html)
            cout << "Your input was of invalid format. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
    }
}