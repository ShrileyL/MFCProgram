// ODBC_DAOView.cpp : implementation of the CODBC_DAOView class
//

#include "stdafx.h"
#include "ODBC_DAO.h"

#include "ODBC_DAODoc.h"
#include "ODBC_DAOView.h"

#include "Dbxh1.h"//序号对话框
#include "Carset.h"//数据集类
#include "Dispdata.h"//显示数据对话框

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBC_DAOView

IMPLEMENT_DYNCREATE(CODBC_DAOView, CView)

BEGIN_MESSAGE_MAP(CODBC_DAOView, CView)
	//{{AFX_MSG_MAP(CODBC_DAOView)
	ON_COMMAND(ID_DB_READ, OnDbRead)
	ON_COMMAND(ID_DB_WRITE, OnDbWrite)
	ON_COMMAND(ID_TABLE_ADD, OnTableAdd)
	ON_COMMAND(ID_RECORD_ADD, OnRecordAdd)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBC_DAOView construction/destruction

CODBC_DAOView::CODBC_DAOView()
{
	// TODO: add construction code here

}

CODBC_DAOView::~CODBC_DAOView()
{
}

BOOL CODBC_DAOView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CODBC_DAOView drawing

void CODBC_DAOView::OnDraw(CDC* pDC)
{
	CODBC_DAODoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CODBC_DAOView printing

BOOL CODBC_DAOView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CODBC_DAOView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CODBC_DAOView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CODBC_DAOView diagnostics

#ifdef _DEBUG
void CODBC_DAOView::AssertValid() const
{
	CView::AssertValid();
}

void CODBC_DAOView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CODBC_DAODoc* CODBC_DAOView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBC_DAODoc)));
	return (CODBC_DAODoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CODBC_DAOView message handlers

void CODBC_DAOView::OnDbRead() 
{
	int record_xh;//记录ID号
	CDbxh dlg;
	CDispdata ddlg;
	if (dlg.DoModal()==IDOK)
	{
		record_xh = dlg.m_xh;
	}

	CCarset* m_pset;
	m_pset=&GetDocument()->cset;
	m_pset->m_strFilter.Format("ID=%d",record_xh);//设置过滤条件
	m_pset->Open();

	ddlg.m_id = m_pset->m_ID;
	ddlg.m_name = m_pset->m_name;
	ddlg.m_length = m_pset->m_length;
	ddlg.m_width = m_pset->m_width;
	ddlg.m_height = m_pset->m_height;
	ddlg.m_factory = m_pset->m_factory;

	ddlg.DoModal();//数据显示
	m_pset->Close();
	
}

void CODBC_DAOView::OnDbWrite() 
{
CDispdata ddlg;
if (ddlg.DoModal())
{
	CCarset* m_pset;
	m_pset=&GetDocument()->cset;
	
	m_pset->Open();
	m_pset->AddNew();
	
	m_pset->m_ID = ddlg.m_id;
	m_pset->m_name = ddlg.m_name;
	m_pset->m_length = ddlg.m_length;
	m_pset->m_width = ddlg.m_width;
	m_pset->m_height = ddlg.m_height;
	m_pset->m_factory = ddlg.m_factory;

	m_pset->Update();//更新数据源完成添加
}
	
}

void CODBC_DAOView::OnTableAdd() 
{
	CDatabase db;
	db.Open("carlib");
	db.ExecuteSQL("CREATE TABLE guestbook(name VARCHAR(20),address TEXT,birthday DATETIME)");
	db.Close();
	
}

void CODBC_DAOView::OnRecordAdd() 
{
	CDatabase db;
	db.Open("carlib");
	db.ExecuteSQL("INSERT INTO example(id,name,factory) VALUES(6,'索纳塔','南京')");
	db.Close();
	
}
