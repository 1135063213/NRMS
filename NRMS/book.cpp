#include "book.h"
#include "mysql_books.h"


int addBook()
{
    Book book;

    //�������
    cout << "������С˵����";
    cin >> book.m_book_name;

    cout << "����������id��";
    cin >> book.m_authorID;

    cout << "������۸�";
    cin >> book.m_price;

    cout << "������������ڣ�ʾ����1992-5-1����";
    cin >> book.m_publishDate;

    if (mysql_insert_books(book) == 0)
    {
        printf("����С˵��¼�ɹ�!\n");
        return 0;
    }
    else
    {
        printf("����С˵��¼ʧ�ܣ����������ʽ!\n");
        return -1;
    }
}

void queryAllBook()
{
    mysql_query_books();
}

void queryBook()
{
    cout << "������Ҫ��ѯ��С˵id��";
    int id;
    cin >> id;

    mysql_query_books(id);
}