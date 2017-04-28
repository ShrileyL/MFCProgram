// Eyedlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyVC4.h"
#include "Eyedlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEyedlg dialog


CEyedlg::CEyedlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEyedlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEyedlg)
	m_chkRR = FALSE;
	//}}AFX_DATA_INIT
}


void CEyedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEyedlg)
	DDX_Check(pDX, IDC_CHK_RR, m_chkRR);//连接control ID与变量的宏？
	DDX_Check(pDX, IDC_RAD_1, radIndex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEyedlg, CDialog)
	//{{AFX_MSG_MAP(CEyedlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEyedlg message handlers



