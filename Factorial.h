

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class FactType
{
public:
	FactType();
	void DisplayHeader(ofstream& outfact);
	void GetData(int& item, bool& complete, ifstream& infact, ofstream& outfact);
	void OutputIfactorial(int item, ofstream& outfact);
	void OutputRfactorial(int item, ofstream& outfact);
	int FactorialInterative(int item, ofstream& outfact);
	int FactorialRecursive(int item, ofstream& outfact);
private:
	int count;
	int index;
	int fact;
	bool done;
	char sp;
	char par;
	string header;
	string end;
	string dash1;
	string dash2;
	string ifactstr;
	string rfactstr;
	string arrow;
	string times;
	string equals;
	string ind;
	string noMore;
	string factEnd;
};