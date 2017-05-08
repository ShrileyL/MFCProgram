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
	void InitCircleQueue();//队列初始化
	void EnQueue(CPoint vPoint,CString vString);//入队列
	void DeQueue();//出队列
	void DrawInitCircleQueue(CDC *pDC);//绘制初始循环列表
	void DrawCircleQueue(CDC *pDC);//绘制循环列表
	bool DrawCircleQueNode(CCircleQueNode *pCircleQueNode, CDC *pDC);//绘制结点元素
	void DrawRearArrow(double vAngle,CDC *pDC);//绘制尾指针
	void DrawFrontArrow(double vAngle,CDC *pDC);//绘制头指针
	void DrawSeqNum(double vX,double vY,double vAngle,int vI,CDC *pDC);// 绘制元素序号
	void DrawCircle(int vX,int vY,int vRadius,CDC *pDC);//八分法绘制圆
	void DrawCirclePoint(int vX,int vY,CDC *pDC);//八分法绘制圆点
	void DrawMidCircle(CDC *pDC);//绘制队列圆环
private:
	CTypedPtrList <CObList,CCircleQueNode*> m_CircleQueue;//循环队列
	int m_Head,m_Rear;//队头指针及队尾指针
	int m_AverDiameter;//平均内径
	int m_Cx,m_Cy;
	int m_InDiameter,m_OutDiameter;//圆环内径和外径
};

#endif // !defined(AFX_CIRCLEQUEUE_H__66891D82_4E89_4F7F_8541_BB46D2E98A19__INCLUDED_)
