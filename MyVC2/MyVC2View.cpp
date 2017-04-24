// MyVC2View.cpp : implementation of the CMyVC2View class
//

#include "stdafx.h"
#include "MyVC2.h"

#include "MyVC2Doc.h"
#include "MyVC2View.h"

#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyVC2View

IMPLEMENT_DYNCREATE(CMyVC2View, CView)

BEGIN_MESSAGE_MAP(CMyVC2View, CView)
	//{{AFX_MSG_MAP(CMyVC2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyVC2View construction/destruction

CMyVC2View::CMyVC2View()
{
	// TODO: add construction code here

}

CMyVC2View::~CMyVC2View()
{
}

BOOL CMyVC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC2View drawing

void CMyVC2View::OnDraw(CDC* pDC)
{
	CMyVC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC2View printing

BOOL CMyVC2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyVC2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyVC2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC2View diagnostics

#ifdef _DEBUG
void CMyVC2View::AssertValid() const
{
	CView::AssertValid();
}

void CMyVC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyVC2Doc* CMyVC2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyVC2Doc)));
	return (CMyVC2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyVC2View message handlers

void CMyVC2View::FillRect0(CDC *pDC, COLORREF col, CPoint point, int chd, int kd)
//meaning: 颜色 col,左上点 Point，矩形长度 chd,宽度 kd
{
CBrush newBrust(col);
CBrush* pOldBrust;
pOldBrust = pDC->SelectObject(&newBrust);

pDC->FillRect(CRect(point.x,point.y,point.x+chd,point.y+kd),&newBrust);

pDC->SelectObject(pOldBrust);
newBrust.DeleteObject();//delete newBrust object
}
