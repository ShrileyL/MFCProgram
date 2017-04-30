// Rectnum.cpp : implementation file
//

#include "stdafx.h"
#include "MyVC5.h"
#include "Rectnum.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRectnum dialog


CRectnum::CRectnum(CWnd* pParent /*=NULL*/)
	: CDialog(CRectnum::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRectnum)
	m_number = 0;
	//}}AFX_DATA_INIT
}


void CRectnum::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRectnum)
	DDX_Text(pDX, IDC_NUMBER, m_number);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRectnum, CDialog)
	//{{AFX_MSG_MAP(CRectnum)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRectnum message handlers
