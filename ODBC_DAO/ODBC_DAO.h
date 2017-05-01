// ODBC_DAO.h : main header file for the ODBC_DAO application
//

#if !defined(AFX_ODBC_DAO_H__CCD075C7_45D8_42FF_8EFC_E1F5DC84ACB7__INCLUDED_)
#define AFX_ODBC_DAO_H__CCD075C7_45D8_42FF_8EFC_E1F5DC84ACB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CODBC_DAOApp:
// See ODBC_DAO.cpp for the implementation of this class
//

class CODBC_DAOApp : public CWinApp
{
public:
	CODBC_DAOApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBC_DAOApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CODBC_DAOApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBC_DAO_H__CCD075C7_45D8_42FF_8EFC_E1F5DC84ACB7__INCLUDED_)
