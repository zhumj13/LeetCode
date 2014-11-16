// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://go.microsoft.com/fwlink/?LinkId=238214。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// BentleyOttmannView.cpp : CBentleyOttmannView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "BentleyOttmann.h"
#endif

#include "BentleyOttmannDoc.h"
#include "BentleyOttmannView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBentleyOttmannView

IMPLEMENT_DYNCREATE(CBentleyOttmannView, CScrollView)

BEGIN_MESSAGE_MAP(CBentleyOttmannView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBentleyOttmannView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CBentleyOttmannView 构造/析构

CBentleyOttmannView::CBentleyOttmannView()
{
	// TODO: 在此处添加构造代码

}

CBentleyOttmannView::~CBentleyOttmannView()
{
}

BOOL CBentleyOttmannView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CBentleyOttmannView 绘制

void CBentleyOttmannView::OnDraw(CDC* /*pDC*/)
{
	CBentleyOttmannDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CBentleyOttmannView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CBentleyOttmannView 打印


void CBentleyOttmannView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBentleyOttmannView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBentleyOttmannView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CBentleyOttmannView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CBentleyOttmannView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBentleyOttmannView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBentleyOttmannView 诊断

#ifdef _DEBUG
void CBentleyOttmannView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBentleyOttmannView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CBentleyOttmannDoc* CBentleyOttmannView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBentleyOttmannDoc)));
	return (CBentleyOttmannDoc*)m_pDocument;
}
#endif //_DEBUG


// CBentleyOttmannView 消息处理程序


void CBentleyOttmannView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	startPoint=point;  //m_point是一个全局的POINT类
	CScrollView::OnLButtonDown(nFlags, point);
}


void CBentleyOttmannView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC *pDC = GetDC();
	pDC->MoveTo(startPoint);
	pDC->LineTo(point);
	CScrollView::OnLButtonUp(nFlags, point);
}
