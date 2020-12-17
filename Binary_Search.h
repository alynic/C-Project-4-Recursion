

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum RelationType {LESS, GREATER, EQUAL};
enum ActionType {INSERT, ISEARCH, RSEARCH};
const int MAX_ITEMS = 500;

class BinaryType
{
public:
	BinaryType();
	bool IsEmpty() const;
	void DisplayHeader(bool& complete, ofstream& outbinary);
	void InsertItem(char& newitem);
	void GetData(char& newitem, bool& complete, ifstream& inbinary, ofstream& outbinary);
	void BinaryInterative(char newitem, ofstream& outbinary);
	bool BinaryRecursive(char info[], char newitem, ofstream& outbinary);
	RelationType ComparedTo(char newitem) const;
	ActionType Action(ofstream& outbinary);
	void Output();
private:
	int first;
	int last;
	int length;
	int mid;
	int loc;
	int count;
	int from;
	int to;
	int num;
	char *info;
	char par;
	bool moreToSearch;
	bool done;
	bool found;
	string header;
	string noMore;
	string end;
	string binEnd;
	string dash1;
	string dash2;
	string insert;
	string list;
	string getaction;
	string isrch;
	string rsrch;
	string ind;
	string cmma;
	string fnd;
	string notfnd;
	string rsrch2;
	string frmstr;
	string tostr;
	ActionType action;

};