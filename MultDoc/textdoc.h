#if !defined(AFX_TEXTDOC_H__6DD7B8F4_A8A3_4B52_BF73_8A65CD940D4C__INCLUDED_)
#define AFX_TEXTDOC_H__6DD7B8F4_A8A3_4B52_BF73_8A65CD940D4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// textdoc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTextDoc document

class CTextDoc : public CDocument
{
protected:
	CTextDoc();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTextDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextDoc)
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CTextDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTDOC_H__6DD7B8F4_A8A3_4B52_BF73_8A65CD940D4C__INCLUDED_)
