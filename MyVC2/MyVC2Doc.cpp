// MyVC2Doc.cpp : implementation of the CMyVC2Doc class
//

#include "stdafx.h"
#include "MyVC2.h"

#include "MyVC2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyVC2Doc

IMPLEMENT_DYNCREATE(CMyVC2Doc, CDocument)

BEGIN_MESSAGE_MAP(CMyVC2Doc, CDocument)
	//{{AFX_MSG_MAP(CMyVC2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyVC2Doc construction/destruction

CMyVC2Doc::CMyVC2Doc()
{
	// TODO: add one-time construction code here

}

CMyVC2Doc::~CMyVC2Doc()
{
}

BOOL CMyVC2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyVC2Doc serialization

void CMyVC2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC2Doc diagnostics

#ifdef _DEBUG
void CMyVC2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyVC2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyVC2Doc commands
