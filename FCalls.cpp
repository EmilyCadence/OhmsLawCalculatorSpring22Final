#include "FCalls.h"
#include "UnitTests.h"

std::ostream& operator<<(std::ostream& os, const history& historyentry) { // overloads OS stream class for our custom type of <struct history>
	os << historyentry.historyentry;
	return os;
}

FCalls::FCalls ()
{
}

 
void FCalls::maincalls()
{

	 
	  
	UnitTests test;

	bool exitstatus = false; //used to terminate program, and unwind stack back to main.  
	bool debugMode = false;
	double debugOut[8];
 

	do {
	 
		
		printmainmenu.print_main_menu(debugMode);  //prints main menu

			   //Cheat sheet, with array values for user entered variables.  
			   //we also use these for some of our functionality and math. 
			   //index 0 current
			   //index 1 voltage
			   //index 2 resistance
			   //index 3 vsource
			   //index 4 r1
			   //index 5 r2
			   //index 6 watts.  

		switch (getinput.getnuminput_int()) {   //main menu 

		case 1: {	// ohms law


			uservars.cleararray(uservars.uservars, 7); //initializes array values to 0;

			getUserInput(uservars.uservars);   //gets user input for ohms law calculations

			ohmsLawInputLogic(uservars.uservars);

			//calls papertape appened string function with parameters, of ohms law calculation. 

			tape.appenedstring(calc.solve_ohmslaw(uservars.uservars[0], uservars.uservars[2], uservars.uservars[1]), uservars.uservars, historyentry, debugOut);

			break;
		}

		case 2: { //voltage divider


			uservars.cleararray(uservars.uservars, 7); //initializes array values to 0;

			std::cout << "\nEnter Source Voltage, in Volts\n"; //prompts user to enter source voltage
			uservars.uservars[3] = getinput.getnuminput_double(); // gets source voltage, and saves to uservars array.

			std::cout << "\nEnter Value of R1, in Ohms\n"; //prompts user to enter value of r1
			uservars.uservars[4] = getinput.getnuminput_double(); // gets value of r1, and saves to uservars array.

			std::cout << "\nEnter Value of R2, in Ohms\n"; //prompts user to enter value of r2
			uservars.uservars[5] = getinput.getnuminput_double(); // gets value of r2, and saves to uservars array.

			//call papertape append string function with parameters of voltage divider calculation. 

			tape.appenedstring(voltagediv.voltaged_divider(uservars.uservars[3], uservars.uservars[4], uservars.uservars[5]), uservars.uservars, historyentry, debugOut);

			break;
		}

		case 3: {   //print paper tape
			std::cout << std::endl;
			// https://stackoverflow.com/questions/36405202/printing-out-strings-stored-in-a-vector
			// this was a pain to find something that would work.   Key turned out to be overloading cout <<
			// because of custom data type.  Every code example or demo people seem to give for std::vector
			// is always something easy like type of int and all code declared in main.


			std::copy(historyentry.begin(), historyentry.end(), std::ostream_iterator<history>(std::cout, ",\n"));

			break;
		}

		case 4: {
			//clear paper tape
			historyentry.clear();  //clears vector container, that stores history. 
			std::cout << "\n history cleared \n";
			break;


			/*  function used to test code that  limits history entries, to 100.
			  tries to spam vector with 1000 entries.
			  don't uncomment this.

			for (auto i = 0; i < 1000; i++) {

				if (historyentry.size() == 100) { historyentry.erase(historyentry.begin() + 1); }
				historyentry.emplace_back("test");

			}
			*/

		}

		case 5: {  //papertape file export

			exportPaperTape(historyentry);

			break;

		}

		case 6: {  //quits program 
			exitstatus = true;
			break;
		}

		case 7: {  //debug mode. 

			if (debugMode == false) {

				debugMode = true;
				std::cout << "\n Debug Mode On\n";

			}

			else {
				debugMode = false;
				std::cout << "\n Debug Mode Off\n";

			}


			do {

				printmainmenu.debugMenu();

				int ans;

				ans = getinput.getnuminput_int();



				if (ans == 1)
				{
					test.runUnitTests(debugOut);
					
				}
				else if (ans == 2) {
					debugMode = false;
				}


			} while (debugMode == true);
		}

		}

	} while (exitstatus == false);
  

}

FCalls::~FCalls()
{
}
