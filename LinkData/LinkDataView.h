// LinkDataView.h : interface of the CLinkDataView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKDATAVIEW_H__C773CE64_0AE4_4040_90EA_4CD7FE74DF24__INCLUDED_)
#define AFX_LINKDATAVIEW_H__C773CE64_0AE4_4040_90EA_4CD7FE74DF24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLinkDataSet;

class CLinkDataView : public CRecordView
{
protected: // create from serialization only
	CLinkDataView();
	DECLARE_DYNCREATE(CLinkDataView)

public:
	//{{AFX_DATA(CLinkDataView)
	enum { IDD = IDD_LINKDATA_FORM };
	CLinkDataSet* m_pSet;
	//}}AFX_DATA

// Attributes
public:
	CLinkDataDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkDataView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnMove(UINT nIDMoveCommand);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLinkDataView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	BOOL flag;
	//{{AFX_MSG(CLinkDataView)
	afx_msg void OnRecordAdd();
	afx_msg void OnRecordDelete();
	afx_msg void OnSortId();
	afx_msg void OnSortLength();
	afx_msg void OnFilterId();
	afx_msg void OnFilterFactory();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LinkDataView.cpp
inline CLinkDataDoc* CLinkDataView::GetDocument()
   { return (CLinkDataDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKDATAVIEW_H__C773CE64_0AE4_4040_90EA_4CD7FE74DF24__INCLUDED_)
