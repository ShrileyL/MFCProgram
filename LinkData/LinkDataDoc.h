// LinkDataDoc.h : interface of the CLinkDataDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKDATADOC_H__1DEF820D_AD28_4CC6_A328_169789F84D3B__INCLUDED_)
#define AFX_LINKDATADOC_H__1DEF820D_AD28_4CC6_A328_169789F84D3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "LinkDataSet.h"


class CLinkDataDoc : public CDocument
{
protected: // create from serialization only
	CLinkDataDoc();
	DECLARE_DYNCREATE(CLinkDataDoc)

// Attributes
public:
	CLinkDataSet m_linkDataSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkDataDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLinkDataDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLinkDataDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKDATADOC_H__1DEF820D_AD28_4CC6_A328_169789F84D3B__INCLUDED_)
