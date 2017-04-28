// Browdlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyVC4.h"
#include "Browdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBrowdlg dialog


CBrowdlg::CBrowdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBrowdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBrowdlg)
	m_nBrowPos = 0;
	m_nBrowWidth = 0;
	//}}AFX_DATA_INIT
}


void CBrowdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBrowdlg)
	DDX_Control(pDX, IDC_SPIN2, m_spint2);
	DDX_Control(pDX, IDC_SPIN1, m_spint1);
	DDX_Text(pDX, IDC_BROWPOS, m_nBrowPos);
	DDV_MinMaxInt(pDX, m_nBrowPos, -30, 30);
	DDX_Text(pDX, IDC_BROWWIDTH, m_nBrowWidth);
	DDV_MinMaxInt(pDX, m_nBrowWidth, 1, 15);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBrowdlg, CDialog)
	//{{AFX_MSG_MAP(CBrowdlg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, OnDeltaposSpin2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, OnDeltaposSpin1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrowdlg message handlers

void CBrowdlg::OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	if (pNMUpDown->iDelta>0 && m_nBrowPos<31)
	{
		m_nBrowPos--;
	}
	else if(pNMUpDown->iDelta<0 && m_nBrowPos>-30)
	{
		m_nBrowPos++;
	}
	else
	{
		return;
	}
	UpdateData(FALSE);


	*pResult = 0;
}

void CBrowdlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	if (pNMUpDown->iDelta>0 && m_nBrowWidth<16)
	{
		m_nBrowPos--;
	}
	else if(pNMUpDown->iDelta<0 && m_nBrowWidth>1)
	{
		m_nBrowPos++;
	}
	else
	{
		return;
	}
	UpdateData(FALSE);

	*pResult = 0;
}
