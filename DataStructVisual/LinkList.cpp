// LinkList.cpp: implementation of the CLinkList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "datastructvisual.h"
#include "LinkList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLinkList::CLinkList()
{

}

CLinkList::~CLinkList()
{

}

void CLinkList::AddTail(CPoint vPoint,CString vString)
{
	int tWidth,tHeight;
	int tCount=m_LinkList.GetCount();

	tWidth=vPoint.x;
	tHeight=vPoint.y;

	CListNode *pLNode = new CListNode();
	pLNode->m_Visit=0;
	pLNode->m_Color=RGB(0,0,0);
	pLNode->m_StrName=vString;

	int tPerNodeWidth=(tWidth-160)/70;
	int tRow=tCount/tPerNodeWidth;
	int tCol=tCount%tPerNodeWidth;
	if((tRow-1)*70<tHeight-150){
		pLNode->m_Row=tRow;
		pLNode->m_Point.x=(tCol-1)*70+150;
		pLNode->m_Point.y=(tRow-1)*70+100;
		m_LinkList.AddTail(pLNode);
	}else
	{
		::AfxMessageBox("结点数目超限!");
		return;
	}
}
void CLinkList::DrawArrow(CPoint vBeginPoint, CPoint vEndpoint, CDC *pDC)
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

bool CLinkList::DrawLinkNode(CListNode *vPListNode, CDC *pDC)
{
	CPen tDrawPen,*tPOldPen;
	CRect tNodeRect, tLinkRect;
	CPoint tCPoint=vPListNode->m_Point;

	tPOldPen=pDC->SelectObject(&tDrawPen);
	tNodeRect.SetRect(tCPoint.x-12,tCPoint.y-12,
		tCPoint.x+12,tCPoint.y+12);
	tLinkRect.SetRect(tCPoint.x+12,tCPoint.y-12,
		tCPoint.x+2*12,tCPoint.y+12);
	if(!pDC->Rectangle(tNodeRect)) return false;
	pDC->SelectObject(tPOldPen);
	if(!pDC->Rectangle(tLinkRect)) return false;
	CString tStrName;
	tStrName.Format("%d",vPListNode->m_StrName);
	if(!pDC->TextOut(tCPoint.x-15+7,tCPoint.y-15+7,
		vPListNode->m_StrName)) return false;
   	return true;
}

bool CLinkList::DrawLinkList(CDC *pDC)
{

	POSITION TPos,TPrePos;
	CString tStr;
	CPoint tEndPoint,tBeginPoint;
	CListNode *tPCurLNode,*tPNextLNode;

	for(TPos = m_LinkList.GetHeadPosition();TPos != NULL;)
	{
		TPrePos=TPos;
		tPCurLNode=m_LinkList.GetNext(TPos);
		DrawLinkNode(tPCurLNode,pDC);
		if(TPos!=NULL)
        {
			tPNextLNode=m_LinkList.GetAt(TPos);
			if(tPCurLNode->m_Row==tPNextLNode->m_Row)
			{
			
				tBeginPoint.x=tPCurLNode->m_Point.x+18;
				tBeginPoint.y=tPCurLNode->m_Point.y;
				tEndPoint.x=tPNextLNode->m_Point.x-12;
				tEndPoint.y=tPNextLNode->m_Point.y;
				DrawArrow(tBeginPoint,tEndPoint,pDC);
			}else
			{
				DrawPolyLine(tPCurLNode->m_Point,
					tPNextLNode->m_Point,pDC);
			}
		}
	}
    //绘制表头指针
	tPCurLNode=m_LinkList.GetHead();
	CPoint tCurPoint, tNextPoint;
	tCurPoint.x=tPCurLNode->m_Point.x-52;
	tCurPoint.y=tPCurLNode->m_Point.y;
	tNextPoint.x=tPCurLNode->m_Point.x-12;
	tNextPoint.y=tPCurLNode->m_Point.y;
	DrawArrow(tCurPoint,tNextPoint,pDC);
	tStr="Head";
	if(!pDC->TextOut(tPCurLNode->m_Point.x-56,
		tCurPoint.y-22,tStr)) return false;
	//绘制表尾指针
	tPCurLNode=m_LinkList.GetTail();
	tCurPoint.x=tPCurLNode->m_Point.x+18;
	tCurPoint.y=tPCurLNode->m_Point.y+48;
	tNextPoint.x=tPCurLNode->m_Point.x+18;
	tNextPoint.y=tPCurLNode->m_Point.y+12;
	DrawArrow(tCurPoint,tNextPoint,pDC);
	tStr="Tail";
	if(!pDC->TextOut(tNextPoint.x+4,
		tNextPoint.y+10,tStr)) return false;

	return true;
}
void CLinkList::DrawPolyLine(CPoint vCurpoint, 
							 CPoint vNextpoint, CDC *pDC)
{
	CPoint tBPoint,tEPoint;
	CListNode *tPCurLNode=m_LinkList.GetHead();

	tBPoint.x=vCurpoint.x+18;
	tBPoint.y=vCurpoint.y;
	tEPoint.x=vCurpoint.x+48;
	tEPoint.y=vCurpoint.y;
	pDC->MoveTo(tBPoint);
	pDC->LineTo(tEPoint);

	tBPoint=tEPoint;
	tEPoint.x=tEPoint.x;
	tEPoint.y=tEPoint.y+35;
	pDC->MoveTo(tBPoint);
	pDC->LineTo(tEPoint);

	tBPoint=tEPoint;
	tEPoint.x=tPCurLNode->m_Point.x-52;
	pDC->MoveTo(tBPoint);
	pDC->LineTo(tEPoint);

	tBPoint=tEPoint;
	tEPoint.x=tEPoint.x;
	tEPoint.y=tEPoint.y+35;
	pDC->MoveTo(tBPoint);
	pDC->LineTo(tEPoint);

	tBPoint=tEPoint;
	tEPoint.x=tBPoint.x+40;
	DrawArrow(tBPoint,tEPoint,pDC);
}
void CLinkList::InsertNode(CPoint vPoint,int vPos,CString vString)
{

	int tWidth,tHeight,tPos;
	int tCount=m_LinkList.GetCount();
	POSITION pos;
	CListNode *pCurLNode;
	tWidth=vPoint.x;
	tHeight=vPoint.y;

	if(vPos<0 && vPos>=tCount)
	{
		::AfxMessageBox("插入位置错误!");
		return;
	}
	int tPerNodeWidth=(tWidth-160)/70;
	int tRow=(tCount+1)/tPerNodeWidth;
	
	if((tRow-1)*70>tHeight-150){
		::AfxMessageBox("结点数目超限,不能插入!");
		return;
	}else{
		pos=m_LinkList.FindIndex(vPos);
		tRow=(vPos)/tPerNodeWidth;
		int tCol=vPos%tPerNodeWidth;
		CListNode *pLNode = new CListNode();
		pLNode->m_Visit=0;
		pLNode->m_Color=RGB(0,0,0);
		pLNode->m_StrName=vString;
		m_LinkList.InsertBefore(pos,pLNode);
		//修改后面结点的显示位置
		tPos=vPos;
		for(int i=tPos;i<m_LinkList.GetCount();i++)
		{
			pos=m_LinkList.FindIndex(i);
			pCurLNode=m_LinkList.GetAt(pos);
			tRow=i/tPerNodeWidth;
			tCol=i%tPerNodeWidth;
			pCurLNode->m_Row=tRow;
			pCurLNode->m_Point.x=(tCol-1)*70+150;
			pCurLNode->m_Point.y=(tRow-1)*70+100;
			m_LinkList.SetAt(pos,pCurLNode);
		}
	}
}
void CLinkList::DeleteNode(CPoint vPoint,int vPos)
{

	int tWidth,tHeight;
	int tCount=m_LinkList.GetCount();
	POSITION pos;
	CListNode *pCurLNode;
	tWidth=vPoint.x;
	tHeight=vPoint.y;

	if(vPos<0 && vPos>=tCount)
	{
		::AfxMessageBox("删除位置错误!");
		return;
	}
	if(tCount<=1){
		::AfxMessageBox("链表为空,不能删除!");
		return;
	}else{

		int tPerNodeWidth=(tWidth-160)/70;
		int tRow=(tCount+1)/tPerNodeWidth;
		pos=m_LinkList.FindIndex(vPos);
		tRow=(vPos)/tPerNodeWidth;
		int tCol=vPos%tPerNodeWidth;
		m_LinkList.RemoveAt(pos);;
		//修改后面结点的显示位置
		for(int i=vPos;i<m_LinkList.GetCount();i++)
		{
			pos=m_LinkList.FindIndex(i);
			pCurLNode=m_LinkList.GetAt(pos);
			tRow=i/tPerNodeWidth;
			tCol=i%tPerNodeWidth;
			pCurLNode->m_Row=tRow;
			pCurLNode->m_Point.x=(tCol-1)*70+150;
			pCurLNode->m_Point.y=(tRow-1)*70+100;
			m_LinkList.SetAt(pos,pCurLNode);
		}
	}
}

BOOL CLinkList::Search(CString vString)
{
	POSITION pos;
	CListNode *pCurLNode;
	int i=0;
	int tCount=m_LinkList.GetCount(); 
	for(pos = m_LinkList.GetHeadPosition();pos != NULL;) 
	{ 
		i++;
		pCurLNode=m_LinkList.GetNext(pos);
		if(vString==pCurLNode->m_StrName)
		{
			m_pCurLNode=pCurLNode;
			n_pCurLNode=pCurLNode;
			::AfxMessageBox("查找成功！");
			return(TRUE);
		}
		if(i>=tCount)
		{
			::AfxMessageBox("查找的结点不存在！");
			return(FALSE);
		}		
	} 
	return(TRUE);
}
void CLinkList::DrawSearchArrow(CDC *pDC)
{
	CPoint tBegin,tEnd;
	tBegin.x=m_pCurLNode->m_Point.x+5;
	tBegin.y=m_pCurLNode->m_Point.y+40;
	tEnd.x=m_pCurLNode->m_Point.x+5;
	tEnd.y=m_pCurLNode->m_Point.y+12;
	DrawArrow(tBegin,tEnd,pDC); 
}