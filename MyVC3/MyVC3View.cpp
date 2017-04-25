// MyVC3View.cpp : implementation of the CMyVC3View class
//

#include "stdafx.h"
#include "MyVC3.h"

#include "MyVC3Doc.h"
#include "MyVC3View.h"

#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyVC3View

IMPLEMENT_DYNCREATE(CMyVC3View, CView)

BEGIN_MESSAGE_MAP(CMyVC3View, CView)
	//{{AFX_MSG_MAP(CMyVC3View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyVC3View construction/destruction
const double PI= 3.14159;
COLORREF color;
double HI,poix[723],poiy[721];
int index;//program index
int width;//carve width

CMyVC3View::CMyVC3View()
{
	// TODO: add construction code here
	int i;
	for (i = 0; i<722;++i)
	{
		poix[i]=0;
		poiy[i] = 0;
	}
	color = RGB(220,220,220);
	HI = 38;
	index = 0;
	width = 4;
}

CMyVC3View::~CMyVC3View()
{
}

BOOL CMyVC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC3View drawing

void CMyVC3View::OnDraw(CDC* pDC)
{
	CMyVC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC3View printing

BOOL CMyVC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyVC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyVC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC3View diagnostics

#ifdef _DEBUG
void CMyVC3View::AssertValid() const
{
	CView::AssertValid();
}

void CMyVC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyVC3Doc* CMyVC3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyVC3Doc)));
	return (CMyVC3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyVC3View message handlers

void CMyVC3View::FillRect0(CDC *pDC, COLORREF col, CPoint point, int chd, int kd)
{
	CBrush newBrust(col);
	CBrush* pOldBrust;   
	pOldBrust = pDC->SelectObject(&newBrust); 

	
	pDC->FillRect(CRect(point.x,point.y,point.x+chd,point.y+kd),&newBrust);
	
	pDC->SelectObject(pOldBrust);//release newBrush, and recover to old Brush
newBrust.DeleteObject();//delete newBrust object
}

void CMyVC3View::Line0(CDC *pDC, int x1, int y1, int x2, int y2, int wid, COLORREF col)
{
	CPen siPen;
	CPen* pOldPen;
	siPen.CreatePen(PS_SOLID,wid,col);
	pOldPen = pDC->SelectObject(&siPen);
	
	pDC->MoveTo(int(HI*x1),int(HI*y1));
	pDC->LineTo(int(HI*x2),int(HI*y2));
	pDC->SelectObject(pOldPen);
	siPen.DeleteObject();
}

void CMyVC3View::SIN0()
{
	for (int i=0;i<722;++i)
	{
		poix[i] = i;//value of angle
		poiy[i] = sin(poix[i]*PI/180);//value of sin()
	}
}

void CMyVC3View::COS0()
{
	for (int i=0;i<722;++i)
	{
		poix[i] = i;//value of angle
		poiy[i] = cos(poix[i]*PI/180);//value of sin()
	}
}

void CMyVC3View::SINCOS()
{
	for (int i=0;i<722;++i)
	{
		poix[i] = i;//value of angle
		poiy[i] =sqrt(3.0)* sin(poix[i]*PI/180)*cos(poix[i]*PI/180);
	}
}
