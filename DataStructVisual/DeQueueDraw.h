#if !defined(AFX_DEQUEUEDRAW_H__EBC1AED5_986B_42F0_B78B_49D4DA339BDA__INCLUDED_)
#define AFX_DEQUEUEDRAW_H__EBC1AED5_986B_42F0_B78B_49D4DA339BDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeQueueDraw.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeQueueDraw form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "DataStructVisualDoc.h"

class CDeQueueDraw : public CFormView
{
protected:
	CDeQueueDraw();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDeQueueDraw)

// Form Data
public:
	//{{AFX_DATA(CDeQueueDraw)
	enum { IDD = IDD_DEQUEUE_DRAW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	int	m_Flag;
	HANDLE	m_hThreadDeQueue;
	HANDLE	m_hEventDeQueue;
	CDataStructVisualDoc* 	m_pDoc;

// Operations
public:
	void DeDeQueue(bool vIsHead);
	void EnDeQueue(CString vDeQueValue,bool vIsHead);
	void DrawDeQueue (CDC* pDC);
	static DWORD WINAPI DeQueueProc (LPVOID lpParameter);
	CDataStructVisualDoc* GetDocument();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeQueueDraw)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDeQueueDraw();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CDeQueueDraw)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEQUEUEDRAW_H__EBC1AED5_986B_42F0_B78B_49D4DA339BDA__INCLUDED_)
