#if !defined(AFX_BROWDLG_H__8502751C_F2E2_4BE7_B62B_F44313AD9B97__INCLUDED_)
#define AFX_BROWDLG_H__8502751C_F2E2_4BE7_B62B_F44313AD9B97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Browdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBrowdlg dialog

class CBrowdlg : public CDialog
{
// Construction
public:
	CBrowdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBrowdlg)
	enum { IDD = IDD_D_BROW };
	CSpinButtonCtrl	m_spint2;
	CSpinButtonCtrl	m_spint1;
	int		m_nBrowPos;
	int		m_nBrowWidth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrowdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBrowdlg)
	afx_msg void OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWDLG_H__8502751C_F2E2_4BE7_B62B_F44313AD9B97__INCLUDED_)
