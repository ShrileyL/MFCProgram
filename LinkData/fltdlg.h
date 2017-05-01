#if !defined(AFX_FLTDLG_H__53DE052E_9D13_494D_9909_5EA3BFB2ED6C__INCLUDED_)
#define AFX_FLTDLG_H__53DE052E_9D13_494D_9909_5EA3BFB2ED6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// fltdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cfltdlg dialog

class Cfltdlg : public CDialog
{
// Construction
public:
	Cfltdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cfltdlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_fltvalue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cfltdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cfltdlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLTDLG_H__53DE052E_9D13_494D_9909_5EA3BFB2ED6C__INCLUDED_)
