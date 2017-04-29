// MyVC5View.h : interface of the CMyVC5View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYVC5VIEW_H__05F27110_D391_4DDD_9786_D0F4CF541A6A__INCLUDED_)
#define AFX_MYVC5VIEW_H__05F27110_D391_4DDD_9786_D0F4CF541A6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyVC5View : public CView
{
protected: // create from serialization only
	CMyVC5View();
	DECLARE_DYNCREATE(CMyVC5View)

// Attributes
public:
	CMyVC5Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyVC5View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyVC5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void Bit4(CDC* pDC, CPoint point);
	void Bit3(CDC* pDC, int dx);
	void Bit2(CDC* pDC);
	void Bit1(CDC* pDC);
	//{{AFX_MSG(CMyVC5View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyVC5View.cpp
inline CMyVC5Doc* CMyVC5View::GetDocument()
   { return (CMyVC5Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVC5VIEW_H__05F27110_D391_4DDD_9786_D0F4CF541A6A__INCLUDED_)
