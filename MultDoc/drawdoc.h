// drawdoc.h : interface of the CDrawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWDOC_H__86524A72_A3B3_41AF_A7ED_AC0D38D6B19F__INCLUDED_)
#define AFX_DRAWDOC_H__86524A72_A3B3_41AF_A7ED_AC0D38D6B19F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


enum STYLE{Line,Rect,Elli};

class CShape
{
	friend class CDrawDoc;
public:
	void SetStyle(STYLE s){m_style=s;}
	void SetPenWidth(int w){m_penwidth = w;}
	void SetPenColor(COLORREF c){m_pencolor = c;}
	void SetBrushColor(COLORREF c){m_brushcolor = c;}
	void SetCPoint1(CPoint pt){m_point1 = pt;}
	void SetCPoint2(CPoint pt){m_point2 = pt;}
	STYLE GetStyle(){return m_style;}
	int GetPenWidth(){return m_penwidth;}
	COLORREF GetPenColor(){return m_pencolor;}
	COLORREF GetBrushColor(){return m_brushcolor;}
	CPoint GetCPoint1(){return m_point1;}
	CPoint GetCPoint2(){return m_point2;}
protected:
private:
	STYLE m_style;
	int m_penwidth;
	COLORREF m_pencolor;
	COLORREF m_brushcolor;
	CPoint m_point1;
	CPoint m_point2;
};

class CDrawDoc : public CDocument
{
protected: // create from serialization only
	CDrawDoc();
	DECLARE_DYNCREATE(CDrawDoc)

// Attributes
public:
	CShape m_shape;//定义一个数据管理类CShape对象
	void SetStyle(STYLE s){m_shape.SetStyle(s);}
	void SetPenWidth(int w){m_shape.SetPenWidth(w);}
	void SetPenColor(COLORREF c){m_shape.SetPenColor(c);}
	void SetBrushColor(COLORREF c){m_shape.SetBrushColor(c);}
	void SetCPoint1(CPoint pt){m_shape.SetCPoint1(pt);}
	void SetCPoint2(CPoint pt){m_shape.SetCPoint2(pt);}
	STYLE GetStyle(){return m_shape.GetStyle();}
	int GetPenWidth(){return m_shape.GetPenWidth();}
	COLORREF GetPenColor(){return m_shape.GetPenColor();}
	COLORREF GetBrushColor(){return m_shape.GetBrushColor();}
	CPoint GetCPoint1(){return m_shape.GetCPoint1();}
	CPoint GetCPoint2(){return m_shape.GetCPoint2();}

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWDOC_H__86524A72_A3B3_41AF_A7ED_AC0D38D6B19F__INCLUDED_)
