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

// ����� ���� �Լ�
void changeLocation(Reservation reservations[], int reservationCount) {
	printf("�����ϰ���� ������ ������� �Է����ּ���.\n(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
	scanf_s("%s", reservations[reservationCount].location, (int)sizeof(reservations[reservationCount].location));
	printf("������ ������� %s(��)�� ����Ǿ����ϴ�.\n", reservations[reservationCount].location);
}
// �����ϱ� �Լ�
void makeReservation(Reservation reservations[], int* reservationCount) {
	// ���� ������ ������ ����ü�� �ε���
	int currentIndex = *reservationCount;

	// ������ �Է�
	printf("���Ͻô� �������� �Է����ּ���.\n(��, �λ�, �뱸, ��õ, ����, ����, ��� ������)\n");
	scanf_s("%s", reservations[currentIndex].destination, (int)sizeof(reservations[currentIndex].destination));

	// �������� �������� ������ Ȯ��
	if (strcmp(reservations[currentIndex].location, reservations[currentIndex].destination) == 0) {
		// ������� ����
		do {
			printf("���Ͻô� ��������� �������ּ���.(�ý�, ����ö)\n");
			scanf_s("%s", reservations[currentIndex].transportation, (int)sizeof(reservations[currentIndex].transportation));

			// �ý�, ����ö�� �Է����� �ʾ��� ���
			if (stricmp(reservations[currentIndex].transportation, "�ý�") != 0 && stricmp(reservations[currentIndex].transportation, "����ö") != 0) {
				printf("��ȿ���� ���� ��������Դϴ�. �ٽ� �Է����ּ���.\n");
			}
		} while (stricmp(reservations[currentIndex].transportation, "�ý�") != 0 && stricmp(reservations[currentIndex].transportation, "����ö") != 0);

		// �Ÿ� �Է�
		printf("���ϴ� ���������� �ɸ��� �Ÿ��� �Է����ּ���.(m ������)\n");
		scanf_s("%d", &reservations[currentIndex].distance);

		// ������ܿ� ���� ���� ���
		if (stricmp(reservations[currentIndex].transportation, "�ý�") == 0) {
			reservations[currentIndex].price = 4300 + ((reservations[currentIndex].distance / 150) * 100);
			printf("%s�� %dm �̵��Ͽ� %d�� �����Ǿ����ϴ�.\n", reservations[currentIndex].transportation, reservations[currentIndex].distance, reservations[currentIndex].price);
		}
		else if (stricmp(reservations[currentIndex].transportation, "����ö") == 0) {
			reservations[currentIndex].price = 1250;
			if (reservations[currentIndex].distance > 10000 && reservations[currentIndex].distance < 50000) {
				reservations[currentIndex].price += ((reservations[currentIndex].distance - 10000) / 5000) * 100;
			}
			if (reservations[currentIndex].distance >= 50000) {
				reservations[currentIndex].price = 2050;
				reservations[currentIndex].price += ((reservations[currentIndex].distance - 50000) / 8000) * 100;
			}
			printf("%s�� %dm �̵��Ͽ� %d�� �����Ǿ����ϴ�.\n", reservations[currentIndex].transportation, reservations[currentIndex].distance, reservations[currentIndex].price);
		}
	}
	else {
		// �̵��� ��¥ �Է�
		do {
			printf("�̵��Ͻ� ��¥�� �Է����ּ���.(��, ��, ��,���� ����)\n");
			scanf_s("%d %d %d", &reservations[currentIndex].date[0], &reservations[currentIndex].date[1], &reservations[currentIndex].date[2]);

			if (reservations[currentIndex].date[0] != 2023 && reservations[currentIndex].date[0] != 2024) {
				printf("2023��~2024�� ���� ��¥�� �Է����ּ���.\n");
			}
		} while ((reservations[currentIndex].date[0] != 2023 && reservations[currentIndex].date[0] != 2024) || (reservations[currentIndex].date[1] > 12 || reservations[currentIndex].date[1] < 0));

		// ������� ����
		do {
			printf("���Ͻô� ��������� �������ּ���.(��ӹ���, ����)\n");
			scanf_s("%s", reservations[currentIndex].transportation, (int)sizeof(reservations[currentIndex].transportation));

			if (stricmp(reservations[currentIndex].transportation, "��ӹ���") != 0 && stricmp(reservations[currentIndex].transportation, "����") != 0) {
				printf("��ȿ���� ���� ��������Դϴ�. �ٽ� �Է����ּ���.\n");
			}
		} while (stricmp(reservations[currentIndex].transportation, "��ӹ���") != 0 && stricmp(reservations[currentIndex].transportation, "����") != 0);

		// ������ܿ� ���� ���� ���
		if (stricmp(reservations[currentIndex].transportation, "��ӹ���") == 0) {
			reservations[currentIndex].price = 20000;
		}
		else if (stricmp(reservations[currentIndex].transportation, "����") == 0) {
			reservations[currentIndex].price = 50000;
		}
		printf("%d�� �����Ǿ����ϴ�.\n", reservations[currentIndex].price);
	}

	// ���� ���Ÿ� ���� �ʱ�ȭ
	strcpy_s(reservations[currentIndex + 1].location, sizeof(reservations[currentIndex + 1].location), reservations[currentIndex].location);
	(*reservationCount)++;
}
// ���� ��� �Լ�
void cancelReservation(Reservation reservations[], int* reservationCount) {
	int cancelIndex;
	printf("����� ���� ��ȣ�� �Է��ϼ���: ");
	scanf_s("%d", &cancelIndex);
	if (*reservationCount == 0) {
		printf("������ ������ �����ϴ�.\n");
	}
	else {
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

}
// ���� ���� Ȯ�� �Լ�
void showReservationInfo(Reservation reservations[], int reservationCount) {
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
		case 1:  // 1.����� ����
			changeLocation(reservations, reservationCount);
			break;
		case 2:  // 2.�����ϱ�
			makeReservation(reservations, &reservationCount);
			break;
		case 3:  // 3. ���� ���
			cancelReservation(reservations, &reservationCount);
			break;
		case 4:  // 4. ���� ���� �� ���� ���� Ȯ��
			showReservationInfo(reservations, reservationCount);
			break;
		case 5:  // 5. ���α׷� ����
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