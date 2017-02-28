#pragma once

#include <iostream>
#include <string>
#include <fstream>

/**
 * �e�L�X�g�t�@�C���̓Ǐ���
 * �Q�� : �u[C++] �t�@�C�����o�͂̊o���v (Qiita) http://qiita.com/lazynick/items/8aede589bb9ca0c8b64f
 * �Q�� : �u������̌������@�ɂ�鑬�x���v (Qiita) http://qiita.com/ampersand/items/0322e0820badf2c020be
 * �Q�� : �󕶎���ŏ���������ɂ� : �u������̏������v (��𓮂����Ă��������������� C++ ������N���X std::string ����) http://vivi.dyndns.org/tech/cpp/string.html
 */
class UtilFile
{
public:
	UtilFile();
	~UtilFile();

	static void Write(std::string filename, std::string contents);

	static std::string Read(std::string filename);
};

