// ODBC_DAODoc.h : interface of the CODBC_DAODoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODBC_DAODOC_H__9896F1AC_ACB6_466D_A44D_95AED75E3AA7__INCLUDED_)
#define AFX_ODBC_DAODOC_H__9896F1AC_ACB6_466D_A44D_95AED75E3AA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Carset.h" //加入数据库类头文件

class CODBC_DAODoc : public CDocument
{
protected: // create from serialization only
	CODBC_DAODoc();
	DECLARE_DYNCREATE(CODBC_DAODoc)

// Attributes
public:
	CCarset cset;//定义类对象

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBC_DAODoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CODBC_DAODoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CODBC_DAODoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBC_DAODOC_H__9896F1AC_ACB6_466D_A44D_95AED75E3AA7__INCLUDED_)
