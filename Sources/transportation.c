#include <stdio.h>

#define MAX_RESERVATIONS 10  //

typedef struct {
	char location[7];  // �������� �����ϴ� ����
	char destination[7];
	char transportation[100];
	int date[3];
	int distance;
	int price;
} Reservation;

int main() {
	int reservationCount = 0;  // ���ŵ� Ƚ���� �����ϴ� ����
	Reservation reservations[MAX_RESERVATIONS];  // ���� ���� ������ �����ϱ� ���� �迭

	// �� ������ �Է� �ޱ�
	printf("���߱��� ���� ���α׷��� �����մϴ�.\n");
	printf("������ �������� �Է����ּ���.(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
	scanf_s("%s", reservations[0].location, (int)sizeof(reservations[0].location));
	printf("������ �������� %s�Դϴ�.\n", reservations[0].location);

	while (1) {
		int menu = -1;  // �Է��� �޴� ��ȣ�� �����ϴ� ����

		// ���� �޴� ����
		printf("-------------------\n");
		printf("�޴��� �Է����ּ���\n");
		printf("1. ������ ����\n2. �����ϱ�\n3. ���� ���� �� ���� ���� Ȯ��\n4. ����\n");
		printf("-------------------\n");
		scanf_s("%d", &menu);

		int terminate = 0;  // ���α׷� ���Ḧ ���� ����

		switch (menu) {
		case 1:  // 1.������ ����
			printf("�����ϰ���� ������ �������� �Է����ּ���.\n(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
			scanf_s("%s", reservations[0].location, (int)sizeof(reservations[0].location));
			printf("������ �������� %s(��)�� ����Ǿ����ϴ�.\n", reservations[0].location);
			break;
		case 2:  // 2.�����ϱ�
			printf("���Ͻô� �������� �Է����ּ���.\n(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
			scanf_s("%s", reservations[reservationCount].destination, (int)sizeof(reservations[reservationCount].destination));  // ������� ������ �Է¹ޱ�
			// �������� �������� ���� ���
			if (strcmp(reservations[0].location, reservations[reservationCount].destination) == 0) {
				do {
					printf("���Ͻô� ��������� �������ּ���.(�ý�, ����ö)\n");
					scanf_s("%s", reservations[reservationCount].transportation, (int)sizeof(reservations[reservationCount].transportation));  // ����ڰ� ���ϴ� ������� �Է¹ޱ�

					if (stricmp(reservations[reservationCount].transportation, "�ý�") != 0 && stricmp(reservations[reservationCount].transportation, "����ö") != 0) {
						// �ý�, ����ö�� �Է����� �ʾ��� ���
						printf("��ȿ���� ���� ��������Դϴ�. �ٽ� �Է����ּ���.\n");
					}
				} while (stricmp(reservations[reservationCount].transportation, "�ý�") != 0 && stricmp(reservations[reservationCount].transportation, "����ö") != 0);

				printf("���ϴ� ���������� �ɸ��� �Ÿ��� �Է����ּ���.(m ������)\n");
				scanf_s("%d", &reservations[reservationCount].distance);  // ���������� �ɸ��� �Ÿ� �Է¹ޱ�

				if (stricmp(reservations[reservationCount].transportation, "�ý�") == 0) {
					reservations[reservationCount].price = 4300 + ((reservations[reservationCount].distance / 150) * 100);
					printf("%s�� %dm �̵��Ͽ� %d�� �����Ǿ����ϴ�.\n", reservations[reservationCount].transportation, reservations[reservationCount].distance, reservations[reservationCount].price);
				}
				else if (stricmp(reservations[reservationCount].transportation, "����ö") == 0) {
					reservations[reservationCount].price = 1250;
					if (reservations[reservationCount].distance > 10000 && reservations[reservationCount].distance < 50000) {
						reservations[reservationCount].price += ((reservations[reservationCount].distance - 10000) / 5000) * 100;
					}
					else if (reservations[reservationCount].distance >= 50000) {
						reservations[reservationCount].price += ((reservations[reservationCount].distance - 50000) / 8000) * 100;
					}
					printf("%s�� %dm �̵��Ͽ� %d�� �����Ǿ����ϴ�.\n", reservations[reservationCount].transportation, reservations[reservationCount].distance, reservations[reservationCount].price);
				}
				reservationCount++;  // ���� Ƚ�� ����
			}
			// �������� �������� �ٸ� ���
			else {
				printf("�̵��Ͻ� ��¥�� �Է����ּ���.(��, ��, ��,���� ����)\n");
				scanf_s("%d %d %d", &reservations[reservationCount].date[0], &reservations[reservationCount].date[1], &reservations[reservationCount].date[2]);

				do {
					printf("���Ͻô� ��������� �������ּ���.(��ӹ���, ����)\n");
					scanf_s("%s", reservations[reservationCount].transportation, (int)sizeof(reservations[reservationCount].transportation));  // ����ڰ� ���ϴ� ������� �Է¹ޱ�

					if (stricmp(reservations[reservationCount].transportation, "��ӹ���") != 0 && stricmp(reservations[reservationCount].transportation, "����") != 0) {
						// �ý�, ����ö�� �Է����� �ʾ��� ���
						printf("��ȿ���� ���� ��������Դϴ�. �ٽ� �Է����ּ���.\n");
					}
				} while (stricmp(reservations[reservationCount].transportation, "��ӹ���") != 0 && stricmp(reservations[reservationCount].transportation, "����") != 0);

				if (stricmp(reservations[reservationCount].transportation, "��ӹ���") == 0) {
					reservations[reservationCount].price = 20000;
					printf("%d�� �����Ǿ����ϴ�.\n", reservations[reservationCount].price);
				}
				else if (stricmp(reservations[reservationCount].transportation, "����ö") == 0) {
					reservations[reservationCount].price = 50000;
					printf("%d�� �����Ǿ����ϴ�.\n", reservations[reservationCount].price);
				}
				reservationCount++;  // ���� Ƚ�� ����
			}
			break;
		case 3:
			printf("������ ������ Ȯ���մϴ�.\n");

			if (reservationCount > 0) {
				printf("---------- ���� ���� ----------\n");
				for (int i = 0; i < reservationCount; i++) {
					printf("���� ��ȣ: %d\n", i + 1);
					printf("������: %s\n", reservations[0].location);
					printf("������: %s\n", reservations[i].destination);
					printf("�̵� ��¥: %d�� %d�� %d��\n", reservations[i].date[0], reservations[i].date[1], reservations[i].date[2]);
					printf("�������: %s\n", reservations[i].transportation);
					printf("�̵� �Ÿ�: %dm\n", reservations[i].distance);
					printf("���� �ݾ�: %d��\n", reservations[i].price);
					printf("-----------------------------\n");
				}
			}
			else {
				printf("���ŵ� ������ �����ϴ�.\n");
			}
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