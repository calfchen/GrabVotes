
// GrabVotesDlg.h : ͷ�ļ�
//

#pragma once

#include "Select.h"
#include <iostream>
#include <fstream>
using namespace std;

// CGrabVotesDlg �Ի���
class CGrabVotesDlg : public CDialogEx
{
// ����
public:
	CGrabVotesDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GRABVOTES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonOpenfile();
	afx_msg void OnBnClickedButtonOutputresult();
	afx_msg void OnBnClickedOk();
private:
	CSelect Winners;
};
