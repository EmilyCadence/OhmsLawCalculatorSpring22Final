#pragma once

#include <iostream>

#ifndef ohmslaw_H

class ohmslaw {
public:

	ohmslaw();

	// parameters double current, double resistance, double voltage
	// returns current resistance or voltage as type double.
	// returns numerical flag.  1 = voltage, 2 = current, 3 = resistance, 4 = exception.
	// solves for voltage.
	// parameters current, and resistance.
	// returns voltage.

	std::pair<double, int> solve_ohmslaw(const double, const double, const double);


	~ohmslaw();


private: 

	double solve_voltage(const double, const double);
 

	// solves for current.
	// parameters voltage, and resistance.
	// returns current.

	double solve_current(const double, const double);
	

		// solves for resistance.
		// parameters voltage, and current.
		// returns resistance.

	double solve_resistance(const double, const double);

	 

};

#endif