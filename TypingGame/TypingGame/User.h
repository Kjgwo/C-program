#ifndef __USER_H_
#define __USER_H_

#include "Header.h"

class User {
public: 
	// ���ϸ�
	std::string username;

	// ���Ÿ�ڼӵ�
	float avgSpeed = 0.0f;

	// Ÿ�ڹ����� �󸶳� �Է��ߴ���
	int typingCount = 0;

	User(const std::string& username);
	void save();
	void load();

	void printUserInfo();
};
#endif '!__USER_H_'
