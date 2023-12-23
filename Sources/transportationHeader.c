#include <stdio.h>
#define MAX_RESERVATIONS 10  // 총 예매 가능한 횟수

typedef struct {
	char location[100];  // 거주지를 저장하는 변수
	char destination[100];  // 목적지를 저장하는 변수
	char transportation[100];  // 교통수단을 저장하는 변수
	int number;  // 거주지 번호를 저장하는 변수
	int date[3];  // 날짜를 저장하는 변수
	int distance;  // 거리를 저장하는 변수
	int price;  // 가격을 저장하는 변수
} Reservation;
// 출발지 입력 함수
void enterLocation(Reservation* reservation) {
	printf("대중교통 예매 프로그램을 실행합니다.\n");

	while (1) {
		printf("고객님의 출발지를 입력해주세요. (1.부산 2.대구 3.대전 4.광주 5.인천 6.울산)\n");
		scanf_s("%d", &reservation->number);

		switch (reservation->number) {
		case 1:
			strcpy_s(reservation->location, sizeof(reservation->location), "부산");
			break;
		case 2:
			strcpy_s(reservation->location, sizeof(reservation->location), "대구");
			break;
		case 3:
			strcpy_s(reservation->location, sizeof(reservation->location), "대전");
			break;
		case 4:
			strcpy_s(reservation->location, sizeof(reservation->location), "광주");
			break;
		case 5:
			strcpy_s(reservation->location, sizeof(reservation->location), "인천");
			break;
		case 6:
			strcpy_s(reservation->location, sizeof(reservation->location), "울산");
			break;
		default:
			printf("유효하지 않은 번호입니다. 다시 입력해주세요.\n");
			continue;  // 올바른 번호를 입력할 때까지 반복
		}

		printf("고객님의 출발지는 %s입니다.\n", reservation->location);
		break;  // 올바른 번호를 입력하면 반복문 종료
	}
}
// 출발지 변경 함수
void changeLocation(Reservation* reservation) {
	printf("변경하고 싶은 고객님의 출발지를 입력해주세요.\n(1.부산 2.대구 3.대전 4.광주 5.인천 6.울산)\n");
	scanf_s("%d", &reservation->number);

	switch (reservation->number) {
	case 1:
		strcpy_s(reservation->location, sizeof(reservation->location), "부산");
		break;
	case 2:
		strcpy_s(reservation->location, sizeof(reservation->location), "대구");
		break;
	case 3:
		strcpy_s(reservation->location, sizeof(reservation->location), "대전");
		break;
	case 4:
		strcpy_s(reservation->location, sizeof(reservation->location), "광주");
		break;
	case 5:
		strcpy_s(reservation->location, sizeof(reservation->location), "인천");
		break;
	case 6:
		strcpy_s(reservation->location, sizeof(reservation->location), "울산");
		break;
	default:
		printf("유효하지 않은 번호입니다. 출발지 변경에 실패했습니다.\n");
		return;  // 함수 종료
	}

	printf("고객님의 출발지가 %s(으)로 변경되었습니다.\n", reservation->location);
}
// 예매하기 함수
void makeReservation(Reservation reservations[], int* reservationCount) {

	if (*reservationCount >= MAX_RESERVATIONS) {
		printf("최대 예매 가능 횟수 10개로 다 찼으므로 프로그램을 종료합니다.\n");
		exit(0);  // 프로그램 종료
	}
	// 예매 정보를 저장할 구조체의 인덱스
	int currentIndex = *reservationCount;

	while (1) {
		// 목적지 번호 입력
		printf("원하시는 목적지를 선택해주세요.\n(1.부산 2.대구 3.대전 4.광주 5.인천 6.울산)\n");
		scanf_s("%d", &reservations[currentIndex].number);
		// 번호에 따른 목적지 설정
		switch (reservations[currentIndex].number) {
		case 1:
			strcpy_s(reservations[currentIndex].destination, sizeof(reservations[currentIndex].destination), "부산");
			break;
		case 2:
			strcpy_s(reservations[currentIndex].destination, sizeof(reservations[currentIndex].destination), "대구");
			break;
		case 3:
			strcpy_s(reservations[currentIndex].destination, sizeof(reservations[currentIndex].destination), "대전");
			break;
		case 4:
			strcpy_s(reservations[currentIndex].destination, sizeof(reservations[currentIndex].destination), "광주");
			break;
		case 5:
			strcpy_s(reservations[currentIndex].destination, sizeof(reservations[currentIndex].destination), "인천");
			break;
		case 6:
			strcpy_s(reservations[currentIndex].destination, sizeof(reservations[currentIndex].destination), "울산");
			break;
		default:
			printf("유효하지 않은 번호입니다. 다시 입력해주세요.\n");
			// 옳바른 번호를 입력할 때까지 반복
			continue;
		}
		break;
	}
	// 거주지와 목적지가 같은지 확인
	if (strcmp(reservations[currentIndex].location, reservations[currentIndex].destination) == 0) {
		// 교통수단 선택
		do {
			printf("원하시는 교통수단을 선택해주세요.(택시, 지하철)\n");
			scanf_s("%s", reservations[currentIndex].transportation, (int)sizeof(reservations[currentIndex].transportation));

			// 택시, 지하철을 입력하지 않았을 경우
			if (stricmp(reservations[currentIndex].transportation, "택시") != 0 && stricmp(reservations[currentIndex].transportation, "지하철") != 0) {
				printf("유효하지 않은 교통수단입니다. 다시 입력해주세요.\n");
			}
		} while (stricmp(reservations[currentIndex].transportation, "택시") != 0 && stricmp(reservations[currentIndex].transportation, "지하철") != 0);

		// 거리 입력
		printf("원하는 목적지까지 걸리는 거리를 입력해주세요.(m 단위로)\n");
		scanf_s("%d", &reservations[currentIndex].distance);

		// 교통수단에 따른 가격 계산
		if (stricmp(reservations[currentIndex].transportation, "택시") == 0) {
			reservations[currentIndex].price = 4300 + ((reservations[currentIndex].distance / 150) * 100);
			printf("%s로 %dm 이동하여 %d원 결제되었습니다.\n", reservations[currentIndex].transportation, reservations[currentIndex].distance, reservations[currentIndex].price);
		}
		else if (stricmp(reservations[currentIndex].transportation, "지하철") == 0) {
			reservations[currentIndex].price = 1250;
			if (reservations[currentIndex].distance > 10000 && reservations[currentIndex].distance < 50000) {
				reservations[currentIndex].price += ((reservations[currentIndex].distance - 10000) / 5000) * 100;
			}
			if (reservations[currentIndex].distance >= 50000) {
				reservations[currentIndex].price = 2050;
				reservations[currentIndex].price += ((reservations[currentIndex].distance - 50000) / 8000) * 100;
			}
			printf("%s로 %dm 이동하여 %d원 결제되었습니다.\n", reservations[currentIndex].transportation, reservations[currentIndex].distance, reservations[currentIndex].price);
		}
	}
	else {
		// 이동할 날짜 입력
		int maxDay;
		do {
			printf("이동하실 날짜를 입력해주세요.(년, 월, 일, 띄어쓰기 구분)\n");
			scanf_s("%d %d %d", &reservations[currentIndex].date[0], &reservations[currentIndex].date[1], &reservations[currentIndex].date[2]);

			if (reservations[currentIndex].date[0] != 2023 && reservations[currentIndex].date[0] != 2024) {
				printf("유효하지 않은 년도입니다. 2023년~2024년 사이 날짜를 입력해주세요.\n");
			}  // 년도는 2023~2024년으로 제한

			if (reservations[currentIndex].date[1] < 1 || reservations[currentIndex].date[1] > 12) {
				printf("유효하지 않은 월입니다. 1월부터 12월 사이의 값을 입력해주세요.\n");
			}

			// 월에 따른 일자 제한 확인
			switch (reservations[currentIndex].date[1]) {
			case 2:  // 2월
				maxDay = (reservations[currentIndex].date[0] % 4 == 0 && (reservations[currentIndex].date[0] % 100 != 0 || reservations[currentIndex].date[0] % 400 == 0)) ? 29 : 28;
				break;
			case 4: case 6: case 9: case 11:  // 4, 6, 9, 11월
				maxDay = 30;
				break;
			default:  // 나머지 월
				maxDay = 31;
				break;
			}

			if (reservations[currentIndex].date[2] < 1 || reservations[currentIndex].date[2] > maxDay) {
				printf("유효하지 않은 일자입니다. 1일부터 %d일 사이의 값을 입력해주세요.\n", maxDay);
			}
		} while ((reservations[currentIndex].date[0] != 2023 && reservations[currentIndex].date[0] != 2024) || (reservations[currentIndex].date[1] < 1 || reservations[currentIndex].date[1] > 12) || (reservations[currentIndex].date[2] < 1 || reservations[currentIndex].date[2] > maxDay));
		// 교통수단 선택
		do {
			printf("원하시는 교통수단을 선택해주세요.(고속버스, 기차)\n");
			scanf_s("%s", reservations[currentIndex].transportation, (int)sizeof(reservations[currentIndex].transportation));

			if (stricmp(reservations[currentIndex].transportation, "고속버스") != 0 && stricmp(reservations[currentIndex].transportation, "기차") != 0) {
				printf("유효하지 않은 교통수단입니다. 다시 입력해주세요.\n");
			}
		} while (stricmp(reservations[currentIndex].transportation, "고속버스") != 0 && stricmp(reservations[currentIndex].transportation, "기차") != 0);

		// 교통수단에 따른 가격 계산
		if (stricmp(reservations[currentIndex].transportation, "고속버스") == 0) {
			reservations[currentIndex].price = 20000;
		}
		else if (stricmp(reservations[currentIndex].transportation, "기차") == 0) {
			reservations[currentIndex].price = 50000;
		}
		printf("%d원 결제되었습니다.\n", reservations[currentIndex].price);
	}

	strcpy_s(reservations[currentIndex + 1].location, sizeof(reservations[currentIndex + 1].location), reservations[currentIndex].location);
	(*reservationCount)++;
}
// 예매 취소 함수
void cancelReservation(Reservation reservations[], int* reservationCount) {
	int cancelIndex;
	printf("취소할 예매 번호를 입력하세요: ");
	scanf_s("%d", &cancelIndex);
	if (*reservationCount == 0) {
		printf("예매한 정보가 없습니다.\n");
	}
	else {
		// 예매 번호가 유효한 범위 내에 있는지 확인
		if (cancelIndex >= 1 && cancelIndex <= *reservationCount) {
			// 선택한 예매 정보를 삭제하고 나머지 정보를 쉬프트
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
			printf("예매가 취소되었습니다.\n");
		}
		else {
			printf("유효하지 않은 예매 번호입니다.\n");
		}
	}

}
// 예매 정보 확인 함수
void showReservationInfo(Reservation reservations[], int reservationCount) {
	printf("예매한 정보를 확인합니다.\n");
	if (reservationCount > 0) {
		for (int i = 0; i < reservationCount; i++) {
			if (strcmp(reservations[i].location, reservations[i].destination) == 0) {
				printf("---------- 예매 정보 ----------\n");
				printf("예매 번호: %d\n", i + 1);
				printf("출발지: %s\n", reservations[i].location);
				printf("교통수단: %s\n", reservations[i].transportation);
				printf("이동 거리: %dm\n", reservations[i].distance);
				printf("결제 금액: %d원\n", reservations[i].price);
				printf("-----------------------------\n");
			}
			else {
				printf("---------- 예매 정보 ----------\n");
				printf("예매 번호: %d\n", i + 1);
				printf("출발지: %s\n", reservations[i].location);
				printf("목적지: %s\n", reservations[i].destination);
				printf("이동 날짜: %d년 %d월 %d일\n", reservations[i].date[0], reservations[i].date[1], reservations[i].date[2]);
				printf("교통수단: %s\n", reservations[i].transportation);
				printf("결제 금액: %d원\n", reservations[i].price);
				printf("-----------------------------\n");
			}
		}
	}
	else {
		printf("예매된 정보가 없습니다.\n");
	}
}
