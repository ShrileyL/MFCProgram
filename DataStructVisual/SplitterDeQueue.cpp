// SplitterDeQueue.cpp : implementation file
//

#include "stdafx.h"
#include "datastructvisual.h"
#include "SplitterDeQueue.h"

#include "DeQueueDraw.h"
#include "DeQueueCrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitterDeQueue

IMPLEMENT_DYNCREATE(CSplitterDeQueue, CView)

CSplitterDeQueue::CSplitterDeQueue()
{
}

CSplitterDeQueue::~CSplitterDeQueue()
{
}


BEGIN_MESSAGE_MAP(CSplitterDeQueue, CView)
	//{{AFX_MSG_MAP(CSplitterDeQueue)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitterDeQueue drawing

void CSplitterDeQueue::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterDeQueue diagnostics

#ifdef _DEBUG
void CSplitterDeQueue::AssertValid() const
{
	CView::AssertValid();
}

void CSplitterDeQueue::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSplitterDeQueue message handlers

int CSplitterDeQueue::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CRect rect;
	GetClientRect(&rect);
	m_WndDeQueueSplitter.CreateStatic(this, 2, 1);
	CCreateContext *pContext = (CCreateContext*) 
		lpCreateStruct->lpCreateParams;
	m_WndDeQueueSplitter.CreateView(
		0,
		0,
		RUNTIME_CLASS(CDeQueueDraw),
		CSize(rect.Width(),rect.Height()/2), 
		pContext);
	m_WndDeQueueSplitter.CreateView(
		1,
		0,
		RUNTIME_CLASS(CDeQueueCrl),
		CSize(rect.Width(),rect.Height()/2), 
		pContext);
	return 0;
}

void CSplitterDeQueue::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	m_WndDeQueueSplitter.MoveWindow(0,0,cx,cy);
	m_WndDeQueueSplitter.SetRowInfo(0, cy-(cy/9), 0);
	m_WndDeQueueSplitter.SetRowInfo(1, cy/9, 20);
	m_WndDeQueueSplitter.RecalcLayout();
}
