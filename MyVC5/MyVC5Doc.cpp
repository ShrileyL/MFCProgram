// MyVC5Doc.cpp : implementation of the CMyVC5Doc class
//

#include "stdafx.h"
#include "MyVC5.h"

#include "MyVC5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyVC5Doc

IMPLEMENT_DYNCREATE(CMyVC5Doc, CDocument)

BEGIN_MESSAGE_MAP(CMyVC5Doc, CDocument)
	//{{AFX_MSG_MAP(CMyVC5Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyVC5Doc construction/destruction

CMyVC5Doc::CMyVC5Doc()
{
	// TODO: add one-time construction code here

}

CMyVC5Doc::~CMyVC5Doc()
{
}

BOOL CMyVC5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyVC5Doc serialization

void CMyVC5Doc::Serialize(CArchive& ar)
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
// CMyVC5Doc diagnostics

#ifdef _DEBUG
void CMyVC5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyVC5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyVC5Doc commands
