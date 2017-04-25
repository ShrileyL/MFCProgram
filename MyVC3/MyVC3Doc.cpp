// MyVC3Doc.cpp : implementation of the CMyVC3Doc class
//

#include "stdafx.h"
#include "MyVC3.h"

#include "MyVC3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyVC3Doc

IMPLEMENT_DYNCREATE(CMyVC3Doc, CDocument)

BEGIN_MESSAGE_MAP(CMyVC3Doc, CDocument)
	//{{AFX_MSG_MAP(CMyVC3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyVC3Doc construction/destruction

CMyVC3Doc::CMyVC3Doc()
{
	// TODO: add one-time construction code here

}

CMyVC3Doc::~CMyVC3Doc()
{
}

BOOL CMyVC3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyVC3Doc serialization

void CMyVC3Doc::Serialize(CArchive& ar)
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
// CMyVC3Doc diagnostics

#ifdef _DEBUG
void CMyVC3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyVC3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyVC3Doc commands
