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
	CDaoDatabase db;//�������ݿ����
	CDaoRecordset RecSet(&db);//�����¼������
	COleVariant var;//�ֶ�����
	var.ChangeType(VT_BSTR,NULL);
	CString strName,fieldname;
	m_list1.ResetContent();//����б��

	db.Open("C:\\Users\\Paopao\\Desktop\\car.mdb");//���Ѵ�����car���ݿ�


	UpdateData(TRUE);
	fieldname = "FACTORY";//��ѯ�ֶ���
	RecSet.m_strFilter = fieldname+"='"+m_factory+"'";//���ù����ַ���
	//
	RecSet.Open(AFX_DAO_USE_DEFAULT_TYPE,"SELECT* FROM example",NULL);
	while(!RecSet.IsEOF())//�Ƿ񵽱�β
	{
		RecSet.GetFieldValue("NAME",var);//�õ��ֶε�ֵ
		strName = (LPCSTR)var.pbstrVal;
		m_list1.AddString(strName);//��ӵ��б��
		RecSet.MoveNext();//��¼ָ������
	}
	RecSet.Close();//�رռ�¼��
	db.Close();//�ر����ݿ�
	
	
}
