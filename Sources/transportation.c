#include <stdio.h>

int main() {
	char location[7] = { "" };  // �������� �����ϴ� ����

	// �� ������ �Է� �ޱ�
	printf("���߱��� ���� ���α׷��� �����մϴ�.\n");
	printf("������ �������� �Է����ּ���.(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
	scanf_s("%s", location, (int)sizeof(location));
	printf("������ �������� %s�Դϴ�.\n", location);

	while (1) {
		int menu = -1;  // �Է��� �޴� ��ȣ�� �����ϴ� ����

		// ���� �޴� ����
		printf("-------------------\n");
		printf("�޴��� �Է����ּ���\n");
		printf("1. ������ ����\n2. �����ϱ�\n3. ���� ���� �� ���� ���� Ȯ��\n4. ����\n");
		printf("-------------------\n");
		scanf_s("%d", &menu);

		int terminate = 0;  // ���α׷� ���Ḧ ���� ����
		char destination[7] = { "" };  // �������� �����ϴ� ����
		int time = 0;  // �̵��ϴµ� �ɸ��� �ð��� �����ϴ� ����
		int date[3] = { 0 };  // ��¥�� �Է¹޴� ����

		switch (menu) {
		case 1:
			printf("�����ϰ���� ������ �������� �Է����ּ���.\n(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
			scanf_s("%s", location, (int)sizeof(location));
			printf("������ �������� %s(��)�� ����Ǿ����ϴ�.\n", location);
			break;
		case 2:
			printf("���Ͻô� �������� �Է����ּ���.\n(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
			scanf_s("%s", destination, (int)sizeof(destination));
			if (location == destination) {
				printf("���������� �ɸ��� �ð��� �Է����ּ���.\n");
				scanf_s("%d", &time);
			}
			else {
				printf("��¥�� �Է����ּ���.(���� ����)\n");
				scanf_s("%d %d %d", &date[0], &date[1], &date[2]);
				printf("%d %d %d", date[0], date[1], date[2]);
			}

			break;
		case 3:
			break;
		case 4:
			terminate = 1;
			break;
		default:
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �������ּ���.\n");
		}

		if (terminate == 1) {
			printf("���α׷��� �����մϴ�.");
			break;
		}
	}

}