/** @file  Drzewa Czerwono-Czarne.
		   Plik g³ówny.
*/

/*
Drzewa Czerwono-Czarne

Plik g³ówny
 
 */

#include <iostream>
#include <string>
#include <fstream>
#include "funkcje.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "\nInappropriate use of file. The proper use:\nprogram_name -i input_file\n\n";
		return 1;
	}
	else
	{
		ReadFromFile(argv[2]);
		return 0;
	}
 }