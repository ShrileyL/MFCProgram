// DeQueue.cpp: implementation of the CDeQueue class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "datastructvisual.h"
#include "DeQueue.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDeQueue::CDeQueue()
{

}

CDeQueue::~CDeQueue()
{

}

void CDeQueue::DrawInitDeQueue(CDC *pDC)
{
	CPoint tTopLeft(140,100);
	CPoint tTopRight(700,100);
	CPoint tBottomLeft(140,200);
	CPoint tBottomRight(700,200);
	if(!pDC->TextOut(tTopLeft.x,tTopLeft.y-25,"前端")) return;
	if(!pDC->TextOut(tTopRight.x-25,tTopRight.y-25,"后端")) return;
	pDC->MoveTo(tTopLeft);
	pDC->LineTo(tTopRight);
	pDC->MoveTo(tBottomLeft);
	pDC->LineTo(tBottomRight);
	tTopLeft.x=150,tTopLeft.y=125;
	tBottomLeft.x=200;tBottomLeft.y=175;
	CRect tDeNodeRect;
	
	for(int i=0;i<8;i++)
	{	 
		tDeNodeRect.SetRect(tTopLeft,tBottomLeft);
		if(!pDC->Rectangle(tDeNodeRect)) return;
		tTopLeft.x+=70;
		tBottomLeft.x+=70;
	}
	tTopLeft.x=90;tTopLeft.y=125;
	tTopRight.x=140;tTopRight.y=125;
	DrawArrow(tTopLeft,tTopRight,pDC);
	tTopLeft.y+=50;tTopRight.y+=50;
	DrawArrow(tTopRight,tTopLeft,pDC);
	tTopLeft.x=750;tTopLeft.y=125;
	tTopRight.x=700;tTopRight.y=125;
	DrawArrow(tTopLeft,tTopRight,pDC);
	tTopLeft.y+=50;tTopRight.y+=50;
	DrawArrow(tTopRight,tTopLeft,pDC);
}
void CDeQueue::DrawDeQueue(CDC *pDC)
{
	
	DrawInitDeQueue(pDC);
	POSITION tPos;
	CDeQueNode *tPCurDeQueNode;

	for(tPos = m_DeQueue.GetHeadPosition();tPos != NULL;)
	{
		tPCurDeQueNode=m_DeQueue.GetNext(tPos);
		DrawDeQueNode(tPCurDeQueNode,pDC);
	}
}
void CDeQueue::EnDeQueue(CPoint vPoint,CString vString,bool vIsHead)
{
	int tWidth,tHeight;
	POSITION tPos;
	int tCount=m_DeQueue.GetCount();
	tWidth=vPoint.x;
	tHeight=vPoint.y;
	CDeQueNode *tPDeQueNode = new CDeQueNode();
	tPDeQueNode->m_Visit=0;
	tPDeQueNode->m_Color=RGB(0,0,0);
	tPDeQueNode->m_StrName=vString;
	int tPerNodeWidth=(tWidth-160)/70;
	int tRow=tCount/tPerNodeWidth;
	int tCol=tCount%tPerNodeWidth;
	if(tCount<8)
	{
		tPDeQueNode->m_Point.x=-(tCol-1)*70+595;
		tPDeQueNode->m_Point.y=(tRow-1)*70+220;
		if(vIsHead)
			m_DeQueue.AddTail(tPDeQueNode);
		else
		{
			CDeQueNode *tPCurDeQueNode; 
			tPos=m_DeQueue.GetHeadPosition();
			m_DeQueue.InsertBefore(tPos,tPDeQueNode); 
			//修改后面结点的显示位置 
			for(int i=0;i<m_DeQueue.GetCount();i++)
			{ 
				tPos=m_DeQueue.FindIndex(i);
				tPCurDeQueNode=m_DeQueue.GetAt(tPos);
				tRow=i/tPerNodeWidth;
				tCol=i%tPerNodeWidth;
				tPCurDeQueNode->m_Point.x=-(tCol-1)*70+595;
				tPCurDeQueNode->m_Point.y=(tRow-1)*70+220;
				m_DeQueue.SetAt(tPos,tPCurDeQueNode);
			}
		}
	}else
	{
		::AfxMessageBox("队列已满!");
		return;
	}
}
bool CDeQueue::DrawDeQueNode(CDeQueNode *vPDeQueNode, CDC *pDC)
{
	CPen tDrawPen,*tPOldPen;
	CPoint tPoint=vPDeQueNode->m_Point;
	tPOldPen=pDC->SelectObject(&tDrawPen);
	if(!pDC->TextOut(
		tPoint.x-15+7,
		tPoint.y-15+7,
		vPDeQueNode->m_StrName)
	) return false;
   	return true;
}

void CDeQueue::DeDeQueue(CPoint vPoint,bool vIsHead)
{
	int tWidth,tHeight,tNum;
	int tCount=m_DeQueue.GetCount();
	if(vIsHead)
		tNum=tCount-1;
	else tNum=0;
	POSITION tPos;
	CDeQueNode *tPCurDeQueNode; 
	tWidth=vPoint.x; 
	tHeight=vPoint.y; 
	if(tCount<1)
	{ 
		::AfxMessageBox("队列已空,不能出队!");
		return;
	}
	else
	{
		int tPerNodeWidth=(tWidth-160)/70;
		int tRow=(tCount+1)/tPerNodeWidth;
		tPos=m_DeQueue.FindIndex(tNum); 
		tRow=(tNum)/tPerNodeWidth; 
		int tCol=tNum%tPerNodeWidth; 
		m_DeQueue.RemoveAt(tPos);
		//修改后面结点的显示位置 
		for(int i=tNum;i<m_DeQueue.GetCount();i++)
		{ 
			tPos=m_DeQueue.FindIndex(i); 
			tPCurDeQueNode=m_DeQueue.GetAt(tPos);
			tRow=i/tPerNodeWidth; 
			tCol=i%tPerNodeWidth;
			tPCurDeQueNode->m_Point.x=-(tCol-1)*70+595;
			tPCurDeQueNode->m_Point.y=(tRow-1)*70+220;
			m_DeQueue.SetAt(tPos,tPCurDeQueNode);
		}
	}
}

void CDeQueue::DrawArrow(CPoint vBeginPoint, CPoint vEndpoint, CDC *pDC)
{
	CPoint tPoint; 
	pDC->MoveTo(vBeginPoint); 
	pDC->LineTo(vEndpoint); 
	
	double tX=vBeginPoint.x-vEndpoint.x;
	double tY=vBeginPoint.y-vEndpoint.y; 
	double tRotX,tRotY; 
	double tAngle=asin(1.0)/3;
	tRotY=tY*cos(tAngle)+tX*sin(tAngle); 
	tRotX=tX*cos(tAngle)-tY*sin(tAngle); 
	tRotY=tRotY/5+vEndpoint.y; 
	tRotX=tRotX/5+vEndpoint.x; 
	tPoint.x=(int)tRotX; 
	tPoint.y=(int)tRotY; 
	pDC->MoveTo(vEndpoint); 
	pDC->LineTo(tPoint);
	
	tAngle=-tAngle;
	tRotY=tY*cos(tAngle)+tX*sin(tAngle); 
	tRotX=tX*cos(tAngle)-tY*sin(tAngle); 
	tRotY=tRotY/5+vEndpoint.y; 
	tRotX=tRotX/5+vEndpoint.x; 
	tPoint.x=(int)tRotX; 
	tPoint.y=(int)tRotY; 
	pDC->MoveTo(vEndpoint); 
	pDC->LineTo(tPoint);
}