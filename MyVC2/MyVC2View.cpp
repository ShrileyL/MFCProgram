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

	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_LOMETRIC);
	pDC->SetViewportOrg(int(rect.right/2),int(rect.bottom/2));
	FillRect0(pDC,RGB(192,192,192),(0,0),700,500);
	Rectangle0(pDC,-700,0,0,-500,RGB(128,128,128));
	Ellipses(pDC,-300,500,0,0,1,RGB(192,192,192),LTGRAY_BRUSH);
	Ellipsem(pDC,-500,250,200,RGB(192,192,192));
	Polygon1(pDC,350,-300,RGB(255,0,0));
	Polygon0(pDC,350,-300,RGB(0,0,0));
	Line0(pDC,-700,500,700,-500,4,RGB(255,0,0));
	Line0(pDC,-700,-500,700,500,4,RGB(0,255,0));
	Ellipses(pDC,-500,350,500,-350,4,RGB(0,0,0),NULL_BRUSH);
	Arc0(pDC,0,0,350,4,RGB(0,0,255));
	Arc1(pDC,100,0,950,140,220,4,RGB(0,0,0));
	Arc1(pDC,-100,0,950,-40,40,4,RGB(0,0,0));
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


// Draw rectangle without borders
void CMyVC2View::FillRect0(CDC *pDC, COLORREF col, CPoint point, int chd, int kd)
//meaning: 颜色 col,左上点 Point，矩形长度 chd,宽度 kd
{
CBrush newBrust(col);//define and initial a CBrush Object
CBrush* pOldBrust;   //define the pointer to CBrush Object
pOldBrust = pDC->SelectObject(&newBrust); //set DC's Brush to new one
											//at the same time,assign the old one's address to pOldBrust

pDC->FillRect(CRect(point.x,point.y,point.x+chd,point.y+kd),&newBrust);//draw Rect using present DC enviroment

pDC->SelectObject(pOldBrust);//release newBrush, and recover to old Brush
newBrust.DeleteObject();//delete newBrust object
}

// Draw rectangle including borders
void CMyVC2View::Rectangle0(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF col)
{
	CBrush eiBrush;
	CBrush* pOldBrush;
	CPen* pOldPen;
	pOldPen =(CPen*) pDC->SelectStockObject(NULL_PEN);
	// set a 透明笔
	//用透明笔画矩形边界，不显示边界
	eiBrush.CreateSolidBrush(col);
	pOldBrush = pDC->SelectObject(&eiBrush);
	pDC->Rectangle(x1,y1,x2,y2);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	eiBrush.DeleteObject();// delete the free Brush object
}

//Draw Line
void CMyVC2View::Line0(CDC *pDC, int x1, int y1, int x2, int y2, int width, COLORREF col)
{
	CPen siPen;
	CPen* pOldPen;
	siPen.CreatePen(PS_SOLID,width,col);
	pOldPen = pDC->SelectObject(&siPen);

	pDC->MoveTo(x1,y1);
	pDC->LineTo(x2,y2);
	pDC->SelectObject(pOldPen);
	siPen.DeleteObject();
}

//Draw ellipse
void CMyVC2View::Ellipses(CDC *pDC, int x1, int y1, int x2, int y2, int width, COLORREF col, BOOL mb)
{
	CPen eiPen;
	CPen* pOldPen;
	CBrush* pOldBrush;
	pOldBrush =(CBrush*) pDC->SelectStockObject(mb);
	eiPen.CreatePen(PS_SOLID,width,col);
	pOldPen = pDC->SelectObject(&eiPen);

	pDC->Ellipse(x1,y1,x2,y2);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	eiPen.DeleteObject();

}

void CMyVC2View::Arc0(CDC *pDC, int x0, int y0, int r, int width, COLORREF col)
{
	CPen eiPen;
	CPen* pOldPen;

	eiPen.CreatePen(PS_SOLID,width,col);
	pOldPen = pDC->SelectObject(&eiPen);
	
	pDC->Arc(x0-r,y0+r,x0+r,y0-r,0,0,0,0);
	pDC->SelectObject(pOldPen);
	eiPen.DeleteObject();
}

void CMyVC2View::Ellipsem(CDC *pDC, int x0, int y0, int r, COLORREF col)
{
	CBrush eiBrush;
	CPen* pOldPen;
	CBrush* pOldBrush;
	pOldPen =(CPen*) pDC->SelectStockObject(NULL_PEN);
	eiBrush.CreateSolidBrush(col);
	pOldBrush = pDC->SelectObject(&eiBrush);
	
	pDC->Ellipse(x0-r,y0+r,x0+r,y0-r);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	eiBrush.DeleteObject();
}

void CMyVC2View::Arc1(CDC *pDC, int x0, int y0, int r, double Ro, double Rd, int width, COLORREF col)
{
	CPen eiPen;
	CPen* pOldPen;

	double pxo,pyo,pxd,pyd,PI;
	PI = 3.1415;
	pxo = r*cos(Ro*PI/180.0) + x0;
	pyo = r*cos(Ro*PI/180.0) + y0;
	pxd = r*cos(Rd*PI/180.0) + x0;
	pyd = r*cos(Rd*PI/180.0) + y0;
	
	eiPen.CreatePen(PS_SOLID,width,col);
	pOldPen = pDC->SelectObject(&eiPen);
	
	pDC->Arc((x0-r),(y0+r),(x0+r),(y0-r),int(pxo),int(pyo),int(pxd),int(pyd));
	pDC->SelectObject(pOldPen);
	eiPen.DeleteObject();
}

void CMyVC2View::Polygon0(CDC *pDC, int x0, int y0, COLORREF col)
{
	CPoint pt[6];
	double Angle,PI;
	CBrush goBrust;
	CBrush* pOldBrush;
	CPen* pOldPen;
	goBrust.CreateHatchBrush(HS_CROSS,col);
	pOldBrush = pDC->SelectObject(&goBrust);
	pOldPen = (CPen*)pDC->SelectStockObject(BLACK_PEN);
	pDC->SetBkMode(TRANSPARENT);

	PI = 3.1415;
	Angle = 2.0*PI/5;
	for (int i = 0; i<5; ++i)
		{
			pt[i].x = x0 + int(sin(double(i)*Angle)*300);
			pt[i].y = x0 + int(cos(double(i)*Angle)*300);
		}
	pDC->Polygon(pt,5);
	pDC->SelectObject(pOldBrush);
	goBrust.DeleteObject();
	pDC->SelectObject(pOldPen);
}

void CMyVC2View::Polygon1(CDC *pDC, int x0, int y0, COLORREF col)
{	
	CPoint pt[6];
	CBrush goBrust;
	CBrush* pOldBrush;
	CPen* pOldPen;
	goBrust.CreateHatchBrush(HS_CROSS,col);
	pOldBrush = pDC->SelectObject(&goBrust);
	pOldPen = (CPen*)pDC->SelectStockObject(NULL_PEN);
	//pDC->SetBkMode(TRANSPARENT);
	
	double Angle = (720.0/57.295)/5;
	for (int i = 0; i<5; ++i)
	{
		pt[i].x = x0 + int(sin(double(i)*Angle)*300.0);
		pt[i].y = x0 + int(cos(double(i)*Angle)*300.0);
	}
	pDC->SetPolyFillMode(WINDING);
	pDC->Polygon(pt,5);
	pDC->SelectObject(pOldBrush);
	goBrust.DeleteObject();
	pDC->SelectObject(pOldPen);
}
