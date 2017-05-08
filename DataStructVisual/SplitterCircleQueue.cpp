// SplitterCircleQueue.cpp : implementation file
//

#include "stdafx.h"
#include "datastructvisual.h"
#include "SplitterCircleQueue.h"

#include "CircleQueueDraw.h"
#include "CircleQueueCrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitterCircleQueue

IMPLEMENT_DYNCREATE(CSplitterCircleQueue, CView)

CSplitterCircleQueue::CSplitterCircleQueue()
{
}

CSplitterCircleQueue::~CSplitterCircleQueue()
{
}


BEGIN_MESSAGE_MAP(CSplitterCircleQueue, CView)
	//{{AFX_MSG_MAP(CSplitterCircleQueue)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitterCircleQueue drawing

void CSplitterCircleQueue::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterCircleQueue diagnostics

#ifdef _DEBUG
void CSplitterCircleQueue::AssertValid() const
{
	CView::AssertValid();
}

void CSplitterCircleQueue::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSplitterCircleQueue message handlers

int CSplitterCircleQueue::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CRect rect;
	GetClientRect(&rect);
	m_WndCircleQueueSplitter.CreateStatic(this, 2, 1);
	CCreateContext *pContext = (CCreateContext*) lpCreateStruct->lpCreateParams;
	m_WndCircleQueueSplitter.CreateView(0,0,RUNTIME_CLASS(CCircleQueueDraw), CSize(rect.Width(),rect.Height()/2), pContext);
	m_WndCircleQueueSplitter.CreateView(1,0,RUNTIME_CLASS(CCircleQueueCrl), CSize(rect.Width(),rect.Height()/2), pContext);
	return 0;
}

void CSplitterCircleQueue::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	m_WndCircleQueueSplitter.MoveWindow(0,0,cx,cy);
	m_WndCircleQueueSplitter.SetRowInfo(0, cy-(cy/9), 0);
	m_WndCircleQueueSplitter.SetRowInfo(1, cy/9, 20);
	m_WndCircleQueueSplitter.RecalcLayout();
}
