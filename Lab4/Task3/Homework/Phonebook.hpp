#pragma once
#include "stdafx.hpp"
#include "ContactStruct.hpp"

void printAll(Contact *buffer, int numberOfRecords);
char* getPhoneNumber(char *name, Contact* buffer, int numberOfRecords);
char* getName(char *phone, Contact* buffer, int numberOfRecords);
void saveData(Contact *buffer, int numberOfRecords);