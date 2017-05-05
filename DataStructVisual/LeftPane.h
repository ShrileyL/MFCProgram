#if !defined(AFX_LEFTPANE_H__9E32898F_9D87_4DE3_9732_0CED21224347__INCLUDED_)
#define AFX_LEFTPANE_H__9E32898F_9D87_4DE3_9732_0CED21224347__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftPane.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeftPane form view

#include "MainFrm.h"
#include "RightSwitchFrame.h"

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CLeftPane : public CFormView
{
protected:
	CLeftPane();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLeftPane)

// Form Data
public:
	//{{AFX_DATA(CLeftPane)
	enum { IDD = IDD_LEFTPANE_FORMVIEW };
	CTreeCtrl	m_LeftTree;
	//}}AFX_DATA

// Attributes
public:


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftPane)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLeftPane();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CLeftPane)
	afx_msg void OnSelchangedLeftpaneTree(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CRect m_sRect;
	HTREEITEM m_Root;
	void InitTree();
	CImageList m_TreeImageList;

	CRightSwitchFrame* m_pRightSwitchFrame;

	CMainFrame* m_pMainFrame;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTPANE_H__9E32898F_9D87_4DE3_9732_0CED21224347__INCLUDED_)
