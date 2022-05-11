#include "Header.h";


int main() {

	char mbti[5] = { 0, }; // 마지막 \n이 들어가므로 5의 크기의 배열 생성
	
	int quest1 = 0;
	int quest2 = 1;
			
	test_I_E();
	test_S_N();
	test_T_F();
	test_J_P();

	getResult(mbti);
	printResult(mbti);

	return 0;
 }

void test_I_E() {
	printf("1 번째 문항입니다.\n");
	question("나는 처음 보는 사람에게 자신을 소개하는 것이 두렵지 않다", score_I_E, 0);
	printf("2 번째 문항입니다.\n");
	question("내가 스트레스를 푸는 방법은 사람들을 만나는 것이다", score_I_E, 0);
	printf("3 번째 문항입니다.\n");
	question("대화를 시작하기보다 맞장구 치는걸 좋아한다", score_I_E, 1);
	printf("4 번째 문항입니다.\n");
	question("술자리에서 노는것 보다 집에서 게임하는게 좋다", score_I_E, 1);
}

void test_S_N() {
	printf("5 번째 문항입니다.\n");
	question("업무를 하거나 과제를 할 때 계획을 먼저 세운다", score_S_N, 0);
	printf("6 번째 문항입니다.\n");
	question("가끔 번뜩이는 아이디어가 생각나 메모를 하곤 한다", score_S_N, 0);
	printf("7 번째 문항입니다.\n");
	question("가끔 비현실적인 망상을 하는 편 이다", score_S_N, 0);
	printf("8 번째 문항입니다.\n");
	question("나는 내성적인 성격이다", score_S_N, 0);
}

void test_T_F() {
	printf("9 번째 문항입니다.\n");
	question("상대방의 고민을 들어줄 때 원인을 찾기보다 공감을 해주는 편 이다", score_T_F, 0);
	printf("10 번째 문항입니다.\n");
	question("어떤 이유에서건 상대방의 기분을 먼저 생각해야 한다", score_T_F, 0);
	printf("11 번째 문항입니다.\n");
	question("다른 사람들이 나를 어떻게 생각하는지 지나치게 생각한다", score_T_F, 0);
	printf("12 번째 문항입니다.\n");
	question("영화나 드라마가 뮤지컬이나 예술작품보다 더 많은 영감을 준다", score_T_F, 1);
}

void test_J_P() {
	printf("13 번째 문항입니다.\n");
	question("방 정리가 되어있지 않으면 일을 시작할 수 없다", score_J_P, 1);
	printf("14 번째 문항입니다.\n");
	question("과제나 업무는 최대한 미루었다가 한꺼번에 하는 편 이다", score_J_P, 0);
	printf("15 번째 문항입니다.\n");
	question("호기심은 나를 움직이는 원동력이다", score_J_P, 0);
	printf("16 번째 문항입니다.\n");
	question("프리랜서가 회사원보다 더 나은 삶을 살고 있다고 생각한다", score_J_P, 0);
}

void question(const char* quest, int score, int qst) {
	printf("%s", quest);
	if (qst == 0) {
		score += dis1(getInput());
	}
	else {
		score += dis2(getInput());
	}

}

int getInput() {

	int input;

	printf("\n강한 부정(1)  약한 부정(2)  약한 긍정(3)  강한 긍정(4)  \n");
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);
	if (input < 1 || input > 4) {
		printf("잘못된 입력");
		getInput();
	}

	return input;

}

int dis1(int input) {
	
	if (input == 1) {
		return -3;
	}
	else if (input == 2) {
		return -1;
	}
	else if (input == 3) {
		return 1;

	}
	else  {
		return 3;
	}

}

int dis2(int input) {

	if (input == 1) {
		return 3;
	}
	else if (input == 2) {
		return 1;
	}
	else if (input == 3) {
		return -1;

	}
	else {
		return -3;
	}

}

void getResult(char* mbti) {
	if (score_I_E > 0) {
		mbti[0] = 'E';
	}
	else {
		mbti[0] = 'I';
	}
	if (score_S_N > 0) {
		mbti[1] = 'N';
	}
	else {
		mbti[1] = 'S';
	}
	if (score_T_F > 0) {
		mbti[2] = 'F';
	}
	else {
		mbti[2] = 'T';
	}
	if (score_J_P > 0) {
		mbti[3] = 'J';
	}
	else {
		mbti[3] = 'P';
	}
}

void printResult(char* mbti) {

	if (strcmp(mbti, "ISTJ") == 0) {
		printf("1. ISTJ\n당신은 논리주의자 입니다.사실에 대하여 정확하고 체계적으로 기억하며 신중하고 책임감이 있습니다.\n인물: 퓨디파이");
	}
	else if (strcmp(mbti, "ISFJ") == 0) {
		printf("2. ISFJ\n당신은 조용하고 차분하며 친근합니다.가장 믿음직스러운 사람입니다.\n인물 : 태연(가수)");
	}
	else if (strcmp(mbti, "INFJ") == 0) {
		printf("3. INFJ\n당신은 인내심이 많고 사람들을 좋아합니다.눈치가 빠르고 영감이 있습니다.\n인물 : J.K.롤링(해리포터 작가)");
	}
	else if (strcmp(mbti, "INTJ") == 0) {
		printf("4. INTJ\n당신은 논리적이고 효율성을 중시하는 냉철한 사람입니다.\n인물 : 진용진(유튜버)");
	}
	else if (strcmp(mbti, "ISTP") == 0) {
		printf("5. ISTP\n조용하고 과묵하고 손재주가 있는 공학자 스타일 입니다.\n인물 : 박명수(연예인)");
	}
	else if (strcmp(mbti, "ISFP") == 0) {
		printf("6. ISFP\n다정하고 착하고 상대방에 대한 배려심이 많습니다.주위 사람들에게 많이 휩쓸리는 성격입니다\n인물 : 정국(가수, BTS)");
	}
	else if (strcmp(mbti, "INFP") == 0) {
		printf("7. INFP\n당신은 정열적이고 완벽을 추구하며 유토피아를 추구하는 성격입니다.\n인물 : 셰익스피어(작가)");
	}
	else if (strcmp(mbti, "INTP") == 0) {
		printf("8. INTP\n당신은 조용하고 과묵하며 상상을 즐기는 사색가 입니다.사회성이 부족하다는 말을 많이 듣습니다.\n인물 : 아인슈타인(과학자)");
	}
	else if (strcmp(mbti, "ESTP") == 0) {
		printf("9. ESTP\n당신은 활동하는 것을 좋아하는 사업가형 입니다.\n인물 : 존 F 케네디(미국의 전 대통령)");
	}
	else if (strcmp(mbti, "ESFP") == 0) {
		printf("10. ESFP\n당신은 자유로운 영혼을 갖고있는 연예인 스타일입니다.\n인물 : 비(가수)");
	}
	else if (strcmp(mbti, "ENFP") == 0) {
		printf("11. ENFP\n당신은 넘치는 상상력을 바탕으로 항상 새로운 가능성을 찾아보는 탐험가입니다.\n인물 : 대도서관(유튜버, 방송인)");
	}
	else if (strcmp(mbti, "ENTP") == 0) {
		printf("12. ENTP\n당신은 논쟁을 즐기며 사람을 만나는 것을 좋아합니다.\n인물 : 서새봄(스트리머)");
	}
	else if (strcmp(mbti, "ESTJ") == 0) {
		printf("13. ESTJ\n현실적 구체적이고 사실적이며 조직을 이끌어나가는 리더형 입니다.\n인물 : 허경영(정치인)");
	}
	else if (strcmp(mbti, "ESFJ") == 0) {
		printf("14. ESFJ\n동정심이 많고 다른 사람에게 관심을 주는 것을 좋아하며 협력을 조항하고 동료애가 끈끈합니다.\n인물 : 김남주(가수)");
	}
	else if (strcmp(mbti, "ENFJ") == 0) {
		printf("15. ENFJ\n당신은 따뜻하고 적극적이며 사교성이 풍부하고 이타적입니다.\n인물 : 신세경(연예인)");
	}
	else if (strcmp(mbti, "ENTJ") == 0) {
		printf("16. ENTJ\n당신은 열정적이며 솔직하고 지도력과 통솔력이 있습니다.활동적이고 장기적인 계획을 좋아합니다.\n인물 : 고든 램지(요리인, 방송인)");
	}
	else {
		printf("성격유형 검사로 도출되지 않습니다");
	}
}



