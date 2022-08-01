#ifndef __USER_H_
#define __USER_H_

#include "Header.h"

class User {
public: 
	// 파일명
	std::string username;

	// 평균타자속도
	float avgSpeed = 0.0f;

	// 타자문장을 얼마나 입력했는지
	int typingCount = 0;

	User(const std::string& username);
	void save();
	void load();

	void printUserInfo();
};
#endif '!__USER_H_'
