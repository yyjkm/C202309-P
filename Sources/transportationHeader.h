typedef struct {
	char location[100];  // 출발지를 저장하는 변수
	char destination[100];  // 목적지를 저장하는 변수
	char transportation[100];  // 교통수단을 저장하는 변수
	int number;  // 거주지 번호를 저장하는 변수
	int date[3];  // 날짜를 저장하는 변수
	int distance;  // 거리를 저장하는 변수
	int price;  // 가격을 저장하는 변수
} Reservation;

void enterLocation(Reservation* reservation);
void changeLocation(Reservation* reservation);
void makeReservation(Reservation reservations[], int* reservationCount);
void cancelReservation(Reservation reservations[], int* reservationCount);
void showReservationInfo(Reservation reservations[], int reservationCount);