#include "Header.h";


int main() {

	char mbti[5] = { 0, }; // ������ \n�� ���Ƿ� 5�� ũ���� �迭 ����
	
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
	printf("1 ��° �����Դϴ�.\n");
	question("���� ó�� ���� ������� �ڽ��� �Ұ��ϴ� ���� �η��� �ʴ�", score_I_E, 0);
	printf("2 ��° �����Դϴ�.\n");
	question("���� ��Ʈ������ Ǫ�� ����� ������� ������ ���̴�", score_I_E, 0);
	printf("3 ��° �����Դϴ�.\n");
	question("��ȭ�� �����ϱ⺸�� ���屸 ġ�°� �����Ѵ�", score_I_E, 1);
	printf("4 ��° �����Դϴ�.\n");
	question("���ڸ����� ��°� ���� ������ �����ϴ°� ����", score_I_E, 1);
}

void test_S_N() {
	printf("5 ��° �����Դϴ�.\n");
	question("������ �ϰų� ������ �� �� ��ȹ�� ���� �����", score_S_N, 0);
	printf("6 ��° �����Դϴ�.\n");
	question("���� �����̴� ���̵� ������ �޸� �ϰ� �Ѵ�", score_S_N, 0);
	printf("7 ��° �����Դϴ�.\n");
	question("���� ���������� ������ �ϴ� �� �̴�", score_S_N, 0);
	printf("8 ��° �����Դϴ�.\n");
	question("���� �������� �����̴�", score_S_N, 0);
}

void test_T_F() {
	printf("9 ��° �����Դϴ�.\n");
	question("������ ����� ����� �� ������ ã�⺸�� ������ ���ִ� �� �̴�", score_T_F, 0);
	printf("10 ��° �����Դϴ�.\n");
	question("� ���������� ������ ����� ���� �����ؾ� �Ѵ�", score_T_F, 0);
	printf("11 ��° �����Դϴ�.\n");
	question("�ٸ� ������� ���� ��� �����ϴ��� ����ġ�� �����Ѵ�", score_T_F, 0);
	printf("12 ��° �����Դϴ�.\n");
	question("��ȭ�� ��󸶰� �������̳� ������ǰ���� �� ���� ������ �ش�", score_T_F, 1);
}

void test_J_P() {
	printf("13 ��° �����Դϴ�.\n");
	question("�� ������ �Ǿ����� ������ ���� ������ �� ����", score_J_P, 1);
	printf("14 ��° �����Դϴ�.\n");
	question("������ ������ �ִ��� �̷���ٰ� �Ѳ����� �ϴ� �� �̴�", score_J_P, 0);
	printf("15 ��° �����Դϴ�.\n");
	question("ȣ����� ���� �����̴� �������̴�", score_J_P, 0);
	printf("16 ��° �����Դϴ�.\n");
	question("���������� ȸ������� �� ���� ���� ��� �ִٰ� �����Ѵ�", score_J_P, 0);
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

	printf("\n���� ����(1)  ���� ����(2)  ���� ����(3)  ���� ����(4)  \n");
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);
	if (input < 1 || input > 4) {
		printf("�߸��� �Է�");
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
		printf("1. ISTJ\n����� �������� �Դϴ�.��ǿ� ���Ͽ� ��Ȯ�ϰ� ü�������� ����ϸ� �����ϰ� å�Ӱ��� �ֽ��ϴ�.\n�ι�: ǻ������");
	}
	else if (strcmp(mbti, "ISFJ") == 0) {
		printf("2. ISFJ\n����� �����ϰ� �����ϸ� ģ���մϴ�.���� ������������ ����Դϴ�.\n�ι� : �¿�(����)");
	}
	else if (strcmp(mbti, "INFJ") == 0) {
		printf("3. INFJ\n����� �γ����� ���� ������� �����մϴ�.��ġ�� ������ ������ �ֽ��ϴ�.\n�ι� : J.K.�Ѹ�(�ظ����� �۰�)");
	}
	else if (strcmp(mbti, "INTJ") == 0) {
		printf("4. INTJ\n����� �����̰� ȿ������ �߽��ϴ� ��ö�� ����Դϴ�.\n�ι� : ������(��Ʃ��)");
	}
	else if (strcmp(mbti, "ISTP") == 0) {
		printf("5. ISTP\n�����ϰ� �����ϰ� �����ְ� �ִ� ������ ��Ÿ�� �Դϴ�.\n�ι� : �ڸ��(������)");
	}
	else if (strcmp(mbti, "ISFP") == 0) {
		printf("6. ISFP\n�����ϰ� ���ϰ� ���濡 ���� ������� �����ϴ�.���� ����鿡�� ���� �۾����� �����Դϴ�\n�ι� : ����(����, BTS)");
	}
	else if (strcmp(mbti, "INFP") == 0) {
		printf("7. INFP\n����� �������̰� �Ϻ��� �߱��ϸ� �����ǾƸ� �߱��ϴ� �����Դϴ�.\n�ι� : ���ͽ��Ǿ�(�۰�)");
	}
	else if (strcmp(mbti, "INTP") == 0) {
		printf("8. INTP\n����� �����ϰ� �����ϸ� ����� ���� ����� �Դϴ�.��ȸ���� �����ϴٴ� ���� ���� ����ϴ�.\n�ι� : ���ν�Ÿ��(������)");
	}
	else if (strcmp(mbti, "ESTP") == 0) {
		printf("9. ESTP\n����� Ȱ���ϴ� ���� �����ϴ� ������� �Դϴ�.\n�ι� : �� F �ɳ׵�(�̱��� �� �����)");
	}
	else if (strcmp(mbti, "ESFP") == 0) {
		printf("10. ESFP\n����� �����ο� ��ȥ�� �����ִ� ������ ��Ÿ���Դϴ�.\n�ι� : ��(����)");
	}
	else if (strcmp(mbti, "ENFP") == 0) {
		printf("11. ENFP\n����� ��ġ�� ������ �������� �׻� ���ο� ���ɼ��� ã�ƺ��� Ž�谡�Դϴ�.\n�ι� : �뵵����(��Ʃ��, �����)");
	}
	else if (strcmp(mbti, "ENTP") == 0) {
		printf("12. ENTP\n����� ������ ���� ����� ������ ���� �����մϴ�.\n�ι� : ������(��Ʈ����)");
	}
	else if (strcmp(mbti, "ESTJ") == 0) {
		printf("13. ESTJ\n������ ��ü���̰� ������̸� ������ �̲������ ������ �Դϴ�.\n�ι� : ��濵(��ġ��)");
	}
	else if (strcmp(mbti, "ESFJ") == 0) {
		printf("14. ESFJ\n�������� ���� �ٸ� ������� ������ �ִ� ���� �����ϸ� ������ �����ϰ� ����ְ� �����մϴ�.\n�ι� : �賲��(����)");
	}
	else if (strcmp(mbti, "ENFJ") == 0) {
		printf("15. ENFJ\n����� �����ϰ� �������̸� �米���� ǳ���ϰ� ��Ÿ���Դϴ�.\n�ι� : �ż���(������)");
	}
	else if (strcmp(mbti, "ENTJ") == 0) {
		printf("16. ENTJ\n����� �������̸� �����ϰ� �����°� ��ַ��� �ֽ��ϴ�.Ȱ�����̰� ������� ��ȹ�� �����մϴ�.\n�ι� : ��� ����(�丮��, �����)");
	}
	else {
		printf("�������� �˻�� ������� �ʽ��ϴ�");
	}
}



