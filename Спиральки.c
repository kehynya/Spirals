#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
const int ENTER = 13;
const int UP = 72;
const int DOWN = 80;
int a[11][11];

void menu(int k) {
	if (k == 1) { printf("1.Введите число n <--\n2.Введите число m\n3.Спираль внутрь слева\n4.Спираль внутрь справа\n5.Спираль изнутри вправо\n6.Спираль изнутри влево\n7.Выход\n"); }
	if (k == 2) { printf("1.Введите число n\n2.Введите число m <--\n3.Спираль внутрь слева\n4.Спираль внутрь справа\n5.Спираль изнутри вправо\n6.Спираль изнутри влево\n7.Выход\n"); }
	if (k == 3) { printf("1.Введите число n\n2.Введите число m\n3.Спираль внутрь слева <--\n4.Спираль внутрь справа\n5.Спираль изнутри вправо\n6.Спираль изнутри влево\n7.Выход\n"); }
	if (k == 4) { printf("1.Введите число n\n2.Введите число m\n3.Спираль внутрь слева\n4.Спираль внутрь справа <--\n5.Спираль изнутри вправо\n6.Спираль изнутри влево\n7.Выход\n"); }
	if (k == 5) { printf("1.Введите число n\n2.Введите число m\n3.Спираль внутрь слева\n4.Спираль внутрь справа\n5.Спираль изнутри вправо <--\n6.Спираль изнутри влево\n7.Выход\n"); }
	if (k == 6) { printf("1.Введите число n\n2.Введите число m\n3.Спираль внутрь слева\n4.Спираль внутрь справа\n5.Спираль изнутри вправо\n6.Спираль изнутри влево <--\n7.Выход\n"); }
	if (k == 7) { printf("1.Введите число n\n2.Введите число m\n3.Спираль внутрь слева\n4.Спираль внутрь справа\n5.Спираль изнутри вправо\n6.Спираль изнутри влево\n7.Выход <--\n"); }
	if (k >= 8 || k <= 0) { printf("ОШИБКА"); }
}
int main() {
	setlocale(LC_ALL, "Rus");
	int k;
	int s = 1;
	int n, m;
	bool was_n = false;
	bool was_m = false;
	menu(s);
	while (1) {
		k = _getch();
		system("cls");
		if (k == UP) {
			s = s - 1;
			if (s < 1) s = 1;
		}
		if (k == DOWN) {
			s = s + 1;
			if (s > 7) s = 7;
		}
		menu(s);
		if (k == ENTER) {
			k = s + '0'; //по аське 0 = 48, т.е. к = код числа по аське
		}
		if (k == '1') {
			scanf("%d", &n);
			if (1 <= n < 12){
				was_n = true;
			}
			else {
				was_n = false;
				printf("Введите число n в диапазоне от 1 до 11 включительно");
			}
		}
		if (k == '2') {
			scanf("%d", &m);
			if (1 <= m < 12) {
				was_m = true;
			}
			else {
				was_m = false;
				printf("Введите число m в диапазоне от 1 до 11 включительно");
			}
		}
		if (k == '3') {
			for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) printf("%d %d", i, j);//a[i][j];
			int dx[] = { 0, 1, 0, -1 };
			int dy[] = { 1, 0, -1, 0 };

			int counter = 1;
			int current_direction = 0;

			int x = 0, y = 0;
			a[0][0] = counter;
			counter++;

			while (counter <= n * m) {
				while (
					x + dx[current_direction] < n
					&& x + dx[current_direction] >= 0
					&& y + dy[current_direction] < m
					&& y + dy[current_direction] >= 0
					&& a[x + dx[current_direction]][y + dy[current_direction]] == 0)
				{
					x += dx[current_direction];
					y += dy[current_direction];
					a[x][y] = counter;
					counter++;
				}
				current_direction = (current_direction + 1) % 4;
			}

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					printf("%3d ", a[i][j]);
				}
				printf("\n");
			}
		} 
		if (k == '4') {
			for (int i = 0; i < 12; ++i) for (int j = 0; j < 12; ++j) a[i][j] = 0;
			int dx[] = { 0, 1, 0, -1 };
			int dy[] = { -1, 0, 1, 0 };

			int counter = 1;
			int current_direction = 0;

			int x = 0, y = m - 1;
			a[x][y] = counter;
			counter++;

			while (counter <= n * m) {
				while (
					x + dx[current_direction] < n
					&& x + dx[current_direction] >= 0
					&& y + dy[current_direction] < m
					&& y + dy[current_direction] >= 0
					&& a[x + dx[current_direction]][y + dy[current_direction]] == 0)
				{
					x += dx[current_direction];
					y += dy[current_direction];
					a[x][y] = counter;
					counter++;
				}
				current_direction = (current_direction + 1) % 4;
			}

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					printf("%3d ", a[i][j]);
				}
				printf("\n");
			}
		}
		if (k == '6') {
			for (int i = 0; i < 12; ++i) for (int j = 0; j < 12; ++j) a[i][j] = 0;
			int dx[] = { 0, 1, 0, -1 };
			int dy[] = { -1, 0, 1, 0 };

			int counter = 1;
			int current_direction = 0;

			int x = 0, y = m - 1;
			a[x][y] = n * m - counter + 1;
			counter++;

			while (counter <= n * m) {
				while (
					x + dx[current_direction] < n
					&& x + dx[current_direction] >= 0
					&& y + dy[current_direction] < m
					&& y + dy[current_direction] >= 0
					&& a[x + dx[current_direction]][y + dy[current_direction]] == 0)
				{
					x += dx[current_direction];
					y += dy[current_direction];
					a[x][y] = n * m - counter + 1;
					counter++;
				}
				current_direction = (current_direction + 1) % 4;
			}

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					printf("%3d ", a[i][j]);
				}
				printf("\n");
			}
		}
		if (k == '5') {
			for (int i = 0; i < 12; ++i) for (int j = 0; j < 12; ++j) a[i][j] = 0;
			int dx[] = { 0, 1, 0, -1 };
			int dy[] = { 1, 0, -1, 0 };

			int counter = 1;
			int current_direction = 0;

			int x = 0, y = 0;
			a[x][y] = n * m - counter + 1;
			counter++;

			while (counter <= n * m) {
				while (
					x + dx[current_direction] < n
					&& x + dx[current_direction] >= 0
					&& y + dy[current_direction] < m
					&& y + dy[current_direction] >= 0
					&& a[x + dx[current_direction]][y + dy[current_direction]] == 0)
				{
					x += dx[current_direction];
					y += dy[current_direction];
					a[x][y] = n * m - counter + 1;
					counter++;
				}
				current_direction = (current_direction + 1) % 4;
			}

			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					printf("%3d ", a[i][j]);
				}
				printf("\n");
			}
		}
		if (k == '7') {
			return 0;
		}
	}

	_getch();
	return 0;
}
