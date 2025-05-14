#pragma once

#include "main.h"

string getValidatedInput(int minSize, int maxSize, const string &mode,
                         bool toUpper, string prompt);
// read an integer between min and max (inclusive) with prompt
int getValidatedInt(int minValue, int maxValue, const string &prompt);