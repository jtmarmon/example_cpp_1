#include <stdio.h> // includes standard input & output library which allows us to use things like scanf and printf
#include <string>
#include <iostream>


/* i know we were having problems with the whole string thing in class, but i figured it out.  we need to 
include the string library. also, in C++ string is lower case -  i thought it was upper. finally, we need to use namespace std (or write std::string every time).
i'll explain this more in class, but essentially namespaces are like classes in that they hold certain functions and other important shit - using namespace tells 
the compiler to use the standard namespace for all things it can't find in default C++ libraries
JUST IGNORE THIS IF IT MAKES NO SENSE TO YOU KTHX
*/

//also::
	/* cout and cin are two input and output functions in the standard c++ input/output libraries.  they're much less clunky and annoying than printf and scanf, so we'll
	be using these in class from now. this is their general format
	
	cout << some string to be printed << endl;  <----endl ends the line - it's not mandatory, but it's useful if you know the line will end after the printed statement

	cin >> variable where data will be stored;

	you can remember >> vs << by think that << are like soundwaves getting bigger as they travel from the source, therefore they're output
	*/


//ok! onto the code. don't be intimidated by this - just take time and slowly read it and think it over. i'll be sure to explain all of this at the next meeting


using namespace std;
bool more_than_half(string student) //i put our function before the main function because the compilr won't understand what we're talking about if we call this function in the main function before it has been defined
{ //furthermore, this function is of type bool, so it will return a boolean value (true or false), and takes in a string (in our case the student name) as its parameter
	// the purpose of this function is to determine if at least half the letters in the student's name are in the first half of the alphabet
	int letterCounter=0; //this variable will hold the total number of letters that the student's name has in the first half of the alphabet
	string halfAlphabet[13] = {"a","b","c","d","e","f","g","h","i","j","k","l","m"}; //this string will be used to compare each letter of the student's name to - if it is within this array then it is within the first half of the alphabet :)
	for (size_t i=0; i<student.length(); i++) // our iterator (variable i) is of type size_t because student.length() returns a variable of type size_t (yes you can write your own types)
	{ 
		string currentLetter=student.substr(i,1); //every time we pass through this loop we will iterate to the next letter of the student's name - we pass in two parameters: i and 1 (continued)
		for (int i=0; i<13; i++) //the first parameter, i, is where the substring starts.  the second parameter is the length of our substring
		{
			if (currentLetter==halfAlphabet[i])  //if the current letter of the student's name (defined in previous for loop) is equal to whatever letter of the first half of the alphabet we've currently iterated to
				letterCounter++; //then we add one onto our counter variable
		}

	}
	
	// ONCE WE RETURN TRUE OR FALSE, THE COMPILR RETURNS TO THE PORTION OF THE MAIN FUNCTION WHERE THIS FUNCTION WAS CALLED AND CONTINUES FROM THERE

	if ((student.length()/2)<letterCounter) //finally we've fully run our loops and letterCounter is filled correctly, so now we check if half the length of the student's name is less than the number of letters in the first 1/2 of the alphabet (stored in our counter variable)
		return true; //on a side note: since student.length() is still an integral variable (even though it's of type size_t - the type just stores more space for the variable), the compilr must round whatever student.length()/2  is.  c++ compilrs always round down, which is fine here


	else //if there are less numbers in the first half of the alphabet than in half the length of the name, then return false 
		return false;
}	
int main() // starts the main function of type int with no parameters
{
	int numberOfStudents;
	cout << "How many students are in your class?" << endl; 


	cin >> numberOfStudents; //cin is the input version of cout. note the >> instead of << as it is an input rather than output function
	cout << "Please input each student's name followed by \"enter\" " << endl; //the backslashes i'll explain in class. basically they let you do things that would otherwise be ignored or recognized as something else by the compilr in a string
	string cppStudents[25]; //initializes an array of type "string" with 25 potential slots. these do not have to be used up, so it's a good idea to initialize the array with the max amount you think you might need
	for (int i=0; i<numberOfStudents;i++) // i used a "for" loop to load the classmates' names into the cppStudents array until it had reached the total number of students in the class
		cin >> cppStudents[i]; //every time the loop iterates, the user types in a new name. the loop continues until you reach the total number of students in the class

	for (int i=0;i<numberOfStudents;i++) //now we've loaded all the names, we call the function we just wrote for each name in our array until we've run out of students
		{
			if(more_than_half(cppStudents[i])) //more_than_half is the name of our function! we pass the argument cppStudents[i], meaning whatever name was stored in the array at location i.  now the compilr goes to the function we wrote and executes from there
				cout << cppStudents[i] << " has at least half of its letters in the first half of the alphabet" << endl; //if the function returns true, we print out which name proved to have more than half its letters in the first half of the alphabet
		}
	cout << "Thanks for playing.  Click the exit button on the top right to quit!";
	int holderval;
	cin >> holderval; //i just used this to prevent the program from closing so the user can read. there's likely a better way to do this but i'm tired.

return 0; /* Since we have a function of type int, we must return an integral value at the end of our main function.  
		 returning 0 tells our compiler that the program ran with no errors */
}
