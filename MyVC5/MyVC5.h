// MyVC5.h : main header file for the MYVC5 application
//

#if !defined(AFX_MYVC5_H__A5D0EC1C_2101_4FF6_AE4C_A3C36DFDF874__INCLUDED_)
#define AFX_MYVC5_H__A5D0EC1C_2101_4FF6_AE4C_A3C36DFDF874__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyVC5App:
// See MyVC5.cpp for the implementation of this class
//

class CMyVC5App : public CWinApp
{
public:
	CMyVC5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyVC5App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyVC5App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVC5_H__A5D0EC1C_2101_4FF6_AE4C_A3C36DFDF874__INCLUDED_)
