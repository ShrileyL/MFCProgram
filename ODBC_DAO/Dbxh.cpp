// Dbxh.cpp : implementation file
//

#include "stdafx.h"
#include "ODBC_DAO.h"
#include "Dbxh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDbxh dialog


CDbxh::CDbxh(CWnd* pParent /*=NULL*/)
	: CDialog(CDbxh::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDbxh)
	m_xh = 0;
	//}}AFX_DATA_INIT
}


void CDbxh::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDbxh)
	DDX_Text(pDX, IDC_XH, m_xh);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDbxh, CDialog)
	//{{AFX_MSG_MAP(CDbxh)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDbxh message handlers
