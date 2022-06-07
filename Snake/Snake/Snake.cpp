// Змейка.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>  //стандартна¤ библиотека
#include <time.h> //случайные числа
#include <stdio.h> //дл¤ printf
#include <windows.h> // дл¤ HANDLE, курсора, цвета
#include <conio.h>  //дл¤ kbhit
#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

//int main(){std::cout << "Hello World!\n";}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.



/*
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

//старт игры и нужные параметры
void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2 - 1;
    y = height / 2 - 1;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw() { //основная карта
    system("cls"); //system("clear"); верх
    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) { //боковые грнц.
        for (int j = 0; j < width; i++) {
            if (j == 0 || j == width - 1)
                cout << "#";
            if (i == y && j == x)
                cout << "0";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "0";
                    }
                }
                if (!print)
                cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 1; i++) //низ
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input() { //нажатия от пользователя
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic() { //логика игры
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
    //if (x > width || x < 0 || y > height || y < 0)
    //    gameOver = true;
    if (x >= width - 1)
        x = 0;
    else if (x < 0)
        x = width - 2;

    if (y >= height)
        y = 0;
    else if (y < 0)
        y = height - 1;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main() { //основная функция
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
    }
    return 0;
}
*/


//1 <-------------------------------------------------------


/*
int MapW, MapH;
char Map[100][100] = {
"########################################################",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                                      #",
"#                                         @            #",
"#                                                      #",
"#                                                      #",
"########################################################" };
struct snakeBlock {
    int x, y;
};
void gotoxy(int x, int y){
    COORD coord = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void drawMap(vector <snakeBlock>snake){
    MapH = 0;
    system("cls");
    for (int i = 0; Map[i][0]; i++){
        MapW = 0;
        for (int j = 0; Map[i][j]; j++){
            MapW++;
            if (Map[i][j] != ' '){
                gotoxy(j, i);
                cout << Map[i][j];
            }
        }
        MapH++;
    }
    for (int i = 0; i < snake.size(); i++){
        gotoxy(snake[i].x, snake[i].y);
        cout << char(219);
    }
}
bool checkLose(int x, int y, vector <snakeBlock>& snake){
    if (Map[y][x] == '#')
        return true;
    if (snake.size() > 3){
        for (int i = 3; i < snake.size(); i++)
            if (snake[i].x == x && snake[i].y == y)
                return true;
    }
    if (Map[y][x] == '@'){
        Map[y][x] = ' ';
        snakeBlock newSnake;
        newSnake.x = snake[snake.size() - 1].x;
        newSnake.y = snake[snake.size() - 1].y;
        snake.push_back(newSnake);
        int rx, ry;
        do {
            rx = rand() % MapW;
            ry = rand() % MapH;
        } while (checkLose(rx, ry, snake));
        Map[ry][rx] = '@';
        drawMap(snake);
    }
    return false;
}
void snakeInit(int x, int y, vector<snakeBlock>& snake){
    snakeBlock newSnake;
    newSnake.x = x;
    newSnake.y = y;
    snake.push_back(newSnake);
}
bool snakeMove(vector<snakeBlock>& snake, short dire[2]){
    int oldx, oldy, x, y;
    gotoxy(snake[snake.size() - 1].x, snake[snake.size() - 1].y);
    cout << " ";
    oldx = snake[0].x;
    oldy = snake[0].y;
    snake[0].x += dire[0];
    snake[0].y += dire[1];
    gotoxy(snake[0].x, snake[0].y);
    cout << char(219);
    if (snake.size() > 1){
        for (int i = 1; i < snake.size(); i++){
            x = snake[i].x;
            y = snake[i].y;
            snake[i].x = oldx;
            snake[i].y = oldy;
            oldx = x;
            oldy = y;
        }
    }
    if (checkLose(snake[0].x, snake[0].y, snake))
        return true;
    return false;
}
int main(){
    bool GameIsRunning = true;
    int GameSpeed = 80;
    short dire[2] = { 0,1 };
    vector<snakeBlock> snake;
    snakeInit(1, 1, snake);
    drawMap(snake);
    while (GameIsRunning){
        if (GetAsyncKeyState(VK_UP)){
            if (dire[1] == 0){
                dire[1] = -1;
                dire[0] = 0;
            }
        }
        else if (GetAsyncKeyState(VK_DOWN)){
            if (dire[1] == 0){
                dire[1] = 1;
                dire[0] = 0;
            }
        }
        else if (GetAsyncKeyState(VK_LEFT)){
            if (dire[0] == 0){
                dire[1] = 0;
                dire[0] = -1;
            }
        }
        else if (GetAsyncKeyState(VK_RIGHT)){
            if (dire[0] == 0){
                dire[1] = 0;
                dire[0] = 1;
            }
        }
        if (snakeMove(snake, dire)){
            system("cls");
            cout << "Game Over" << endl;
            system("pause");
            return 0;
        }
        Sleep(GameSpeed);
    }
}
*/


//2 <-------------------------------------------------------


/*
HANDLE hConsole;
//HANDLE hStdout, hStdin;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void GotoXY(int X, int Y){
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}
//÷вет
enum ConsoleColor{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};
void SetColor(ConsoleColor text, ConsoleColor background){
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
class Zmeja{  // структура змейка
public:COORD* t; //точки
public:int PCount; //количество ¤блок
};
enum uprawlenie { LEFT, UP, RIGHT, DOWN }; //направление змейки
class Game{ //даные-точности: змейки, ¤блок, передвижение по X и Y, задержка, направление
public:Zmeja gaduka; //змейка
public:COORD jabloko; //¤блоко
public:int dx, dy; //передвижение
public:int pause; //задержка
public:int nap; //направление
};
void PlusJabloko(Game& g){ //‘ункци¤ разброски ¤блок
    int i, x, y;
    int n = g.gaduka.PCount;
    do{
        x = rand() % 56 + 3; //
        y = rand() % 19 + 3; //кординаты ¤блока
        for (i = 0; i < n; i++){
            if (x == g.gaduka.t[i].X && y == g.gaduka.t[i].Y) break; // проверка чтоб ¤блоко не бросить на змею
        }
    } while (i < n);
    g.jabloko.X = x; //
    g.jabloko.Y = y; //запоминаем позицию ¤блока
    SetConsoleCursorPosition(hConsole, g.jabloko); //переносим курсор в эту позицию
    SetConsoleTextAttribute(hConsole, 0x0c); //цвет ¤блока
    printf("%c", 4); //рисуем ¤блоко каким хотим символом
}
void skorostGame(Game& g){ // ‘ункцы¤ старта змейки ее координат и скорости
    system("cls");
    g.gaduka.PCount = 3; //сколько точек в змейке
    g.gaduka.t = new COORD[3];//создали точки
    for (int i = 0; i < 3; i++){
        g.gaduka.t[i].X = 20 + i;
        g.gaduka.t[i].Y = 20;
    }
    g.dx = 1;
    g.dy = 0;
    g.pause = 100;//скорость передвижение змеи
    PlusJabloko(g);//рисуем ¤блока
}
void Level(){
    GotoXY(10, 10); cout << "Vy nikogda ne vyigraete" << endl; //Ќјƒѕ»—№: ¬ы никогда не выиграете
    GotoXY(10, 11); cout << "esli ne budete bditelny!" << endl; //Ќјƒѕ»—№: ≈сли не будете бдительны!
}
void ZmejaStart(){
    GotoXY(10, 15); cout << "Soberi 50 yablok, togda posmotrim ;)" << endl; //Ќјƒѕ»—№: —обери 50 ¤блок, тогда посмотрим ;)
}
void STENA_2(){ //¬с¤ информаци¤, отображаема¤ на стене
    SetColor(LightBlue, Black); GotoXY(20, 0); cout << "Snake game by Danilenko Alexander" << endl;  //Ќјƒѕ»—№: »гра «мейка ƒаниленко јлександра
    GotoXY(64, 2); cout << "Dannue:" << endl; //ƒанные
    GotoXY(64, 3); cout << "Yablok:0" << endl; //яблок
    GotoXY(64, 4); cout << "Dlina:3" << endl; //ƒлина
    GotoXY(64, 5); cout << "Speed:0" << endl; //—корость
    GotoXY(64, 7); cout << "Uprawlenie:" << endl; //”правление
    GotoXY(64, 8); cout << "Esc:Wuxod" << endl; //¬ыход
    GotoXY(64, 9); cout << "P:Pause" << endl; //ѕауза
    GotoXY(64, 10); cout << "S:Start" << endl; //—тарт
    GotoXY(64, 11); cout << "L:Level" << endl; //”ровень
    GotoXY(64, 13); printf("%c", 24); cout << ":Wwerx" << endl; //¬верх
    GotoXY(64, 14); printf("%c", 25); cout << ":Wniz" << endl;   //¬низ
    GotoXY(64, 15); printf("%c", 27); cout << ":Wlewo" << endl;  //¬лево
    GotoXY(64, 16); printf("%c", 26); cout << ":Wprawo" << endl; //¬право
    {SetColor(LightMagenta, Black);
    GotoXY(2, 2); //–исуем верхнюю горизонтальную линию-стенку
    int m = 0;
    for (m = 0; m < 60; m++){
        printf("*");
        }
    }    {
        GotoXY(2, 24); //–исуем нижнюю горизонтальную линию-стенку
        int m = 0;
        for (m = 0; m < 60; m++){
            printf("*");
        }
    }    {   //–исуем левую вертикальную линию-стенку
        GotoXY(2, 3); cout << "*" << endl;
        GotoXY(2, 4); cout << "*" << endl;
        GotoXY(2, 5); cout << "*" << endl;
        GotoXY(2, 6); cout << "*" << endl;
        GotoXY(2, 7); cout << "*" << endl;
        GotoXY(2, 8); cout << "*" << endl;
        GotoXY(2, 9); cout << "*" << endl;
        GotoXY(2, 10); cout << "*" << endl;
        GotoXY(2, 11); cout << "*" << endl;
        GotoXY(2, 12); cout << "*" << endl;
        GotoXY(2, 13); cout << "*" << endl;
        GotoXY(2, 14); cout << "*" << endl;
        GotoXY(2, 15); cout << "*" << endl;
        GotoXY(2, 16); cout << "*" << endl;
        GotoXY(2, 17); cout << "*" << endl;
        GotoXY(2, 18); cout << "*" << endl;
        GotoXY(2, 19); cout << "*" << endl;
        GotoXY(2, 20); cout << "*" << endl;
        GotoXY(2, 21); cout << "*" << endl;
        GotoXY(2, 22); cout << "*" << endl;
        GotoXY(2, 23); cout << "*" << endl;
    }    {   //–исуем правую вертикальную линию-стенку
        GotoXY(61, 3); cout << "*" << endl;
        GotoXY(61, 4); cout << "*" << endl;
        GotoXY(61, 5); cout << "*" << endl;
        GotoXY(61, 6); cout << "*" << endl;
        GotoXY(61, 7); cout << "*" << endl;
        GotoXY(61, 8); cout << "*" << endl;
        GotoXY(61, 9); cout << "*" << endl;
        GotoXY(61, 10); cout << "*" << endl;
        GotoXY(61, 11); cout << "*" << endl;
        GotoXY(61, 12); cout << "*" << endl;
        GotoXY(61, 13); cout << "*" << endl;
        GotoXY(61, 14); cout << "*" << endl;
        GotoXY(61, 15); cout << "*" << endl;
        GotoXY(61, 16); cout << "*" << endl;
        GotoXY(61, 17); cout << "*" << endl;
        GotoXY(61, 18); cout << "*" << endl;
        GotoXY(61, 19); cout << "*" << endl;
        GotoXY(61, 20); cout << "*" << endl;
        GotoXY(61, 21); cout << "*" << endl;
        GotoXY(61, 22); cout << "*" << endl;
        GotoXY(61, 23); cout << "*" << endl;
    }
}
//‘ункци¤ котора¤ двигает и рисует
enum { KONEC, STENA, PLUS, MOVE };
int Move(Game& g){
    int& n = g.gaduka.PCount;
    COORD head = g.gaduka.t[n - 1]; //голова
    COORD tail = g.gaduka.t[0]; //хвост
    COORD next;
    next.X = head.X + g.dx;
    next.Y = head.Y + g.dy; //проверка следующей точки по направлению
    if (next.X < 3 || next.Y < 3 || next.X > 60 || next.Y > 23)//не уперлась ли в стену?
        return STENA;
    if (n > 4){
        for (int i = 0; i < n; i++)
            if (next.X == g.gaduka.t[i].X && next.Y == g.gaduka.t[i].Y) //не наехали ли на себ¤?
                return KONEC;
    }
    if (next.X == g.jabloko.X && next.Y == g.jabloko.Y){
        COORD* temp = new COORD[++n]; //новый масив больший на 1
        for (int i = 0; i < n; i++)
            temp[i] = g.gaduka.t[i]; //перекопируем
        temp[n - 1] = next; //добавл¤ем одну
        delete[] g.gaduka.t;
        g.gaduka.t = temp;
        SetConsoleCursorPosition(hConsole, head);
        SetConsoleTextAttribute(hConsole, 0x0a); //закрашываем ¤блоко которое сели
        printf("*");
        SetConsoleCursorPosition(hConsole, next);
        SetConsoleTextAttribute(hConsole, 0x0a);
        printf("%c", 1);
        PlusJabloko(g);
        return PLUS;
    }

    for (int i = 0; i < n - 1; i++)
        g.gaduka.t[i] = g.gaduka.t[i + 1];
    g.gaduka.t[n - 1] = next;
    SetConsoleCursorPosition(hConsole, tail);//закрашиваем хвостик
    printf(" ");
    SetConsoleCursorPosition(hConsole, head);
    SetConsoleTextAttribute(hConsole, 0x0a);//красим хвост змеи в зелений цвет
    printf("*");
    SetConsoleCursorPosition(hConsole, next);
    SetConsoleTextAttribute(hConsole, 0x0f); //красим курсор в белый цвет (голову змеи)
    printf("%c", 1);
    return MOVE;
}
void intro(){
    GotoXY(3, 10); //»нтруха
    printf("О°лз**п Іђ•©™*. Уѓа*¢Ђ•*®• Іђ•о™Ѓ© - бва•ЂЃз™*ђ®. Esc - ¢леЃ§ ®І ®£ал.");
    GotoXY(15, 11);
    printf("ЕбЂ® бЃ°•асв• 50 п°ЂЃ™, вЃ ¢*б ¶§св боаѓа®І ;)");
    GotoXY(18, 15);
    printf("ДЂп ѓаЃ§ЃЂ¶•*®п вл™*®в• ** **®™•© :D");
    getch();
}
int main(){
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //получаем дескриптор консоли
    intro();
    int key = 0, count = 0;
    bool Pause = false;
    Game g;
    skorostGame(g);
    STENA_2();
    srand(time(0));
    bool pause = false;
    while (key != 27){
        while (!kbhit()){ //ждет пока нажмем
            if (Pause == true){
                Sleep(1);
                continue;
            }
            switch (Move(g)){//движение
            case PLUS:
                ++count;
                g.pause -= 1;
                SetColor(LightBlue, Black);
                GotoXY(64, 2); cout << "Danue:" << endl;
                GotoXY(64, 3); cout << "Jablok:" << count << endl;
                GotoXY(64, 4); cout << "Dlina:" << g.gaduka.PCount << endl;
                GotoXY(64, 5); cout << "Speed:" << g.pause << endl;
                GotoXY(64, 7); cout << "Uprawlenie:" << endl;
                GotoXY(64, 8); cout << "Esc:Wuxod" << endl;
                GotoXY(64, 9); cout << "P:Pause" << endl;
                GotoXY(64, 10); cout << "S:Start" << endl;
                GotoXY(64, 11); cout << "L:Level" << endl;
                GotoXY(64, 13); printf("%c", 24); cout << ":Wwerx" << endl;
                GotoXY(64, 14); printf("%c", 25); cout << ":Wniz" << endl;
                GotoXY(64, 15); printf("%c", 27); cout << ":Wlewo" << endl;
                GotoXY(64, 16); printf("%c", 26); cout << ":Wprawo" << endl;
                if (count == 50){
                    SetColor(White, Black);
                    GotoXY(24, 1); cout << "Vy vyigrali! Pozdravlyayu! Vy ne chelovek! xD" << endl; //¬ы выиграли
                    getch();
                    return(0);
                }
                break;
            case STENA:
            case KONEC:
                GotoXY(23, 1); printf("Вл ѓаЃ®£а*Ђ®! Х*-е*-е*!!!\n\n\t\t\t"); //¬ы проиграли, ’ј ’ј ’ј
                getch();
                break;
            }
            Sleep(g.pause); //«адержка
        }
        key = getch();
        if (key == 'P' || key == 'p')
            Pause = !Pause;
        else if (key == 'S' || key == 's')
            ZmejaStart();
        else if (key == 'L' || key == 'l')
            Level();
        else if (key == 0 || key == 224){
            key = getch();
            if (key == 72 && g.nap != DOWN){
                g.nap = UP;
                g.dx = 0;
                g.dy = -1;
            }
            else if (key == 80 && g.nap != UP){
                g.nap = DOWN;
                g.dx = 0;
                g.dy = 1;
            }
            else if (key == 75 && g.nap != RIGHT){
                g.nap = LEFT;
                g.dx = -1;
                g.dy = 0;
            }
            else if (key == 77 && g.nap != LEFT){
                g.nap = RIGHT;
                g.dx = 1;
                g.dy = 0;
            }
        }
    }
}
*/


//3   <-------------------------------------------------------



const int WIDTH = 80;
const int HEIGHT = 20;

template<typename T>
using T_list_ = std::list<T>;

struct T_point {
    int  x;
    int  y;

    T_point(int x = 0, int y = 0) :
        x(x), y(y) {}

    bool operator< (const T_point& point) const {
        return  std::make_pair(x, y) < std::make_pair(point.x, point.y);
    }
    T_point operator+= (const T_point& point) {
        x += point.x;
        y += point.y;
        return *this;
    }
    T_point operator+ (const T_point& point) const {
        T_point res = *this;
        return  res += point;
    }
    bool operator== (const T_point& point) const {
        return x == point.x && y == point.y;
    }
    void print_position_() const {
        std::cout
            << x << ' '
            << y << ' '
            << std::endl;
    }
};

class T_snake {
    T_list_<T_point> snake;

public:
    T_snake(const T_point& start_position) {
        snake.push_back(start_position);
    }
    T_point get_head_position_() const {
        return  *snake.begin();
    }
    T_point get_end_tail_position_() const {
        return *(std::prev(snake.end()));
    }
    T_list_<T_point> get_all_snake_() const {
        return  snake;
    }
    void add_tail_snake_() {
        snake.push_back(*std::prev(snake.cend()));
    }
    void move_new_snake_(T_list_<T_point>&& new_list) {
        snake = std::move(new_list);
    }
};

class T_food {
    T_point position_food;

public:
    T_food(const T_point& position_food = { 2,2 }) :
        position_food(position_food) {}
    void generate_new_position_food_() {
        static std::mt19937 gen(std::time(nullptr));
        static std::uniform_int_distribution<> distance_width(1, WIDTH - 2);
        static std::uniform_int_distribution<> distance_height(1, HEIGHT - 2);
        position_food.x = distance_width(gen);
        position_food.y = distance_height(gen);
    }
    T_point get_food_position_() const {
        return  position_food;
    }
};

class T_draw_base {
    COORD windows_coord_;
    const static HANDLE handle_;
    T_point coord_;

public:
    T_draw_base(const T_point& point = { 1,1 }) :
        coord_(point) {}
    virtual ~T_draw_base() {}
    void draw_char_in_coord_(const T_point& point, const char& c = ' ') {
        coord_ = point;
        set_windows_coord_();
        SetConsoleCursorPosition(handle_, windows_coord_);
        std::cout.put(c);
        clear_windows_coord_();
    }
private:
    void clear_windows_coord_() {
        windows_coord_.X = 0;
        windows_coord_.Y = 0;
    }
    void set_windows_coord_() {
        windows_coord_.X = coord_.x;
        windows_coord_.Y = coord_.y;
    }
};
const HANDLE T_draw_base::handle_ = GetStdHandle(STD_OUTPUT_HANDLE);
class T_draw_field : public T_draw_base {
public:
    T_draw_field() {}
    void draw_field_() {
        for (int x = 0; x < WIDTH; ++x) {
            for (int y = 0; y < HEIGHT; ++y) {
                if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1) {
                    draw_char_in_coord_({ x,y }, '#');
                } // if
            } // for
        } // for
    }
};

class T_draw_snake : public T_draw_base {
public:
    T_draw_snake() {}
    void draw_snake_(const T_snake& snake) {
        auto snake_tail = snake.get_all_snake_();
        for (auto i = snake_tail.cbegin(); i != snake_tail.cend(); ++i) {
            if (*i == snake.get_head_position_()) {
                draw_char_in_coord_(*i, 'O');
            }
            else {
                draw_char_in_coord_(*i, 'o');
            }
        }
    }
};

class T_snake_game {
    T_snake         snake_;
    T_draw_base     drawer_base_;
    T_draw_field    drawer_field_;
    T_draw_snake    drawer_snake_;
    T_food          food_;
    int             size_snake_;
    enum {
        STOP, UP, DOWN, LEFT, RIGHT
    } direction;
public:
    T_snake_game() :
        snake_({ 40,10 }),
        size_snake_(0) {}

private:
    void initial_varialbes_and_draw_() {
        drawer_field_.draw_field_();
        food_.generate_new_position_food_();
        drawer_base_.draw_char_in_coord_(food_.get_food_position_(), '@');
        drawer_snake_.draw_snake_(snake_);
    }
    void calculate_direction_() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'w':
                direction = UP;
                break;
            case 'a':
                direction = LEFT;
                break;
            case 's':
                direction = DOWN;
                break;
            case 'd':
                direction = RIGHT;
                break;
            default:
                break;
            } // switch
        } // if
    }
    bool check_conflict_with_wall_() const {
        return snake_.get_head_position_().x == 0 || snake_.get_head_position_().x == WIDTH - 1 || snake_.get_head_position_().y == 0 || snake_.get_head_position_().y == HEIGHT - 1;
    }
    bool check_conflict_with_food_() const {
        return snake_.get_head_position_() == food_.get_food_position_();
    }
    //TODO
    bool check_conflict_with_tail_() const {
        if (size_snake_ == 0) {
            return false;
        }
        for (auto i = std::next(snake_.get_all_snake_().begin());
            i != snake_.get_all_snake_().end();
            ++i) {
            if (*i == snake_.get_head_position_()) {
                return true;
            }
        }
        return false;
    }
    void        change_direction_() {
        //создаем новую змейку в которую пишем новые координаты змейки
        //потом перемещаем новую змейку вместо старой
        T_point new_head = *snake_.get_all_snake_().begin();
        T_list_<T_point>&& new_snake(snake_.get_all_snake_());
        switch (direction) {
        case UP:
            new_head.y--;
            break;
        case LEFT:
            new_head.x--;
            break;
        case DOWN:
            new_head.y++;
            break;
        case RIGHT:
            new_head.x++;
            break;
        default:
            break;
        }
        new_snake.push_front(new_head);
        T_point erase_elem = *std::prev(new_snake.end());
        new_snake.erase(std::prev(new_snake.end()));
        snake_.move_new_snake_(std::move(new_snake));
        drawer_base_.draw_char_in_coord_(erase_elem);
        drawer_snake_.draw_snake_(snake_);
    }
public:
    void game_loop_() {
        initial_varialbes_and_draw_();
        for (;;) {
            calculate_direction_();
            if (check_conflict_with_wall_()) { // || check_conflict_with_tail_() 
                drawer_base_.draw_char_in_coord_({ 0,0 }, '#');
                break;
            }
            if (check_conflict_with_food_()) {
                food_.generate_new_position_food_();
                snake_.add_tail_snake_();
            }
            drawer_base_.draw_char_in_coord_(food_.get_food_position_(), '@');
            change_direction_();
            Sleep(50);
        }
    }
};
int main() {
    T_snake_game game;
    game.game_loop_();
}
