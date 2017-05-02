#if !defined(AFX_DBQUERY_H__BDE906FF_921B_41ED_9055_8B6D39FC114F__INCLUDED_)
#define AFX_DBQUERY_H__BDE906FF_921B_41ED_9055_8B6D39FC114F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dbquery.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDbquery dialog

class CDbquery : public CDialog
{
// Construction
public:
	CDbquery(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDbquery)
	enum { IDD = IDD_DIALOG3 };
	CListBox	m_list1;
	CString	m_factory;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDbquery)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDbquery)
	afx_msg void OnQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBQUERY_H__BDE906FF_921B_41ED_9055_8B6D39FC114F__INCLUDED_)
