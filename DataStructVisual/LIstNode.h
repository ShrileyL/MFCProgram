// LIstNode.h: interface for the CLIstNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTNODE_H__47723BA1_047B_4351_A45B_5142C61246F0__INCLUDED_)
#define AFX_LISTNODE_H__47723BA1_047B_4351_A45B_5142C61246F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CListNode : public CObject  
{
public:
	CListNode();
	virtual ~CListNode();
public:	
	CPoint m_Point;//������������λ��
	COLORREF m_Color; //����������ɫ
	CString m_StrName; //������������
	BOOL m_Visit;//���������Ƿ����
	int m_Row;//��������ʾ����
};

#endif // !defined(AFX_LISTNODE_H__47723BA1_047B_4351_A45B_5142C61246F0__INCLUDED_)
