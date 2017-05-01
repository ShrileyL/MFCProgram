// LinkDataSet.h : interface of the CLinkDataSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKDATASET_H__475835E2_D5A5_469D_BCB3_B004AD51D54B__INCLUDED_)
#define AFX_LINKDATASET_H__475835E2_D5A5_469D_BCB3_B004AD51D54B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLinkDataSet : public CRecordset
{
public:
	CLinkDataSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CLinkDataSet)

// Field/Param Data
	//{{AFX_FIELD(CLinkDataSet, CRecordset)
	long	m_ID;
	CString	m_name;
	double	m_length;
	double	m_width;
	double	m_height;
	CString	m_factory;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkDataSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKDATASET_H__475835E2_D5A5_469D_BCB3_B004AD51D54B__INCLUDED_)

