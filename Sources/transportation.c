#include <stdio.h>
#define MAX_RESERVATIONS 10  // �� ���� ������ Ƚ��

typedef struct {
	char location[100];  // �������� �����ϴ� ����
	char destination[100];  // �������� �����ϴ� ����
	char transportation[100];  // ��������� �����ϴ� ����
	int date[3];  // ��¥�� �����ϴ� ����
	int distance;  // �Ÿ��� �����ϴ� ����
	int price;  // ������ �����ϴ� ����
} Reservation;

// ���� ��� �Լ�
void cancelReservation(Reservation reservations[], int* reservationCount) {
	int cancelIndex;
	printf("����� ���� ��ȣ�� �Է��ϼ���: ");
	scanf_s("%d", &cancelIndex);

	// ���� ��ȣ�� ��ȿ�� ���� ���� �ִ��� Ȯ��
	if (cancelIndex >= 1 && cancelIndex <= *reservationCount) {
		// ������ ���� ������ �����ϰ� ������ ������ ����Ʈ
		for (int i = cancelIndex - 1; i < *reservationCount - 1; i++) {
			strcpy_s(reservations[i].location, sizeof(reservations[i].location), reservations[i + 1].location);
			strcpy_s(reservations[i].destination, sizeof(reservations[i].destination), reservations[i + 1].destination);
			strcpy_s(reservations[i].transportation, sizeof(reservations[i].transportation), reservations[i + 1].transportation);
			reservations[i].date[0] = reservations[i + 1].date[0];
			reservations[i].date[1] = reservations[i + 1].date[1];
			reservations[i].date[2] = reservations[i + 1].date[2];
			reservations[i].distance = reservations[i + 1].distance;
			reservations[i].price = reservations[i + 1].price;
		}
		(*reservationCount)--;
		printf("���Ű� ��ҵǾ����ϴ�.\n");
	}
	else {
		printf("��ȿ���� ���� ���� ��ȣ�Դϴ�.\n");
	}
}

int main() {
	int reservationCount = 0;  // ���ŵ� Ƚ���� �����ϴ� ����
	Reservation reservations[MAX_RESERVATIONS];  // ���� ���� ������ �����ϱ� ���� �迭
	// �� ������ �Է� �ޱ�
	printf("���߱��� ���� ���α׷��� �����մϴ�.\n");
	printf("������ ������� �Է����ּ���.(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
	scanf_s("%s", reservations[reservationCount].location, (int)sizeof(reservations[reservationCount].location));
	printf("������ ������� %s�Դϴ�.\n", reservations[reservationCount].location);

	while (1) {
		int menu = -1;  // �Է��� �޴� ��ȣ�� �����ϴ� ����

		// ���� �޴� ����
		printf("-------------------\n");
		printf("�޴��� �Է����ּ���\n");
		printf("1. ����� ����\n2. �����ϱ�\n3. ���� ���\n4. ���� ���� �� ���� ���� Ȯ��\n5. ����\n");
		printf("-------------------\n");
		scanf_s("%d", &menu);

		int terminate = 0;  // ���α׷� ���Ḧ ���� ����

		switch (menu) {
		case 1:  // 1.������ ����
			printf("�����ϰ���� ������ ������� �Է����ּ���.\n(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
			scanf_s("%s", reservations[reservationCount].location, (int)sizeof(reservations[reservationCount].location));
			printf("������ ������� %s(��)�� ����Ǿ����ϴ�.\n", reservations[reservationCount].location);
			break;
		case 2:  // 2.�����ϱ�
			printf("���Ͻô� �������� �Է����ּ���.\n(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
			scanf_s("%s", reservations[reservationCount].destination, (int)sizeof(reservations[reservationCount].destination));  // ����ڷκ��� ������ �Է¹ޱ�
			// �������� �������� ���� ���
			if (strcmp(reservations[reservationCount].location, reservations[reservationCount].destination) == 0) {
				do {
					printf("���Ͻô� ��������� �������ּ���.(�ý�, ����ö)\n");
					scanf_s("%s", reservations[reservationCount].transportation, (int)sizeof(reservations[reservationCount].transportation));  // ����ڷκ��� ���ϴ� ������� �Է¹ޱ�

					// �ý�, ����ö�� �Է����� �ʾ��� ���
					if (stricmp(reservations[reservationCount].transportation, "�ý�") != 0 && stricmp(reservations[reservationCount].transportation, "����ö") != 0) {
						printf("��ȿ���� ���� ��������Դϴ�. �ٽ� �Է����ּ���.\n");
					}
				} while (stricmp(reservations[reservationCount].transportation, "�ý�") != 0 && stricmp(reservations[reservationCount].transportation, "����ö") != 0);

				printf("���ϴ� ���������� �ɸ��� �Ÿ��� �Է����ּ���.(m ������)\n");
				scanf_s("%d", &reservations[reservationCount].distance);  // ����ڷκ��� ���������� �ɸ��� �Ÿ� �Է¹ޱ�

				// ��������� �ý��� ���
				if (stricmp(reservations[reservationCount].transportation, "�ý�") == 0) {
					reservations[reservationCount].price = 4300 + ((reservations[reservationCount].distance / 150) * 100);  // �⺻��� 4300���� 150m�� 100�� �߰�
					printf("%s�� %dm �̵��Ͽ� %d�� �����Ǿ����ϴ�.\n", reservations[reservationCount].transportation, reservations[reservationCount].distance, reservations[reservationCount].price);
				}
				// ��������� ����ö�� ���
				else if (stricmp(reservations[reservationCount].transportation, "����ö") == 0) {
					reservations[reservationCount].price = 1250;  // �⺻��� 1250�� 
					if (reservations[reservationCount].distance > 10000 && reservations[reservationCount].distance < 50000) {
						reservations[reservationCount].price += ((reservations[reservationCount].distance - 10000) / 5000) * 100;  // �Ÿ��� 10km �ʰ� 50km �̸��� ��� 5km�� 100�� �߰�
					}
					if (reservations[reservationCount].distance >= 50000) {
						reservations[reservationCount].price = 2050;
						reservations[reservationCount].price += ((reservations[reservationCount].distance - 50000) / 8000) * 100;
					}  // �Ÿ��� 50km �̻� �� ��� 8km�� 100�� �߰�
					printf("%s�� %dm �̵��Ͽ� %d�� �����Ǿ����ϴ�.\n", reservations[reservationCount].transportation, reservations[reservationCount].distance, reservations[reservationCount].price);
				}
				strcpy_s(reservations[reservationCount + 1].location, sizeof(reservations[reservationCount + 1].location), reservations[reservationCount].location);
				reservationCount++;  // ���� Ƚ�� ����
			}
			// �������� �������� �ٸ� ���
			else {
				// ����ڷκ��� �̵��� ��¥ �Է¹ޱ�
				do {
					printf("�̵��Ͻ� ��¥�� �Է����ּ���.(��, ��, ��,���� ����)\n");
					scanf_s("%d %d %d", &reservations[reservationCount].date[0], &reservations[reservationCount].date[1], &reservations[reservationCount].date[2]);

					if (reservations[reservationCount].date[0] != 2023 && reservations[reservationCount].date[0] != 2024) {
						printf("2023��~2024�� ���� ��¥�� �Է����ּ���.\n");
					}
				} while ((reservations[reservationCount].date[0] != 2023 && reservations[reservationCount].date[0] != 2024) || (reservations[reservationCount].date[1] > 12 && reservations[reservationCount].date[1] < 0));

				do {
					printf("���Ͻô� ��������� �������ּ���.(��ӹ���, ����)\n");
					scanf_s("%s", reservations[reservationCount].transportation, (int)sizeof(reservations[reservationCount].transportation));  // ����ڰ� ���ϴ� ������� �Է¹ޱ�

					if (stricmp(reservations[reservationCount].transportation, "��ӹ���") != 0 && stricmp(reservations[reservationCount].transportation, "����") != 0) {
						// ��ӹ���, ������ �Է����� �ʾ��� ���
						printf("��ȿ���� ���� ��������Դϴ�. �ٽ� �Է����ּ���.\n");
					}
				} while (stricmp(reservations[reservationCount].transportation, "��ӹ���") != 0 && stricmp(reservations[reservationCount].transportation, "����") != 0);

				// ��������� ��ӹ����� ���
				if (stricmp(reservations[reservationCount].transportation, "��ӹ���") == 0) {
					reservations[reservationCount].price = 20000;
					printf("%d�� �����Ǿ����ϴ�.\n", reservations[reservationCount].price);
				}
				// ��������� ������ ���
				else if (stricmp(reservations[reservationCount].transportation, "����") == 0) {
					reservations[reservationCount].price = 50000;
					printf("%d�� �����Ǿ����ϴ�.\n", reservations[reservationCount].price);
				}
				strcpy_s(reservations[reservationCount + 1].location, sizeof(reservations[reservationCount + 1].location), reservations[reservationCount].location);
				reservationCount++;  // ���� Ƚ�� ����
			}
			break;
		case 3:  // 5. ���� ����ϱ�
			if (reservationCount == 0) {
				printf("������ ������ �����ϴ�.\n");
				break;
			}
			else {
				cancelReservation(reservations, &reservationCount);
				break;
			}
		case 4:
			printf("������ ������ Ȯ���մϴ�.\n");
			if (reservationCount > 0) {
				for (int i = 0; i < reservationCount; i++) {
					if (strcmp(reservations[i].location, reservations[i].destination) == 0) {
						printf("---------- ���� ���� ----------\n");
						printf("���� ��ȣ: %d\n", i + 1);
						printf("�����: %s\n", reservations[i].location);
						printf("�������: %s\n", reservations[i].transportation);
						printf("�̵� �Ÿ�: %dm\n", reservations[i].distance);
						printf("���� �ݾ�: %d��\n", reservations[i].price);
						printf("-----------------------------\n");
					}
					else {
						printf("---------- ���� ���� ----------\n");
						printf("���� ��ȣ: %d\n", i + 1);
						printf("�����: %s\n", reservations[i].location);
						printf("������: %s\n", reservations[i].destination);
						printf("�̵� ��¥: %d�� %d�� %d��\n", reservations[i].date[0], reservations[i].date[1], reservations[i].date[2]);
						printf("�������: %s\n", reservations[i].transportation);
						printf("���� �ݾ�: %d��\n", reservations[i].price);
						printf("-----------------------------\n");
					}
				}
			}
			else {
				printf("���ŵ� ������ �����ϴ�.\n");
			}
			break;
		case 5:
			terminate = 1;
			break;
		default:
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �������ּ���.\n");
		}

		if (terminate == 1) {
			printf("���α׷��� �����մϴ�.");
			break;
		}
		if (reservationCount == 10) {
			printf("�ִ� ���� ���� Ƚ�� 10���� �� á���Ƿ� ���α׷��� �����մϴ�.\n");
			break;  // ���� Ƚ���� 10���� �� ���� ���α׷� ����
		}
	}

}