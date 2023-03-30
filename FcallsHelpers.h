#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "history.h"
#include "userinput.h"
#include "num_inputprompt.h"

 


//#ifdef FcallsHelpers_H

class FcallsHelpers {


public:

	
	FcallsHelpers();

	void ohmsLawInputLogic(double[]);

	void exportPaperTape(std::list<history>& history);

	template<typename T>
	inline void writeObject(T& container, std::ofstream& stream)
	{

		for (auto const& i : container) {

			stream << i.historyentry << "\n";

		}

	}

	void getUserInput(double[]);
	
	~FcallsHelpers();


};

#//endif 

 