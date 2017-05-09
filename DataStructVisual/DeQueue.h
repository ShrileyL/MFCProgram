// DeQueue.h: interface for the CDeQueue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEQUEUE_H__55C7F925_784C_4D88_9161_8EAECA49A747__INCLUDED_)
#define AFX_DEQUEUE_H__55C7F925_784C_4D88_9161_8EAECA49A747__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "math.h"
#include <afxtempl.h>
#include <afxwin.h>
#include <afxext.h>
#include "DeQueNode.h"

class CDeQueue  
{
public:
	CDeQueue();
	virtual ~CDeQueue();
	void DrawInitDeQueue(CDC *pDC);//绘制初始双端队列
	void DrawDeQueue(CDC *pDC);//绘制双端队列
	void EnDeQueue(
		CPoint vPoint,
		CString vString,
		bool vIsHead)
		;//双端队列入队，IsHead==TRUE 为前端入队否则后端
	bool DrawDeQueNode(CDeQueNode *vPDeQueNode, CDC *pDC);//绘制双端队列节点
	void DeDeQueue(
		CPoint vPoint,
		bool vIsHead);//双端队列出队，IsHead==TRUE 为前端入队否则后端
	void DrawArrow(CPoint vBeginPoint, CPoint vEndpoint, CDC *pDC);
public:
	CTypedPtrList <CObList,CDeQueNode*>   m_DeQueue; //双端队列容器
};

#endif // !defined(AFX_DEQUEUE_H__55C7F925_784C_4D88_9161_8EAECA49A747__INCLUDED_)
