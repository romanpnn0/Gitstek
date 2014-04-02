#include <iostream>
#define MAX 15
 
using namespace std;
 
char *stack[MAX]; // ������ ��� �����
int tos=0; // ��� ������� �����
 /*!
       * Push body 
       */
void push(char *i) // ������� ���������� ������� � ����
{
    if(tos >= MAX) // �������� �� ������������� �����
    {
        cout << "���� �����!" << endl;
        return;
    }
    strcpy(stack[tos],i); // ���������� ������ � ����
    tos = tos + 1; // ����������� ������� �����
}
 /*!
       * Sizing 
       */
int size() // ��� ����������� ������� �����
{
    if (tos >= 0) return tos;// ���� ������ ����, �� ���������� ������� �������� ������� �����
    else return 0; // ����� ���������� ����
}
 
char *pop(void) // ������� ������������ �������� �� ������
{
    char *str = new char[30]; // ������
    tos = tos - 1; // ���������� �� ������ ����
    if(tos < 0) // ���� ������� ������ ����, �� ���� ������
    {
        cout << "���� ����!" << endl;
        return 0;
    }
    strcpy(str, stack[tos]); //����� � ������ �������� ������� �������� �������
    return str; // ���������� ��� ��������
}
 /*!
       * Delete function 
       */
void delet(char *element) // ������� ��������
{
    int razmer = size(); // �������� ����������� �����
    char *buf[MAX]; // ��� �������, ������������� ��� ��������
    for(int i = 0;i<MAX;i++) // ��������� ������
    {
        buf[i] = new char[30];
    }
    int c = 0; // ��������
    int ravn = 0;
    for(int i = 0;i<=size();i++) // ���� ��� ��������
    {
        /*���������,���� �� ����� ������� ��
        ����� � ������� ��������� � ����������,
        �� �������� � ������
        ����������� �������
        � ������� ��������� ������ ����� �� �����*/
        if (strcmp(element,stack[i])!=0)
        {
            strcpy(buf[c],stack[i]);
            c = c + 1;
            delete stack[i];
        }
        else //����� ������ ������� ��������� ������ �� �����
        {
            delete stack[i];
            ravn = ravn + 1;
        }
    }
    tos=0;
    /*�������� ������ ��� �����, ��� ��� ��� ����
    �������
    � ������ � ���� ��������*/
    for (int i=0;i<=(razmer-ravn);i++)
    {
        stack[i] = new char[30];
        push(buf[i]);
    }
}
 /*!
       * main function
       */
int main() // �c������ ���� ���������
{
    system("chcp 1251");
    setlocale(0, "rus");
    
    for (int i = 0;i<MAX;i++) // ��������� ������� ��� ��������� ����
    {
        stack[i] = new char[30];
    }
    char *Element = new char[30]; // ��� ����� �������� ��� ��������
    
    cout << "���� ���������" << endl;
    
    cout << "���: ";
    cin >> Element;
    push(Element);
    cout << "��� ������: ";
    cin >> Element;
    push(Element);
    cout << "���������: ";
    cin >> Element;
    push(Element);
    cout << "�������������: ";
    cin >> Element;
    push(Element);
    cout << "�������: ";
    cin >> Element;
    push(Element);
    
    cout << "������� �����: " << pop() << endl; // ���� �������� ��� ��������
    cout << "����� ������� �������? (������� ���): ";
    char *ItemToDelete = new char[30];
    cin >> ItemToDelete;
    delet(ItemToDelete); // �������� ��������
    cout <<"������� �����: " << pop() << endl << endl; // ������ ������� ������� �����
    cout << "����� ������� �������? (������� ���): ";
    cin >> ItemToDelete;
    delet(ItemToDelete); // �������� ��������
    cout <<"������� �����: " << pop() << endl << endl; // ������ ������� ������� �����
    cout << "����� ������� �������? (������� ���): ";
    cin >> ItemToDelete;
    delet(ItemToDelete); // �������� ��������
    cout <<"������� �����: " << pop() << endl << endl; // ������ ������� ������� �����
    cout << "����� ������� �������? (������� ���): ";
    cin >> ItemToDelete;
    delet(ItemToDelete); // �������� ��������
    cout <<"������� �����: " << pop() << endl << endl; // ������ ������� ������� �����
    cout << "����� ������� �������? (������� ���): ";
    cin >> ItemToDelete;
    delet(ItemToDelete); // �������� ��������
    cout << pop();
    
    system("PAUSE");
}