#include "TimeKit.h"

namespace Base
{
	CDuiString CTimeKit::GetCurDateTime(LPCTSTR pstrFormat)
	{
		SYSTEMTIME sysTime;
		::GetLocalTime(&sysTime);
		CDuiString strTime;
		strTime.SmallFormat(pstrFormat, sysTime.wHour, sysTime.wMinute, sysTime.wSecond, sysTime.wYear, sysTime.wMonth, sysTime.wDay);
		return strTime;
	}
}