//NIM				: Rehuel Grace M
//Nama				: 18218006
//Tanggal			: 18 September 2019
//Topik praktikum	: Pengenalan C
//Deskripsi			: Menjumlahkan deret dari input yang diberikan dan mencetak ke layar

int main(){
	int N, sum, i;
	scanf("%d", &N);
	sum = 0;
	for (i=1; i<=N; i++)
		sum += i;
	printf("%d\n", sum);
	return 0;
}
