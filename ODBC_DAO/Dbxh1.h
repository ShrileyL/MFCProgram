#if !defined(AFX_DBXH1_H__A277359A_136D_4742_A533_4A1318EB2218__INCLUDED_)
#define AFX_DBXH1_H__A277359A_136D_4742_A533_4A1318EB2218__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dbxh1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDbxh dialog

class CDbxh : public CDialog
{
// Construction
public:
	CDbxh(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDbxh)
	enum { IDD = IDD_XH };
	int		m_xh;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDbxh)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDbxh)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBXH1_H__A277359A_136D_4742_A533_4A1318EB2218__INCLUDED_)
