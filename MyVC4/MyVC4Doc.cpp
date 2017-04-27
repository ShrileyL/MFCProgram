// MyVC4Doc.cpp : implementation of the CMyVC4Doc class
//

#include "stdafx.h"
#include "MyVC4.h"

#include "MyVC4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyVC4Doc

IMPLEMENT_DYNCREATE(CMyVC4Doc, CDocument)

BEGIN_MESSAGE_MAP(CMyVC4Doc, CDocument)
	//{{AFX_MSG_MAP(CMyVC4Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyVC4Doc construction/destruction

CMyVC4Doc::CMyVC4Doc()
{
	// TODO: add one-time construction code here

}

CMyVC4Doc::~CMyVC4Doc()
{
}

BOOL CMyVC4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyVC4Doc serialization

void CMyVC4Doc::Serialize(CArchive& ar)
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
// CMyVC4Doc diagnostics

#ifdef _DEBUG
void CMyVC4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyVC4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyVC4Doc commands
