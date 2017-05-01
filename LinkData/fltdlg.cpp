// fltdlg.cpp : implementation file
//

#include "stdafx.h"
#include "LinkData.h"
#include "fltdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cfltdlg dialog


Cfltdlg::Cfltdlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cfltdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cfltdlg)
	m_fltvalue = _T("");
	//}}AFX_DATA_INIT
}


void Cfltdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cfltdlg)
	DDX_Text(pDX, IDC_FILTER_VALUE, m_fltvalue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cfltdlg, CDialog)
	//{{AFX_MSG_MAP(Cfltdlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cfltdlg message handlers
