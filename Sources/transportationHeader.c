#include <stdio.h>
#define MAX_RESERVATIONS 10  // �� ���� ������ Ƚ��

typedef struct {
	char location[100];  // �������� �����ϴ� ����
	char destination[100];  // �������� �����ϴ� ����
	char transportation[100];  // ��������� �����ϴ� ����
	int number;  // ������ ��ȣ�� �����ϴ� ����
	int date[3];  // ��¥�� �����ϴ� ����
	int distance;  // �Ÿ��� �����ϴ� ����
	int price;  // ������ �����ϴ� ����
} Reservation;
// ����� �Է� �Լ�
void enterLocation(Reservation* reservation) {
	printf("���߱��� ���� ���α׷��� �����մϴ�.\n");

	while (1) {
		printf("������ ������� �Է����ּ���. (1.�λ� 2.�뱸 3.���� 4.���� 5.��õ 6.���)\n");
		scanf_s("%d", &reservation->number);

		switch (reservation->number) {
		case 1:
			strcpy_s(reservation->location, sizeof(reservation->location), "�λ�");
			break;
		case 2:
			strcpy_s(reservation->location, sizeof(reservation->location), "�뱸");
			break;
		case 3:
			strcpy_s(reservation->location, sizeof(reservation->location), "����");
			break;
		case 4:
			strcpy_s(reservation->location, sizeof(reservation->location), "����");
			break;
		case 5:
			strcpy_s(reservation->location, sizeof(reservation->location), "��õ");
			break;
		case 6:
			strcpy_s(reservation->location, sizeof(reservation->location), "���");
			break;
		default:
			printf("��ȿ���� ���� ��ȣ�Դϴ�. �ٽ� �Է����ּ���.\n");
			continue;  // �ùٸ� ��ȣ�� �Է��� ������ �ݺ�
		}

		printf("������ ������� %s�Դϴ�.\n", reservation->location);
		break;  // �ùٸ� ��ȣ�� �Է��ϸ� �ݺ��� ����
	}
}
// ����� ���� �Լ�
void changeLocation(Reservation* reservation) {
	printf("�����ϰ� ���� ������ ������� �Է����ּ���.\n(1.�λ� 2.�뱸 3.���� 4.���� 5.��õ 6.���)\n");
	scanf_s("%d", &reservation->number);

	switch (reservation->number) {
	case 1:
		strcpy_s(reservation->location, sizeof(reservation->location), "�λ�");
		break;
	case 2:
		strcpy_s(reservation->location, sizeof(reservation->location), "�뱸");
		break;
	case 3:
		strcpy_s(reservation->location, sizeof(reservation->location), "����");
		break;
	case 4:
		strcpy_s(reservation->location, sizeof(reservation->location), "����");
		break;
	case 5:
		strcpy_s(reservation->location, sizeof(reservation->location), "��õ");
		break;
	case 6:
		strcpy_s(reservation->location, sizeof(reservation->location), "���");
		break;
	default:
		printf("��ȿ���� ���� ��ȣ�Դϴ�. ����� ���濡 �����߽��ϴ�.\n");
		return;  // �Լ� ����
	}

	printf("������ ������� %s(��)�� ����Ǿ����ϴ�.\n", reservation->location);
}
// �����ϱ� �Լ�
void makeReservation(Reservation reservations[], int* reservationCount) {

	if (*reservationCount >= MAX_RESERVATIONS) {
		printf("�ִ� ���� ���� Ƚ�� 10���� �� á���Ƿ� ���α׷��� �����մϴ�.\n");
		exit(0);  // ���α׷� ����
	}
	// ���� ������ ������ ����ü�� �ε���
	int currentIndex = *reservationCount;

	while (1) {
		// ������ ��ȣ �Է�
		printf("���Ͻô� �������� �������ּ���.\n(1.�λ� 2.�뱸 3.���� 4.���� 5.��õ 6.���)\n");
		scanf_s("%d", &reservations[currentIndex].number);
		// ��ȣ�� ���� ������ ����
		switch (reservations[currentIndex].number) {
		case 1:
			strcpy_s(reservations[currentIndex].destination, sizeof(reservations[currentIndex].destination), "�λ�");
			break;
		case 2:
			strcpy_s(reservations[currentIndex].destination, sizeof(reservations[currentIndex].destination), "�뱸");
			break;
		case 3:
			strcpy_s(reservations[currentIndex].destination, sizeof(reservations[currentIndex].destination), "����");
			break;
		case 4:
			strcpy_s(reservations[currentIndex].destination, sizeof(reservations[currentIndex].destination), "����");
			break;
		case 5:
			strcpy_s(reservations[currentIndex].destination, sizeof(reservations[currentIndex].destination), "��õ");
			break;
		case 6:
			strcpy_s(reservations[currentIndex].destination, sizeof(reservations[currentIndex].destination), "���");
			break;
		default:
			printf("��ȿ���� ���� ��ȣ�Դϴ�. �ٽ� �Է����ּ���.\n");
			// �ǹٸ� ��ȣ�� �Է��� ������ �ݺ�
			continue;
		}
		break;
	}
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
		int maxDay;
		do {
			printf("�̵��Ͻ� ��¥�� �Է����ּ���.(��, ��, ��, ���� ����)\n");
			scanf_s("%d %d %d", &reservations[currentIndex].date[0], &reservations[currentIndex].date[1], &reservations[currentIndex].date[2]);

			if (reservations[currentIndex].date[0] != 2023 && reservations[currentIndex].date[0] != 2024) {
				printf("��ȿ���� ���� �⵵�Դϴ�. 2023��~2024�� ���� ��¥�� �Է����ּ���.\n");
			}  // �⵵�� 2023~2024������ ����

			if (reservations[currentIndex].date[1] < 1 || reservations[currentIndex].date[1] > 12) {
				printf("��ȿ���� ���� ���Դϴ�. 1������ 12�� ������ ���� �Է����ּ���.\n");
			}

			// ���� ���� ���� ���� Ȯ��
			switch (reservations[currentIndex].date[1]) {
			case 2:  // 2��
				maxDay = (reservations[currentIndex].date[0] % 4 == 0 && (reservations[currentIndex].date[0] % 100 != 0 || reservations[currentIndex].date[0] % 400 == 0)) ? 29 : 28;
				break;
			case 4: case 6: case 9: case 11:  // 4, 6, 9, 11��
				maxDay = 30;
				break;
			default:  // ������ ��
				maxDay = 31;
				break;
			}

			if (reservations[currentIndex].date[2] < 1 || reservations[currentIndex].date[2] > maxDay) {
				printf("��ȿ���� ���� �����Դϴ�. 1�Ϻ��� %d�� ������ ���� �Է����ּ���.\n", maxDay);
			}
		} while ((reservations[currentIndex].date[0] != 2023 && reservations[currentIndex].date[0] != 2024) || (reservations[currentIndex].date[1] < 1 || reservations[currentIndex].date[1] > 12) || (reservations[currentIndex].date[2] < 1 || reservations[currentIndex].date[2] > maxDay));
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
