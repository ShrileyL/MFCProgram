// LinkList.h: interface for the CLinkList class.
//
//////////////////////////////////////////////////////////////////////

#include <afxwin.h>
#include <afxtempl.h>
#include <afxext.h>
#include "math.h"
#include "LIstNode.h"

#if !defined(AFX_LINKLIST_H__1CE8AA0E_C20C_44FE_9AF7_12A370DDF646__INCLUDED_)
#define AFX_LINKLIST_H__1CE8AA0E_C20C_44FE_9AF7_12A370DDF646__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLinkList  
{
public:
	CLinkList();//���캯��
	virtual ~CLinkList();//��������
	void AddTail(CPoint vPoint,CString vString);//β�巨����������
	void InsertNode(CPoint vPoint,int vPos,CString vString);//�������в�����
	void DeleteNode(CPoint vPoint,int vPos);//������ɾ�����
	BOOL Search(CString vString);//��ֵ����
	void DrawArrow(CPoint vBeginPoint, CPoint vEndpoint, CDC *pDC);//���Ƽ�ͷ
	bool DrawLinkNode(CListNode *vPListNode, CDC *pDC);//���ƽ��
	bool DrawLinkList(CDC *pDC);//���Ƶ�����
	void DrawPolyLine(CPoint curpoint, CPoint nextpoint, CDC *pDC);//��������
	void DrawSearchArrow(CDC *pDC);//���Ʋ��ҽ����ͷ
public:
	
	CTypedPtrList <CObList,CListNode*>   m_LinkList; //������������
private:
	CListNode* m_pCurLNode;//���ָʾ��
	CListNode* n_pCurLNode;//���ָʾ��
};

#endif // !defined(AFX_LINKLIST_H__1CE8AA0E_C20C_44FE_9AF7_12A370DDF646__INCLUDED_)
