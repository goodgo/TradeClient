#pragma once

#include <iostream>
#include <vector>
#include "DataSetRow.h"

using namespace std;

class SDK_API DataSet{
public:
	void Append(DataSetRow*, bool IsDelete = false);

	DataSetRow* Get(int);
	void Modify(int, DataSetRow*);

	int Length();
	void Clear();
private:
	vector<DataSetRow> _mRows;
};
