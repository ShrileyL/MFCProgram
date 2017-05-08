#if !defined(AFX_CIRCLEQUEUEDRAW_H__9D3C02F7_AFE6_4361_8AC7_232B9B5713B9__INCLUDED_)
#define AFX_CIRCLEQUEUEDRAW_H__9D3C02F7_AFE6_4361_8AC7_232B9B5713B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CircleQueueDraw.h : header file
//

#include "DataStructVisualDoc.h"
/////////////////////////////////////////////////////////////////////////////
// CCircleQueueDraw form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CCircleQueueDraw : public CFormView
{
public:
	CCircleQueueDraw();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCircleQueueDraw)

// Form Data
public:
	//{{AFX_DATA(CCircleQueueDraw)
	enum { IDD = IDD_CIRCLEQUEUE_DRAW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	int	m_Flag;
	HANDLE	m_hThreadCircleQueue;
	HANDLE	m_hEventCircleQueue;
	CDataStructVisualDoc* 	m_pDoc;

// Operations
public:
	void DeCircleQueue();
	void EnCircleQueue(CString vCQValue);
	void InitCircleQueue(CRect vRect);
	static DWORD WINAPI CircleQueueProc(LPVOID lpParameter);
	CDataStructVisualDoc* GetDocument();
	void DrawCircleQueue(CDC* pDC);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCircleQueueDraw)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCircleQueueDraw();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CCircleQueueDraw)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CIRCLEQUEUEDRAW_H__9D3C02F7_AFE6_4361_8AC7_232B9B5713B9__INCLUDED_)
