#ifndef __TIME_KIT_H__
#define __TIME_KIT_H__
#include "../stdafx.h"

namespace Base
{
class CTimeKit
{
public:
	//时间处理函数
	static CDuiString GetCurDateTime(LPCTSTR pstrFormat);
};
}
#endif