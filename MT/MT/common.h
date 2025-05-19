#pragma once
// �ڲ����ߺ��������ֽ�ת���ַ�
std::wstring multi_byte_to_wide_char(const std::string& str, UINT code_page);
// �ڲ����ߺ��������ַ�ת���ֽ�
std::string wide_char_to_multi_byte(const std::wstring& wstr, UINT code_page);
// UTF-8 ת GBK
std::string utf8_to_gbk(const std::string& utf8_str);
// GBK ת UTF-8
std::string gbk_to_utf8(const std::string& gbk_str);
