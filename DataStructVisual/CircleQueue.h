// CircleQueue.h: interface for the CCircleQueue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRCLEQUEUE_H__66891D82_4E89_4F7F_8541_BB46D2E98A19__INCLUDED_)
#define AFX_CIRCLEQUEUE_H__66891D82_4E89_4F7F_8541_BB46D2E98A19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "math.h"
#include <afxtempl.h>
#include <afxwin.h>
#include <afxext.h>
#include "CircleQueNode.h"

class CCircleQueue  
{
public:
	CCircleQueue();
	virtual ~CCircleQueue();
	void InitCircleQueue();//���г�ʼ��
	void EnQueue(CPoint vPoint,CString vString);//�����
	void DeQueue();//������
	void DrawInitCircleQueue(CDC *pDC);//���Ƴ�ʼѭ���б�
	void DrawCircleQueue(CDC *pDC);//����ѭ���б�
	bool DrawCircleQueNode(CCircleQueNode *pCircleQueNode, CDC *pDC);//���ƽ��Ԫ��
	void DrawRearArrow(double vAngle,CDC *pDC);//����βָ��
	void DrawFrontArrow(double vAngle,CDC *pDC);//����ͷָ��
	void DrawSeqNum(double vX,double vY,double vAngle,int vI,CDC *pDC);// ����Ԫ�����
	void DrawCircle(int vX,int vY,int vRadius,CDC *pDC);//�˷ַ�����Բ
	void DrawCirclePoint(int vX,int vY,CDC *pDC);//�˷ַ�����Բ��
	void DrawMidCircle(CDC *pDC);//���ƶ���Բ��
private:
	CTypedPtrList <CObList,CCircleQueNode*> m_CircleQueue;//ѭ������
	int m_Head,m_Rear;//��ͷָ�뼰��βָ��
	int m_AverDiameter;//ƽ���ھ�
	int m_Cx,m_Cy;
	int m_InDiameter,m_OutDiameter;//Բ���ھ����⾶
};

#endif // !defined(AFX_CIRCLEQUEUE_H__66891D82_4E89_4F7F_8541_BB46D2E98A19__INCLUDED_)
