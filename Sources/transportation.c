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

int main() {
	int reservationCount = 0;  // 예매된 횟수를 저장하는 변수
	Reservation reservations[MAX_RESERVATIONS];  // 여러 예약 정보를 저장하기 위한 배열

	// 고객 거주지 입력 받기
	printf("대중교통 예매 프로그램을 실행합니다.\n");
	printf("고객님의 거주지를 입력해주세요.(단, 부산, 대구, 인천, 광주, 대전, 울산 에서만)\n");
	scanf_s("%s", reservations[0].location, (int)sizeof(reservations[0].location));
	printf("고객님의 거주지는 %s입니다.\n", reservations[0].location);

	while (1) {
		int menu = -1;  // 입력한 메뉴 번호를 저장하는 변수

		// 메인 메뉴 선택
		printf("-------------------\n");
		printf("메뉴를 입력해주세요\n");
		printf("1. 거주지 변경\n2. 예매하기\n3. 결제 내역 및 예매 정보 확인\n4. 종료\n");
		printf("-------------------\n");
		scanf_s("%d", &menu);

		int terminate = 0;  // 프로그램 종료를 위한 변수

		switch (menu) {
		case 1:  // 1.거주지 변경
			printf("변경하고싶은 고객님의 거주지를 입력해주세요.\n(단, 부산, 대구, 인천, 광주, 대전, 울산 에서만)\n");
			scanf_s("%s", reservations[0].location, (int)sizeof(reservations[0].location));
			printf("고객님의 거주지가 %s(으)로 변경되었습니다.\n", reservations[0].location);
			break;
		case 2:  // 2.예매하기
			printf("원하시는 목적지를 입력해주세요.\n(단, 부산, 대구, 인천, 광주, 대전, 울산 에서만)\n");
			scanf_s("%s", reservations[reservationCount].destination, (int)sizeof(reservations[reservationCount].destination));  // 사용자로부터 목적지 입력받기
			// 거주지와 목적지가 같을 경우
			if (strcmp(reservations[0].location, reservations[reservationCount].destination) == 0) {
				do {
					printf("원하시는 교통수단을 선택해주세요.(택시, 지하철)\n");
					scanf_s("%s", reservations[reservationCount].transportation, (int)sizeof(reservations[reservationCount].transportation));  // 사용자로부터 원하는 교통수단 입력받기

					// 택시, 지하철을 입력하지 않았을 경우
					if (stricmp(reservations[reservationCount].transportation, "택시") != 0 && stricmp(reservations[reservationCount].transportation, "지하철") != 0) {
						printf("유효하지 않은 교통수단입니다. 다시 입력해주세요.\n");
					}
				} while (stricmp(reservations[reservationCount].transportation, "택시") != 0 && stricmp(reservations[reservationCount].transportation, "지하철") != 0);

				printf("원하는 목적지까지 걸리는 거리를 입력해주세요.(m 단위로)\n");
				scanf_s("%d", &reservations[reservationCount].distance);  // 사용자로부터 목적지까지 걸리는 거리 입력받기

				// 교통수단이 택시일 경우
				if (stricmp(reservations[reservationCount].transportation, "택시") == 0) {
					reservations[reservationCount].price = 4300 + ((reservations[reservationCount].distance / 150) * 100);  // 기본요금 4300원에 150m당 100원 추가
					printf("%s로 %dm 이동하여 %d원 결제되었습니다.\n", reservations[reservationCount].transportation, reservations[reservationCount].distance, reservations[reservationCount].price);
				}
				// 교통수단이 지하철일 경우
				else if (stricmp(reservations[reservationCount].transportation, "지하철") == 0) {
					reservations[reservationCount].price = 1250;  // 기본요금 1250원 
					if (reservations[reservationCount].distance > 10000 && reservations[reservationCount].distance < 50000) {
						reservations[reservationCount].price += ((reservations[reservationCount].distance - 10000) / 5000) * 100;  // 거리가 10km 초과 50km 미만 일 경우 5km당 100원 추가
						if (reservations[reservationCount].distance >= 50000) {
							reservations[reservationCount].price += ((reservations[reservationCount].distance - 50000) / 8000) * 100;
						}  // 거리가 50km 이상 일 경우 8km당 100원 추가
					}
					printf("%s로 %dm 이동하여 %d원 결제되었습니다.\n", reservations[reservationCount].transportation, reservations[reservationCount].distance, reservations[reservationCount].price);
				}
				reservationCount++;  // 예매 횟수 증가
			}
			// 거주지와 목적지가 다를 경우
			else {
				// 사용자로부터 이동할 날짜 입력받기
				do {
					printf("이동하실 날짜를 입력해주세요.(년, 월, 일,띄어쓰기 구분)\n");
					scanf_s("%d %d %d", &reservations[reservationCount].date[0], &reservations[reservationCount].date[1], &reservations[reservationCount].date[2]);

					if (reservations[reservationCount].date[0] != 2023 && reservations[reservationCount].date[0] != 2024) {
						printf("2023년~2024년 사이 날짜를 입력해주세요.\n");
					}
					if (reservations[reservationCount].date[1] > 12 && reservations[reservationCount].date[1] < 0) {
						printf("1월~12월 사이 날짜를 입력해주세요.\n");
					}
				} while (reservations[reservationCount].date[0] != 2023 && reservations[reservationCount].date[0] != 2024 || reservations[reservationCount].date[1] > 12 && reservations[reservationCount].date[1] < 0);

				do {
					printf("원하시는 교통수단을 선택해주세요.(고속버스, 기차)\n");
					scanf_s("%s", reservations[reservationCount].transportation, (int)sizeof(reservations[reservationCount].transportation));  // 사용자가 원하는 교통수단 입력받기

					if (stricmp(reservations[reservationCount].transportation, "고속버스") != 0 && stricmp(reservations[reservationCount].transportation, "기차") != 0) {
						// 고속버스, 기차를 입력하지 않았을 경우
						printf("유효하지 않은 교통수단입니다. 다시 입력해주세요.\n");
					}
				} while (stricmp(reservations[reservationCount].transportation, "고속버스") != 0 && stricmp(reservations[reservationCount].transportation, "기차") != 0);

				// 교통수단이 고속버스일 경우
				if (stricmp(reservations[reservationCount].transportation, "고속버스") == 0) {
					reservations[reservationCount].price = 20000;
					printf("%d원 결제되었습니다.\n", reservations[reservationCount].price);
				}
				// 교통수단이 기차일 경우
				else if (stricmp(reservations[reservationCount].transportation, "기차") == 0) {
					reservations[reservationCount].price = 50000;
					printf("%d원 결제되었습니다.\n", reservations[reservationCount].price);
				}
				reservationCount++;  // 예매 횟수 증가
			}
			break;
		case 3:
			printf("예매한 정보를 확인합니다.\n");
			if (reservationCount > 0) {
				for (int i = 0; i < reservationCount; i++) {
					if (strcmp(reservations[0].location, reservations[i].destination) == 0) {
						printf("---------- 예매 정보 ----------\n");
						printf("예매 번호: %d\n", i + 1);
						printf("교통수단: %s\n", reservations[i].transportation);
						printf("이동 거리: %dm\n", reservations[i].distance);
						printf("결제 금액: %d원\n", reservations[i].price);
						printf("-----------------------------\n");
					}
					else {
						printf("---------- 예매 정보 ----------\n");
						printf("예매 번호: %d\n", i + 1);
						printf("거주지: %s\n", reservations[0].location);
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
			break;
		case 4:
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