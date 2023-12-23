typedef struct {
	char location[100];  // ������� �����ϴ� ����
	char destination[100];  // �������� �����ϴ� ����
	char transportation[100];  // ��������� �����ϴ� ����
	int number;  // ������ ��ȣ�� �����ϴ� ����
	int date[3];  // ��¥�� �����ϴ� ����
	int distance;  // �Ÿ��� �����ϴ� ����
	int price;  // ������ �����ϴ� ����
} Reservation;

void enterLocation(Reservation* reservation);
void changeLocation(Reservation* reservation);
void makeReservation(Reservation reservations[], int* reservationCount);
void cancelReservation(Reservation reservations[], int* reservationCount);
void showReservationInfo(Reservation reservations[], int reservationCount);