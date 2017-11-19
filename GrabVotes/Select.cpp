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
	//������ѧ����ѧ�ű�����m_all_StudentID��
	SaveStudentID();
}

void CSelect ::GetOutputFileName(CString file_name)
{
	m_output_file = file_name;
}

void CSelect::SaveStudentID()
{
	//���ļ�
	//���ļ��е��ı���string��ʽ������m_all_studentID��
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
	//���������
	int rank_number = 0;
	if (m_student_total_number){
		for (int i = 0; i < number; i++){
			rank_number = rand() % m_student_total_number;
			//�����rank_number֮ǰû�г��֣��򱣴�����
			vector<int>::iterator iter_number;
			iter_number = find(m_selected_number.begin(), m_selected_number.end(), rank_number);

			if (iter_number != m_selected_number.end()){
				//m_selected_number�д���rank_numberֵ
				i--;
				continue;
			}
			else{
				//m_selected_number�в�����rank_numberֵ
				m_selected_number.push_back(rank_number);
			}
		}
	}
	else{
		cerr << "û��ѧ������ ��" << endl;
	}
}

void CSelect::SelectResult(int number)
{
	//��ѡ�е�ѧ����ű�����m_selected_number��
	SelectedSerialNumber(number);
	//������ļ���
	ofstream Result(m_output_file, ios::out);
	if (!Result.is_open()){
		cerr << "Error opening output file"; exit(1);
	}
	//��ѡ�е�ѧ����ID��������
	for (int i = 0; i < number; i++){
		m_selectedID.push_back(m_all_studentID[m_selected_number[i]]);
	}
	//��ѡ�е�ѧ����ѧ�Ž�������
	sort(m_selectedID.begin(), m_selectedID.end());
	//��ѡ�е�ѧ��������ļ�
	for (vector<string>::iterator iter = m_selectedID.begin(); iter != m_selectedID.end(); iter++){
		Result << *iter << endl;
	}
	Result.close();
}

int CSelect::GetTotalNumber()
{
	return m_student_total_number;
}