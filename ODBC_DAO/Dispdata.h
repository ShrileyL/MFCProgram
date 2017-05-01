#if !defined(AFX_DISPDATA_H__C67D1D56_F770_42E4_9407_21CC156B75FB__INCLUDED_)
#define AFX_DISPDATA_H__C67D1D56_F770_42E4_9407_21CC156B75FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dispdata.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDispdata dialog

class CDispdata : public CDialog
{
// Construction
public:
	CDispdata(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDispdata)
	enum { IDD = IDD_DIALOG1 };
	CString	m_factory;
	double	m_height;
	int		m_id;
	double	m_length;
	CString	m_name;
	double	m_width;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDispdata)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDispdata)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISPDATA_H__C67D1D56_F770_42E4_9407_21CC156B75FB__INCLUDED_)
