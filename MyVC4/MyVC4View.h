// MyVC4View.h : interface of the CMyVC4View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYVC4VIEW_H__D6425855_BB4C_41AC_AB83_EA4AA0FD9A3A__INCLUDED_)
#define AFX_MYVC4VIEW_H__D6425855_BB4C_41AC_AB83_EA4AA0FD9A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyVC4View : public CView
{
protected: // create from serialization only
	CMyVC4View();
	DECLARE_DYNCREATE(CMyVC4View)

// Attributes
public:
	CMyVC4Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyVC4View)
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
	virtual ~CMyVC4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void MyFace(CDC* pDC,int x,int y);
	void MyPolygon(CDC* pDC,int x0,int y0);
	void MyLine(CDC* pDC,int x,int y, int dx,int dy,int width,COLORREF col);
	void MyEllipse(CDC* pDC,int x0,int y0);
	void MyCircle(CDC* pDC,int x0,int y0, int r,int brush);
	//{{AFX_MSG(CMyVC4View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyVC4View.cpp
inline CMyVC4Doc* CMyVC4View::GetDocument()
   { return (CMyVC4Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVC4VIEW_H__D6425855_BB4C_41AC_AB83_EA4AA0FD9A3A__INCLUDED_)
