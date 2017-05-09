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
	void DrawInitDeQueue(CDC *pDC);//���Ƴ�ʼ˫�˶���
	void DrawDeQueue(CDC *pDC);//����˫�˶���
	void EnDeQueue(
		CPoint vPoint,
		CString vString,
		bool vIsHead)
		;//˫�˶�����ӣ�IsHead==TRUE Ϊǰ����ӷ�����
	bool DrawDeQueNode(CDeQueNode *vPDeQueNode, CDC *pDC);//����˫�˶��нڵ�
	void DeDeQueue(
		CPoint vPoint,
		bool vIsHead);//˫�˶��г��ӣ�IsHead==TRUE Ϊǰ����ӷ�����
	void DrawArrow(CPoint vBeginPoint, CPoint vEndpoint, CDC *pDC);
public:
	CTypedPtrList <CObList,CDeQueNode*>   m_DeQueue; //˫�˶�������
};

#endif // !defined(AFX_DEQUEUE_H__55C7F925_784C_4D88_9161_8EAECA49A747__INCLUDED_)
