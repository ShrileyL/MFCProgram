// LinkDataView.cpp : implementation of the CLinkDataView class
//

#include "stdafx.h"
#include "LinkData.h"

#include "LinkDataSet.h"
#include "LinkDataDoc.h"
#include "LinkDataView.h"

#include "fltdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinkDataView

IMPLEMENT_DYNCREATE(CLinkDataView, CRecordView)

BEGIN_MESSAGE_MAP(CLinkDataView, CRecordView)
	//{{AFX_MSG_MAP(CLinkDataView)
	ON_COMMAND(ID_RECORD_ADD, OnRecordAdd)
	ON_COMMAND(ID_RECORD_DELETE, OnRecordDelete)
	ON_COMMAND(ID_SORT_ID, OnSortId)
	ON_COMMAND(ID_SORT_LENGTH, OnSortLength)
	ON_COMMAND(ID_FILTER_ID, OnFilterId)
	ON_COMMAND(ID_FILTER_FACTORY, OnFilterFactory)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinkDataView construction/destruction

CLinkDataView::CLinkDataView()
	: CRecordView(CLinkDataView::IDD)
{
	//{{AFX_DATA_INIT(CLinkDataView)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	flag = FALSE;
}

CLinkDataView::~CLinkDataView()
{
}

void CLinkDataView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinkDataView)
	DDX_FieldText(pDX, IDC_FACTORY, m_pSet->m_factory, m_pSet);
	DDX_FieldText(pDX, IDC_HEIGHT, m_pSet->m_height, m_pSet);
	DDX_FieldText(pDX, IDC_ID, m_pSet->m_ID, m_pSet);
	DDX_FieldText(pDX, IDC_LENGTH, m_pSet->m_length, m_pSet);
	DDX_FieldText(pDX, IDC_NAME, m_pSet->m_name, m_pSet);
	DDX_FieldText(pDX, IDC_WIDTH, m_pSet->m_width, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CLinkDataView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CLinkDataView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_linkDataSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CLinkDataView diagnostics

#ifdef _DEBUG
void CLinkDataView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CLinkDataView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CLinkDataDoc* CLinkDataView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLinkDataDoc)));
	return (CLinkDataDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLinkDataView database support
CRecordset* CLinkDataView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CLinkDataView message handlers

void CLinkDataView::OnRecordAdd() 
{
	m_pSet->AddNew();//add record
	flag = TRUE;//set flag(update status) to True
	CEdit* pCtrl = (CEdit*)GetDlgItem(IDC_ID);
	pCtrl->SetReadOnly(FALSE);//change Read-only edit box to editable
	UpdateData(FALSE);//print new blank record
	
}

void CLinkDataView::OnRecordDelete() 
{
	m_pSet->Delete();//delete present record
	m_pSet->MoveNext();//next record
	if(m_pSet->IsEOF())//if is the last record
		m_pSet->MoveLast();//move to last record
	if(m_pSet->IsBOF())//if no record
		m_pSet->SetFieldNull(NULL);//set present record and present feild to Null

	m_pSet->Requery();//re-built data set
	UpdateData(FALSE);//transfer records to windows controls
	
}

void CLinkDataView::OnSortId() 
{
	m_pSet->Close();
	m_pSet->m_strSort = "ID";
	m_pSet->Open();
	UpdateData(FALSE);
	
}

void CLinkDataView::OnSortLength() 
{
	m_pSet->Close();
	m_pSet->m_strSort = "LENGTH";
	m_pSet->Open();
	UpdateData(FALSE);
	
}

void CLinkDataView::OnFilterId() 
{
	Cfltdlg dlg;
	int index;
	if (dlg.DoModal()==IDOK)
	{
		sscanf(dlg.m_fltvalue,"%d",&index);
		m_pSet->Close();
		m_pSet->m_strFilter.Format("ID=%d",index);
		m_pSet->Open();
		int count = m_pSet->GetRecordCount();//get record's number
		if (count == 0)
		{
			MessageBox("无匹配记录！");
			m_pSet->Close();
			m_pSet->m_strFilter = "";
			m_pSet->Open();
		}
		UpdateData(FALSE);
	}
	
}

void CLinkDataView::OnFilterFactory() 
{
	CString str,str1;
	str1="FACTORY";
	Cfltdlg dlg;
	if (dlg.DoModal()==IDOK)
	{
		str = str1+"='"+dlg.m_fltvalue+"'";
		m_pSet->Close();
		m_pSet->m_strFilter=str;
		m_pSet->Open();
		int count = m_pSet->GetRecordCount();//get record's number
		if (count == 0)
		{
			MessageBox("无匹配记录！");
			m_pSet->Close();
			m_pSet->m_strFilter = "";
			m_pSet->Open();
		}
		UpdateData(FALSE);
	}
	
}

BOOL CLinkDataView::OnMove(UINT nIDMoveCommand) 
{
	if (flag)
	{
		UpdateData(TRUE);//transfer the new record to data Set
		if (m_pSet->CanUpdate())
		{
			m_pSet->Update();//update for data set
		} 
		else
		{
			MessageBox("数据源不能完成更新！");
			
		}
		flag= FALSE;
		m_pSet->Requery();//re-build data Set
		UpdateData(FALSE);//transfer records to windows control
		CEdit* pCtrl = (CEdit*)GetDlgItem(IDC_ID);
		pCtrl->SetReadOnly(TRUE);//set Read-only
		return TRUE;
	}
	else
		return CRecordView::OnMove(nIDMoveCommand);
}
