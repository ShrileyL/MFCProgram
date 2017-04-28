// Mouthdlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyVC4.h"
#include "Mouthdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMouthdlg dialog


CMouthdlg::CMouthdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMouthdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMouthdlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMouthdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMouthdlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMouthdlg, CDialog)
	//{{AFX_MSG_MAP(CMouthdlg)
	ON_BN_CLICKED(IDC_MOUTH_D, OnMouthD)
	ON_BN_CLICKED(IDC_MOUTH_N, OnMouthN)
	ON_BN_CLICKED(IDC_MOUTH_U, OnMouthU)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMouthdlg message handlers

void CMouthdlg::OnMouthD() 
{
	// TODO: Add your control notification handler code here
	EndDialog(IDC_MOUTH_D);
}

void CMouthdlg::OnMouthN() 
{
	// TODO: Add your control notification handler code here
	EndDialog(IDC_MOUTH_N);
}

void CMouthdlg::OnMouthU() 
{
	// TODO: Add your control notification handler code here
	EndDialog(IDC_MOUTH_U);
}
