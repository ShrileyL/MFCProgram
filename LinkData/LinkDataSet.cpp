// LinkDataSet.cpp : implementation of the CLinkDataSet class
//

#include "stdafx.h"
#include "LinkData.h"
#include "LinkDataSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinkDataSet implementation

IMPLEMENT_DYNAMIC(CLinkDataSet, CRecordset)

CLinkDataSet::CLinkDataSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CLinkDataSet)
	m_ID = 0;
	m_name = _T("");
	m_length = 0.0;
	m_width = 0.0;
	m_height = 0.0;
	m_factory = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CLinkDataSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=carlib");
}

CString CLinkDataSet::GetDefaultSQL()
{
	return _T("[example]");
}

void CLinkDataSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CLinkDataSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Double(pFX, _T("[length]"), m_length);
	RFX_Double(pFX, _T("[width]"), m_width);
	RFX_Double(pFX, _T("[height]"), m_height);
	RFX_Text(pFX, _T("[factory]"), m_factory);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CLinkDataSet diagnostics

#ifdef _DEBUG
void CLinkDataSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CLinkDataSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
