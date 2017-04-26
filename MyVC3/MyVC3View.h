// MyVC3View.h : interface of the CMyVC3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYVC3VIEW_H__DCF961AC_805C_4831_AD48_B1DF8AB9FC8A__INCLUDED_)
#define AFX_MYVC3VIEW_H__DCF961AC_805C_4831_AD48_B1DF8AB9FC8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyVC3View : public CView
{
protected: // create from serialization only
	CMyVC3View();
	DECLARE_DYNCREATE(CMyVC3View)

// Attributes
public:
	CMyVC3Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyVC3View)
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
	virtual ~CMyVC3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void paint0(CDC* pDC);
	void CoordinateSystem(CDC* pDC);
	void SINCOS();
	void COS0();
	void SIN0();
	void Line0(CDC *pDC, double x1, double y1, double x2, double y2, int wid, COLORREF col);
	void FillRect0(CDC* pDC,COLORREF col,CPoint point, int chd,int kd);
	//{{AFX_MSG(CMyVC3View)
	afx_msg void OnSin();
	afx_msg void OnCos();
	afx_msg void OnSincos();
	afx_msg void OnWidth1();
	afx_msg void OnWidth2();
	afx_msg void OnWidth3();
	afx_msg void OnWidth4();
	afx_msg void OnUpdateWidth1(CCmdUI* pCmdUI);
	afx_msg void OnUpdateWidth2(CCmdUI* pCmdUI);
	afx_msg void OnUpdateWidth3(CCmdUI* pCmdUI);
	afx_msg void OnUpdateWidth4(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyVC3View.cpp
inline CMyVC3Doc* CMyVC3View::GetDocument()
   { return (CMyVC3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVC3VIEW_H__DCF961AC_805C_4831_AD48_B1DF8AB9FC8A__INCLUDED_)
