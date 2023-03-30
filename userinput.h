#pragma once 

#ifndef USERINPUT_H
#define USERINPUT_H

struct userinput{
public:

	userinput();

	double uservars[7];

	//index 0 current
	//index 1 voltage
	//index 2 resistance
	//index 3 vsource
	//index 4 r1
	//index 5 r2
	//index 6 power/watts

	//Function sets each array index to 0 to initialize array to something.
	//so we at least have a 0 value in each index, not whatever is in that memory.
	//Parameters Array, and Size of Array.

	void cleararray(double[], int);

	~userinput();
};

#endif

 