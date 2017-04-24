// MyVC2.h : main header file for the MYVC2 application
//

#if !defined(AFX_MYVC2_H__68A670B9_F2D9_48B6_8416_3BB3EFF0AAFD__INCLUDED_)
#define AFX_MYVC2_H__68A670B9_F2D9_48B6_8416_3BB3EFF0AAFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyVC2App:
// See MyVC2.cpp for the implementation of this class
//

class CMyVC2App : public CWinApp
{
public:
	CMyVC2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyVC2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyVC2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVC2_H__68A670B9_F2D9_48B6_8416_3BB3EFF0AAFD__INCLUDED_)
