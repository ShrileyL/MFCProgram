// Dispdata.cpp : implementation file
//

#include "stdafx.h"
#include "ODBC_DAO.h"
#include "Dispdata.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDispdata dialog


CDispdata::CDispdata(CWnd* pParent /*=NULL*/)
	: CDialog(CDispdata::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDispdata)
	m_factory = _T("");
	m_height = 0.0;
	m_id = 0;
	m_length = 0.0;
	m_name = _T("");
	m_width = 0.0;
	//}}AFX_DATA_INIT
}


void CDispdata::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDispdata)
	DDX_Text(pDX, IDC_FACTORY, m_factory);
	DDX_Text(pDX, IDC_HEIGHT, m_height);
	DDX_Text(pDX, IDC_ID, m_id);
	DDX_Text(pDX, IDC_LENGTH, m_length);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_WIDTH, m_width);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDispdata, CDialog)
	//{{AFX_MSG_MAP(CDispdata)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDispdata message handlers
