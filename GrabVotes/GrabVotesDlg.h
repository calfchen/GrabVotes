
// GrabVotesDlg.h : 头文件
//

#pragma once

#include "Select.h"
#include <iostream>
#include <fstream>
using namespace std;

// CGrabVotesDlg 对话框
class CGrabVotesDlg : public CDialogEx
{
// 构造
public:
	CGrabVotesDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GRABVOTES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
