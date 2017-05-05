// LeftPane.cpp : implementation file
//

#include "stdafx.h"
#include "DataStructVisual.h"
#include "LeftPane.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftPane

IMPLEMENT_DYNCREATE(CLeftPane, CFormView)

CLeftPane::CLeftPane()
	: CFormView(CLeftPane::IDD)
{
	//{{AFX_DATA_INIT(CLeftPane)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CLeftPane::~CLeftPane()
{
}

void CLeftPane::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeftPane)
	DDX_Control(pDX, IDC_LEFTPANE_TREE, m_LeftTree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeftPane, CFormView)
	//{{AFX_MSG_MAP(CLeftPane)
	ON_NOTIFY(TVN_SELCHANGED, IDC_LEFTPANE_TREE, OnSelchangedLeftpaneTree)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftPane diagnostics

#ifdef _DEBUG
void CLeftPane::AssertValid() const
{
	CFormView::AssertValid();
}

void CLeftPane::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftPane message handlers

void CLeftPane::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CRect rect;	
	GetClientRect(&rect);
	if (rect.right - rect.left > 0)
	{
		m_sRect.left	= rect.left + 10;
		m_sRect.right	= rect.right - 10;
	}
	else
	{
		m_sRect.left	= rect.left;
		m_sRect.right	= rect.right;
	}
	m_sRect.top=rect.top+10;
	m_sRect.bottom=rect.bottom-10;
	
	m_LeftTree.MoveWindow(m_sRect);
	InitTree();
}

void CLeftPane::InitTree()
{
	LPSTR pszText;
	m_TreeImageList.Create(16, 16, TRUE, 6, 1);
	HICON hIcon;
	hIcon=::LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON1));
	m_TreeImageList.Add(hIcon);
    hIcon=::LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON1));
	m_TreeImageList.Add(hIcon);
	hIcon=::LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON1));
	m_TreeImageList.Add(hIcon);
    hIcon=::LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON1));
	m_TreeImageList.Add(hIcon);
	hIcon=::LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON1));
	m_TreeImageList.Add(hIcon);
	hIcon=::LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON1));
	m_TreeImageList.Add(hIcon);
	hIcon=::LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDI_ICON1));
	m_TreeImageList.Add(hIcon);
	m_LeftTree.SetImageList(&m_TreeImageList,TVSIL_NORMAL);

	//////////////////////在树控件添加信息/////////////////////////////////////
	
	m_LeftTree.DeleteAllItems();//清空当前书控件所有节点
	m_Root = m_LeftTree.InsertItem("动态切换视图");//插入根节点
	TV_INSERTSTRUCT TCItem;
	TCItem.item.mask=TVIF_TEXT|TVIF_PARAM|TVIF_IMAGE|TVIF_SELECTEDIMAGE;//设屏蔽
	TCItem.hInsertAfter=TVI_LAST;//在最后项之后

	CString strTreeNodeName="测试一";
	pszText=strTreeNodeName.LockBuffer();
	TCItem.hParent=m_Root;
	TCItem.item.pszText=pszText;	
	TCItem.item.iImage=1;
	TCItem.item.iSelectedImage=2;
	HTREEITEM hCurrent=m_LeftTree.InsertItem(&TCItem);
	m_LeftTree.SetItemData(hCurrent,1);

	strTreeNodeName="测试二";
	pszText=strTreeNodeName.LockBuffer();
	TCItem.hParent=m_Root;
	TCItem.item.pszText=pszText;	
	TCItem.item.iImage=1;
	TCItem.item.iSelectedImage=2;
	hCurrent=m_LeftTree.InsertItem(&TCItem);
	m_LeftTree.SetItemData(hCurrent,2);


	m_LeftTree.Expand(m_Root, TVE_EXPAND); //展开根节点
}

void CLeftPane::OnSelchangedLeftpaneTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	int nIndex= -1;
	UINT nView;
	m_pMainFrame = (CMainFrame*)GetParentFrame();//获得主框架指针

	nIndex=m_LeftTree.GetItemData(m_LeftTree.GetSelectedItem());

	switch(nIndex)
	{		
	case 1:	
		nView = VIEW_SPLITTER1;
		break;	
	case 2:	
		nView = VIEW_SPLITTER2;
		break;

	default:
		break;
	}
	m_pRightSwitchFrame->SwitchToView(nView);
	*pResult = 1;
}
