// DlgPrintDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DlgPrint.h"
#include "DlgPrintDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPrintDlg dialog

CDlgPrintDlg::CDlgPrintDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPrintDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPrintDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgPrintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPrintDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

typedef struct tagData 
{
	int nColIndex;//������
	CString strColText;//�б���
	int nPrintX;//����ʼx����
	int nSubItemIndex;//�ӱ�������
}Data;

BEGIN_MESSAGE_MAP(CDlgPrintDlg, CDialog)
	//{{AFX_MSG_MAP(CDlgPrintDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PRINT, OnPrint)
	ON_BN_CLICKED(IDC_READDB, OnReaddb)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPrintDlg message handlers

BOOL CDlgPrintDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgPrintDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDlgPrintDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDlgPrintDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDlgPrintDlg::OnPrint() 
{
	PRINTDLG pd;//����ṹ�����
	pd.lStructSize = sizeof(PRINTDLG);
	pd.Flags = PD_RETURNDC;
	pd.hDC = NULL;
	pd.hwndOwner = NULL;
	pd.hInstance = NULL;
	pd.nMaxPage = 1;
	pd.nMinPage = 1;
	pd.nFromPage = 1;
	pd.nToPage = 1;
	pd.nCopies = 1;
	pd.hDevMode = NULL;
	pd.hDevNames = NULL;
	if(!PrintDlg(&pd))
		return;
	ASSERT(pd.hDC != NULL);

	int nHorRes = GetDeviceCaps(pd.hDC,HORZSIZE);
	int nVerRes = GetDeviceCaps(pd.hDC,VERTSIZE);
	int log_x = GetDeviceCaps(pd.hDC,LOGPIXELSX);
	double scale = log_x/96.0;
	int nXMargin = 2;
	TEXTMETRIC tm;
	GetTextMetrics(pd.hDC,&tm);
	int nCharHeight = tm.tmHeight;
	int nCharWidth = tm.tmAveCharWidth;
	CHeaderCtrl* pHeader = m_list.GetHeaderCtrl();
	int nColCount = pHeader->GetItemCount();//��ñ�ͷ����
	int nLineCout = m_list.GetItemCount();//����б���ͼ����
	int ColOrderArray[100];
	Data dt[100];//�ṹ���������
	m_list.GetColumnOrderArray(ColOrderArray,nColCount);//��ȡ�б���ͼ�ռ������
	int nColX= nXMargin* nCharWidth;//��0�������ʼx����
	int wid,i;
	for (i=0;i<nColCount;++i)
	{
		dt[i].nColIndex = ColOrderArray[i];
		LVCOLUMN lvc;
		char text[100];
		lvc.mask = LVCF_TEXT|LVCF_SUBITEM;
		lvc.pszText=text;
		lvc.cchTextMax = 100;
		m_list.GetColumn(dt[i].nColIndex,&lvc);//��ȡ�б���ͼ���е�����
		dt[i].strColText = lvc.pszText;//��ȡ�б���
		dt[i].nSubItemIndex = lvc.iSubItem;//��ȡ�ӱ�������
		dt[i].nPrintX = nColX;
		wid =  m_list.GetColumnWidth(i);//�õ��п�
		nColX += int(wid*scale);
		if (nColX>nHorRes)
		{
			DeleteDC(pd.hDC);
			AfxMessageBox("�ֶ�̫�࣬�޷���һ���ڴ�ӡ�������ýϴ��ֽ������ӡ��");
			return;
		}

	}

	DOCINFO di;
	di.cbSize = sizeof(DOCINFO);
	di.lpszDocName = "ListCtrl Printing";
	di.lpszOutput = (LPCSTR)NULL;
	di.lpszDatatype = (LPCSTR)NULL;
	di.fwType = 0;
	StartDoc(pd.hDC,&di);//��ʼһ����ӡ��ҵ
	StartPage(pd.hDC);//֪ͨ��ӡ����������׼����ʼ��������
	int space = (nHorRes-nColX)/(nColCount+1);
	
	for (i=0;i<nColCount;++i)
	{
		dt[i].nPrintX+=space;
	}
	TextOut(pd.hDC,int((nColX+space)/2),2*nCharHeight,"�� ��",6);//�����ͷ
	MoveToEx(pd.hDC,nXMargin*nCharWidth,3*nCharHeight,NULL);//����
	LineTo(pd.hDC,nColX+space,3*nCharHeight);
	//����б���
	for (i=0;i<nColCount;++i)
	{
		TextOut(pd.hDC,dt[i].nPrintX,4*nCharHeight,dt[i].strColText,strlen(dt[i].strColText));
	}
	int nMaxLinePerPage = nVerRes/nCharHeight-5;
	int nCurPage = 1;
	for (i=0;i<nLineCout;++i)
	{
		for (int j=0;j<nColCount;++j)
		{
			if ((i+1-(nCurPage-1)*nMaxLinePerPage)>nMaxLinePerPage)
			{
				EndPage(pd.hDC);
				StartPage(pd.hDC);
				nCurPage++;
			}
			CString subitem = m_list.GetItemText(i,dt[j].nSubItemIndex);//�õ��б����������ı�
			int PrintY = 4*nCharHeight+(i+1-(nCurPage-1)*nMaxLinePerPage)*nCharHeight;
			TextOut(pd.hDC,dt[j].nPrintX,PrintY,subitem,strlen(subitem));//��ӡ�б���ͼ������
		}
	}
	EndPage(pd.hDC);
	EndDoc(pd.hDC);
	DeleteDC(pd.hDC);
	AfxMessageBox("��ӡ���");
}

void CDlgPrintDlg::OnReaddb() 
{
	m_list.InsertColumn(0,"��������",LVCFMT_LEFT,150,0);//���롰�������ơ���
	m_list.InsertColumn(1,"����",LVCFMT_LEFT,100,1);
	m_list.InsertColumn(2,"������",LVCFMT_LEFT,120,2);
	CDaoDatabase db;				//�������ݿ����
	CDaoRecordset RecSet(&db);		//�����¼������
	COleVariant var;				//�ֶ�����
	var.ChangeType(VT_BSTR,NULL);
	CString strName,strType,strFactory;
	
	db.Open("model.mdb");//�����ݿ�
	
	RecSet.Open(AFX_DAO_USE_DEFAULT_TYPE,"SELECT * FROM car",NULL);
	int i=0;
	while(!RecSet.IsEOF())//�Ƿ񵽴��β
	{
		RecSet.GetFieldValue("Name",var);//�õ����������ơ��ֶε�ֵ
		strName = (LPCSTR)var.pbstrVal;
		RecSet.GetFieldValue("type",var);
		strType = (LPCSTR)var.pbstrVal;
		RecSet.GetFieldValue("manufacturer",var);
		strFactory = (LPCSTR)var.pbstrVal;
		m_list.InsertItem(i,"0");
		m_list.SetItemText(i,0,strName);//�����б���ͼ������ı�
		m_list.SetItemText(i,1,strType);
		m_list.SetItemText(i,2,strFactory);
		RecSet.MoveNext();
		++i;
	}
	RecSet.Close();
	db.Close();
}
