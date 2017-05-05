// DataStructVisual.h : main header file for the DATASTRUCTVISUAL application
//

#if !defined(AFX_DATASTRUCTVISUAL_H__1EFF4885_B85A_4571_B7E9_333D0D96D69F__INCLUDED_)
#define AFX_DATASTRUCTVISUAL_H__1EFF4885_B85A_4571_B7E9_333D0D96D69F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDataStructVisualApp:
// See DataStructVisual.cpp for the implementation of this class
//

class CDataStructVisualApp : public CWinApp
{
public:
	CDataStructVisualApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataStructVisualApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDataStructVisualApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATASTRUCTVISUAL_H__1EFF4885_B85A_4571_B7E9_333D0D96D69F__INCLUDED_)
