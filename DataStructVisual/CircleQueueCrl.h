#if !defined(AFX_CIRCLEQUEUECRL_H__0F17427C_2872_4625_BAE6_5FA235A395EC__INCLUDED_)
#define AFX_CIRCLEQUEUECRL_H__0F17427C_2872_4625_BAE6_5FA235A395EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CircleQueueCrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCircleQueueCrl form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CCircleQueueCrl : public CFormView
{
public:
	CCircleQueueCrl();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCircleQueueCrl)

// Form Data
public:
	//{{AFX_DATA(CCircleQueueCrl)
	enum { IDD = IDD_CIRCLEQUEUE_CONTROL };
	CString	m_CircleQueNodeVal;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCircleQueueCrl)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCircleQueueCrl();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CCircleQueueCrl)
	afx_msg void OnButtonEnqueue();
	afx_msg void OnButtonDequeue();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CIRCLEQUEUECRL_H__0F17427C_2872_4625_BAE6_5FA235A395EC__INCLUDED_)
