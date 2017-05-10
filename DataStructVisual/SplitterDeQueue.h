#if !defined(AFX_SPLITTERDEQUEUE_H__BC80AD4F_B7A6_4324_A2BD_7C9247F22CC0__INCLUDED_)
#define AFX_SPLITTERDEQUEUE_H__BC80AD4F_B7A6_4324_A2BD_7C9247F22CC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SplitterDeQueue.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSplitterDeQueue view

class CSplitterDeQueue : public CView
{
public:
	CSplitterDeQueue();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSplitterDeQueue)

// Attributes
public:
	CSplitterWnd m_WndDeQueueSplitter;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitterDeQueue)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSplitterDeQueue();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSplitterDeQueue)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITTERDEQUEUE_H__BC80AD4F_B7A6_4324_A2BD_7C9247F22CC0__INCLUDED_)
