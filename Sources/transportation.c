#include <stdio.h>
#define MAX_RESERVATIONS 10  // 총 예매 가능한 횟수

typedef struct {
	char location[100];  // 거주지를 저장하는 변수
	char destination[100];  // 목적지를 저장하는 변수
	char transportation[100];  // 교통수단을 저장하는 변수
	int date[3];  // 날짜를 저장하는 변수
	int distance;  // 거리를 저장하는 변수
	int price;  // 가격을 저장하는 변수
} Reservation;

// 출발지 변경 함수
void changeLocation(Reservation reservations[], int reservationCount) {
	printf("변경하고싶은 고객님의 출발지를 입력해주세요.\n(단, 부산, 대구, 인천, 광주, 대전, 울산 에서만)\n");
	scanf_s("%s", reservations[reservationCount].location, (int)sizeof(reservations[reservationCount].location));
	printf("고객님의 출발지가 %s(으)로 변경되었습니다.\n", reservations[reservationCount].location);
}
// 예매하기 함수
void makeReservation(Reservation reservations[], int* reservationCount) {
	// 예매 정보를 저장할 구조체의 인덱스
	int currentIndex = *reservationCount;

	// 목적지 입력
	printf("원하시는 목적지를 입력해주세요.\n(단, 부산, 대구, 인천, 광주, 대전, 울산 에서만)\n");
	scanf_s("%s", reservations[currentIndex].destination, (int)sizeof(reservations[currentIndex].destination));

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
		do {
			printf("이동하실 날짜를 입력해주세요.(년, 월, 일,띄어쓰기 구분)\n");
			scanf_s("%d %d %d", &reservations[currentIndex].date[0], &reservations[currentIndex].date[1], &reservations[currentIndex].date[2]);

			if (reservations[currentIndex].date[0] != 2023 && reservations[currentIndex].date[0] != 2024) {
				printf("2023년~2024년 사이 날짜를 입력해주세요.\n");
			}
		} while ((reservations[currentIndex].date[0] != 2023 && reservations[currentIndex].date[0] != 2024) || (reservations[currentIndex].date[1] > 12 || reservations[currentIndex].date[1] < 0));

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

	// 다음 예매를 위한 초기화
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

int main() {
	int reservationCount = 0;  // 예매된 횟수를 저장하는 변수
	Reservation reservations[MAX_RESERVATIONS];  // 여러 예약 정보를 저장하기 위한 배열
	// 고객 거주지 입력 받기
	printf("대중교통 예매 프로그램을 실행합니다.\n");
	printf("고객님의 출발지를 입력해주세요.(단, 부산, 대구, 인천, 광주, 대전, 울산 에서만)\n");
	scanf_s("%s", reservations[reservationCount].location, (int)sizeof(reservations[reservationCount].location));
	printf("고객님의 출발지는 %s입니다.\n", reservations[reservationCount].location);

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
			changeLocation(reservations, reservationCount);
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
		if (reservationCount == 10) {
			printf("최대 예매 가능 횟수 10개로 다 찼으므로 프로그램을 종료합니다.\n");
			break;  // 예매 횟수가 10개로 다 차면 프로그램 종료
		}
	}

}