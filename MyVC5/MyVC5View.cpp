// MyVC5View.cpp : implementation of the CMyVC5View class
//

#include "stdafx.h"
#include "MyVC5.h"

#include "MyVC5Doc.h"
#include "MyVC5View.h"

#include "Rectnum.h"//��ҳ��ӡ

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyVC5View

IMPLEMENT_DYNCREATE(CMyVC5View, CView)

BEGIN_MESSAGE_MAP(CMyVC5View, CView)
	//{{AFX_MSG_MAP(CMyVC5View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_NUMBER, OnNumber)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyVC5View construction/destruction

CMyVC5View::CMyVC5View()
{
	print = 0;//print=0��ʾ����Ļ��ʾ��print=1��ʾ��ӡ������ߴ�ӡԤ��
	number = 1;

}

CMyVC5View::~CMyVC5View()
{
}

BOOL CMyVC5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC5View drawing

void CMyVC5View::OnDraw(CDC* pDC)
{
	CMyVC5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
/*	Bit1(pDC);
	Bit2(pDC);
	int i,j;
	j =0;
	for (i=0;i<10800;++i)
	{
		if (i%15==0)
		{
			j+=1;
			Bit3(pDC,j);
		}
	}
	*/

	//��ӡһ������
	/*
	pDC->SetMapMode(MM_LOMETRIC);//��λ��0.1mm
	CRect rect;
	GetClientRect(&rect);
	if (print == 0)
	{
		pDC->SetViewportOrg(rect.right/2,rect.bottom/2);
	}
	else if (print==1)
	{
		pDC->SetViewportOrg(offsetx,offsety);
	}

	pDC->Rectangle(-250,200,250,-200);
	*/

	//��ҳ��ӡ
	pDC->SetMapMode(MM_LOMETRIC);
	CRect rect;
	char s[10];
	GetClientRect(&rect);
	if (print == 0)
	{
		pDC->SetViewportOrg(rect.right/2,rect.bottom/2);
	}
	else if (print==1)
	{
		pDC->SetViewportOrg(offsetx,offsety);
	}

	if (number ==1)
	{pDC->Rectangle-250,200,250,-200;	}

	if (number>1)
	{
		for (int x = 0;x<number;++x)
		{
			pDC->Rectangle(-100,-(x*200+70),100,-(x*200+200));
		}
	}

	wsprintf(s,"%d",number);
	pDC->TextOut(0,0,s);//������ԭ��������θ���
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC5View printing

BOOL CMyVC5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���ô�ӡҳ����Χ
	pInfo->SetMinPage(1);
	pInfo->SetMaxPage(numpages);

	return DoPreparePrinting(pInfo);
}

void CMyVC5View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	/*
	int pageheight = pDC->GetDeviceCaps(VERTSIZE);//�õ���ӡֽ�߶ȣ�mm)
	int pagewidth = pDC->GetDeviceCaps(HORZSIZE);//��ӡֽ���
	int logpixelx = pDC->GetDeviceCaps(LOGPIXELSX);//ʵ���豸Y����ÿ�߼�Ӣ�����������
	int logpixely = pDC->GetDeviceCaps(LOGPIXELSY);//ʵ���豸X����ÿ�߼�Ӣ�����������

	offsetx = int(pagewidth*logpixelx/(50.8));//ȷ������ԭ��X�����ƫ����
	offsety = int(pageheight*logpixely/(50.8));//
	print = 1;//��ӡ״̬
	*/

	int pageheight = pDC->GetDeviceCaps(VERTSIZE);
	double rectheight = 20;//���θ߶�+���=20mm
	int pnum  = int(0.5*pageheight/rectheight);//��һҳҳ��ʾ�ľ��θ���
	if (number<pnum)//��ҳ��ӡ
	{
		numpages = 1;
	} 
	else//��ҳ��ӡ
	{
		numpages = (int)((number-pnum)*rectheight/pageheight)+2;
	}

	print = 1;
	Invalidate();
}

void CMyVC5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	print = 0;
	Invalidate();
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC5View diagnostics

#ifdef _DEBUG
void CMyVC5View::AssertValid() const
{
	CView::AssertValid();
}

void CMyVC5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyVC5Doc* CMyVC5View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyVC5Doc)));
	return (CMyVC5Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyVC5View message handlers

void CMyVC5View::Bit1(CDC *pDC)
{
	CBitmap bitmap,*pOldBitmap;
	CDC MemDC;//����һ���ڴ��豸����
	bitmap.LoadBitmap(IDB_BITMAP1);
	MemDC.CreateCompatibleDC(pDC);
	pOldBitmap = MemDC.SelectObject(&bitmap);
	pDC->BitBlt(200,150,326,103,&MemDC,0,0,SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
}

void CMyVC5View::Bit2(CDC *pDC)
{
	CBitmap bitmap,*pOldBitmap;
	CDC MemDC;//����һ���ڴ��豸����
	bitmap.LoadBitmap(IDB_BITMAP2);
	MemDC.CreateCompatibleDC(pDC);
	pOldBitmap = MemDC.SelectObject(&bitmap);
	pDC->BitBlt(530,90,170,232,&MemDC,0,0,SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
}

void CMyVC5View::Bit3(CDC *pDC, int dx)
{
	CBitmap bitmap,*pOldBitmap;
	CDC MemDC;//����һ���ڴ��豸����
	bitmap.LoadBitmap(IDB_BITMAP3);
	MemDC.CreateCompatibleDC(pDC);
	pOldBitmap = MemDC.SelectObject(&bitmap);
	pDC->BitBlt(15,800-dx,733,273,&MemDC,0,0,SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
}

void CMyVC5View::Bit4(CDC *pDC, CPoint point)
{
	CBitmap bitmap,*pOldBitmap;
	CDC MemDC;//����һ���ڴ��豸����
	bitmap.LoadBitmap(IDB_BITMAP4);
	MemDC.CreateCompatibleDC(pDC);
	pOldBitmap = MemDC.SelectObject(&bitmap);
	pDC->BitBlt(point.x-11,point.y-11,22,22,&MemDC,0,0,SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
}

///////////////////////////////////////////////////////////////
BOOL ButtonDown = FALSE;

void CMyVC5View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CDC* pDC= GetDC();
	Bit4(pDC,point);
	ReleaseDC(pDC);
	ButtonDown = TRUE;
	
	//CView::OnLButtonDown(nFlags, point);
}

void CMyVC5View::OnLButtonUp(UINT nFlags, CPoint point) 
{

	ButtonDown = FALSE;
//	CView::OnLButtonUp(nFlags, point);
}

void CMyVC5View::OnMouseMove(UINT nFlags, CPoint point) 
{
	CDC* pDC= GetDC();
	if (ButtonDown==TRUE)
	{
		Bit4(pDC,point);
	}
	ReleaseDC(pDC);
	
	//CView::OnMouseMove(nFlags, point);
}

void CMyVC5View::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	CDC* pDC= GetDC();
	CRect rect;
	CBrush eraser(GetSysColor(COLOR_WINDOW));
	GetClientRect(&rect);
	pDC->FillRect(&rect,&eraser);
	ReleaseDC(pDC);
	
	//CView::OnRButtonDblClk(nFlags, point);
}

void CMyVC5View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CDC* pDC= GetDC();
	CPoint point;
	GetCursorPos(&point);
	switch (nChar)
	{
	case VK_LEFT:
		point.x -= 3;
		break;
	case VK_RIGHT:
		point.x += 3;
		break;
	case VK_UP:
		point.y -= 3;
		break;
	case VK_DOWN:
		point.y += 3;
		break;
	default:
		break;
	}
	
	SetCursorPos(point.x,point.y);
	if (GetKeyState(VK_SHIFT)<0)
	{
		ScreenToClient(&point);
		Bit4(pDC,point);
	}
	ReleaseDC(pDC);
	//CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMyVC5View::OnNumber() 
{
	CRectnum dlg;
	if (dlg.DoModal()==IDOK)
	{
		number = dlg.m_number;//���Ի���������ľ��θ���������View��number��
		Invalidate();
	}
	
}

void CMyVC5View::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	if (pDC->IsPrinting())
	{
		int pageheight = pDC->GetDeviceCaps(VERTSIZE);
		int pagewidth = pDC->GetDeviceCaps(HORZSIZE);
		int logpixelsx = pDC->GetDeviceCaps(LOGPIXELSX);//�õ���ӡ��ˮƽ�ֱ���
		int logpixelsy = pDC->GetDeviceCaps(LOGPIXELSY);//�õ���ӡ����ֱ�ֱ���
		double rectheight = 20;//���θ߶�+���
		int pnum = int(0.5*pageheight/rectheight);
		offsetx = int(pagewidth*logpixelsx/(2*25.4));
		offsety = int((0.5*pageheight-pageheight*(pInfo->m_nCurPage-1))*logpixelsy/25.4);
	}
	
	CView::OnPrepareDC(pDC, pInfo);
}
