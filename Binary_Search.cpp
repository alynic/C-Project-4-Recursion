

#include "Binary_Search.h"

BinaryType :: BinaryType()
{
	done = false;
	header = "-- CPSC 131: Lab#4 (2.i & 2.r): Binary Search --";
	noMore = "No more items to process.\n\n";
	binEnd = "-- The End of CPSC 131 Lab#4 (2.i & 2.r) : Binary Search --\n\n";
	end = "-- The End of CPSC 131 Lab#4 --\n\n";
	dash1 = "\n-- ";
	dash2 = " --\n";
	count = 1;
	insert = "Insert: ";
	list = "\nList: ";
	isrch = "iSearch: ";
	rsrch = "rSearch: ";
	ind = "index = ";
	cmma = ", ";
	fnd = "found\n";
	notfnd = "not-found\n";
	rsrch2 = "rSearch(item = ";
	frmstr = "from = ";
	tostr = "to = ";
	par = ')';
	length = 0;
	info = new char[MAX_ITEMS];
}

bool BinaryType :: IsEmpty() const
{
	return (length == 0);
}

void BinaryType :: DisplayHeader(bool& complete, ofstream& outbinary)
{
	if (!done)
	{
		outbinary << header;
		done = true;
		complete = false;
	}
	else
		outbinary << dash1 << count << dash2;
}

ActionType BinaryType :: Action(ofstream& outbinary)
{
	if (getaction == "Insert")
		return INSERT;
	else if (getaction == "iSearch")
		return ISEARCH;
	else if (getaction == "rSearch")
		return RSEARCH;
	else
		outbinary << "Input Error";
		exit(1);
}

void BinaryType :: GetData(char& newitem, bool& complete, ifstream& inbinary, ofstream& outbinary)
{
	if (inbinary >> getaction >> newitem)
	{
		switch (Action(outbinary))
		{
		case INSERT:		InsertItem(newitem);
							outbinary << insert << newitem << list;
							for (int index = 0; index < length; index++)
								outbinary << info[index];
							break;
		case ISEARCH:		BinaryInterative(newitem, outbinary);
							break;
		case RSEARCH:		num = 0;
							from = 0;
							to = length - 1;
							outbinary << rsrch << newitem << endl;
							BinaryRecursive(info, newitem, outbinary);
							break;
		default:			outbinary << "Input Error";
							exit(1);
							break;
		}
	}
	else
	{
		outbinary << noMore;
		outbinary << binEnd;
		outbinary << end;
		complete = true;
	}
}

void BinaryType :: InsertItem(char& newitem)
{
	loc = 0;
	first = 0;
	last = length - 1;
	moreToSearch = first <= last;
	
	if (IsEmpty())
		moreToSearch = false;
	while (moreToSearch)
	{
		mid = (first + last) / 2;
		switch (ComparedTo(newitem))
		{
		case LESS:			if (mid == 0)
								moreToSearch = false;
							else
							{
								last = mid - 1;
								moreToSearch = first <= last;
							}
							break;
		case GREATER:		first = mid + 1;
							loc = first;
							moreToSearch = first <= last;
							break;
		}
	}
	for (int index = length; index > loc; index--)
		info[index] = info[index - 1];
	info[loc] = newitem;
	length++;
}

RelationType BinaryType :: ComparedTo(char newitem) const
{
	if (newitem < info[mid])
		return LESS;
	else if (info[mid] < newitem)
		return GREATER;
	else
		return EQUAL;
}

void BinaryType :: BinaryInterative(char newitem, ofstream& outbinary)
{
	first = 0;
	last = length - 1;
	moreToSearch = first <= last;
	found = false;
	num = 0;
	while (moreToSearch && !found)
	{
		mid = (first + last) / 2;
		switch (ComparedTo(newitem))
		{
		case LESS:		last = mid - 1;
						moreToSearch = first <= last;
						num++;
						break;
		case GREATER:	first = mid + 1;
						moreToSearch = first <= last;
						num++;
						break;
		case EQUAL:		found = true;
						newitem = info[mid];
						num++;
						break;
		}
	}
	if (found)
	{
		outbinary << isrch << newitem << endl;
		for (int index = 1; index <= num; index++)
			outbinary << ind << index << cmma;
		outbinary << fnd;
	}
	else
	{
		outbinary << isrch << newitem << endl;
		for (int index = 1; index <= num; index++)
			outbinary << ind << index << cmma;
		outbinary << notfnd;
	}
}
bool BinaryType :: BinaryRecursive(char info[], char newitem, ofstream& outbinary)
{
	if (from > to)
	{
		outbinary << notfnd;
		return false;
	}
	else
	{
		mid = (from + to) / 2;
		if (newitem < info[mid])
		{
			num++;
			outbinary << rsrch2 << newitem << cmma << frmstr << from
				 << cmma << tostr << to << par << cmma;
			to = mid - 1;
			return BinaryRecursive(info, newitem, outbinary);
		}
		else if (newitem == info[mid])
		{
			num++;
			outbinary << rsrch2 << newitem << cmma << frmstr << from
				 << cmma << tostr << to << par << cmma << fnd;
			return true;
		}
		else
		{
			num++;
			outbinary << rsrch2 << newitem << cmma << frmstr << from
				 << cmma << tostr << to << par << cmma;
			from = mid + 1;
			return BinaryRecursive(info, newitem, outbinary);
		}
	}

}

void BinaryType :: Output()
{
	count++;
}	