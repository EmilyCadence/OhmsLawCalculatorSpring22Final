
//creates a string with the variables user entered, formula,
// and the result.
// stores in std::vector.
// parameters result, array with user variables, and
// type int resultcode which specify's the type of calculation
// for the result.

//we pass in result, and numeric flag with 
//std::pair from ohmslaw calculator class. 

//uservars[6]
//index 0 current
//index 1 voltage
//index 2 resistance
//index 3 vsource
//index 4 r1
//index 5 r2
//index 6 power/watts

#include "ohmslaw.h"

ohmslaw::ohmslaw()
{
}

std::pair <double, int> ohmslaw::solve_ohmslaw(const double current, const double resistance, const double voltage) {
	const int voltageflag = 1;
	const int currentflag = 2;
	const int resistanceflag = 3;
	const int exceptionflag = 4;

	//Tests input values to see if we need to  solve for voltage 
	//returns voltage, and numerical flag we can use to flag our result as voltage. 

	if ((voltage == NULL) && (current != 0) && (resistance != 0)) {
		return std::make_pair(solve_voltage(current, resistance), voltageflag);
	}

	else

		//tests input values to see if we need to solve for current 
		//returns current, and numerical flag we can use to flag or result as current 

		if ((current == NULL) && (voltage != 0) && (resistance != 0)) {
			return std::make_pair(solve_current(voltage, resistance), currentflag);
		}

		else

			//tests input values to see if we need to solve for resistance
			//returns resistance, and numerical flag we can use to flag our result as resistance. 

			if ((resistance == NULL) && (voltage != 0) && (current != 0)) {
				return std::make_pair(solve_resistance(voltage, current), resistanceflag);
			}

			else

				return std::make_pair(0, exceptionflag);

}	ohmslaw::~ohmslaw()
{
}

	// solves for voltage.  
	// parameters current, and resistance.  
	// returns voltage. 

	double ohmslaw::solve_voltage(const double current, const double resistance) {
			return current * resistance;
		}

	// solves for current.  
	// parameters voltage, and resistance.  
	// returns current. 

	double ohmslaw::solve_current(const double voltage, const double resistance) {
		return voltage / resistance;
	}

	// solves for resistance.  
	// parameters voltage, and current.  
	// returns resistance. 

	double ohmslaw::solve_resistance(const double voltage, const double current) {
		return voltage / current;
	}

 


 