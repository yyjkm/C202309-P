#include <stdio.h>

int main() {
	char location[7] = { "" };  // �������� �����ϴ� ����
	char* location_ptr = &location;

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
		int distance = 0;  // �̵��ϴµ� �ɸ��� �ð��� �����ϴ� ����
		int date[3] = { 0 };  // ��¥�� �Է¹޴� ����
		char destination[7] = { "" };  // �������� �����ϴ� ����
		char transportation[8] = { "" };  // ��������� �����ϴ� ����

		char* destination_ptr = &destination;

		switch (menu) {
		case 1:  // 1.������ ����
			printf("�����ϰ���� ������ �������� �Է����ּ���.\n(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
			scanf_s("%s", location, (int)sizeof(location));
			printf("������ �������� %s(��)�� ����Ǿ����ϴ�.\n", location);
			break;
		case 2:  // 2.�����ϱ�
			printf("���Ͻô� �������� �Է����ּ���.\n(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
			scanf_s("%s", destination, (int)sizeof(destination));  // ������� ������ �Է¹ޱ�
			// �������� �������� ���� ���
			if (*location_ptr == *destination_ptr) {
				printf("���ϴ� ���������� �ɸ��� �Ÿ��� �Է����ּ���.(m ������)\n");
				scanf_s("%d", &distance);  // ���������� �ɸ��� �Ÿ� �Է¹ޱ�

				printf("���Ͻô� ��������� �������ּ���.(�ý�, ����ö)\n");
				scanf_s("s", transportation, (int)sizeof(transportation));  // ����ڰ� ���ϴ� ������� �Է¹ޱ�

				if (transportation == "�ý�") {
					double price = 4300 + (distance % 150) * 100;  // �⺻��ݿ� �Է¹��� �Ÿ����� 150m�� 100���� ���ϴ� ����
				}
				else if (transportation == "����ö") {
					int price = 1250;  // �⺻���
					if (distance > 10000 && distance < 50000) {
						price += ((distance - 10000) / 5000) * 100;  // 10km �ʰ� �� �� �⺻��ݿ� 5km�� 100���� ���ϴ� ����
					}
					else if (distance >= 50000) {
						price += ((distance - 50000) / 8000) * 100;  // 50km �ʰ� �� �� �⺻��ݿ� 8km�� 100���� ���ϴ� ����
					}
				}
			}
			// �������� �������� �ٸ� ���
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