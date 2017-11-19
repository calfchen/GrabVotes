#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class CSelect
{
public:
	CSelect();
	~CSelect();

private:
	CString m_input_file;
	CString m_output_file;
	vector<string> m_all_studentID;
	vector<int> m_selected_number;
	vector<string> m_selectedID;
	int m_student_total_number;

	void SaveStudentID();
	void SelectedSerialNumber(int number);
public:
	void GetInputFileName(CString file_name);
	void GetOutputFileName(CString file_name);
	void SelectResult(int number);
	int GetTotalNumber();
};

