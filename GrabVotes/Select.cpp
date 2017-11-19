#include "stdafx.h"
#include "Select.h"


CSelect::CSelect() :m_input_file(""), m_output_file(""),m_student_total_number(0)
{
	m_all_studentID.clear();
	m_selected_number.clear();
	m_selectedID.clear();
}


CSelect::~CSelect()
{
}

void CSelect::GetInputFileName(CString file_name)
{
	m_input_file = file_name;
	//将所有学生的学号保存在m_all_StudentID中
	SaveStudentID();
}

void CSelect ::GetOutputFileName(CString file_name)
{
	m_output_file = file_name;
}

void CSelect::SaveStudentID()
{
	//打开文件
	//将文件中的文本以string形式保存在m_all_studentID中
	ifstream SignUp(m_input_file, ios::in);
	string studentID;
	if (!SignUp.is_open())
	{
		cerr << "Error opening input file"; exit(1);
	}
	while (!SignUp.eof())
	{
		SignUp >> studentID;

		if (m_student_total_number){
			if (studentID != m_all_studentID[m_student_total_number-1]){
				m_student_total_number++;
				m_all_studentID.push_back(studentID);
			}
		}
		else{
			m_student_total_number++;
			m_all_studentID.push_back(studentID);
		}
	}
	SignUp.close();
}

void CSelect::SelectedSerialNumber(int number)
{
	//产生随机数
	int rank_number = 0;
	if (m_student_total_number){
		for (int i = 0; i < number; i++){
			rank_number = rand() % m_student_total_number;
			//如果此rank_number之前没有出现，则保存起来
			vector<int>::iterator iter_number;
			iter_number = find(m_selected_number.begin(), m_selected_number.end(), rank_number);

			if (iter_number != m_selected_number.end()){
				//m_selected_number中存在rank_number值
				i--;
				continue;
			}
			else{
				//m_selected_number中不存在rank_number值
				m_selected_number.push_back(rank_number);
			}
		}
	}
	else{
		cerr << "没有学生报名 ！" << endl;
	}
}

void CSelect::SelectResult(int number)
{
	//将选中的学生序号保存在m_selected_number中
	SelectedSerialNumber(number);
	//输出到文件中
	ofstream Result(m_output_file, ios::out);
	if (!Result.is_open()){
		cerr << "Error opening output file"; exit(1);
	}
	//将选中的学生的ID保存起来
	for (int i = 0; i < number; i++){
		m_selectedID.push_back(m_all_studentID[m_selected_number[i]]);
	}
	//对选中的学生按学号进行排序
	sort(m_selectedID.begin(), m_selectedID.end());
	//将选中的学生输出到文件
	for (vector<string>::iterator iter = m_selectedID.begin(); iter != m_selectedID.end(); iter++){
		Result << *iter << endl;
	}
	Result.close();
}

int CSelect::GetTotalNumber()
{
	return m_student_total_number;
}