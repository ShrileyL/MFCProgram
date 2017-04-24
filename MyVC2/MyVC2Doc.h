// MyVC2Doc.h : interface of the CMyVC2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYVC2DOC_H__25C256F5_807C_4A99_BAAD_BE961873A9CA__INCLUDED_)
#define AFX_MYVC2DOC_H__25C256F5_807C_4A99_BAAD_BE961873A9CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyVC2Doc : public CDocument
{
protected: // create from serialization only
	CMyVC2Doc();
	DECLARE_DYNCREATE(CMyVC2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyVC2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyVC2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyVC2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVC2DOC_H__25C256F5_807C_4A99_BAAD_BE961873A9CA__INCLUDED_)
