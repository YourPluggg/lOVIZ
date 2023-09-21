#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;
std::ofstream out;

void shell(int* items, int count);
void qs(int* chasti, int left, int right);
//void qsortRecursive(int* mas, int size);
int qsortRecursive(const void* a, const void* b);

