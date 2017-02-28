#include "stdafx.h"
#include "UtilString.h"

std::string UtilString::Trim(const std::string& string, const char* trimCharacterList)
{
	std::string result;

	// ��������g�������镶���ȊO��������ʒu���������܂��B
	std::string::size_type left = string.find_first_not_of(trimCharacterList);

	if (left != std::string::npos)
	{
		// ��������g�������镶���ȊO�����������ꍇ�́A�����悤�ɉE��������������܂��B
		std::string::size_type right = string.find_last_not_of(trimCharacterList);

		// �߂�l�����肵�܂��B�����ł͉E�����猟�����Ă��A�g�������镶���ȊO���K�����݂���̂Ŕ���s�v�ł��B
		result = string.substr(left, right - left + 1);
	}

	return result;
}
