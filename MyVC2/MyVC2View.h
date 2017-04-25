// MyVC2View.h : interface of the CMyVC2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYVC2VIEW_H__9A9B4F14_6BB1_49CD_B3C8_F2AC006A2C3E__INCLUDED_)
#define AFX_MYVC2VIEW_H__9A9B4F14_6BB1_49CD_B3C8_F2AC006A2C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyVC2View : public CView
{
protected: // create from serialization only
	CMyVC2View();
	DECLARE_DYNCREATE(CMyVC2View)

// Attributes
public:
	CMyVC2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyVC2View)
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
	void FillRect0(CDC* pDC,COLORREF col,CPoint point,int chd,int kd);
	virtual ~CMyVC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void Polygon1(CDC *pDC, int x0, int y0, COLORREF col);
	void Polygon0(CDC *pDC, int x0, int y0,COLORREF col);
	void Arc1(CDC *pDC, int x0, int y0, int r,double Ro,double Rd, int width, COLORREF col);
	void Ellipsem(CDC *pDC, int x0, int y0, int r, COLORREF col);
	void Arc0(CDC* pDC,int x0,int y0,int r,int width,COLORREF col);
	void Ellipses(CDC* pDC, int x1,int y1, int x2, int y2,int width, COLORREF col,BOOL mb);
	void Line0(CDC* pDC,int x1,int y1,int x2,int y2,int width,COLORREF col);
	void Rectangle0(CDC* pDC,int x1,int y1,int x2,int y2,COLORREF col);
	//{{AFX_MSG(CMyVC2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyVC2View.cpp
inline CMyVC2Doc* CMyVC2View::GetDocument()
   { return (CMyVC2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVC2VIEW_H__9A9B4F14_6BB1_49CD_B3C8_F2AC006A2C3E__INCLUDED_)
