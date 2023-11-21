#include <stdio.h>

int main() {
	char location[7] = { "" };  // 거주지를 저장하는 변수
	char* location_ptr = &location;

	// 고객 거주지 입력 받기
	printf("대중교통 예매 프로그램을 실행합니다.\n");
	printf("고객님의 거주지를 입력해주세요.(단, 부산, 대구, 인천, 광주, 대전, 울산 에서만)\n");
	scanf_s("%s", location, (int)sizeof(location));
	printf("고객님의 거주지는 %s입니다.\n", location);

	while (1) {
		int menu = -1;  // 입력한 메뉴 번호를 저장하는 변수

		// 메인 메뉴 선택
		printf("-------------------\n");
		printf("메뉴를 입력해주세요\n");
		printf("1. 거주지 변경\n2. 예매하기\n3. 결제 내역 및 예매 정보 확인\n4. 종료\n");
		printf("-------------------\n");
		scanf_s("%d", &menu);

		int terminate = 0;  // 프로그램 종료를 위한 변수
		int distance = 0;  // 이동하는데 걸리는 시간을 저장하는 변수
		int date[3] = { 0 };  // 날짜를 입력받는 변수
		char destination[7] = { "" };  // 목적지를 저장하는 변수
		char transportation[8] = { "" };  // 교통수단을 저장하는 변수

		char* destination_ptr = &destination;

		switch (menu) {
		case 1:  // 1.거주지 변경
			printf("변경하고싶은 고객님의 거주지를 입력해주세요.\n(단, 부산, 대구, 인천, 광주, 대전, 울산 에서만)\n");
			scanf_s("%s", location, (int)sizeof(location));
			printf("고객님의 거주지가 %s(으)로 변경되었습니다.\n", location);
			break;
		case 2:  // 2.예매하기
			printf("원하시는 목적지를 입력해주세요.\n(단, 부산, 대구, 인천, 광주, 대전, 울산 에서만)\n");
			scanf_s("%s", destination, (int)sizeof(destination));  // 사용자의 목적지 입력받기
			// 거주지와 목적지가 같을 경우
			if (*location_ptr == *destination_ptr) {
				printf("원하는 목적지까지 걸리는 거리를 입력해주세요.(m 단위로)\n");
				scanf_s("%d", &distance);  // 목적지까지 걸리는 거리 입력받기

				printf("원하시는 교통수단을 선택해주세요.(택시, 지하철)\n");
				scanf_s("s", transportation, (int)sizeof(transportation));  // 사용자가 원하는 교통수단 입력받기

				if (transportation == "택시") {
					double price = 4300 + (distance % 150) * 100;  // 기본요금에 입력받은 거리에서 150m당 100원을 더하는 변수
				}
				else if (transportation == "지하철") {
					int price = 1250;  // 기본요금
					if (distance > 10000 && distance < 50000) {
						price += ((distance - 10000) / 5000) * 100;  // 10km 초과 할 시 기본요금에 5km당 100원을 더하는 변수
					}
					else if (distance >= 50000) {
						price += ((distance - 50000) / 8000) * 100;  // 50km 초과 할 시 기본요금에 8km당 100원을 더하는 변수
					}
				}
			}
			// 거주지와 목적지가 다를 경우
			else {
				printf("날짜를 입력해주세요.(띄어쓰기 구분)\n");
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
			printf("잘못 입력하셨습니다. 다시 선택해주세요.\n");
		}

		if (terminate == 1) {
			printf("프로그램을 종료합니다.");
			break;
		}
	}

}