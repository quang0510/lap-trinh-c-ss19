#include <stdio.h>
#include <string.h>
typedef  struct {
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
}SinhVien;
void del( SinhVien sv[], int n );
int main(){
	SinhVien sv[50] = {
        {1, "Nguyen Dang Quang", 18, "092734675"},
        {2, "Nguyen Dang Xuan", 21, "094626744"},
        {3, "Vu Thi Dung", 22, "094726443"},
        {4, "Nguyen Dang Vinh", 18, "093274234"},
        {5, "Nguyen Dang Cuong", 24, "094327525"}
    };
	del(sv, 5);
	return 0;
}
void del( SinhVien sv[], int  n ){
	for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(sv[j].name, sv[j+1].name) > 0) {
                SinhVien temp = sv[j+1];
                sv[j+1] = sv[j];
                sv[j] = temp;
            }
        }
    }
    
    printf("\nKet qua: \n");
	for ( int i = 0; i< n ; i++){
		printf("\n\nID: %d", sv[i].id);
		printf("\nTen: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSdt: %s ", sv[i].phoneNumber);
	}
}
