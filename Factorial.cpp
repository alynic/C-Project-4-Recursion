

#include "Factorial.h"

FactType :: FactType()
{
	header = "-- CPSC 131: Lab#4 (1.i & 1.r) : Factorial --";
	dash1 = "\n-- ";
	dash2 = " --\n";
	ifactstr = "\nifactorial (";
	rfactstr = "rfactorial (";
	par = ')';
	arrow = " => ";
	times = " * ";
	equals = " = ";
	ind = "index = ";
	sp = ' ';
	done = false;
	count = 1;
	noMore = "No more items to process.\n\n";
	factEnd = "-- The End of CPSC 131 Lab#4 (1.i & 1.r) : Factorial --\n\n";
}

void FactType :: DisplayHeader(ofstream& outfact)
{
	if (!done)
	{
		outfact << header;
		done = true;
	}
	else
		outfact << dash1 << count << dash2;
}

void FactType :: GetData(int& item, bool& complete, ifstream& infact, ofstream& outfact)
{
	if (infact >> item)
		outfact << item;
	else
	{	
		outfact << noMore << factEnd;
		complete = true;
	}
}

void FactType :: OutputIfactorial(int item, ofstream& outfact)
{
	outfact << ifactstr << item << par << arrow;
	item = FactorialInterative(item, outfact);
	outfact << item << endl;
}

void FactType :: OutputRfactorial(int item, ofstream& outfact)
{
	int temp;
	for (temp = item; temp != -1; temp--)
	{
		outfact << rfactstr << temp << par << arrow;
	}
	for (temp = item; temp != 0; temp--)
	{
		outfact << temp << times;
	}
	item = FactorialRecursive(item, outfact);
	outfact << temp + 1 << equals << item << endl;
	count++;
}


int FactType :: FactorialInterative(int item, ofstream& outfact)
{
	fact = 1;
	outfact << ind << fact << arrow;

	for (index = 2; index <= item; index++)
	{
		fact *= index;
		outfact << ind << index << arrow;
	}

	return fact;
}

int FactType :: FactorialRecursive(int item, ofstream& outfact)
{					
	if (item == 0)
		return 1;
	else
		return item * FactorialRecursive(item - 1, outfact);
}