
// GrabVotesDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GrabVotes.h"
#include "GrabVotesDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CGrabVotesDlg 对话框



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


// CGrabVotesDlg 消息处理程序

BOOL CGrabVotesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGrabVotesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGrabVotesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGrabVotesDlg::OnBnClickedButtonOpenfile()
{
	// TODO:  在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;
	// 显示打开文件对话框
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，
		strFilePath = fileDlg.GetPathName();
		//获得输入文件的路径名称
		Winners.GetInputFileName(strFilePath);
		//将选择的文件路径显示到编辑框里
		SetDlgItemText(IDC_EDIT_InputStudentID, strFilePath);
	}
}


void CGrabVotesDlg::OnBnClickedButtonOutputresult()
{
	// TODO:  在此添加控件通知处理程序代码
	// 设置过滤器
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*) | *.* ");
	//TCHAR szFilter[] = _T("文本文件(*.txt)|所有文件(*.*) | *.* ||");
	// 构造保存文件对话框
	CFileDialog fileDlg(FALSE, _T("txt"), _T("GrabVotesResult"), OFN_HIDEREADONLY |
			OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;
	// 显示保存文件对话框
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里
		strFilePath = fileDlg.GetPathName();
		Winners.GetOutputFileName(strFilePath);
		//如果人数为0，则报错
		if (!GetDlgItemInt(IDC_EDIT_SelectNumber)){
			MessageBox(_T("请输入选择人数！\n 将我退出后，重新运行！"));
			OnBnClickedOk();
		}
		if (GetDlgItemInt(IDC_EDIT_SelectNumber) > Winners.GetTotalNumber()){
			MessageBox(_T("报名的学生人数不够 ！\n 全选了吧 ！"));
			OnBnClickedOk();
		}
		if (GetDlgItemInt(IDC_EDIT_SelectNumber) == Winners.GetTotalNumber()){
			MessageBox(_T("报名的学生人数刚好够 ！\n 全选了吧 ！"));
			OnBnClickedOk();
		}
		Winners.SelectResult(GetDlgItemInt(IDC_EDIT_SelectNumber));
		SetDlgItemText(IDC_EDIT_OutputResult, strFilePath);
	}
}


void CGrabVotesDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
