#include "voltagedivider.h"

// solves for output of voltage divider with 2 resistors
	// (source voltage x r2) / (r1 + r2)
	// parameters, double source voltage, double r1, double r2
	// returns output of voltage divider type double.

voltagedivider::voltagedivider()
{
}

std::pair<double, int> voltagedivider::voltaged_divider(const double sourcevoltage, const double r1, const double r2) {
	const int resultcode = 5;;
	return std::make_pair((sourcevoltage * r2) / (r1 + r2), resultcode);
}

voltagedivider::~voltagedivider()
{
}


 