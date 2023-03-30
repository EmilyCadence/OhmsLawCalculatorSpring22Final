#include "papertape.h"
 


	//creates a string with the variables user entered, formula,
	// and the result.
	// stores in std::vector.
	// parameters result, array with user variables, and
	// type int result code which specify's the type of calculation
	// for the result.

	papertape::papertape()
	{
	}

	void papertape::appenedstring(std::pair <const double, const int> result, const double uservars[], std::list<history>& history, double results[]) {

		//we pass in result, and numeric flag with 
		//std::pair from ohmslaw calculator class. 

		//uservars[6]
		//index 0 current
		//index 1 voltage and junction voltage for divider 
		//index 2 resistance
		//index 3 vsource
		//index 4 r1
		//index 5 r2
		//index 6 power/watts

		// forms appropriate string if we are solving for voltage
		// checks for condition, of numerical code that tells us
		// what we are solving for.

		std::string resultentry = "";

		switch (result.second) {
		case 1: {   //current * resistance

			//amps 
			results[0] = uservars[0];
			resultentry.append(std::to_string(results[0]));
			resultentry.append(" amps * ");

			//ohms
			results[2] = uservars[2];
			resultentry.append(std::to_string(results[2]));
			resultentry.append(" ohms  ");

			//voltage
			resultentry.append("voltage = ");
			results[1] = result.first;
			resultentry.append(std::to_string(results[1]));
			resultentry.append(" volts,");

			//power (watts)
			resultentry.append(" power = ");
			results[6] = uservars[2] * (pow(uservars[0], 2));
			resultentry.append(std::to_string(results[6]));  // ohms * amps squared
			resultentry.append(" watts");

			results[7] = 1;

			break;
		}

			  // forms appropriate string if we are solving for current
			  // checks for condition, of numerical code that tells us
			  // what we are solving for.

		case 2: {   //voltage / resistance

			//voltage
			results[1] = uservars[1];
			resultentry.append(std::to_string(results[1]));
			resultentry.append(" volts / ");
			results[2] = uservars[2];
			resultentry.append(std::to_string(results[2]));

			//current
			resultentry.append(" ohms  ");
			resultentry.append("current = ");
			results[0] = result.first;
			resultentry.append(std::to_string(results[0]));

			//power(watts)
			resultentry.append(" amps,");
			resultentry.append(" power = ");
			results[6] = ((pow(uservars[1], 2) / uservars[2]));
			resultentry.append(std::to_string(results[6]));//volts squared / ohms
			resultentry.append(" watts");

			results[7] = 2;

			break;
		}

			  // forms appropriate string if we are solving for resistance
			  // checks for condition, of numerical code that tells us
			  // what we are solving for.

		case 3: {   //voltage / current

			//volts
			results[1] = uservars[1];
			resultentry.append(std::to_string(results[1]));
			resultentry.append(" volts / ");

			//current
			results[0] = uservars[0];
			resultentry.append(std::to_string(results[0]));
			resultentry.append(" amps ");

			//ohms
			results[2] = result.first;
			resultentry.append(" resistance = ");
			resultentry.append(std::to_string(results[2]));
			resultentry.append(" ohms,");

			//power
			results[6] = (uservars[1] * uservars[0]);
			resultentry.append(" power = ");
			resultentry.append(std::to_string(results[6]));
			resultentry.append(" watts");

			results[7] = 3;

			break;
		}

			  // forms appropriate string encase of exception.  I.e. invalid input.

		case 4: {
			resultentry.append("Oops something went wrong, Invalid Input");

			break;
		}

			  // forms appropriate string  if we are doing voltage divider calculation.

		case 5: {  //voltage divider

			//source voltage
			resultentry.append("source voltage = ");

			resultentry.append(std::to_string(uservars[3]));
			resultentry.append(" volts, ");

			//resistance 1 
			resultentry.append("r1 = ");
			results[4] = uservars[4];
			resultentry.append(std::to_string(results[4]));
			resultentry.append(" ohms, ");

			//resistance 2
			resultentry.append("r2 = ");
			results[5] = uservars[5];
			resultentry.append(std::to_string(results[5]));
			resultentry.append(" ohms");

			//output voltage at junction of r1 and r2
			resultentry.append(" output voltage at junction node of r1 and r2 = ");
			results[1] = result.first;
			resultentry.append(std::to_string(results[1]));
			resultentry.append(" volts");

			results[7] = 4;
			break;
		}
		}
		// prints appended string with  appropriate output to terminal.

		std::cout << resultentry;

		//erases first element of vector if number of elements has reached 100
		//creates a hard limit so we do not create
		//potential for memory leaks here.
		//tested with for loop, tried to spam with 1000 entries confirmed it works, and 
		//limits to 100 as intended. 


		//if (history.size() == 100) { history.erase(history.begin() + 1); }  //not compatible with std::list 

		//writes string with result array to vector, so we can spit it back out later.
		//uses emplace back to write directly to vectors allocated memory
		//rather than create a bunch of copies.

		history.emplace_back(resultentry);
	}

 

	papertape::~papertape()
	{
	}
