#pragma once

#include <iostream>
#include "UnitTests.h"
#include "FCalls.h"
 

class UnitTests : public FCalls
{

	public:

	//constructor

	UnitTests();

	//destructor

	~UnitTests();


	void runUnitTests(double[]);

	private:


	bool testCase1(double[]);  //1 amp x 1000 ohms = 1000 volts, 1000 watts.


	

	bool testCase2(double[]); //100 volts / 10 ohms = 10 amps, 1000 watts





	bool testCase3(double[]); //10 volts / 1 amp = 10 ohms, 10 watts




	bool testCase4(double[]); 	//10 watts, 10 amps = 1 volt, 0.1 ohms




	bool testCase5(double[]); 	// 10 watts, 10 volts = 1 amp, 10 ohms.




	bool testCase6(double[]); //Source Voltage 24v, R1 1000 Ohms, R2 100 Ohms. Output Voltage = 2.182 Volts





	//logic unit tests.
	//checks that we are deducing correct formula based on input.; 


	bool testCase7(double[]); // Voltage = current x resistance




	bool testCase8(double[]); 	// Current = voltage / resistance





	bool testCase9(double[]); 	// Resistance = voltage / current





	bool testCase10(double[]); // Power and Resistance


	//debug[6] index
	//index 0 current
	//index 1 voltage and junction voltage for divider 
	//index 2 resistance
	//index 3 vsource
	//index 4 r1
	//index 5 r2
	//index 6 power/watts
	//index 7 numerical flag for logic unit test. 

};

//#endif  
