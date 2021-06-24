#include "mysql_books.h"

//ȫ�ֱ���
MYSQL mysql;     //һ�����ݿ�ṹ��
MYSQL_RES* res;  //һ��������ṹ��
MYSQL_ROW row;   //char** ��ά���飬���һ������¼  //������ǽ�����е�һ��

void mysql_connect()
{
    //MYSQL mysql;    
    mysql_init(&mysql);
    //���ñ��뷽ʽ
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
    //�������ݿ�
    //�ж��������ʧ�ܾ��������ʧ�ܡ�
    //ע�������ӵ��˻�������
    if (mysql_real_connect(&mysql, "localhost", "root", "xxxxxxxxxxx", "novel", 3306, NULL, 0) == NULL)//���� �û��� ���� ���ݿ��� �˿�
        printf("����ʧ�ܣ�\n");
    else
        printf("���ӳɹ���\n");
}

void mysql_create_books()
{
    //mysql_query(&mysql, "drop table if exists books");
    //������
    mysql_query(&mysql, "create table if not exists books (id int primary key auto_increment,name varchar(20),authorID int,price double,publishDate datetime)");

}

int mysql_insert_books(Book book)
{
    //���һ������SQL���
    char query[100];
    sprintf_s(query, "%s '%s','%s',%d,'%s')", "insert into books(name,authorID,price,publishDate) values(", 
        book.m_book_name, book.m_authorID, book.m_price, book.m_publishDate);

    //����0�������ɹ�
    return mysql_query(&mysql, query);
}

void mysql_query_books()
{    
    //��ѯ����
    mysql_query(&mysql, "select * from books");

    //��ȡ�����
    res = mysql_store_result(&mysql);

    //��ʾ����
    printf("ID\t����\t\t\t����ID\t�۸�\t�������� \n");
    //��ROW��ֵ���ж�ROW�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
    while (row = mysql_fetch_row(res))
    {
        printf("%s  ", row[0]);//��ӡID
        printf("\t%s  ", row[1]);//��ӡ����
        printf("\t\t%s  ", row[2]);//��ӡ����ID
        printf("\t%s  ", row[3]);//��ӡ�۸�
        printf("\t%s  \n", row[4]);//��ӡ��������
    }  

    //�ͷŽ����
    mysql_free_result(res);
    //�ر����ݿ�
    //mysql_close(&mysql);
}

void mysql_query_books(int id)
{
    //���һ����ѯSQL���
    char query[100];
    sprintf_s(query, "%s %i", "select * from books where id=", id);

    //��ѯ����
    mysql_query(&mysql, query);

    //��ȡ�����
    res = mysql_store_result(&mysql);

    //��ʾ����
    printf("ID\t����\t\t\t����ID\t�۸�\t�������� \n");
    //��ROW��ֵ���ж�ROW�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
    if ((row = mysql_fetch_row(res)) != NULL)
    {
        printf("%s  ", row[0]);//��ӡID
        printf("\t%s  ", row[1]);//��ӡ����
        printf("\t\t%s  ", row[2]);//��ӡ����ID
        printf("\t%s  ", row[3]);//��ӡ�۸�
        printf("\t%s  \n", row[4]);//��ӡ��������
    }
    else
    {
        printf("��ѯ�����Ϊ�գ���ѯʧ��!\n");
    }
    
    //�ͷŽ����
    mysql_free_result(res);
    //�ر����ݿ�
    //mysql_close(&mysql);
}

