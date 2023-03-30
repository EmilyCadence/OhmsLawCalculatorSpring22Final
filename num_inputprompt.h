#pragma once

 
#include <limits>
#include <iostream>
#include <string>

#ifndef num_inputprompt_H
 

class num_inputprompt
{
	//Description.  Prompts user for input.  Functions for int, and double, and char Returns user int or user double
	//Filters garbage for numerical input functions.
	//Dependencies.  <IO stream> <Limits>

public:

 

	// local variables

	num_inputprompt();

	double getnuminput_double();

	int getnuminput_int();

	char get__menu_input();

	~num_inputprompt();

	
private:

	std::string input_txt;
	std::string inputerror;
};


#endif