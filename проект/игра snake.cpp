#include <stdio.h>

#include <conio.h>

#include <stdlib.h>

#include <time.h>

#include <windows.h>



const int W = 52;//шрина карты

const int H  = 22;//высота карты



char map[22][52];//определить карту 

char key;//



int direct = 4;//Текущее направление движения змеи

int food[2] = {9,11};//food[0]еда абсцисса  food[1]еда ордината


int head;//написать длину



int snake[400][3];//Все змеи и змея координат точек  тело (snake[i][0]=0)   и  Змееголовые(snake[i][0]=1)  Вдали от хвоста до головы


void init(char map[22][52], int snake[400][3]);//Начало инициализации игры

void makeMap(char map[22][52],int snake[400][3],int food[]);//Производство Карта

void move(int snake[400][3],int direct);//Пусть координаты змея движется

void makeFood(int food[]);//Генерирует случайное число, чтобы производить координатные еда

void showView(char map[22][52]);  //Нарисуйте карта 

int ifEat(int head, int food[2]); //ела ли нет  еда

int ifReprat(int snake[400][3], int x, int y);//Определить, является ли полученный пищевой и змеиного перекрытия

int ifBump(int head);//Будет ли столкновение (ударить себя или стену)

void getKey();//снова установить направление движения





int main() {

	init(map, snake);//Инициализировать карту

	while (1) {

		getKey();

		system("cls");

		Sleep(30);

		move(snake, direct);//Пусть змея начала двигаться

		if (!food[0]&&!food[1]) {//еда была съедена - регенерируют пищи

			makeFood(food);//Координация еда поколения

		}

		makeMap(map, snake, food);

		showView(map);

		if (ifBump(head)) {

			printf("Game Over,Ваша оценка:%d", head);

			break;

		}

		getKey();

	}

	getchar();

	return 0;

}



void init(char map[22][52], int snake[400][3]) {//Инициализация змея



	snake[0][0] = 0, snake[0][1] = 9, snake[0][2] = 7;

	snake[1][0] = 0, snake[1][1] = 9, snake[1][2] = 8;

	snake[2][0] = 1, snake[2][1] = 9, snake[2][2] = 9;//Змееголовые

	//Инициализировать карту

	for (int i = 0;i<H;i++) {

		for (int j = 0;j<W;j++) {

			if (i == 0 || j == 0 || i == H - 1 || j == W - 1) {

				map[i][j] = '*';

			}

			else {

				map[i][j] = ' ';

			}

		}

	}

}



void showView(char map[22][52]) {//Значения отпечатанной карты массива

	for (int i = 0;i<H;i++) {

		for (int j = 0;j<W;j++) {

				printf("%c", map[i][j]);

		}

		printf("\n");

	}

}



void move(int snake[400][3],int direct) {//Пусть координаты змея начинает двигаться

	int x, y;// head является Змееголовые

	for (int i = 0;i < 400;i++) {

		if (snake[i][0] == 1) {

			head = i;

			break;

		}

	}

	//Найти координаты головы ,и зарезервированные для следующих завалить

	x = snake[head][1];

	y = snake[head][2];

	switch (direct){

		case 1://вверх

			snake[head][1]--;//Постоянная абсцисса, ордината+1

			break;

		case 2://вниз

			snake[head][1]++;//Постоянная ордината,абсцисса-1

			break;

		case 3://Влево

			snake[head][2]--;//Постоянная ордината,абсцисса-1

			break;

		case 4://вправо

			snake[head][2]++;//Неизменная ордината, абсцисса+1

			break;

	}

	//Пришло в голову следующей позиции, в первую очередь определить, следует ли есть еду, организм будет поставлен перед следующей всей предыдущей позиции 

	if (ifEat(head, food)) {

		snake[head + 1][0] = 1, snake[head + 1][1] = food[0], snake[head + 1][2] = food[1];//сновь определеть Змееголовые		snake[head][0] = 0;//отиетить перед Змееголовые	

		food[0] = 0, food[1] = 0;//

	}

		for (int j = head - 1;j >= 0;j--) {

			int temp;

			temp = x, x = snake[j][1], snake[j][1] = temp;

			temp = y, y = snake[j][2], snake[j][2] = temp;

		}

}



void makeFood(int food[]) {//Генерация координат еды

	srand(time(0));

	int x = rand() % 49 + 2, y = rand() % 19 + 2;//Генерация числа 1-50 поабсциссе  Количество 1-20 ординаты

	while (ifReprat(snake,x,y)) {//Если повторяются до тех пор, пока не будет повторно генерировать далеко не повторять

		x = rand() % 49 + 2, y = rand() % 19 + 2;

	}

	food[0] = y;

	food[1] = x;

}



void makeMap(char map[22][52], int snake[400][3], int food[]) {//Сбросить карту по координатам пищевой ценности змеи

	int i;

	//Переинициализируйте карту

	for (int i = 0;i<H;i++) {

		for (int j = 0;j<W;j++) {

			if (i == 0 || j == 0 || i == H - 1 || j == W - 1) {

				map[i][j] = '*';

			}

			else {

				map[i][j] = ' ';

			}

		}

	}

	//Перекрасить змей

	for (i = 0;i < 400;i++) {

		if (snake[i][0] == 1) break;

		map[snake[i][1]][snake[i][2]] = '#';

	}

	//Рисование головы и пищи

	map[snake[i][1]][snake[i][2]] = '@';

	map[food[0]][food[1]] = 'o';

}





int ifEat(int head,int food[2]) {

	if (snake[head][1] == food[0] && snake[head][2] == food[1])

		return 1;

	else

		return 0;

}



int ifReprat(int snake[400][3],int x,int y) {//Определить, является ли полученный пищевой и змеиного перекрытия

	for (int i = 0;i < 400;i++) {

		if (snake[i][0] == 1) break;

		if ((snake[i][1] == x&&snake[i][2] == y)) {//перекрываться

			return 1;

		}

	}

	return 0;

}



int ifBump(int head) {//Будет ли столкновение (ударить себя или стену)

		if ((snake[head][2]==0|| snake[head][0] == 51)  ||  (snake[head][1] == 0|| snake[head][1] == 21))//удврить стену

			return 1;

		for (int i = 0;i < head-1;i++) {

			if ((snake[i][1] == snake[head][1]&&snake[i][2] == snake[head][2])) {//ударить себя

				return 1;

			}

		}

		return 0;

}

void getKey() {

	if (_kbhit()) {

		key = _getch();

	}

	switch (key) {

	case 'H':

		if (direct != 2)

			direct = 1;

		break;

	case 'P':

		if (direct != 1)

			direct = 2;

		break;

	case 'K':

		if (direct != 4)

			direct = 3;

		break;

	case 'M':

		if (direct != 3)

			direct = 4;

		break;

	}

}
