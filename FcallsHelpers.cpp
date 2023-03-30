
#include "FcallsHelpers.h"

FcallsHelpers::FcallsHelpers()
{

}

void FcallsHelpers::ohmsLawInputLogic(double uservars[]) //case 1 logic goes with main calls.
{
	//If we know power, and one of our other variables.  Lets handle that with the following code,
	//and solve for a second, of our other variables.

	// I should have written a method/function to do this but I don't have time to do that.

	if (uservars[6] != 0 && uservars[1] != 0) {  // tests if we entered power and voltage
		//uservars[0] = current
		//uservars[1] = voltage
		//uservars[6] = power/watts

		uservars[0] = uservars[6] / uservars[1]; //calculates current, from power / voltage
	}

	else

		if (uservars[6] != 0 && uservars[0] != 0) { //tests if we entered power and current
			//uservars[0] = current
			//uservars[1] = voltage
			//uservars[6] = power/watts

			uservars[1] = uservars[6] / uservars[0];	//calculates voltage, from power/current
		}

		else

			if (uservars[6] != 0 && uservars[2] != 0) { //tests if we entered power and ohms
				//uservars[0] = current
				//uservars[1] = voltage
				//uservars[2] = resistance
				//uservars[6] = power/watts

				uservars[1] = sqrt(uservars[6] * uservars[2]);  //calculates voltage from square root of power * resistance
			}
}


void FcallsHelpers::exportPaperTape(std::list<history>& history)
{
	std::ofstream outputFile;

	char fileName[250] = "Untitled";  //default. 

	std::cout << "\nEnter file name\n";

	std::cin.ignore();
	std::cin.getline(fileName, 250);   //limits file name to 250 chars.  

	outputFile.open(fileName);

	if (outputFile.fail()) {

		std::cout << "\nError something went wrong creating file\n";

	}
	else if (outputFile.is_open()) {



		writeObject(history, outputFile);


		outputFile.close();
	}


}


void FcallsHelpers::getUserInput(double arr[])
{
	num_inputprompt InputPrompt;

	std::cout << "\n Enter any two known values of, power, current, voltage, or resistance,\n";

	int numInputs = 0;

	for (int i = 0; i < 4; i++) {

		switch (i) {

		case 0: {  //get voltage

			std::cout << "\nEnter Voltage, in Volts, or 0 If Unknown \n"; //prompts user to enter voltage
			arr[1] = InputPrompt.getnuminput_double(); // gets voltage, and saves to uservars array
			if (arr[1] > 0) { numInputs++; }
			break;
		}

		case 1: { //get current 

			std::cout << "\nEnter Current, in Amps, or 0 If Unknown \n"; //prompts user to enter current
			arr[0] = InputPrompt.getnuminput_double(); // gets current, and saves to uservars array.
			if (arr[0] > 0) { numInputs++; };
			break;
		}

		case 2: { //get resistance 

			std::cout << "\nEnter Resistance, in Ohms or 0 If Unknown \n"; //prompts user to enter resistance
			arr[2] = InputPrompt.getnuminput_double(); // gets resistance, and saves to uservars array.
			if (arr[2] > 0) { numInputs++; }
			break;

		}

		case 3: { //gets current {

			std::cout << "\n Enter power in watts,\n"; //
			arr[6] = InputPrompt.getnuminput_double(); // gets power in watts, and saves to uservars array.
			if (arr[6] > 0) { numInputs++; }
			break;
		}

		}  //end of switch 


		if (numInputs >= 2) { break; }  //made this equal or greater in case something weird happens like cosmic bit flip and we somehow end up greater than 2.  

	}
}

FcallsHelpers::~FcallsHelpers()
{
}
