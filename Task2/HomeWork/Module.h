#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int &a, int &b);
int getLength();
void printArray(int *theArray, int length);
int* initArray(int length);
void quickSort(int* theArray, int firstIndex, int lastIndex);
int mostFrequentElement(int *theArray, int length);