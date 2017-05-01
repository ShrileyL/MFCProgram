// ODBC_DAODoc.cpp : implementation of the CODBC_DAODoc class
//

#include "stdafx.h"
#include "ODBC_DAO.h"

#include "ODBC_DAODoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBC_DAODoc

IMPLEMENT_DYNCREATE(CODBC_DAODoc, CDocument)

BEGIN_MESSAGE_MAP(CODBC_DAODoc, CDocument)
	//{{AFX_MSG_MAP(CODBC_DAODoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBC_DAODoc construction/destruction

CODBC_DAODoc::CODBC_DAODoc()
{
	// TODO: add one-time construction code here

}

CODBC_DAODoc::~CODBC_DAODoc()
{
}

BOOL CODBC_DAODoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CODBC_DAODoc serialization

void CODBC_DAODoc::Serialize(CArchive& ar)
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
// CODBC_DAODoc diagnostics

#ifdef _DEBUG
void CODBC_DAODoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CODBC_DAODoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CODBC_DAODoc commands
