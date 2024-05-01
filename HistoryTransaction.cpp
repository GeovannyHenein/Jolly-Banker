#include "stdafx.h"
#include "HistoryTransaction.h"

HistoryTransaction::HistoryTransaction()
{
}

HistoryTransaction::~HistoryTransaction()
{
}

bool HistoryTransaction::IsValid() const
{
	return valid;
}

HistoryTransaction::HistoryTransaction(istream& istr)
{
	string ID;
	istr >> ID;

	

		if (ID.length() == MAX_ID_LENGTH) // display history by specified fund
		{
			fundType = ID[ID.length() - 1] - '0';
			ID.resize(ID.length() - 1);
			accountID = stoi(ID);
			setValid(true);
		}
		else if(ID.length()	== 4)	// display history by fund
		{
			fundType = -1;
			accountID = stoi(ID);
			setValid(true);
		}
		else 
		{
			cerr << "Error: Invalid Account Input" << endl;
			setValid(false);
		}


	

}

void HistoryTransaction::updateHistory(Transaction* trans, bool valid)
{
	if (valid) 
	{
		history.push_back(trans->historyLog());
	}
	else
	{
		history.push_back(trans->historyLog() + " (Failed)");
	}
}



ostream& operator<<(ostream& istr, const HistoryTransaction& rhs)
{
	for (int i = 0; i < rhs.history.size(); i++)
	{
	
		istr << "   " + rhs.history[i] << endl;
	
	}

	return istr;
}
