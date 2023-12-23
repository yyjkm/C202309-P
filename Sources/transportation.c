#include <stdio.h>
#include "transportationHeader.h"
#define MAX_RESERVATIONS 10  // 총 예매 가능한 횟수

int main() {
	int reservationCount = 0;  // 예매된 횟수를 저장하는 변수
	Reservation reservations[MAX_RESERVATIONS];  // 여러 예약 정보를 저장하기 위한 배열

	enterLocation(&reservations[reservationCount]);

	while (1) {
		int menu = -1;  // 입력한 메뉴 번호를 저장하는 변수

		// 메인 메뉴 선택
		printf("-------------------\n");
		printf("메뉴를 입력해주세요\n");
		printf("1. 출발지 변경\n2. 예매하기\n3. 예매 취소\n4. 결제 내역 및 예매 정보 확인\n5. 종료\n");
		printf("-------------------\n");
		scanf_s("%d", &menu);

		int terminate = 0;  // 프로그램 종료를 위한 변수

		switch (menu) {
		case 1:  // 1.출발지 변경
			changeLocation(&reservations[reservationCount]);
			break;
		case 2:  // 2.예매하기
			makeReservation(reservations, &reservationCount);
			break;
		case 3:  // 3. 예매 취소
			cancelReservation(reservations, &reservationCount);
			break;
		case 4:  // 4. 결제 내역 및 예매 정보 확인
			showReservationInfo(reservations, reservationCount);
			break;
		case 5:  // 5. 프로그램 종료
			terminate = 1;
			break;
		default:
			printf("잘못 입력하셨습니다. 다시 선택해주세요.\n");
		}

		if (terminate == 1) {
			printf("프로그램을 종료합니다.");
			break;
		}

	}

}