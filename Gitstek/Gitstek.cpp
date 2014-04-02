#include <iostream>
#define MAX 15
 
using namespace std;
 
char *stack[MAX]; // Массив для стека
int tos=0; // Для вершины стека
 /*!
       * Push body 
       */
void push(char *i) // Функция добавления элемета в стэк
{
    if(tos >= MAX) // Проверка на заполненность стека
    {
        cout << "Стек полон!" << endl;
        return;
    }
    strcpy(stack[tos],i); // Записываем строку в стэк
    tos = tos + 1; // Увеличиваем вершину стэка
}
 /*!
       * Sizing 
       */
int size() // Для определения размера стека
{
    if (tos >= 0) return tos;// Если больше нуля, то возвращаем текущее значение вершины стэка
    else return 0; // иначе возвращаем ноль
}
 
char *pop(void) // Функция вытаскивания элемента из головы
{
    char *str = new char[30]; // Буффер
    tos = tos - 1; // Сдвигаемся от головы вниз
    if(tos < 0) // Если вершина меньше нуля, то стэк пустой
    {
        cout << "Стек пуст!" << endl;
        return 0;
    }
    strcpy(str, stack[tos]); //иначе в буффер помешаем текущее значение вершины
    return str; // везвращаем это значение
}
 /*!
       * Delete function 
       */
void delet(char *element) // Функция удаления
{
    int razmer = size(); // Получаем размерность стека
    char *buf[MAX]; // Для буффера, исчпользуется при удалении
    for(int i = 0;i<MAX;i++) // ВЫделение памяти
    {
        buf[i] = new char[30];
    }
    int c = 0; // Счетчики
    int ravn = 0;
    for(int i = 0;i<=size();i++) // Цикл для удаления
    {
        /*Проверяем,если не равны элемент из
        стека и элемент введедный с клавиатуры,
        то копируем в буффер
        увеличиваем счетчик
        и удаляем полностью данную ячеку из стека*/
        if (strcmp(element,stack[i])!=0)
        {
            strcpy(buf[c],stack[i]);
            c = c + 1;
            delete stack[i];
        }
        else //иначе просто удаляем полнустью ячейку из стека
        {
            delete stack[i];
            ravn = ravn + 1;
        }
    }
    tos=0;
    /*Выделяем память для стека, так как она была
    удалена
    и кладем в стек значения*/
    for (int i=0;i<=(razmer-ravn);i++)
    {
        stack[i] = new char[30];
        push(buf[i]);
    }
}
 /*!
       * main function
       */
int main() // Оcновное тело программы
{
    system("chcp 1251");
    setlocale(0, "rus");
    
    for (int i = 0;i<MAX;i++) // Выделение ппамяти для элементов стэк
    {
        stack[i] = new char[30];
    }
    char *Element = new char[30]; // Для ввода элемента для удаления
    
    cout << "Ввод элементов" << endl;
    
    cout << "Имя: ";
    cin >> Element;
    push(Element);
    cout << "Вид спорта: ";
    cin >> Element;
    push(Element);
    cout << "Факультет: ";
    cin >> Element;
    push(Element);
    cout << "Специальность: ";
    cin >> Element;
    push(Element);
    cout << "Возраст: ";
    cin >> Element;
    push(Element);
    
    cout << "Вершина стека: " << pop() << endl; // Ввод элемента для удаления
    cout << "Какой элемент удалить? (впишите его): ";
    char *ItemToDelete = new char[30];
    cin >> ItemToDelete;
    delet(ItemToDelete); // Удаление элемента
    cout <<"Вершина стека: " << pop() << endl << endl; // Печать текущей вершины стека
    cout << "Какой элемент удалить? (впишите его): ";
    cin >> ItemToDelete;
    delet(ItemToDelete); // Удаление элемента
    cout <<"Вершина стека: " << pop() << endl << endl; // Печать текущей вершины стека
    cout << "Какой элемент удалить? (впишите его): ";
    cin >> ItemToDelete;
    delet(ItemToDelete); // Удаление элемента
    cout <<"Вершина стека: " << pop() << endl << endl; // Печать текущей вершины стека
    cout << "Какой элемент удалить? (впишите его): ";
    cin >> ItemToDelete;
    delet(ItemToDelete); // Удаление элемента
    cout <<"Вершина стека: " << pop() << endl << endl; // Печать текущей вершины стека
    cout << "Какой элемент удалить? (впишите его): ";
    cin >> ItemToDelete;
    delet(ItemToDelete); // Удаление элемента
    cout << pop();
    
    system("PAUSE");
}