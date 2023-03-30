#pragma once


#include "FcallsHelpers.h"
#include "menudialog.h"
#include "history.h"
#include "PaperTape.h"
#include "ohmslaw.h"
#include "voltagedivider.h"
#include "num_inputprompt.h"
#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include <fstream>
 


class FCalls :  public FcallsHelpers 
{
public:

	 
	menudialog printmainmenu;				//functions to print main menu 
	std::list<history> historyentry;		//instance of vector container
	userinput uservars;						//array, to store user entered variables.  
	papertape tape;							//class instance for paper tape, and output functionality
	ohmslaw calc;							//instance for math functions for calculating ohms law 
	voltagedivider voltagediv;				//instance for math function for voltage divider calculation. 
	num_inputprompt getinput;				//class for prompting user for, and handling user input


	double debugOut[8];

	FCalls();

	void maincalls();

	~FCalls();


};

