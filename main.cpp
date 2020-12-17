

#include "Factorial.h"
#include "Binary_Search.h"

int main()
{
	int item;									// Declares item as int
	char newitem;								// Declares newitem as char
	bool complete = false;						// Sets bool complete to false
	ifstream infact;							// Declares infiles infact
	ifstream inbinary;							// Declares infile inbinary
	ofstream outfact;							// Declares outfile outfact
	ofstream outbinary;							// Declares outfile outbinary
	infact.open("factorial.in");				// Opens the file
	outfact.open("factorial.out");				// Opens the file
	inbinary.open("binary_search.in");			// Opens the file
	outbinary.open("binary_search.out");		// Opens the file	

	FactType fact;								// Creates the class type FactType called fact
	BinaryType binary;							// Creates the class type BinaryType called binary

	FactType();									// Runs function FactType
	BinaryType();								// Runs function BinaryType
	fact.DisplayHeader(outfact);				// Runs function DisplayHeader
	while (!complete)							// Runs loop until complete
	{
		fact.DisplayHeader(outfact);			// Displays the header
		fact.GetData(item, complete, infact, outfact);// Gets data
		if (complete)							// Makes sure it has collected all the data
			break;
		fact.OutputIfactorial(item, outfact);	// Outputs data
		fact.OutputRfactorial(item, outfact);	// Outputs data
	}											// End while-loop

	binary.DisplayHeader(complete, outbinary);	// Displays header
	while (!complete)							// Runs loop until complete
	{
		binary.DisplayHeader(complete, outbinary);	// Displays the header
		binary.GetData(newitem, complete, inbinary, outbinary);
		if (complete)							// Makes sure it has collected all the data
			break;
		binary.Output();						// Outputs data
	}											// End while-loop

	infact.close();								// Closes the file
	outfact.close();							// Closes the file
	inbinary.close();							// Closes the file
	outbinary.close();							// Closes the file

	return 0;
}												// End main