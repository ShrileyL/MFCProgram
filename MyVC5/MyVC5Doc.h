// MyVC5Doc.h : interface of the CMyVC5Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYVC5DOC_H__D0A97BFE_5C17_49C8_9E47_ADCC55D82DC4__INCLUDED_)
#define AFX_MYVC5DOC_H__D0A97BFE_5C17_49C8_9E47_ADCC55D82DC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyVC5Doc : public CDocument
{
protected: // create from serialization only
	CMyVC5Doc();
	DECLARE_DYNCREATE(CMyVC5Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyVC5Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyVC5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyVC5Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVC5DOC_H__D0A97BFE_5C17_49C8_9E47_ADCC55D82DC4__INCLUDED_)
