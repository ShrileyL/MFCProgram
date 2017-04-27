// MyVC4Doc.h : interface of the CMyVC4Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYVC4DOC_H__741124B0_7453_47EB_B530_B0DB3B0D179C__INCLUDED_)
#define AFX_MYVC4DOC_H__741124B0_7453_47EB_B530_B0DB3B0D179C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyVC4Doc : public CDocument
{
protected: // create from serialization only
	CMyVC4Doc();
	DECLARE_DYNCREATE(CMyVC4Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyVC4Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyVC4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyVC4Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVC4DOC_H__741124B0_7453_47EB_B530_B0DB3B0D179C__INCLUDED_)
