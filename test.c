#include <stdio.h>
#include "fec.h"
#include "rs.h"
#define N (6)
#define M (3)
#define DATA_CNT (4)
#define FEC_CNT (2)
#define ALL_CNT (DATA_CNT + FEC_CNT)

void
print_data(char *data[N])
{

	for(int i=0; i < N; i++)
	{
		if (NULL == data[i]) {
			printf("------\n");
			continue;
		}
		for (int j = 0; j < M; j++) {
			printf("%02X", (unsigned char)data[i][j]);
		}
		printf("\n");
	}

}

int
main()
{
	int i;
	void *code = fec_new(DATA_CNT, ALL_CNT);
	char arr[N][M+M]=
	{
		"aaa","bbb","ccc",
		"ddd","eee","fff"
	};
	char *data[N];
	for(i = 0; i < N; i++)
	{
		data[i] = arr[i];
	}

	printf("[input]\n");
	print_data(data);

	rs_encode2(DATA_CNT, ALL_CNT, data, M);
	//printf("%d %d",(int)(unsigned char)arr[5][0],(int)('a'^'b'^'c'^'d'^'e'));

	printf("[encode]\n");
	print_data(data);

	data[0] = NULL;
	data[1] = NULL;

	printf("[loss]\n");
	print_data(data);

	int ret = rs_decode2(DATA_CNT, ALL_CNT, data, M);
	printf("decode ret %d\n", ret);

	printf("[decode]\n");
	print_data(data);

	fec_free(code);
	return 0;
}
