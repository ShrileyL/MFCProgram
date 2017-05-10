// DeQueueDraw.cpp : implementation file
//

#include "stdafx.h"
#include "datastructvisual.h"
#include "DeQueueDraw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeQueueDraw

IMPLEMENT_DYNCREATE(CDeQueueDraw, CFormView)

CDeQueueDraw::CDeQueueDraw()
	: CFormView(CDeQueueDraw::IDD)
{
	//{{AFX_DATA_INIT(CDeQueueDraw)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CDeQueueDraw::~CDeQueueDraw()
{
}

void CDeQueueDraw::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeQueueDraw)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeQueueDraw, CFormView)
	//{{AFX_MSG_MAP(CDeQueueDraw)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeQueueDraw diagnostics

#ifdef _DEBUG
void CDeQueueDraw::AssertValid() const
{
	CFormView::AssertValid();
}

void CDeQueueDraw::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDeQueueDraw message handlers

CDataStructVisualDoc* CDeQueueDraw::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS
		(CDataStructVisualDoc)));
	return (CDataStructVisualDoc*)m_pDocument;
}

void CDeQueueDraw::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_pDoc = GetDocument();
	m_hEventDeQueue=::CreateEvent(NULL,true,true,"DeQueue");
	m_Flag=0;
}

DWORD WINAPI CDeQueueDraw::DeQueueProc(LPVOID lpParameter)
{
	CDeQueueDraw *tPDeQueueDraw = (CDeQueueDraw*)lpParameter;
	CRect WinSize;
	CPoint CenterPoint;
	tPDeQueueDraw->GetClientRect(WinSize);
	CDC *tPDC=tPDeQueueDraw->GetDC();
	if(tPDeQueueDraw->m_Flag == -1) 
	{ 
		tPDeQueueDraw->DrawDeQueue(tPDC); 
	} 
	
	if(tPDeQueueDraw->m_Flag == 0)
	{
		tPDeQueueDraw->m_Flag = -1;
		tPDeQueueDraw->DrawDeQueue(tPDC);
	}	
	return 1;
}

void CDeQueueDraw::DrawDeQueue(CDC *pDC)
{
	m_pDoc->m_DeQueue.DrawDeQueue(pDC);
}

void CDeQueueDraw::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CDeQueueDraw *tPDeQueueDraw = this;
	m_hThreadDeQueue=CreateThread(
		NULL,
		0,
		DeQueueProc,
		(LPVOID)tPDeQueueDraw,0,NULL
		);
	CloseHandle(m_hThreadDeQueue);

	// Do not call CFormView::OnPaint() for painting messages
}

void CDeQueueDraw::EnDeQueue(CString vDeQueValue, bool vIsHead)
{
	CDataStructVisualDoc* pDoc = GetDocument();
	CPoint tCenterPoint;
	CRect tWinSize;
	this->GetClientRect(tWinSize);
	tCenterPoint.x=tWinSize.right;
	tCenterPoint.y=tWinSize.bottom; 
	pDoc->m_DeQueue.EnDeQueue(tCenterPoint,vDeQueValue,vIsHead);
	m_Flag= 0;
	this->Invalidate();
}

void CDeQueueDraw::DeDeQueue(bool vIsHead)
{
	
	CDataStructVisualDoc* pDoc = GetDocument();
	CPoint tCenterPoint;
	CRect tWinSize; 
	this->GetClientRect(tWinSize);
	tCenterPoint.x=tWinSize.right;
	tCenterPoint.y=tWinSize.bottom;
	pDoc->m_DeQueue.DeDeQueue(tCenterPoint,vIsHead);
	m_Flag = 0;
	this->Invalidate();
}