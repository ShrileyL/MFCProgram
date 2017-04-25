// MyVC3.h : main header file for the MYVC3 application
//

#if !defined(AFX_MYVC3_H__7B4FC163_FD1C_4B33_8605_E7E9691CB895__INCLUDED_)
#define AFX_MYVC3_H__7B4FC163_FD1C_4B33_8605_E7E9691CB895__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyVC3App:
// See MyVC3.cpp for the implementation of this class
//

class CMyVC3App : public CWinApp
{
public:
	CMyVC3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyVC3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyVC3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYVC3_H__7B4FC163_FD1C_4B33_8605_E7E9691CB895__INCLUDED_)
