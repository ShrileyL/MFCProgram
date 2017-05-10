#if !defined(AFX_DEQUEUECRL_H__B7F40915_5D1F_420A_BF39_BEB4B90660B4__INCLUDED_)
#define AFX_DEQUEUECRL_H__B7F40915_5D1F_420A_BF39_BEB4B90660B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeQueueCrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeQueueCrl form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CDeQueueCrl : public CFormView
{
protected:
	CDeQueueCrl();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDeQueueCrl)

// Form Data
public:
	//{{AFX_DATA(CDeQueueCrl)
	enum { IDD = IDD_DEQUEUE_CONTROL };
	CString	m_DeQueNodeVal;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeQueueCrl)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDeQueueCrl();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CDeQueueCrl)
	afx_msg void OnButtonEnheadqueue();
	afx_msg void OnButtonDeheadqueue();
	afx_msg void OnButtonEnrearqueue();
	afx_msg void OnButtonDerearqueue();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEQUEUECRL_H__B7F40915_5D1F_420A_BF39_BEB4B90660B4__INCLUDED_)
