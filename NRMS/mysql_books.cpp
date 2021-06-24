#include "mysql_books.h"

//全局变量
MYSQL mysql;     //一个数据库结构体
MYSQL_RES* res;  //一个结果集结构体
MYSQL_ROW row;   //char** 二维数组，存放一条条记录  //代表的是结果集中的一行

void mysql_connect()
{
    //MYSQL mysql;    
    mysql_init(&mysql);
    //设置编码方式
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
    //连接数据库
    //判断如果连接失败就输出连接失败。
    //注意你连接的账户名密码
    if (mysql_real_connect(&mysql, "localhost", "root", "xxxxxxxxxxx", "novel", 3306, NULL, 0) == NULL)//主机 用户名 密码 数据库名 端口
        printf("连接失败！\n");
    else
        printf("连接成功！\n");
}

void mysql_create_books()
{
    //mysql_query(&mysql, "drop table if exists books");
    //创建表
    mysql_query(&mysql, "create table if not exists books (id int primary key auto_increment,name varchar(20),authorID int,price double,publishDate datetime)");

}

int mysql_insert_books(Book book)
{
    //组成一条插入SQL语句
    char query[100];
    sprintf_s(query, "%s '%s','%s',%d,'%s')", "insert into books(name,authorID,price,publishDate) values(", 
        book.m_book_name, book.m_authorID, book.m_price, book.m_publishDate);

    //返回0代表插入成功
    return mysql_query(&mysql, query);
}

void mysql_query_books()
{    
    //查询数据
    mysql_query(&mysql, "select * from books");

    //获取结果集
    res = mysql_store_result(&mysql);

    //显示数据
    printf("ID\t书名\t\t\t作者ID\t价格\t出版日期 \n");
    //给ROW赋值，判断ROW是否为空，不为空就打印数据。
    while (row = mysql_fetch_row(res))
    {
        printf("%s  ", row[0]);//打印ID
        printf("\t%s  ", row[1]);//打印书名
        printf("\t\t%s  ", row[2]);//打印作者ID
        printf("\t%s  ", row[3]);//打印价格
        printf("\t%s  \n", row[4]);//打印出版日期
    }  

    //释放结果集
    mysql_free_result(res);
    //关闭数据库
    //mysql_close(&mysql);
}

void mysql_query_books(int id)
{
    //组成一条查询SQL语句
    char query[100];
    sprintf_s(query, "%s %i", "select * from books where id=", id);

    //查询数据
    mysql_query(&mysql, query);

    //获取结果集
    res = mysql_store_result(&mysql);

    //显示数据
    printf("ID\t书名\t\t\t作者ID\t价格\t出版日期 \n");
    //给ROW赋值，判断ROW是否为空，不为空就打印数据。
    if ((row = mysql_fetch_row(res)) != NULL)
    {
        printf("%s  ", row[0]);//打印ID
        printf("\t%s  ", row[1]);//打印书名
        printf("\t\t%s  ", row[2]);//打印作者ID
        printf("\t%s  ", row[3]);//打印价格
        printf("\t%s  \n", row[4]);//打印出版日期
    }
    else
    {
        printf("查询结果集为空，查询失败!\n");
    }
    
    //释放结果集
    mysql_free_result(res);
    //关闭数据库
    //mysql_close(&mysql);
}

