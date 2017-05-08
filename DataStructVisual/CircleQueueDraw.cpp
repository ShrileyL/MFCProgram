// CircleQueueDraw.cpp : implementation file
//

#include "stdafx.h"
#include "datastructvisual.h"
#include "CircleQueueDraw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCircleQueueDraw

IMPLEMENT_DYNCREATE(CCircleQueueDraw, CFormView)

CCircleQueueDraw::CCircleQueueDraw()
	: CFormView(CCircleQueueDraw::IDD)
{
	//{{AFX_DATA_INIT(CCircleQueueDraw)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CCircleQueueDraw::~CCircleQueueDraw()
{
}

void CCircleQueueDraw::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCircleQueueDraw)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCircleQueueDraw, CFormView)
	//{{AFX_MSG_MAP(CCircleQueueDraw)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCircleQueueDraw diagnostics

#ifdef _DEBUG
void CCircleQueueDraw::AssertValid() const
{
	CFormView::AssertValid();
}

void CCircleQueueDraw::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCircleQueueDraw message handlers

CDataStructVisualDoc* CCircleQueueDraw::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDataStructVisualDoc)));
	return (CDataStructVisualDoc*)m_pDocument;
}


void CCircleQueueDraw::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_pDoc = GetDocument();
	m_hEventCircleQueue=::CreateEvent(NULL,true,true,"CircleQueue");
	m_Flag=0;
}

DWORD WINAPI CCircleQueueDraw::CircleQueueProc(LPVOID lpParameter)
{
	CCircleQueueDraw *tPCircleQueueDraw = (CCircleQueueDraw*)lpParameter;
	CRect WinSize;
	CPoint CenterPoint;
	tPCircleQueueDraw->GetClientRect(WinSize);
	CDC *tPDC=tPCircleQueueDraw->GetDC();
	if(tPCircleQueueDraw->m_Flag == -1) 
	{ 
		tPCircleQueueDraw->DrawCircleQueue(tPDC); 
	} 
	
	if(tPCircleQueueDraw->m_Flag == 0)
	{
		tPCircleQueueDraw->m_Flag = -1;
		tPCircleQueueDraw->InitCircleQueue(WinSize);
		tPCircleQueueDraw->DrawCircleQueue(tPDC);
	}	
	if(tPCircleQueueDraw->m_Flag == 1)
	{
		tPCircleQueueDraw->m_Flag = -1;
		tPCircleQueueDraw->DrawCircleQueue(tPDC);
	}
	return 1;
}

void CCircleQueueDraw::InitCircleQueue(CRect vRect)
{
	
	m_pDoc->m_CircleQueue.InitCircleQueue();
}
void CCircleQueueDraw::DrawCircleQueue(CDC* pDC)
{
	m_pDoc->m_CircleQueue.DrawCircleQueue(pDC);
}


void CCircleQueueDraw::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CCircleQueueDraw *tPCircleQueueDraw = this;
	m_hThreadCircleQueue=CreateThread(
		NULL,
		0,
		CircleQueueProc,
		(LPVOID)tPCircleQueueDraw,0,NULL
		);
	CloseHandle(m_hThreadCircleQueue);

	// Do not call CFormView::OnPaint() for painting messages
}

void CCircleQueueDraw::EnCircleQueue(CString vCQValue)
{
	CDataStructVisualDoc* pDoc = GetDocument();
	CPoint tCenterPoint;
	CRect tWinSize;
	this->GetClientRect(tWinSize);
	tCenterPoint.x=tWinSize.right;
	tCenterPoint.y=tWinSize.bottom; 
	pDoc->m_CircleQueue.EnQueue(tCenterPoint,vCQValue);
	m_Flag = 1;
	this->Invalidate();
}

void CCircleQueueDraw::DeCircleQueue()
{
	CDataStructVisualDoc* pDoc = GetDocument();
	pDoc->m_CircleQueue.DeQueue();
	m_Flag = 1;
	this->Invalidate();
}