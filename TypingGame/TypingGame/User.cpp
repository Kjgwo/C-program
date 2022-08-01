#include "User.h"

User::User(const std::string& username) {
	this->username = username;

	FILE* fp = fopen(username.c_str(), "r");
	bool exists = fp != nullptr;

	if (exists) fclose(fp);

	if (exists) {
		putStringOnPosition(6, 5, "사용자가 존재합니다... 불러오는중...");
		load();
		putStringOnPosition(6, 6, "계속하려면 엔터를 입력해 주세요");
		fseek(stdin, 0, SEEK_END);
		fgetc(stdin);
	}
	else {
		putStringOnPosition(6, 5, "사용자가 존재하지 않습니다... 새로 만드는중...");
		save();
		putStringOnPosition(6, 6, "계속하려면 엔터를 입력해 주세요");
		fseek(stdin, 0, SEEK_END);
		fgetc(stdin);
	}
	
}

void User::save()
{
	FILE* outfile = fopen(username.c_str(), "w");
	fprintf(outfile, "%f\n", avgSpeed);
	fprintf(outfile, "%d", typingCount);

	fclose(outfile);
}

void User::load()
{
	FILE* infile = fopen(username.c_str(), "r");
	fscanf(infile, "%f", &avgSpeed);
	fgetc(infile);
	fscanf(infile, "%d", &typingCount);
	fgetc(infile);

	fclose(infile);
}

void User::printUserInfo()
{
	char avgSpeed[50];
	sprintf(avgSpeed, "평균타수: %f", this->avgSpeed);

	char count[50];
	sprintf(count, "타이핑 횟수: %d", this->typingCount);
	putStringOnPosition(6, 6, avgSpeed);
	putStringOnPosition(6, 7, count);
	putStringOnPosition(6, 8, "계속 하려면 엔터키를 눌러주세요");
	fseek(stdin, 0, SEEK_END);
	fgetc(stdin);
}
