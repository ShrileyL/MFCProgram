#if !defined(AFX_EYEDLG_H__8E2F85D1_1712_4AD0_B9C5_2E3AA9FAFA5C__INCLUDED_)
#define AFX_EYEDLG_H__8E2F85D1_1712_4AD0_B9C5_2E3AA9FAFA5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Eyedlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEyedlg dialog

class CEyedlg : public CDialog
{
// Construction
public:

	CEyedlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEyedlg)
	enum { IDD = IDD_D_MENU };
	BOOL	m_chkRR;
	int radIndex;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEyedlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEyedlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EYEDLG_H__8E2F85D1_1712_4AD0_B9C5_2E3AA9FAFA5C__INCLUDED_)
