// LinkData.h : main header file for the LINKDATA application
//

#if !defined(AFX_LINKDATA_H__2D25BF95_50F7_481E_A9EB_2C1430D37E83__INCLUDED_)
#define AFX_LINKDATA_H__2D25BF95_50F7_481E_A9EB_2C1430D37E83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLinkDataApp:
// See LinkData.cpp for the implementation of this class
//

class CLinkDataApp : public CWinApp
{
public:
	CLinkDataApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkDataApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLinkDataApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKDATA_H__2D25BF95_50F7_481E_A9EB_2C1430D37E83__INCLUDED_)
