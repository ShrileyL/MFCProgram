// CircleQueNode.h: interface for the CCircleQueNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRCLEQUENODE_H__948244BB_193A_4218_93AE_FC65336101FB__INCLUDED_)
#define AFX_CIRCLEQUENODE_H__948244BB_193A_4218_93AE_FC65336101FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCircleQueNode : public CObject  
{
public:
	CCircleQueNode();
	virtual ~CCircleQueNode();
	CPoint m_Point;//结点坐标位置
	COLORREF m_Color; //结点颜色
	CString m_StrName; //结点名称
	BOOL m_Visit;//结点是否访问
};

#endif // !defined(AFX_CIRCLEQUENODE_H__948244BB_193A_4218_93AE_FC65336101FB__INCLUDED_)
