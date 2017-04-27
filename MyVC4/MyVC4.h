// MyVC4.h : main header file for the MYVC4 application
//

#if !defined(AFX_MYVC4_H__1F875681_8CD6_4462_B9F4_6F8F36EE61D5__INCLUDED_)
#define AFX_MYVC4_H__1F875681_8CD6_4462_B9F4_6F8F36EE61D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyVC4App:
// See MyVC4.cpp for the implementation of this class
//

class CMyVC4App : public CWinApp
{
public:
	CMyVC4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyVC4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyVC4App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVC4_H__1F875681_8CD6_4462_B9F4_6F8F36EE61D5__INCLUDED_)
