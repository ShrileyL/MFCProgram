#if !defined(AFX_CARSET_H__22A2D3CA_8B06_4681_A76A_539888957B11__INCLUDED_)
#define AFX_CARSET_H__22A2D3CA_8B06_4681_A76A_539888957B11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Carset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCarset recordset

class CCarset : public CRecordset
{
public:
	CCarset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCarset)

// Field/Param Data
	//{{AFX_FIELD(CCarset, CRecordset)
	long	m_ID;
	CString	m_name;
	double	m_length;
	double	m_width;
	double	m_height;
	CString	m_factory;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCarset)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARSET_H__22A2D3CA_8B06_4681_A76A_539888957B11__INCLUDED_)
