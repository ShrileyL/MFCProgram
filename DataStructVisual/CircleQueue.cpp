// CircleQueue.cpp: implementation of the CCircleQueue class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "datastructvisual.h"
#include "CircleQueue.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCircleQueue::CCircleQueue()
{
	m_InDiameter=70;
	m_OutDiameter=150;
	m_AverDiameter=(m_InDiameter+m_OutDiameter)/2;
	m_Cx=300;
	m_Cy=200;
	m_Head=0;
	m_Rear=0;
}

CCircleQueue::~CCircleQueue()
{

}

void CCircleQueue::EnQueue(CPoint vPoint,CString vString)
{
	CCircleQueNode *tPCurQueNode;
	double tAngle=asin(1.0)/4;
	int i=0;
	POSITION tPos;
	int count=m_CircleQueue.GetCount();
	if((m_Rear+1)%8==m_Head){
		::AfxMessageBox("队列已满!");
	}else{
		tPos=m_CircleQueue.FindIndex(m_Rear);
		tPCurQueNode=m_CircleQueue.GetAt(tPos);
		tPCurQueNode->m_StrName=vString;
		tPCurQueNode->m_Point.x=m_Cx+m_AverDiameter*sin(tAngle+m_Rear*asin(1.0)/2);
		tPCurQueNode->m_Point.y=m_Cy-m_AverDiameter*cos(tAngle+m_Rear*asin(1.0)/2);
		m_Rear=(m_Rear+1)%8;
	}
}

void CCircleQueue::DrawRearArrow(double vAngle,CDC *pDC)
{

	double tBX,tBY,tTX,tTY,tAngle;
	tBX=m_Cx+m_OutDiameter*sin(vAngle);
	tBY=m_Cy-m_OutDiameter*cos(vAngle);
	tTX=tBX+50*sin(vAngle);
	tTY=tBY-50*cos(vAngle);
	pDC->MoveTo(tTX,tTY);
	pDC->LineTo(tBX,tBY);
	pDC->TextOut(tTX+5,tTY-10,"Rear");

	tAngle=vAngle+asin(1.0)/3;
	tTX=tBX+10*sin(tAngle);
	tTY=tBY-10*cos(tAngle);
	pDC->MoveTo(tBX,tBY);
	pDC->LineTo(tTX,tTY);
	tAngle=vAngle-asin(1.0)/3;
	tTX=tBX+10*sin(tAngle);
	tTY=tBY-10*cos(tAngle);
	pDC->MoveTo(tBX,tBY);
	pDC->LineTo(tTX,tTY);

}
void CCircleQueue::DrawFrontArrow(double vAngle,CDC *pDC)
{
	
	double tBX,tBY,tTX,tTY,tAngle;
	tBX=m_Cx+m_OutDiameter*sin(vAngle);
	tBY=m_Cy-m_OutDiameter*cos(vAngle);
	tTX=tBX+50*sin(vAngle);
	tTY=tBY-50*cos(vAngle);
	pDC->MoveTo(tTX,tTY);
	pDC->LineTo(tBX,tBY);
	pDC->TextOut(tTX+5,tTY-10,"Front");

	tAngle=vAngle+asin(1.0)/3;
	tTX=tBX+10*sin(tAngle);
	tTY=tBY-10*cos(tAngle);
	pDC->MoveTo(tBX,tBY);
	pDC->LineTo(tTX,tTY);
	tAngle=vAngle-asin(1.0)/3;
	tTX=tBX+10*sin(tAngle);
	tTY=tBY-10*cos(tAngle);
	pDC->MoveTo(tBX,tBY);
	pDC->LineTo(tTX,tTY);

}
void CCircleQueue::DrawInitCircleQueue(CDC *pDC)
{

	int tXI,tYI,tXO,tYO;
	int tInRadius,tOutRadius;
	double tAngle,tBX,tBY,tTX,tTY;
	tXI=tXO=0;
	tYI=m_InDiameter;
	tYO=m_OutDiameter;
	tInRadius=1-m_InDiameter;
	tOutRadius=1-m_OutDiameter;
	DrawCircle(tXI,tYI,tInRadius,pDC);
	DrawCircle(tXO,tYO,tOutRadius,pDC);
	for(int i=0;i<8;i++)
	{
		tAngle=i*asin(1.0)/2;
		tBX=m_Cx+m_InDiameter*sin(tAngle);
		tBY=m_Cy-m_InDiameter*cos(tAngle);
		tTX=m_Cx+m_OutDiameter*sin(tAngle);
		tTY=m_Cy-m_OutDiameter*cos(tAngle);
		pDC->MoveTo(tBX,tBY);
		pDC->LineTo(tTX,tTY);
		DrawSeqNum(tBX,tBY,tAngle,i,pDC);
	}
}
void CCircleQueue::DrawCircle(int vX,int vY,int vRadius,CDC *pDC)
{
	while(vX<vY)
	{
		if(vRadius<0)
		{
			vRadius+=2*vX+3;
			vX++;
		}
		else
		{
			vRadius+=2*(vX-vY)+5;
			vX++;
			vY--;
		}
		DrawCirclePoint(vX,vY,pDC);
	}

}
void CCircleQueue::DrawCirclePoint(int vX,int vY,CDC *pDC)
{
	pDC->SetPixelV((m_Cx+vY),(m_Cy+vX),RGB(0,255,0));
	pDC->SetPixelV((m_Cx+vY),(m_Cy-vX),RGB(0,255,0));
	pDC->SetPixelV((m_Cx+vX),(m_Cy-vY),RGB(0,255,0));
	pDC->SetPixelV((m_Cx+vX),(m_Cy+vY),RGB(0,255,0));
	pDC->SetPixelV((m_Cx-vX),(m_Cy-vY),RGB(0,255,0));
	pDC->SetPixelV((m_Cx-vY),(m_Cy-vX),RGB(0,255,0));
	pDC->SetPixelV((m_Cx-vY),(m_Cy+vX),RGB(0,255,0));
	pDC->SetPixelV((m_Cx-vX),(m_Cy+vY),RGB(0,255,0));
}
void CCircleQueue::DrawSeqNum(double vX,double vY,double vAngle, int vI,CDC *pDC)
{

	double tX,tY;
	tX=(vX+m_Cx+m_InDiameter*sin(vAngle+asin(1.0)/2))/2;
	tY=(vY+m_Cy-m_InDiameter*cos(vAngle+asin(1.0)/2))/2;
	switch(vI)
	{
	case 0:tX=tX-4;break;
	case 1:tX=tX-6;tY=tY-4;break;
	case 2:tX=tX-6;tY=tY-8;break;
	case 3:tX=tX-4;tY=tY-14;break;
	case 4:tX=tX-4;tY=tY-14;break;
	case 5:tX=tX+4;tY=tY-10;break;
	case 6:tX=tX+4;tY=tY-6;break;
	case 7:tX=tX-2;break;
	}
	pDC->TextOut(tX,tY,vI+48);
}


void CCircleQueue::InitCircleQueue()
{
	CString tStr;
	for(int i=0;i<8;i++){
		CCircleQueNode *tPCircleQueNode = new CCircleQueNode();
		tPCircleQueNode->m_Visit=0;
		tPCircleQueNode->m_Color=RGB(0,0,0);
		tStr.Format("%d",i);
		tPCircleQueNode->m_StrName=tStr;
		m_CircleQueue.AddTail(tPCircleQueNode);
	}
}
void CCircleQueue::DeQueue()
{
	
	CCircleQueNode *tPCurQueNode;
	POSITION tPos;
	if(m_Rear==m_Head){
		::AfxMessageBox("队列已空!");
	}else{
		tPos=m_CircleQueue.FindIndex(m_Head);
		tPCurQueNode=m_CircleQueue.GetAt(tPos);
		tPCurQueNode->m_StrName="";
		m_Head=(m_Head+1)%8;
	}
}
void CCircleQueue::DrawCircleQueue(CDC *pDC)
{
	POSITION tPos;
	CCircleQueNode *tPCurCircleQueNode;
	double tAngle;
	DrawInitCircleQueue(pDC);
	
	for(tPos = m_CircleQueue.GetHeadPosition();tPos != NULL;)
	{
		tPCurCircleQueNode=m_CircleQueue.GetNext(tPos); 
		
		DrawCircleQueNode(tPCurCircleQueNode,pDC);
	}
	
	tAngle=asin(1.0)/6+asin(1.0)/2*(m_Head);
	DrawFrontArrow(tAngle,pDC);
	tAngle=asin(1.0)/3+asin(1.0)/2*(m_Rear);
	DrawRearArrow(tAngle,pDC);
}
bool CCircleQueue::DrawCircleQueNode(CCircleQueNode *vPCircleQueNode, CDC *pDC)
{
	CPoint tPoint=vPCircleQueNode->m_Point;
	CString tStrName;
	if(!pDC->TextOut(tPoint.x-15+7,tPoint.y-15+7,vPCircleQueNode->m_StrName)) return false;
   	return true;
}
