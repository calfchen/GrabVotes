
// GrabVotes.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGrabVotesApp: 
// �йش����ʵ�֣������ GrabVotes.cpp
//

class CGrabVotesApp : public CWinApp
{
public:
	CGrabVotesApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGrabVotesApp theApp;