#include "userinput.h"

userinput::userinput()
{
	 cleararray(this->uservars, 7);
}

void userinput::cleararray(double array[], int size) {
	for (int i = 0; i < size; i++) { // clears our array writes 0 to each index.
		array[i] = 0;
	}
}

userinput::~userinput()
{
}
 
