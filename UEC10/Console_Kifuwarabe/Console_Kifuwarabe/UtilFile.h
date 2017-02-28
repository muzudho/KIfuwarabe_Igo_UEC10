#pragma once

#include <iostream>
#include <string>
#include <fstream>

/**
 * �e�L�X�g�t�@�C���̓Ǐ���
 *
 * ���� : [C++] �e�L�X�g�t�@�C���Ǐ��� (C#�v���O���}����) (Qiita) http://qiita.com/muzudho1/items/fa1446b85ae64d01a5ca
 * �Q�� : �u[C++] �t�@�C�����o�͂̊o���v (Qiita) http://qiita.com/lazynick/items/8aede589bb9ca0c8b64f
 * �Q�� : �u������̌������@�ɂ�鑬�x���v (Qiita) http://qiita.com/ampersand/items/0322e0820badf2c020be
 * �Q�� : �󕶎���ŏ���������ɂ� : �u������̏������v (��𓮂����Ă��������������� C++ ������N���X std::string ����) http://vivi.dyndns.org/tech/cpp/string.html
 * �Q�� : �ulambda���������Ƃ��Ď󂯎��֐��̎���͂ł��܂����H�v (Teratail) https://teratail.com/questions/37610
 */
namespace UtilFile
{
	/**
	 * �t�@�C���֕�����������o���܂��B
	 */
	void Write(std::string filename, std::string contents);

	/**
	 * �t�@�C�����當�����ǂݎ��܂��B
	 */
	bool Read(std::string filename, std::string& contents);
}

