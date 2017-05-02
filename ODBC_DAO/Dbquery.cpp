// Dbquery.cpp : implementation file
//

#include "stdafx.h"
#include "odbc_dao.h"
#include "Dbquery.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDbquery dialog


CDbquery::CDbquery(CWnd* pParent /*=NULL*/)
	: CDialog(CDbquery::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDbquery)
	m_factory = _T("");
	//}}AFX_DATA_INIT
}


void CDbquery::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDbquery)
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Text(pDX, IDC_FACTORY, m_factory);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDbquery, CDialog)
	//{{AFX_MSG_MAP(CDbquery)
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDbquery message handlers

void CDbquery::OnQuery() 
{
	CDaoDatabase db;//定义数据库对象
	CDaoRecordset RecSet(&db);//定义记录集对象
	COleVariant var;//字段类型
	var.ChangeType(VT_BSTR,NULL);
	CString strName,fieldname;
	m_list1.ResetContent();//清空列表框

	db.Open("C:\\Users\\Paopao\\Desktop\\car.mdb");//打开已创建的car数据库


	UpdateData(TRUE);
	fieldname = "FACTORY";//查询字段名
	RecSet.m_strFilter = fieldname+"='"+m_factory+"'";//设置过滤字符串
	//
	RecSet.Open(AFX_DAO_USE_DEFAULT_TYPE,"SELECT* FROM example",NULL);
	while(!RecSet.IsEOF())//是否到表尾
	{
		RecSet.GetFieldValue("NAME",var);//得到字段的值
		strName = (LPCSTR)var.pbstrVal;
		m_list1.AddString(strName);//添加到列表框
		RecSet.MoveNext();//记录指针下移
	}
	RecSet.Close();//关闭记录集
	db.Close();//关闭数据库
	
	
}
