#if !defined(AFX_LINKLISTDRAW_H__397F7CD4_C2A7_43F7_9C0A_34CE0458AB87__INCLUDED_)
#define AFX_LINKLISTDRAW_H__397F7CD4_C2A7_43F7_9C0A_34CE0458AB87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LinkListDraw.h : header file
//

#include "LinkList.h"
#include "DataStructVisualDoc.h"
/////////////////////////////////////////////////////////////////////////////
// CLinkListDraw form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CLinkListDraw : public CFormView
{
protected:
	CLinkListDraw();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLinkListDraw)

// Form Data
public:
	//{{AFX_DATA(CLinkListDraw)
	enum { IDD = IDD_LINKLISTDRAW_FORMVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	void DrawSearchLinkListFlag(CDC *pDC);
	void AddTailLinkListNode(CString vLNValue);
	void DeleteLinkListNode(int vPos);
	void InsertLinkListNode(int vPos,CString vLNValue);
	void DrawLinkList(CDC* pDC);
	void AddHeadToList(CRect vRect);
	void SearchLinkListNode(CString vString);

	CDataStructVisualDoc* GetDocument();
	CDataStructVisualDoc* m_pDoc;
	HANDLE m_hEventLinkList;
	HANDLE m_hThreadLinkList;
	int m_Flag;
	CLinkList* m_pLinkList;
	static DWORD WINAPI LinkListproc(LPVOID lpParameter);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkListDraw)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLinkListDraw();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CLinkListDraw)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKLISTDRAW_H__397F7CD4_C2A7_43F7_9C0A_34CE0458AB87__INCLUDED_)
