#include <stdio.h>

int main() {
	char location[7] = { "" };  // 거주지를 저장하는 변수

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
		char destination[7] = { "" };  // 목적지를 저장하는 변수
		int time = 0;  // 이동하는데 걸리는 시간을 저장하는 변수
		int date[3] = { 0 };  // 날짜를 입력받는 변수

		switch (menu) {
		case 1:
			printf("변경하고싶은 고객님의 거주지를 입력해주세요.\n(단, 부산, 대구, 인천, 광주, 대전, 울산 에서만)\n");
			scanf_s("%s", location, (int)sizeof(location));
			printf("고객님의 거주지가 %s(으)로 변경되었습니다.\n", location);
			break;
		case 2:
			printf("원하시는 목적지를 입력해주세요.\n(단, 부산, 대구, 인천, 광주, 대전, 울산 에서만)\n");
			scanf_s("%s", destination, (int)sizeof(destination));
			if (location == destination) {
				printf("목적지까지 걸리는 시간을 입력해주세요.\n");
				scanf_s("%d", &time);
			}
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