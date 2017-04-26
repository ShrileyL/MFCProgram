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
	ON_COMMAND(ID_SIN, OnSin)
	ON_COMMAND(ID_COS, OnCos)
	ON_COMMAND(ID_SINCOS, OnSincos)
	ON_COMMAND(ID_WIDTH1, OnWidth1)
	ON_COMMAND(ID_WIDTH2, OnWidth2)
	ON_COMMAND(ID_WIDTH3, OnWidth3)
	ON_COMMAND(ID_WIDTH4, OnWidth4)
	ON_UPDATE_COMMAND_UI(ID_WIDTH1, OnUpdateWidth1)
	ON_UPDATE_COMMAND_UI(ID_WIDTH2, OnUpdateWidth2)
	ON_UPDATE_COMMAND_UI(ID_WIDTH3, OnUpdateWidth3)
	ON_UPDATE_COMMAND_UI(ID_WIDTH4, OnUpdateWidth4)
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

	index = 0;//do nothing
//	index = 1;//calculate sin(x)
//	index = 2;//calculate cos(x)
//	index = 3;//calculate sin(x)cos(x)

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

	CRect rect;
	CFont fnBig;
	CFont* pOldFont;
	fnBig.CreatePointFont(int(HI*8.0),"Arial",pDC);
	pOldFont = pDC->SelectObject(&fnBig);

	FillRect0(pDC,color,(0,0),1600,1600);//画背景矩形
	GetClientRect(&rect);
	pDC->SetMapMode(MM_LOMETRIC);//设定映射模式
	pDC->SetViewportOrg(int(rect.right/10),int(rect.bottom/2));//设定坐标原点

	if (index==0)
	{
	}
	else
	{
		paint0(pDC);
	}
	pDC->SelectObject(pOldFont);
	fnBig.DeleteObject();
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

void CMyVC3View::Line0(CDC *pDC, double x1, double y1, double x2, double y2, int wid, COLORREF col)
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

void CMyVC3View::CoordinateSystem(CDC *pDC)
{
	int j,ds;
	double x1,y1,dsy;
	char buf[25];
	CString sc;
	pDC->SetBkColor(color);//设定文字背景色，与屏幕背景色同色
	ds = 0;
	x1 = 0;
	y1 = 0;
	wsprintf(buf,"%d",ds);
	pDC->TextOut(-40,-10,buf,strlen(buf));
	Line0(pDC,-10,0,75,0,4,RGB(0,0,0));//画横轴坐标线
	pDC->TextOut(int(HI*72.5),-40,"X(度)");//横坐标名

	for (j = 0;j<24;++j)//设定横坐标标尺
	{
		x1+=3;ds+=30;//设横坐标比例1:10
		Line0(pDC,x1,0,x1,0.5,1,RGB(0,0,0));//画刻度坐标线
		wsprintf(buf,"%d",ds);
		if (ds%90 ==0)//90度角的整数倍时
		{
			pDC->TextOut(int(HI*x1)-20,int(21.0*HI)+6,buf,strlen(buf));//标注刻度值
		}
		else
		{
			pDC->TextOut(int(HI*x1)-20,-10,buf,strlen(buf));//标注刻度值
		}
	}
	dsy = 0;
	Line0(pDC,0,-20,0,20,4,RGB(0,0,0));
	pDC->TextOut(-60,int(HI*24),"Y");
	for (j=0;j<5;++j)
	{
		y1+=4;dsy+=0.2;//纵坐标比例1:0.05
		Line0(pDC,0,y1,0.5,y1,1,RGB(0,0,0));//画纵坐标刻度线
		sc.Format("%3.1f",dsy);
		pDC->TextOut(-70,int(HI*y1)+20,sc,strlen(sc));//标注刻度值
	}
}

void CMyVC3View::paint0(CDC *pDC)
{
	int i;
	switch(index)
	{
	case 1:
		SIN0();
		break;
	case 2:
		COS0();
		break;
	case 3:
		SINCOS();
		break;
	}

	CoordinateSystem(pDC);

	for (i=0;i<721;++i)
	{
		if (i%90==0)
		{
			Line0(pDC,poix[i]/10,-1/0.05,poix[i]/10,1/0.05,1,RGB(0,0,0));
		}
		else
		{
		}
		Line0(pDC,poix[i]/10,poiy[i]/0.05,poix[i+1]/10,poiy[i+1]/0.05,width,RGB(255,0,0));
	}
}

void CMyVC3View::OnSin() 
{
	index = 1;
	InvalidateRect(NULL,FALSE);//调用CWnd成员函数，更新View
	
}

void CMyVC3View::OnCos() 
{
	index = 2;
	InvalidateRect(NULL,FALSE);
	
}

void CMyVC3View::OnSincos() 
{
	index = 3;
	InvalidateRect(NULL,FALSE);
	
}

void CMyVC3View::OnWidth1() 
{
	width = 2;
	InvalidateRect(NULL,FALSE);
	
}

void CMyVC3View::OnWidth2() 
{
	width = 4;
	InvalidateRect(NULL,FALSE);
	
}

void CMyVC3View::OnWidth3() 
{
	width = 7;
	InvalidateRect(NULL,FALSE);
	
}

void CMyVC3View::OnWidth4() 
{
	width = 10;
	InvalidateRect(NULL,FALSE);
	
}

void CMyVC3View::OnUpdateWidth1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck((width==2)? 1:0);//若width=2，菜单上有记号
	pCmdUI->Enable((index>0)?TRUE:FALSE);//菜单在选定了计算项目后才有效
}

void CMyVC3View::OnUpdateWidth2(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck((width==4)? 1:0);
	pCmdUI->Enable((index>0)?TRUE:FALSE);
}

void CMyVC3View::OnUpdateWidth3(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck((width==7)? 1:0);
	pCmdUI->Enable((index>0)?TRUE:FALSE);	
}

void CMyVC3View::OnUpdateWidth4(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck((width==10)? 1:0);
	pCmdUI->Enable((index>0)?TRUE:FALSE);	
}
