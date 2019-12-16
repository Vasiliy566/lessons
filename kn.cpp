

Крестики-нолики by Izvraschenok (c)2003г.

Эта программа - пример примитивного искусственного интеллекта
Игра здесь ведется только компьютер - компьютер


//#include #include #include #include // На всякий случай, чтобы не забыть, нужно объявить обозначения меток

#defineL_EMPTY0
#defineL_KRESTIK 1
#defineL_NOLIK2

// Поле, 3 на 3. См. выше, чтобы определить принимаемые значения

int field[3][3];

// Выигрышные позиции

int win_pos[5][2] = {
0,0, 0,2, 2,0, 2,2, 1,1
};

// Массив меток, которые будут ставится в зависимости от значения field

char lab[3] = {'+', 'X', '0' };



int vict = 0;// Определяет, закончена ли игра
int vp=0;// Номер игрока-победителя
int g_over = 0;// Никто не выиграл, поле заполнено


// Процедура, рисующая поле
//
int draw_field()
{

// Цикл по i и j - всего 9 проходов
for (int i=0; i<3; i++) {
// Перенос строки
printf("%c", '\n');
for (int j=0; j<3; j++)
// Рисуется определенная метка
printf("%c", lab[field[i][j]]);

};

// Разрыв строки после прорисовки поля
printf("%c", '\n');

return 1;
};

// Процедура, подщитывающая сумму элементов 3-х ячеечного массива
//
int eval_sum(int arg[3])
{
int ret = 0;
for (int i=0; i<3; i++) ret += arg[i];
return ret;
};

// Процедура, приравнивающая все элементы массива к нулю
//
int clear_arr(int arg[3])
{
for (int i=0; i<3; i++) arg[i] = 0;
return 0;
};

// Процедура, возвращающая номер нулевого элемента массива
//
int find_empty(int arg[3])
{
for (int i=0; i<3;i++)
if (arg[i]==0) return i;
return -1;
};

// Процедура проверки победы какого-либо игрока
//
int check_victory(int arg[3])
{
int ret=0;
for (int i=0; i<3; i++) ret += arg[i];
// Если все заполнены, то - победа
if (ret == 3) { vict=1; return 1; };
return 0;
};

// Процедура, проверяет на предмет опасных или выигрышных ситуаций
// (т.е. две вражеских/своих метки в линии и одна пустая ячейка
//
// Параметры:
// l_pl- метка противника
// l_comp- "своя" метка
//
int check_comp_danger(int l_pl, int l_comp)
{
// Здесь создаются и очищаются 2 3-х элементных массива
// В них будут хранится метки для каждой рассматриваемой метки
// Т.е.: если n-й элемент линии - соответствующая метка, то
// n-й элемент массива = 1, иначе = 0.

int c[3]; clear_arr(c); // Массив для "себя"
int p[3]; clear_arr(p); // Массив для "врага"
int cnt=0; // Счетчик порядкового номера в линии

// Проверка всех горизонтальных линий
//
for (int i=0; i<3; i++) {
for (int j=0; j<3; j++) {
// Если рассматриваемая клетка содержит метку, то заполнить соотвествующий массив
if (field[i][j]==l_pl) p[cnt]=1;
if (field[i][j]==l_comp) c[cnt]=1;
cnt++; // Следующий элемент линии
};

// Проверить, не победил ли кто-либо
if ((check_victory(p))||(check_victory(c))) return 1;

// Проверить, нет ли предвыигрышной ситуации
if ((eval_sum(p)==0)&&(eval_sum(c)==2)) {
int empt=find_empty(c);
field[i][empt] = l_comp;
return 0;
};

// Также, только для опасной ситуации
if ((eval_sum(p)==2)&&(eval_sum(c)==0)) {

int empt=find_empty(p);
field[i][empt] = l_comp;
return 0;
};

cnt = 0; // Переход на новую линию
clear_arr(c);
clear_arr(p);

};

// Все то же, только для вертикальных линий
for (i=0; i<3; i++) {
for (int j=0; j<3; j++) {
if (field[j][i]==l_pl) p[cnt]=1;
if (field[j][i]==l_comp) c[cnt]=1;
cnt++;
};
if ((check_victory(p))||(check_victory(c))) return 1;

if ((eval_sum(p)==0)&&(eval_sum(c)==2)) {
int empt=find_empty(c);
field[i][empt] = l_comp;
return 0;
};

if ((eval_sum(p)==2)&&(eval_sum(c)==0)) {

int empt=find_empty(p);
field[empt][i] = l_comp;
return 0;
};

cnt = 0;
clear_arr(c);
clear_arr(p);

};


// То же для первой диагонали
for (i=0; i<3; i++) {
if (field[i][i]==l_pl) p[cnt]=1;
if (field[i][i]==l_comp) c[cnt]=1;
cnt++;

};

if ((check_victory(p))||(check_victory(c))) return 1;

if ((eval_sum(p)==0)&&(eval_sum(c)==2)) {
int empt=find_empty(c);
field[i][empt] = l_comp;
return 0;
};

if ((eval_sum(p)==2)&&(eval_sum(c)==0)) {

int empt=find_empty(p);
field[empt][empt] = l_comp;
return 0;
};

cnt=0;
clear_arr(c);
clear_arr(p);

// То же для второй диагонали
for (i=0; i<3; i++) {
if (field[i][2-i]==l_pl) p[cnt]=1;
if (field[i][2-i]==l_comp) c[cnt]=1;
cnt++;

};

if ((check_victory(p))||(check_victory(c))) return 1;

if ((eval_sum(p)==0)&&(eval_sum(c)==2)) {
int empt=find_empty(c);
field[i][empt] = l_comp;
return 0;
};

if ((eval_sum(p)==2)&&(eval_sum(c)==0)) {

int empt=find_empty(p);
field[empt][2-empt] = l_comp;
return 0;
};
return 1;
};

// Процедура, которая проверяет, не заполнены ли все выигрышные позиции
//
int check_win_pos()
{
int cnt=0;
for (int i=0; i<5; i++)
if (field[win_pos[i][0]][win_pos[i][1]]!=0) cnt++;
if (cnt==5) return 0;
return 1;
};

// Процедура, проверяющая, не заполнено ли все поле
//
int check_game_over()
{
int cnt=0;
for (int i=0; i<3; i++) {
for (int j=0; j<3; j++) {
if (field[i][j]!=0) cnt++;
}
};

if (cnt==3*3) { g_over=1; return 1; };
return 0;
};

// ПроцедураЮ проверяющая возможность построения выигрышной ситуации
//
// Параметры:
// l- метка игрока
//
int check_corn_pos(int l)
{
// Флаг занятости центральной клетки
int c = (field[1][1] == 0);

// Проверка для верхнего края
// Если две клетки края заняты
if ((field[0][0]==l)&(field[2][0]==l)&(field[1][0]==0)) {
// Проверить первую угловую
if (field[0][2]==0) { field[0][2]=l; return 1; }
// Проверить вторую угловую
if (field[2][2]==0) { field[2][2]=l; return 1; }
// Проверить центральную
if (c) { field[1][1]=l; return 1; }
};

// То же для нижнего края
if ((field[0][2]==l)&(field[2][2]==l)&(field[1][2]==0)) {
if (field[0][0]==0) { field[0][0]=l; return 1; }
if (field[2][0]==0) { field[2][0]=l; return 1; }
};

// ... для левго
if ((field[0][0]==l)&(field[0][2]==l)&(field[0][1]==0)) {
if (field[2][0]==0) { field[2][0]=l; return 1; }
if (field[2][2]==0) { field[2][2]=l; return 1; }
if (c) { field[1][1]=l; return 1; }
};

// ... и правого.
if ((field[2][0]==l)&(field[2][2]==l)&(field[2][1]==0)) {
if (field[0][0]==0) { field[0][0]=l; return 1; }
if (field[2][0]==0) { field[2][0]=l; return 1; }
if (c) { field[1][1]=l; return 1; }
};

return 0;
};



// Процедура, выполняющая ход компьютера
//
// Параметры:
// l_pl- метка противника
// l_comp- "своя" метка
//
int comp_step(int l_pl, int l_comp)
{
// Если кто-то победил, то определить победившего и выйти
if (vict) { vp=l_comp; return 0; };

// Первым делом надо проверить на предмет опасных/выигрышных ситуаций
// Если таковая сложилась, то выйти из процедуры
if (!check_comp_danger(l_pl, l_comp)) return 0;


int b=0; // Контроллер цикла

// Этот цикл - ход компьютера на одну из клеток
while (!b) {

// Если все клетки заполнены - выход
if (check_game_over()) break;

// Если все выигрышные позиции заняты...
if (!check_win_pos())
for (int x=0; x<3; x++)
for (int y=0; y<3; y++)
if (field[x][y]==0) {
// ...походить на первую попавшуюся свободную клетку
field[x][y]=l_comp;
return 0;
};

// Проверить возможность построения выигрышной ситуации
if (check_corn_pos(l_comp)) return 0;

// Полуить текущее время для генерации рандомайза.
// ! Лучше делать с милисекундами
tm st; _getsystime(&st);
// Перевод времени в секунды
int rnd_seed = 3600*st.tm_hour+60*st.tm_min+st.tm_sec;

// Сгенерировать рандомайз
srand(rnd_seed);
int id; // Здесь будет хранится номер выигрышной позиции

// Получить случайное число.
// Цикл - для того, чтобы не брать первое попавшееся число цепочки
for (int i=0; i<10; i++) {
id = (int)(rand()/6000); // Получили
};


// Если больше размера массива, подровнять
if (id>4) id=4;


// Проверка, не занята ли подобранная позиция

if (field[win_pos[id][0]][win_pos[id][1]]==0) {
field[win_pos[id][0]][win_pos[id][1]] = l_comp; // Заполнить...
b=1; // ... и выйти из цикла
};


// Цикл будет длиться до тех пор, пока не будет подобрана выигрышная позиция
// Цикл не может быть бесконечным при правильной работе программы
};





return 1;
};

int main(int argc, char* argv[])
{

printf("Krestiki-Noliki by Izvraschenok (c)\n\n");

// Определить метки
int l_pl = 1;
int l_comp = 2;

// Нарисовать пустое поле
draw_field();

// Играть
while ((vict==0)|(g_over==0)) {

if (g_over) break;

// Метки в параметре меняются - очередность хода
comp_step(l_pl, l_comp);
draw_field();
comp_step(l_comp, l_pl);
draw_field();

};

if (g_over) printf("Game is over.");
else if (vict) printf("Player %d has won.", vp);

getch();

return 0;
}