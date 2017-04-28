// MyVC4View.cpp : implementation of the CMyVC4View class
//

#include "stdafx.h"
#include "MyVC4.h"

#include "MyVC4Doc.h"
#include "MyVC4View.h"

#include "Mouthdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyVC4View

IMPLEMENT_DYNCREATE(CMyVC4View, CView)

BEGIN_MESSAGE_MAP(CMyVC4View, CView)
	//{{AFX_MSG_MAP(CMyVC4View)
	ON_COMMAND(ID_MOUTH, OnMouth)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyVC4View construction/destruction

int MouthPos,REyePos,LEyePos,BrowPos,BrowWidth;

CMyVC4View::CMyVC4View()
{
	MouthPos = 0;
	REyePos = 0;
	LEyePos = 0;
	BrowPos = 0;
	BrowWidth = 3;

}

CMyVC4View::~CMyVC4View()
{
}

BOOL CMyVC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC4View drawing

void CMyVC4View::OnDraw(CDC* pDC)
{
	CMyVC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;
	int x0,y0;
	GetClientRect(&rect);
	x0 = rect.right/2.0;
	y0 = rect.bottom/2.0;
	MyFace(pDC,x0,y0);
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC4View printing

BOOL CMyVC4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyVC4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyVC4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC4View diagnostics

#ifdef _DEBUG
void CMyVC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMyVC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyVC4Doc* CMyVC4View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyVC4Doc)));
	return (CMyVC4Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyVC4View message handlers

void CMyVC4View::MyCircle(CDC *pDC, int x0, int y0, int r, int brush)
{
pDC->SelectStockObject(brush);
pDC->Ellipse(x0-r,y0-r,x0+r,y0+r);
}

void CMyVC4View::MyEllipse(CDC *pDC, int x0, int y0)
{
CBrush eiBrush;
CBrush* pOldBrush;
int x1,y1,x2,y2;
eiBrush.CreateSolidBrush(RGB(240,240,240));
pOldBrush = pDC->SelectObject(&eiBrush);
x1 = x0+55; y1 = y0-35;
x2 = x1-55;y2 = y0+35;
pDC->Ellipse(x1,y1,x2,y2);
pDC->SelectObject(pOldBrush);
eiBrush.DeleteObject();
}

void CMyVC4View::MyLine(CDC *pDC, int x, int y, int dx, int dy, int width, COLORREF col)
{
CPen pen(PS_SOLID,width,col);
CPen* pOldPen = pDC->SelectObject(&pen);
pDC->MoveTo(x-dx,y-dy);
pDC->LineTo(x+dx,y+dy);pDC->SelectObject(pOldPen);
}

void CMyVC4View::MyPolygon(CDC *pDC, int x0, int y0)
{
CPoint pt[3];
CBrush goBrush;
CBrush* pOldBrush;
CPen* pOldPen;
goBrush.CreateSolidBrush(RGB(140,140,140));
pOldBrush = pDC->SelectObject(&goBrush);
pOldPen =(CPen*) pDC->SelectStockObject(NULL_PEN);

pt[0].x = x0; pt[0].y = y0-40;
pt[1].x = x0+38; pt[1].y = y0+68;
pt[2].x = x0-38; pt[2].y = y0+68;

pDC->Polygon(pt,3);

pDC->SelectObject(pOldBrush);
goBrush.DeleteObject();
pDC->SelectObject(pOldPen); 
}

void CMyVC4View::MyFace(CDC *pDC, int x, int y)
{
MyCircle(pDC,x,y,180,LTGRAY_BRUSH);

MyEllipse(pDC,x-70,y-35);
MyEllipse(pDC,x+70,y-35);

MyCircle(pDC,x-70+REyePos,y-35,25,DKGRAY_BRUSH);
MyCircle(pDC,x+70+LEyePos,y-35,25,DKGRAY_BRUSH);

MyLine(pDC,x-70,y-95,40,BrowPos,BrowWidth,RGB(70,70,70));
MyLine(pDC,x+70,y-95,-40,BrowPos,BrowWidth,RGB(70,70,70));

MyPolygon(pDC,x,y);

MyLine(pDC,x,y+20,0,42,2,RGB(120,120,120));
MyLine(pDC,x-40,y+95,40,MouthPos,8,RGB(110,110,110));
MyLine(pDC,x+40,y+95,-40,MouthPos,8,RGB(110,110,110));
}

void CMyVC4View::OnMouth() 
{
	// TODO: Add your command handler code here
	CMouthdlg dlg;
	switch(dlg.DoModal()){
	case IDC_MOUTH_U:
		MouthPos = 12;
		InvalidateRect(NULL,FALSE);
		break;
	case IDC_MOUTH_D:
		MouthPos = -12;
		InvalidateRect(NULL,FALSE);
		break;
	case IDC_MOUTH_N:
		MouthPos = 0;
		InvalidateRect(NULL,FALSE);
		break;
	default:
		break;
	}
}
