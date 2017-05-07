// LinkListCrl.cpp : implementation file
//

#include "stdafx.h"
#include "datastructvisual.h"
#include "LinkListCrl.h"

#include "LinkListDraw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinkListCrl

IMPLEMENT_DYNCREATE(CLinkListCrl, CFormView)

CLinkListCrl::CLinkListCrl()
	: CFormView(CLinkListCrl::IDD)
{
	//{{AFX_DATA_INIT(CLinkListCrl)
	m_LinkNodeValue = _T("");
	m_LinkNodePos = _T("");
	//}}AFX_DATA_INIT
}

CLinkListCrl::~CLinkListCrl()
{
}

void CLinkListCrl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinkListCrl)
	DDX_Text(pDX, IDC_EDIT_DATA, m_LinkNodeValue);
	DDX_Text(pDX, IDC_EDIT_LINKNODE_POS, m_LinkNodePos);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLinkListCrl, CFormView)
	//{{AFX_MSG_MAP(CLinkListCrl)
	ON_BN_CLICKED(IDC_BUTTON_ADDLISTNODE, OnButtonAddlistnode)
	ON_BN_CLICKED(IDC_BUTTON_INSERTLISTNODE, OnButtonInsertlistnode)
	ON_BN_CLICKED(IDC_BUTTON_DELETELISTNODE, OnButtonDeletelistnode)
	ON_BN_CLICKED(IDC_BUTTON_SEARCHLISTNODE, OnButtonSearchlistnode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinkListCrl diagnostics

#ifdef _DEBUG
void CLinkListCrl::AssertValid() const
{
	CFormView::AssertValid();
}

void CLinkListCrl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLinkListCrl message handlers

void CLinkListCrl::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	GetDlgItem(IDC_BUTTON_INSERTLISTNODE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_DELETELISTNODE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SEARCHLISTNODE)->EnableWindow(FALSE);
}

void CLinkListCrl::OnButtonAddlistnode() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_LinkNodeValue.IsEmpty()){
		::AfxMessageBox("请输入插入结点值.");
		return;
	}

	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CLinkListDraw*)(pWnd->GetPane(0, 0)))->AddTailLinkListNode(m_LinkNodeValue);

	GetDlgItem(IDC_BUTTON_INSERTLISTNODE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_DELETELISTNODE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEARCHLISTNODE)->EnableWindow(TRUE);
	
}

void CLinkListCrl::OnButtonInsertlistnode() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_LinkNodePos.IsEmpty()){
		::AfxMessageBox("请输入插入位置.");
		return;
	}
	if(m_LinkNodeValue.IsEmpty()){
		::AfxMessageBox("请输入插入结点值.");
		return;
	}
	int tLinkNodePos=atoi(m_LinkNodePos);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CLinkListDraw*)(pWnd->GetPane(0, 0)))->InsertLinkListNode(tLinkNodePos,m_LinkNodeValue);

}

void CLinkListCrl::OnButtonDeletelistnode() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_LinkNodePos.IsEmpty()){
		::AfxMessageBox("请输入删除位置.");
		return;
	}
	int tLinkNodePos=atoi(m_LinkNodePos);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CLinkListDraw*)(pWnd->GetPane(0, 0)))->DeleteLinkListNode(tLinkNodePos);
}

void CLinkListCrl::OnButtonSearchlistnode() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE); 
	if(m_LinkNodeValue.IsEmpty())
	{ 
		::AfxMessageBox("请输入查找数据.");
		return; 
	} 
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent(); 
	((CLinkListDraw*)(pWnd->GetPane(0, 0)))->SearchLinkListNode(m_LinkNodeValue);
	//GetDlgItem(IDC_NEXTBUTTON)-> EnableWindow(TRUE);
}
