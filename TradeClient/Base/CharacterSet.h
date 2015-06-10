#ifndef __CHARACTERSET_H__
#define __CHARACTERSET_H__

namespace Base {

class CharacterSet
{
public:
    static std::string UnicodeConvert(const std::wstring& strWide, UINT uCodePage);

    static std::string UnicodeToUTF8(const std::wstring& strWide);

    static std::string UnicodeToANSI(const std::wstring& strWide);

    static std::wstring ANSIToUnicode(const std::string& str);

    static std::wstring UTF8ToUnicode(const std::string& str);

};

} // namespace Base

#endif