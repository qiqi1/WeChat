#pragma once
#include "Node.h"

namespace DuiLib
{
	struct BubbleItemInfo			//好友列表信息 结构体
	{
		//NodeType		id;	
		TCHAR buf[MAX_PATH];
	};
	class CBubbleChat : public CListUI
	{
	public:
		CBubbleChat(CPaintManagerUI& paint_manager);
		~CBubbleChat(void);
	public:
		enum {SCROLL_TIMERID = 10};
		Node* AddNode(const BubbleItemInfo& item, Node* parent);
		double GetTextWidth(const TCHAR *text);   //返回字符串的像素宽度
		void RemoveAll();
		bool RemoveNode(Node* node);			//删除节点
		void DoEvent(TEventUI& event); 
	private:
		CDialogBuilder				m_dlgBuilder;
		CPaintManagerUI&		paint_manager_;
		LONG							delay_deltaY_;			//与滚动条滑动速度有关
		DWORD						delay_number_;		
		DWORD						delay_left_;
		Node*							root_node_;				//父节点
	};
}
