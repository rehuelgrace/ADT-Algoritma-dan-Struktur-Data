//NIM				: Rehuel Grace M
//Nama				: 18218006
//Tanggal			: 18 September 2019
//Topik praktikum	: Pengenalan C
//Deskripsi			: Cek wujud air

int main(){
	int suhu;
	scanf("%d", &suhu);
	if (suhu<0){
		printf("PADAT\n");
	}
	else if (suhu == 0){
		printf("PADAT-CAIR\n");
	}
	else if (suhu>0 && suhu<100){
		printf("CAIR\n");
	}
	else if (suhu==100){
		printf("CAIR-GAS\n");
	}
	else{
		printf("GAS\n");
	}
	return 0;
}
