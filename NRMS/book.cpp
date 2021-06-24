#include "book.h"
#include "mysql_books.h"


int addBook()
{
    Book book;

    //添加数据
    cout << "请输入小说名：";
    cin >> book.m_book_name;

    cout << "请输入作者id：";
    cin >> book.m_authorID;

    cout << "请输入价格：";
    cin >> book.m_price;

    cout << "请输入出版日期（示例：1992-5-1）：";
    cin >> book.m_publishDate;

    if (mysql_insert_books(book) == 0)
    {
        printf("插入小说记录成功!\n");
        return 0;
    }
    else
    {
        printf("插入小说记录失败，请检查输入格式!\n");
        return -1;
    }
}

void queryAllBook()
{
    mysql_query_books();
}

void queryBook()
{
    cout << "请输入要查询的小说id：";
    int id;
    cin >> id;

    mysql_query_books(id);
}