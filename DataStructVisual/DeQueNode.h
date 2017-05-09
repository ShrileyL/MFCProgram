// DeQueNode.h: interface for the CDeQueNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEQUENODE_H__6BC80D38_AC05_448C_AF59_8FFBAB303620__INCLUDED_)
#define AFX_DEQUENODE_H__6BC80D38_AC05_448C_AF59_8FFBAB303620__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDeQueNode : public CObject  
{
public:
	CDeQueNode();
	virtual ~CDeQueNode();
	CPoint m_Point;//�������λ��
	COLORREF m_Color; //�����ɫ
	CString m_StrName; //�������
	BOOL m_Visit;//����Ƿ����
};

#endif // !defined(AFX_DEQUENODE_H__6BC80D38_AC05_448C_AF59_8FFBAB303620__INCLUDED_)
