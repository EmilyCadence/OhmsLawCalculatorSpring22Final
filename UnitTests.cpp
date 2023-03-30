#include "UnitTests.h"
#include "FCalls.h"
 

UnitTests::UnitTests()
{
}

UnitTests::~UnitTests()
{
}

void UnitTests::runUnitTests(double debugOut[])
{
	
	std::cout << "\nunit tests entered\n";
	testCase1( debugOut);
	testCase2( debugOut);
	testCase3( debugOut);
	testCase4( debugOut);
	testCase5( debugOut);
	testCase6( debugOut);
 
}

void dumpOutput(double debugOut[]) {   //wrote this to demonstrate use of pointers. 

	double* ptr;
	ptr = debugOut;

	std::cout << "\ndebugOut array dump";

	for (int i = 0; i < 8; i++) {

		std::cout << " index " << i << " = " << *(ptr + i);

	}

	
}

bool UnitTests::testCase1(double debugOut[])   //1 amp x 1000 ohms = 1000 volts, 1000 watts.
{

	std::cout << "\n***************************************";
	std::cout << "\nTEST CASE 1:";
	std::cout << "\nINPUT: 1 AMP 1000 OHMS ";
	std::cout << "\nEXPECTED OUTPUT: 1000 VOLTS 1000 WATTS";
		

	//input

	const double amps_in = 1;
	const double ohms_in = 1000;

	//output

	const double volts_out = 1000;
	const double watts_out = 1000;

	//clear input and output arrays

	uservars.cleararray(uservars.uservars, 7);
	uservars.cleararray(debugOut, 8);

	uservars.uservars[0] = amps_in;
	uservars.uservars[2] = ohms_in;

	ohmsLawInputLogic(uservars.uservars);

	std::cout << "\n";
	tape.appenedstring(calc.solve_ohmslaw(uservars.uservars[0], uservars.uservars[2], uservars.uservars[1]), uservars.uservars, historyentry, debugOut);
	std::cout << "\n";
	testCase7(debugOut);

	dumpOutput(debugOut);


	if (debugOut[1] == volts_out && debugOut[6] == watts_out)
	{ 
		 
		std::cout << "\nOUTPUT VOLTS: " << debugOut[1] << " OUTPUT WATTS: " << debugOut[6];
		std::cout << "\nTEST CASE 1 PASSED";
		std::cout << "\n***************************************";
		return true;
	}

	else
	{
		 
		std::cout << "\nOUTPUT VOLTS: " << debugOut[1] << " OUTPUT WATTS: " << debugOut[6];
		std::cout << "\nTEST CASE 1 FAILED";
		std::cout << "\n***************************************";
		return false;
	}
	 
	
}

bool UnitTests::testCase2(double debugOut[])   //100 volts / 10 ohms = 10 amps, 1000 watts
{
	std::cout << "\nTEST CASE 2:";
	std::cout << "\nINPUT: 100 Volts 10 OHMS ";
	std::cout << "\nEXPECTED OUTPUT: 10 AMPS 1000 WATTS";

	const double volts_in = 100;
	const double ohms_in = 10;

	//output

	const double amps_out = 10;
	const double watts_out = 1000;

	//clear input and output arrays

	uservars.cleararray(uservars.uservars, 7);
	uservars.cleararray(debugOut, 8);

	uservars.uservars[1] = volts_in;
	uservars.uservars[2] = ohms_in;

	ohmsLawInputLogic(uservars.uservars);
	std::cout << "\n";
	tape.appenedstring(calc.solve_ohmslaw(uservars.uservars[0], uservars.uservars[2], uservars.uservars[1]), uservars.uservars, historyentry, debugOut);
	std::cout << "\n";
	testCase8(debugOut);
	
	dumpOutput(debugOut);

	if (debugOut[0] == amps_out && debugOut[6] == watts_out)
	{
		
		std::cout << "\nOUTPUT AMPS: " << debugOut[0] << " OUTPUT WATTS: " << debugOut[6];
		std::cout << "\nTEST CASE 2 PASSED";
		std::cout << "\n***************************************";

		return true;
	
	}

	else
	{
		 
		std::cout << "\nOUTPUT AMPS: " << debugOut[0] << " OUTPUT WATTS: " << debugOut[6];
		std::cout << "\nTEST CASE 2 FAILED";
		std::cout << "\n***************************************";

		return false;
		

	}

}

bool UnitTests::testCase3(double debugOut[])  //10 volts / 1 amp = 10 ohms, 10 watts
{

	std::cout << "\nTEST CASE 3:";
	std::cout << "\nINPUT: 10 Volts 1 AMPS ";
	std::cout << "\nEXPECTED OUTPUT: 10 OHMS 10 WATTS";

	const double volts_in = 10;
	const double amps_in = 1;

	//output

	const double ohms_out = 10;
	const double watts_out = 10;

	//clear input and output arrays

	uservars.cleararray(uservars.uservars, 7);
	uservars.cleararray(debugOut, 8);

	uservars.uservars[1] = volts_in;
	uservars.uservars[0] = amps_in;

	ohmsLawInputLogic(uservars.uservars);
	std::cout << "\n";
	tape.appenedstring(calc.solve_ohmslaw(uservars.uservars[0], uservars.uservars[2], uservars.uservars[1]), uservars.uservars, historyentry, debugOut);
	std::cout << "\n";
	testCase9(debugOut);

	dumpOutput(debugOut);

	if (debugOut[2] == ohms_out && debugOut[6] == watts_out)
	{
		 
		std::cout << "\nOUTPUT OHMS: " << debugOut[2] << " OUTPUT WATTS: " << debugOut[6];
		std::cout << "\nTEST CASE 3 PASSED";
		std::cout << "\n***************************************";

		return true;
		

	}

	else
	{
		 
		std::cout << "\nOUTPUT AMPS: " << debugOut[2] << " OUTPUT WATTS: " << debugOut[6];
		std::cout << "\nTEST CASE 2 FAILED";
		std::cout << "\n***************************************";
		
		return false;


	}
}

bool UnitTests::testCase4(double debugOut[]) 	//10 watts, 10 amps = 1 volt, 0.1 ohms
{

	std::cout << "\nTEST CASE 4:";
	std::cout << "\nINPUT: 10 WATTS 10 AMPS ";
	std::cout << "\nEXPECTED OUTPUT: 1 VOLT 0.1 OHMS";

	const double watts_in = 10;
	const double amps_in = 10;

	//output

	const double volts_out = 1;
	const double ohms_out = 0.1;

	//clear input and output arrays

	uservars.cleararray(uservars.uservars, 7);
	uservars.cleararray(debugOut, 8);

	uservars.uservars[6] = watts_in;
	uservars.uservars[0] = amps_in;

	ohmsLawInputLogic(uservars.uservars);
	tape.appenedstring(calc.solve_ohmslaw(uservars.uservars[0], uservars.uservars[2], uservars.uservars[1]), uservars.uservars, historyentry, debugOut);

	dumpOutput(debugOut);

	if (debugOut[1] == volts_out && debugOut[2] == ohms_out)
	{
		 
		std::cout << "\nOUTPUT VOLTS: " << debugOut[1] << " OUTPUT OHMS: " << debugOut[2];
		std::cout << "\nTEST CASE 4 PASSED";
		std::cout << "\n***************************************";

		return true;
	}

	else
	{
 
		std::cout << "\nOUTPUT VOLTS: " << debugOut[1] << " OUTPUT OHMS: " << debugOut[2];
		std::cout << "\nTEST CASE 4 FAILED";
		std::cout << "\n***************************************";;
		return false;

	}
	 
}

bool UnitTests::testCase5(double debugOut[])  	// 10 watts, 10 volts = 1 amp, 10 ohms.
{
	std::cout << "\nTEST CASE 5:";
	std::cout << "\nINPUT: 10 WATTS 10 VOLTS ";
	std::cout << "\nEXPECTED OUTPUT: 1 AMP 10 OHMS";

	const double watts_in = 10;
	const double volts_in = 10;

	//output

	const double amps_out = 1;
	const double ohms_out = 10;

	//clear input and output arrays

	uservars.cleararray(uservars.uservars, 7);
	uservars.cleararray(debugOut, 8);

	uservars.uservars[6] = watts_in;
	uservars.uservars[1] = volts_in;

	ohmsLawInputLogic(uservars.uservars);
	tape.appenedstring(calc.solve_ohmslaw(uservars.uservars[0], uservars.uservars[2], uservars.uservars[1]), uservars.uservars, historyentry, debugOut);

	dumpOutput(debugOut);

	if (debugOut[0] == amps_out && debugOut[2] == ohms_out)
	{
		 
		std::cout << "\nOUTPUT AMPS: " << debugOut[0] << " OUTPUT OHMS: " << debugOut[2];
		std::cout << "\nTEST CASE 5 PASSED";
		std::cout << "\n***************************************";

		return true;
	}

	else
	{
		 
		std::cout << "\nOUTPUT AMPS: " << debugOut[0] << " OUTPUT OHMS: " << debugOut[2];
		std::cout << "\n TEST CASE 5 FAILED";
		std::cout << "\n***************************************";

		return false;
	}
	 
}

bool UnitTests::testCase6(double debugOut[])  //Source Voltage 24v, R1 1000 Ohms, R2 100 Ohms. Output Voltage = 2.182 Volts
{
	std::cout << "\nTEST CASE 6:\n";

	const double vsource = 24;
	const double r1 = 1000;
	const double r2 = 100;
		//output

	const double volts_out = 2.181818;

	//clear input and output arrays

	uservars.cleararray(uservars.uservars, 7);
	uservars.cleararray(debugOut, 8);

	uservars.uservars[3] = vsource;
	uservars.uservars[4] = r1;
	uservars.uservars[5] = r2;

	tape.appenedstring(voltagediv.voltaged_divider(uservars.uservars[3], uservars.uservars[4], uservars.uservars[5]), uservars.uservars, historyentry, debugOut);

	testCase10(debugOut);  //test case 6a 

	dumpOutput(debugOut);

	std::cout << "\nINPUT: VSOURCE 24V R1 1000 OHMS R2 100 OHMS";
	std::cout << "\nEXPECTED OUTPUT: 2.182 VOLTS";
	std::cout << "\n";

	if (debugOut[1] < (volts_out + (volts_out * .001)) || debugOut[1] > (volts_out + (volts_out * .001)))  //.1% tolerance allows for floating point inaccuracies. 
	{
		 
		std::cout << "\nOUTPUT VOLTS: " << debugOut[1];
		std::cout << "\nTEST CASE 6b PASSED";
		std::cout << "\n***************************************\n";

		return true;
	}

	else
	{
		 
		std::cout << "\nOUTPUT VOLTS: " << debugOut[1];
		std::cout << "\nTEST CASE 6b FAILED";
		std::cout << "\n***************************************\n";

		return false;
	}
	 
}


//	results[8] index 1 = voltage * resistance
//	results[8] index 2 = voltage / resistance
//	results[8] index 3 = voltage / current 
//	results[8] index 4 = voltage Divider 
 

bool UnitTests::testCase7(double debugOut[])   // Voltage = current x resistance
{

	if (debugOut[7] == 1)
	{
		std::cout << "\nLOGIC TEST CASE PASSED VOLTAGE = CURRENT * RESISTANCE DEDUCED";
		std::cout << "\n";
		return true;
	}
	 
	else
	{
		std::cout << "\nLOGIC TEST CASE  FAILED IMPROPER DEDUCTION";
		std::cout << "\n";

		return false;
	}
	std::cout << "\n";
}

bool UnitTests::testCase8(double debugOut[])   	// Current = voltage / resistance
{
	if (debugOut[7] == 2)
	{
		std::cout << "\nLOGIC TEST CASE PASSED CURRENT = VOLTAGE / RESISTANCE DEDUCED";
		std::cout << "\n";
		return true;
	}

	else
	{
		std::cout << "\nLOGIC TEST CASE FAILED IMPROPER DEDUCTION";
		std::cout << "\n";

		return false;
	}
	std::cout << "\n";
}

bool UnitTests::testCase9(double debugOut[]) 	// Resistance = voltage / current
{
	if (debugOut[7] == 3)
	{
		std::cout << "\LOGIC TEST CASE PASSED RESISTANCE = VOLTAGE / CURRENT DEDUCED";
		std::cout << "\n";

		return true;
	}

	else
	{
		std::cout << "\nLOGIC TEST CASE FAILED IMPROPER DEDUCTION";
		std::cout << "\n";

		return false;
	}
	std::cout << "\n";
}

bool UnitTests::testCase10(double debugOut[]) 	// VoltageDivider 
{
	if (debugOut[7] == 4)
	{
		std::cout << "\nTEST CASE 6a PASSED VOLTAGE DIVIDER CALUCLATION RUN";
		std::cout << "\n";
	

		return true;
	}

	else
	{
		std::cout << "\nTEST CASE 6a FAILED VOLTAGE DIVIDER CALUCLATION NOT RUN";
		std::cout << "\n";

		return false;
	}
	
}
 