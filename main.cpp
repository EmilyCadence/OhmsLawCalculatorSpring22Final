/* File Name:

Program: Ohms Law Calculator
Author: Emily Schwartz
Email:  <ecs03300@ccv.vsc.edu>

Class:  CCV C++
Assignment: Final Project
Instructor: Savard

Date: 12/12/2021 
Last Modified: 5/05/2022
Version Info : draft 

Description:
 
5/5/2022
5/13/2022

Goals:  Primary focus right now is to use this to play with implementing some debugging features mainly
unit tests, for maintainability.    The original implementation of this required a lot of repetitive manual
testing, that could be automated. 

Secondary focus is to re write for more readability, and to apply things ive learned since writing the original code.   
E.g. making more object oriented.  
 
 

 


*/

//--------------------------------<Header Files>--------------------------------------


 
#include "FCalls.h"


//--------------------------------<Global Variables>--------------------------------------


 

 
//----------------------------------------------------------------------------------
// struct <menudialog>
// stores functions that print dialog for text based menus to console
// requires <iostream>
 


//----------------------------------------------------------------------------------
// class <papertape>
// functions for a calculator style "papertape" that stores of a history of calculations.
// formats appropriate strings depending on the specific calculation .
// string tells us what the user entered, what formula we used, and the result.
//
// We do this using switch statement that uses a case of a numerical code that we pass in.
// We get this code from the function that is doing our calculations.
//
// When an appropriate string is formed we store it in std::vector container.
//
// requires struct <history>
// requires <vector> <string>, and <iostream>




//----------------------------------------------------------------------------------
// Class <ohmslaw>
// automatically solves for the 3 formulas of ohms law, based on input.
//
// logic that decides:
//
// power  = voltage * current
//
// if power == null
//
// if voltage = null solves for voltage (current * resistance)
// if current = null solves for current (voltage / resistance)
// if resistance = null solves for (voltage / current)
//
//
// then calls a function for the proper formula.

 

 
 

 

//--------------------------------<Main Function>--------------------------------------
// Entry, and exit point for our program.
// not much to see here. 

int main() {

	FCalls fcalls;

	fcalls.maincalls();

	return 0;
}