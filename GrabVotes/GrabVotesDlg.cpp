
// GrabVotesDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GrabVotes.h"
#include "GrabVotesDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGrabVotesDlg �Ի���



CGrabVotesDlg::CGrabVotesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGrabVotesDlg::IDD, pParent)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CGrabVotesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGrabVotesDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OpenFile, &CGrabVotesDlg::OnBnClickedButtonOpenfile)
	ON_BN_CLICKED(IDC_BUTTON_OutputResult, &CGrabVotesDlg::OnBnClickedButtonOutputresult)
	ON_BN_CLICKED(IDOK, &CGrabVotesDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CGrabVotesDlg ��Ϣ�������

BOOL CGrabVotesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGrabVotesDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGrabVotesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGrabVotesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGrabVotesDlg::OnBnClickedButtonOpenfile()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;
	// ��ʾ���ļ��Ի���
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť��
		strFilePath = fileDlg.GetPathName();
		//��������ļ���·������
		Winners.GetInputFileName(strFilePath);
		//��ѡ����ļ�·����ʾ���༭����
		SetDlgItemText(IDC_EDIT_InputStudentID, strFilePath);
	}
}


void CGrabVotesDlg::OnBnClickedButtonOutputresult()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// ���ù�����
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*) | *.* ");
	//TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|�����ļ�(*.*) | *.* ||");
	// ���챣���ļ��Ի���
	CFileDialog fileDlg(FALSE, _T("txt"), _T("GrabVotesResult"), OFN_HIDEREADONLY |
			OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;
	// ��ʾ�����ļ��Ի���
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ����桱��ť����ѡ����ļ�·����ʾ���༭����
		strFilePath = fileDlg.GetPathName();
		Winners.GetOutputFileName(strFilePath);
		//�������Ϊ0���򱨴�
		if (!GetDlgItemInt(IDC_EDIT_SelectNumber)){
			MessageBox(_T("������ѡ��������\n �����˳����������У�"));
			OnBnClickedOk();
		}
		if (GetDlgItemInt(IDC_EDIT_SelectNumber) > Winners.GetTotalNumber()){
			MessageBox(_T("������ѧ���������� ��\n ȫѡ�˰� ��"));
			OnBnClickedOk();
		}
		if (GetDlgItemInt(IDC_EDIT_SelectNumber) == Winners.GetTotalNumber()){
			MessageBox(_T("������ѧ�������պù� ��\n ȫѡ�˰� ��"));
			OnBnClickedOk();
		}
		Winners.SelectResult(GetDlgItemInt(IDC_EDIT_SelectNumber));
		SetDlgItemText(IDC_EDIT_OutputResult, strFilePath);
	}
}


void CGrabVotesDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
