#pragma once

#include <list>
#include <string>
#include <vector>
#include <iostream>
#include "history.h"
#include <math.h>


#ifndef  PAPERTAPE_H

class papertape {
public:

	//creates a string with the variables user entered, formula,
	// and the result.
	// stores in std::vector.
	// parameters result, array with user variables, and
	// type int resultcode which specify's the type of calculation
	// for the result.

	papertape();

	void appenedstring(std::pair<const double, const int>, const double[], std::list<history>& history, double[]);


	~papertape();

private:


};

#endif
