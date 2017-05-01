// LinkDataDoc.cpp : implementation of the CLinkDataDoc class
//

#include "stdafx.h"
#include "LinkData.h"

#include "LinkDataSet.h"
#include "LinkDataDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinkDataDoc

IMPLEMENT_DYNCREATE(CLinkDataDoc, CDocument)

BEGIN_MESSAGE_MAP(CLinkDataDoc, CDocument)
	//{{AFX_MSG_MAP(CLinkDataDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinkDataDoc construction/destruction

CLinkDataDoc::CLinkDataDoc()
{
	// TODO: add one-time construction code here

}

CLinkDataDoc::~CLinkDataDoc()
{
}

BOOL CLinkDataDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLinkDataDoc diagnostics

#ifdef _DEBUG
void CLinkDataDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLinkDataDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLinkDataDoc commands
