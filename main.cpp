//its actually better practice to have a namespace declaration inside of the functions where its used. since this is a tiny script, and we are only using std, we can declare it at the top of the file. see line 10 and line 21 for a better place to have these if we were getting more complicated
using namespace std;
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

//easy print function.
//endline as "true" will just throw in a breakline after the print. should generally be true unless doing something specific like printing and then having input on the same line. in that instance, "endline should be false"
void print(string text, bool endline = true) {
	//using namespace std

	if(endline)
		cout << text << endl;
	else 
		cout << text;
}

//prints info in an organized little list thing for clean stdout, i guess
void printList(string title, string text) {
	//using namespace std

	cout << endl << setw(15) << left << setfill('.') << title + ":" << text;
}

//this question will print a question and then open up stdin for input and return the input as the output
//setting "endline" param to true will put the stdin text thing under the question. false (default) will keep the stdin on the same line
string ask(string question, bool endline = false, bool checkInteger = false) {
	print(question, endline);

	string output;

	getline(cin, output);

	//check if output is empty and rerun the question with a little error print.
	if(output.empty()) {
		print("Please enter a value!!");

		//we are doing some circular stuff here. basically, we are restarting this function by returning it and rerunning the code
		return ask(question, endline, checkInteger);
	}

	//uses a very basic regex expression to check if the text is just
	if(checkInteger) {
		const regex exp("^\\d+$");
		bool onlyNumbers = regex_match(output, exp);

		//with checkInteger == true, we want to not accept integers. so we error and rerun the question
		if(!onlyNumbers) {
			print("Your answer must only be a number!");

			return ask(question, endline, checkInteger);
		}
		
	}

	return output;
}

int main() {
	print("Welcome to my program. Written by Bren C Straub and da Jay");

	string city, state, zipCode, gpa, age;

	//ask each thing and store it in our variable
	//if you wanted to check a thing and validate it immediately, just stick the code in between these variables and return if you want to stop the code execution
	city = ask("Please enter your City: ");
	state = ask("Please enter your State: ");
	zipCode = ask("Please enter your Zip Code: ", false, true);
	gpa = ask("Please enter your GPA: ");
	age = ask("Please enter your age: ", false, true);

	//lets have a little check and get those youngins out
	if(stoi(age) < 10) {
		print("That age is just too young for our program!!!");

		//quits this main function which quits the main program
		//returning 1 here in the function will exit the process with code "1" which is a general error code
		return 1;
	}

	//now print all of our information in a cool list
	printList("City", city);
	printList("State", state);
	printList("Zip Code", zipCode);
	printList("GPA", gpa);
	printList("Age", age);

	//lets throw in an endline because formatting!!
	cout << endl;
}