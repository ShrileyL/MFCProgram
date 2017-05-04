// drawview.cpp : implementation of the CDrawView class
//

#include "stdafx.h"
#include "MultDoc.h"

#include "drawdoc.h"
#include "drawview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	//{{AFX_MSG_MAP(CDrawView)
	ON_COMMAND(ID_ELLIP, OnEllip)
	ON_COMMAND(ID_LINE, OnLine)
	ON_COMMAND(ID_RECT, OnRect)
	ON_UPDATE_COMMAND_UI(ID_ELLIP, OnUpdateEllip)
	ON_UPDATE_COMMAND_UI(ID_LINE, OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_RECT, OnUpdateRect)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawView construction/destruction

CDrawView::CDrawView()
{
	// TODO: add construction code here

}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView drawing

void CDrawView::OnDraw(CDC* pDC)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView printing

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView diagnostics

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawView message handlers

void CDrawView::OnEllip() 
{
	GetDocument()->SetStyle(Elli);
	
}

void CDrawView::OnLine() 
{
	GetDocument()->SetStyle(Line);
	
}

void CDrawView::OnRect() 
{
	GetDocument()->SetStyle(Rect);
	
}

void CDrawView::OnUpdateEllip(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(GetDocument()->GetStyle()==Elli);//菜单中标记记号
	
}

void CDrawView::OnUpdateLine(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(GetDocument()->GetStyle()==Line);
	
}

void CDrawView::OnUpdateRect(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(GetDocument()->GetStyle()==Rect);
	
}

void CDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CDrawDoc* pDoc = GetDocument();

	pDoc->SetCPoint1(point);//获取画图起点
	pDoc->SetCPoint2(point);//取得鼠标当前光点
	SetCapture();//锁定鼠标按钮
	
	
}

void CDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CDrawDoc* pDoc = GetDocument();

	CDC* pDC;
	CPen dashPen(PS_DASH,1,RGB(255,255,255));//虚线笔
	CPen drawPen(PS_INSIDEFRAME,pDoc->GetPenWidth(),pDoc->GetPenColor());//实线笔

	CPen* pOldPen;
	CBrush Brush(pDoc->GetBrushColor());
	CPoint pt1 = pDoc->GetCPoint1();
	CPoint pt2 = pDoc->GetCPoint2();

	pDC = GetDC();
	pDC->SetROP2(R2_XORPEN);//当前绘制模式：像素是画笔颜色和屏幕颜色的组合

	pDC->SelectStockObject(NULL_BRUSH);
	pOldPen= pDC->SelectObject(&dashPen);

	switch (pDoc->GetStyle())
	{
	case Line:
		pDC->MoveTo(pt1);
		pDC->LineTo(pt2);

		pDC->SelectObject(&drawPen);
		pDC->SetROP2(R2_COPYPEN);//当前绘制模式：像素是画笔的颜色

		pDC->MoveTo(pt1);
		pDC->LineTo(point);
		break;
	case Rect:
		pDC->Rectangle(pt1.x,pt1.y,pt2.x,pt2.y);

		pDC->SelectObject(&Brush);//把刷子调换为新的刷子
		pDC->SelectObject(&drawPen);//笔调换为实线笔
		pDC->SetROP2(R2_COPYPEN);//

		pDC->Rectangle(pt1.x,pt1.y,point.x,point.y);
		break;
	case Elli:
		pDC->Ellipse(pt1.x,pt1.y,pt2.x,pt2.y);

		pDC->SelectObject(&Brush);//
		pDC->SelectObject(&drawPen);//
		pDC->SetROP2(R2_COPYPEN);//

		pDC->Ellipse(pt1.x,pt1.y,point.x,point.y);
		break;
	}
	pDoc->SetCPoint2(point);//文档类管理函数取得鼠标当前光点
	
	pDC->SelectObject(pOldPen);
	ReleaseDC(pDC);
	ReleaseCapture();//取消鼠标锁定
}

void CDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CDrawDoc* pDoc = GetDocument();//获得文档类对象指针

	CDC* pDC;
	CPen dashPen(PS_DASH,1,RGB(255,255,255));
	CPen* pOldPen;
	CPoint pt1 = pDoc->GetCPoint1();
	CPoint pt2 = pDoc->GetCPoint2();

	if(!GetCapture())//如果没有按下鼠标
		return;//什么都不做，返回
	//否则

	pDC = GetDC();
	pDC->SetROP2(R2_XORPEN);//设置当前绘制模式
	pDC->SelectStockObject(NULL_BRUSH);//透明刷
	pOldPen=pDC->SelectObject(&dashPen);
	
	switch (pDoc->GetStyle())
	{
	case Line:
		pDC->MoveTo(pt1);
		pDC->LineTo(pt2);
		pDC->MoveTo(pt1);
		pDC->LineTo(point);
		break;
	case Rect:
		pDC->Rectangle(pt1.x,pt1.y,pt2.x,pt2.y);
		pDC->Rectangle(pt1.x,pt1.y,point.x,point.y);
		break;
	case Elli:
		pDC->Ellipse(pt1.x,pt1.y,pt2.x,pt2.y);
		pDC->Ellipse(pt1.x,pt1.y,point.x,point.y);
		break;
	}
	pDoc->SetCPoint2(point);//文档类管理函数取得鼠标当前光点

	pDC->SelectObject(pOldPen);
	ReleaseDC(pDC);
}
