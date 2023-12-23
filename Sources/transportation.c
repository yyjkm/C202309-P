#include <stdio.h>
#include "transportationHeader.h"
#define MAX_RESERVATIONS 10  // �� ���� ������ Ƚ��

int main() {
	int reservationCount = 0;  // ���ŵ� Ƚ���� �����ϴ� ����
	Reservation reservations[MAX_RESERVATIONS];  // ���� ���� ������ �����ϱ� ���� �迭

	enterLocation(&reservations[reservationCount]);

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
			changeLocation(&reservations[reservationCount]);
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

	}

}