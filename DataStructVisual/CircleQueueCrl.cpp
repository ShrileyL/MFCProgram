// CircleQueueCrl.cpp : implementation file
//

#include "stdafx.h"
#include "datastructvisual.h"
#include "CircleQueueCrl.h"

#include "CircleQueueDraw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCircleQueueCrl

IMPLEMENT_DYNCREATE(CCircleQueueCrl, CFormView)

CCircleQueueCrl::CCircleQueueCrl()
	: CFormView(CCircleQueueCrl::IDD)
{
	//{{AFX_DATA_INIT(CCircleQueueCrl)
	m_CircleQueNodeVal = _T("");
	//}}AFX_DATA_INIT
}

CCircleQueueCrl::~CCircleQueueCrl()
{
}

void CCircleQueueCrl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCircleQueueCrl)
	DDX_Text(pDX, IDC_EDIT_CIRCLEQUEUE_DATA, m_CircleQueNodeVal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCircleQueueCrl, CFormView)
	//{{AFX_MSG_MAP(CCircleQueueCrl)
	ON_BN_CLICKED(IDC_BUTTON_ENQUEUE, OnButtonEnqueue)
	ON_BN_CLICKED(IDC_BUTTON_DEQUEUE, OnButtonDequeue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCircleQueueCrl diagnostics

#ifdef _DEBUG
void CCircleQueueCrl::AssertValid() const
{
	CFormView::AssertValid();
}

void CCircleQueueCrl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCircleQueueCrl message handlers

void CCircleQueueCrl::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	GetDlgItem(IDC_BUTTON_DEQUEUE)->EnableWindow(FALSE);
}

void CCircleQueueCrl::OnButtonEnqueue() 
{
	UpdateData(TRUE);
	if(m_CircleQueNodeVal.IsEmpty()){
		::AfxMessageBox("请输入入队数据.");
		return;
	}
	CString tStr;
	tStr=m_CircleQueNodeVal;
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CCircleQueueDraw*)(pWnd->GetPane(0,0)))->EnCircleQueue(m_CircleQueNodeVal);
	GetDlgItem(IDC_BUTTON_DEQUEUE)->EnableWindow(TRUE);
	
}

void CCircleQueueCrl::OnButtonDequeue() 
{
	UpdateData(TRUE); 
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent(); 
	((CCircleQueueDraw*)(pWnd->GetPane(0, 0)))->DeCircleQueue();
	
}
