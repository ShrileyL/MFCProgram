// MyVC5View.cpp : implementation of the CMyVC5View class
//

#include "stdafx.h"
#include "MyVC5.h"

#include "MyVC5Doc.h"
#include "MyVC5View.h"

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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
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
	// TODO: add construction code here

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
	Bit1(pDC);
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
}

/////////////////////////////////////////////////////////////////////////////
// CMyVC5View printing

BOOL CMyVC5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyVC5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyVC5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
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
	CDC MemDC;//定义一个内存设备环境
	bitmap.LoadBitmap(IDB_BITMAP1);
	MemDC.CreateCompatibleDC(pDC);
	pOldBitmap = MemDC.SelectObject(&bitmap);
	pDC->BitBlt(200,150,326,103,&MemDC,0,0,SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
}

void CMyVC5View::Bit2(CDC *pDC)
{
	CBitmap bitmap,*pOldBitmap;
	CDC MemDC;//定义一个内存设备环境
	bitmap.LoadBitmap(IDB_BITMAP2);
	MemDC.CreateCompatibleDC(pDC);
	pOldBitmap = MemDC.SelectObject(&bitmap);
	pDC->BitBlt(530,90,170,232,&MemDC,0,0,SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
}

void CMyVC5View::Bit3(CDC *pDC, int dx)
{
	CBitmap bitmap,*pOldBitmap;
	CDC MemDC;//定义一个内存设备环境
	bitmap.LoadBitmap(IDB_BITMAP3);
	MemDC.CreateCompatibleDC(pDC);
	pOldBitmap = MemDC.SelectObject(&bitmap);
	pDC->BitBlt(15,800-dx,733,273,&MemDC,0,0,SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
}
