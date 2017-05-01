// ODBC_DAOView.h : interface of the CODBC_DAOView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODBC_DAOVIEW_H__167C6298_4C21_4754_961B_FC7ACB01075B__INCLUDED_)
#define AFX_ODBC_DAOVIEW_H__167C6298_4C21_4754_961B_FC7ACB01075B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CODBC_DAOView : public CView
{
protected: // create from serialization only
	CODBC_DAOView();
	DECLARE_DYNCREATE(CODBC_DAOView)

// Attributes
public:
	CODBC_DAODoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBC_DAOView)
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
	virtual ~CODBC_DAOView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CODBC_DAOView)
	afx_msg void OnDbRead();
	afx_msg void OnDbWrite();
	afx_msg void OnTableAdd();
	afx_msg void OnRecordAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ODBC_DAOView.cpp
inline CODBC_DAODoc* CODBC_DAOView::GetDocument()
   { return (CODBC_DAODoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBC_DAOVIEW_H__167C6298_4C21_4754_961B_FC7ACB01075B__INCLUDED_)
