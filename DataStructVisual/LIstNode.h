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
	CPoint m_Point;//单链表结点坐标位置
	COLORREF m_Color; //单链表结点颜色
	CString m_StrName; //单链表结点名称
	BOOL m_Visit;//单链表结点是否访问
	int m_Row;//链表结点显示行数
};

#endif // !defined(AFX_LISTNODE_H__47723BA1_047B_4351_A45B_5142C61246F0__INCLUDED_)
