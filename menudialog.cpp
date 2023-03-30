 
#include "menudialog.h"
 

	menudialog::menudialog(){};

	void menudialog::print_main_menu(bool debugMode) {

		if (debugMode == false) {

			std::cout << "\n";
			std::cout << " * * * * * * * * * * * * * * * * * * * * * * * * * ";
			std::cout << "\n \n";
			std::cout << "Enter the following keys, according to menu options then press enter:";
			std::cout << "\n \n";
			std::cout << "1)   Ohms Law Calculator \n \n";
			std::cout << "2)   Voltage Divider Calculator \n \n";
			std::cout << "3)   Print PaperTape \n \n";
			std::cout << "4)   Clear PaperTape History \n \n";
			std::cout << "5)   Save Papertape to File \n \n";
			std::cout << "6)   Exit \n \n";
			std::cout << "7)   Toggle DebugMode \n \n";
			std::cout << "\n \n";
			std::cout << " * * * * * * * * * * * * * * * * * * * * * * * * * ";
			std::cout << "\n";

		}


	}
	// not implemented

	void menudialog::printexit_comfirmation() {
		std::cout << std::endl;
		std::cout << "are you sure you want to exit";
		std::cout << std::endl;
		std::cout << "press y) for yes and n) for no, and then enter";
	}

	void menudialog::debugMenu() {

		std::cout << "\n\n ***********************";
		std::cout << "\n\n Super Secret Debug Mode";
		std::cout << "\n\n 1) Run Unit Tests";
		std::cout << "\n\n 2) Exit DebugMode";
		std::cout << "\n\n ***********************";
		std::cout << "\n";
	}

	menudialog::~menudialog()
	{
	}

 