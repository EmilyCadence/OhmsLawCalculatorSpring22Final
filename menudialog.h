#pragma once

#include <iostream>

#ifndef menudialog_H

struct menudialog
{
public: 

	menudialog();

	void print_main_menu(bool);
 

	void printexit_comfirmation();

	void debugMenu();

	~menudialog();
};

#endif