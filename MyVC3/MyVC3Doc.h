// MyVC3Doc.h : interface of the CMyVC3Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYVC3DOC_H__3581775F_9F50_4137_ADD0_BD48355416DF__INCLUDED_)
#define AFX_MYVC3DOC_H__3581775F_9F50_4137_ADD0_BD48355416DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyVC3Doc : public CDocument
{
protected: // create from serialization only
	CMyVC3Doc();
	DECLARE_DYNCREATE(CMyVC3Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyVC3Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyVC3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyVC3Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVC3DOC_H__3581775F_9F50_4137_ADD0_BD48355416DF__INCLUDED_)
