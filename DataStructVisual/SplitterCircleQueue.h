#if !defined(AFX_SPLITTERCIRCLEQUEUE_H__5F2836AD_62CB_4F24_898F_0675C06C460A__INCLUDED_)
#define AFX_SPLITTERCIRCLEQUEUE_H__5F2836AD_62CB_4F24_898F_0675C06C460A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SplitterCircleQueue.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSplitterCircleQueue view

class CSplitterCircleQueue : public CView
{
public:
	CSplitterCircleQueue();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSplitterCircleQueue)

// Attributes
public:
	CSplitterWnd m_WndCircleQueueSplitter;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitterCircleQueue)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSplitterCircleQueue();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSplitterCircleQueue)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITTERCIRCLEQUEUE_H__5F2836AD_62CB_4F24_898F_0675C06C460A__INCLUDED_)
