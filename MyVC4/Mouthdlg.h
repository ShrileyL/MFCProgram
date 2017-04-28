#if !defined(AFX_MOUTHDLG_H__30341830_612E_496A_A8B2_1B4B95300A87__INCLUDED_)
#define AFX_MOUTHDLG_H__30341830_612E_496A_A8B2_1B4B95300A87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Mouthdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMouthdlg dialog

class CMouthdlg : public CDialog
{
// Construction
public:
	CMouthdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMouthdlg)
	enum { IDD = IDD_D_MOUTH };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouthdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMouthdlg)
	afx_msg void OnMouthD();
	afx_msg void OnMouthN();
	afx_msg void OnMouthU();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUTHDLG_H__30341830_612E_496A_A8B2_1B4B95300A87__INCLUDED_)
