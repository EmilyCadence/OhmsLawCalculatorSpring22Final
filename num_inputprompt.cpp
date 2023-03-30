#include "num_inputprompt.h"`
 

 
// description.  Prompts user for input.  Functions for int, and double, and char Returns user int or user double
//Filters garbage for numerical input functions.
//Dependencies.  <IO stream> <Limits>


	// local variables

	num_inputprompt::num_inputprompt()
	{
		input_txt = "Enter a number";
		inputerror = "Error, Enter a number without any letters or symbols";
	}

	double num_inputprompt::getnuminput_double() {   // gets type double from user
		double userdouble = 0;
		while ((std::cout << input_txt) && !(std::cin >> userdouble)) {  //gets user input and ignores garbage.
			std::cout << inputerror;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n";
		}

		return (userdouble); // returns numerical input from user.
	}

	int num_inputprompt::getnuminput_int() {   // gets type int from user
		int userint = 0;
		while ((std::cout << input_txt) && !(std::cin >> userint)) {  //gets user input and ignores garbage.
			std::cout << inputerror;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n";
		}

		return (userint); // returns numerical input from user.
	}

	char num_inputprompt::get__menu_input() {
		char ans; // local variable
		std::cin >> ans;
		return ans;
	}

	num_inputprompt::~num_inputprompt()
	{
	}
