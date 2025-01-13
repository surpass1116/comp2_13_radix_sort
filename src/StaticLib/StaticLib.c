#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
#include<stdlib.h>


// 基数ソート(引数が不適切であればfalseを返す)
// begin: ソートする配列の先頭要素へのポインタ
// end: ソートする配列の末尾要素の次の要素へのポインタ
// radix: 基数
bool radix_sort(item* begin, const item* end, int radix)
{
	// ToDo: 基数ソートを実装する
	if (begin == NULL || end == NULL || radix <= 0 || begin > end)return false;

	int num = (end - begin);

	item* a = malloc(sizeof(item) * num);
	int* rad = malloc(sizeof(int) * num);
	

	int m = 1;
	item* n = begin;

	while (m <= num) {	//ここのnumは本来radix
		for (int i = 0; i < num; i++) {
			rad[i] = ((n + i)->key / m) % 10;
		}
		int k = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < num; j++) {
				if (rad[j] == i) {
					a[k] = *(n + j);
					k++;
				}
			}
		}
		for (int i = 0; i < num; i++) {
			*(n + i) = a[i];
		}
		m *= 10;
	}

	free(a);
	free(rad);

	return true;
}
