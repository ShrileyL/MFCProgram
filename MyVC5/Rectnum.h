#if !defined(AFX_RECTNUM_H__AAA4268D_0E2C_4253_A5FB_EDFE3E3E0B44__INCLUDED_)
#define AFX_RECTNUM_H__AAA4268D_0E2C_4253_A5FB_EDFE3E3E0B44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Rectnum.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRectnum dialog

class CRectnum : public CDialog
{
// Construction
public:
	CRectnum(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRectnum)
	enum { IDD = IDD_DIALOG1 };
	int		m_number;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRectnum)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRectnum)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECTNUM_H__AAA4268D_0E2C_4253_A5FB_EDFE3E3E0B44__INCLUDED_)
