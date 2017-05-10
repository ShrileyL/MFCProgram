// DeQueueCrl.cpp : implementation file
//

#include "stdafx.h"
#include "datastructvisual.h"
#include "DeQueueCrl.h"

#include "DeQueueDraw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeQueueCrl

IMPLEMENT_DYNCREATE(CDeQueueCrl, CFormView)

CDeQueueCrl::CDeQueueCrl()
	: CFormView(CDeQueueCrl::IDD)
{
	//{{AFX_DATA_INIT(CDeQueueCrl)
	m_DeQueNodeVal = _T("");
	//}}AFX_DATA_INIT
}

CDeQueueCrl::~CDeQueueCrl()
{
}

void CDeQueueCrl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeQueueCrl)
	DDX_Text(pDX, IDC_EDIT_DEQUEUE_DATA, m_DeQueNodeVal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeQueueCrl, CFormView)
	//{{AFX_MSG_MAP(CDeQueueCrl)
	ON_BN_CLICKED(IDC_BUTTON_ENHEADQUEUE, OnButtonEnheadqueue)
	ON_BN_CLICKED(IDC_BUTTON_DEHEADQUEUE, OnButtonDeheadqueue)
	ON_BN_CLICKED(IDC_BUTTON_ENREARQUEUE, OnButtonEnrearqueue)
	ON_BN_CLICKED(IDC_BUTTON_DEREARQUEUE, OnButtonDerearqueue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeQueueCrl diagnostics

#ifdef _DEBUG
void CDeQueueCrl::AssertValid() const
{
	CFormView::AssertValid();
}

void CDeQueueCrl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDeQueueCrl message handlers

void CDeQueueCrl::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	GetDlgItem(IDC_BUTTON_DEHEADQUEUE)->
		EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_DEREARQUEUE)->
		EnableWindow(FALSE);
}

void CDeQueueCrl::OnButtonEnheadqueue() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_DeQueNodeVal.IsEmpty()){
		::AfxMessageBox("请输入结点值.");
		return;
	}
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CDeQueueDraw*)(pWnd->GetPane(0,0)))->
		EnDeQueue(m_DeQueNodeVal,true);
	GetDlgItem(IDC_BUTTON_DEHEADQUEUE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_DEREARQUEUE)->EnableWindow(TRUE);
}

void CDeQueueCrl::OnButtonDeheadqueue() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CDeQueueDraw*)(pWnd->GetPane(0, 0)))->
		DeDeQueue(true);
}

void CDeQueueCrl::OnButtonEnrearqueue() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_DeQueNodeVal.IsEmpty()){
		::AfxMessageBox("请输入结点值.");
		return;
	}
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CDeQueueDraw*)(pWnd->GetPane(0,0)))->
		EnDeQueue(m_DeQueNodeVal,false);
	GetDlgItem(IDC_BUTTON_DEHEADQUEUE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_DEREARQUEUE)->EnableWindow(TRUE);
}

void CDeQueueCrl::OnButtonDerearqueue() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CDeQueueDraw*)(pWnd->GetPane(0, 0)))->
		DeDeQueue(false);
}
