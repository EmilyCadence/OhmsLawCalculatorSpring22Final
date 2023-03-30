#pragma once
 
#include <iostream>

#ifndef voltagediver_H

class voltagedivider {
public:

	// solves for output of voltage divider with 2 resistors
	// (source voltage x r2) / (r1 + r2)
	// parameters, double source voltage, double r1, double r2
	// returns output of voltage divider type double.

	voltagedivider();

	std::pair<double, int> voltaged_divider(const double, const double, const double);

	~voltagedivider();
};

#endif 