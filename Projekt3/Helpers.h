#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include "Status.h"


void validateDate(int day, int month, int year);

const char* cleaningStatusToString(CleaningStatus status);

CleaningStatus stringToCleaningStatus(const char* statusStr);

#endif