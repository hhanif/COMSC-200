// Lab 7A, String Program
// Programmer: Haris Hanif
// Editor(s) used: Xcode
// Compiler(s) used: G++
// Fig. 18.6: Fig18_06.cpp
// Demonstrating the string find member functions.
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string string1( "noon is 12 pm; midnight is not.");
    int location;
    
    //find "is" at location 5 and 24
    cout << "original string:\n" << string1 << "\n\n(find) \"is\" was found at: " << string1.find("is") << "\n\n(rfind) \"is\" was found at: " << string1.rfind("is");
    
    //find 'o' at location 1
    location = string1.find_first_of("misop");
    cout << "\n\n(find_first_of) found ' " << string1[location] << "' from the group \"misop\" at: " << location;
    
    //find 'o' at location 29
    location = string1.find_last_of("misop");
    cout << "\n\n(find_last_of) found ' " << string1[location] << "' from the group \"misop\" at: " << location;
    
    //find '1' at location 8
    location = string1.find_first_not_of("noi spm");
    cout << "\n\n(find_first_not_of) ' " << string1[location] << "' is not contained in \"noi spm\" and was found at: " << location;
    
    //find '.' at location 12
    location = string1.find_first_not_of("12noi spm");
    cout << "\n\n(find_first_not_of) ' " << string1[location] << "' is not contained in \"12noi spm\" and was " << "found at: " << location << endl;

    // search for characters not in string1
    location = string1.find_first_not_of( "noon is 12 pm; midnight is not.");
    cout << "\nfind_first_not_of(\"noon is 12 pm; midnight is not.\")" << " returned: " << location << endl;
    
    //My own test
    string string2( "Hello World");
    //Find "llo" at location 2
    cout << "\nOriginal string:\n" << string2 << "\n\n(find) \"llo\" was found at: " << string2.find("llo") << endl;
    
    //find 'l' at location 9
    location = string2.find_last_of("Hello");
    cout << "\n\n(find_last_of) found ' " << string2[location] << "' from the group \"Hello\" at: " << location << endl;

    
    
} // end main
