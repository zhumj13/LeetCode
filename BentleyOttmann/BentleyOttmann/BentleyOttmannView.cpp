// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// BentleyOttmannView.cpp : CBentleyOttmannView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBentleyOttmannView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CBentleyOttmannView ����/����

CBentleyOttmannView::CBentleyOttmannView()
{
	// TODO: �ڴ˴���ӹ������

}

CBentleyOttmannView::~CBentleyOttmannView()
{
}

BOOL CBentleyOttmannView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// CBentleyOttmannView ����

void CBentleyOttmannView::OnDraw(CDC* /*pDC*/)
{
	CBentleyOttmannDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CBentleyOttmannView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CBentleyOttmannView ��ӡ


void CBentleyOttmannView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBentleyOttmannView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CBentleyOttmannView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CBentleyOttmannView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CBentleyOttmannView ���

#ifdef _DEBUG
void CBentleyOttmannView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBentleyOttmannView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CBentleyOttmannDoc* CBentleyOttmannView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBentleyOttmannDoc)));
	return (CBentleyOttmannDoc*)m_pDocument;
}
#endif //_DEBUG


// CBentleyOttmannView ��Ϣ�������


void CBentleyOttmannView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	startPoint=point;  //m_point��һ��ȫ�ֵ�POINT��
	CScrollView::OnLButtonDown(nFlags, point);
}


void CBentleyOttmannView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC *pDC = GetDC();
	pDC->MoveTo(startPoint);
	pDC->LineTo(point);
	CScrollView::OnLButtonUp(nFlags, point);
}
