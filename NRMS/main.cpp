#include "book.h"
#include "mysql_books.h"

int main()
{
    //连接数据库
    mysql_connect();

    //创建表
    mysql_create_books();

    //功能代号
    int func=1;
    
    while (func)
    {
        cout << "***************************" << endl;
        cout << "***小说管理系统v0.0.1\t***" << endl;
        cout << "***功能如下：\t\t***" << endl;
        cout << "***1.新增一本小说\t***" << endl;
        cout << "***2.查询库里的小说\t***" << endl;
        cout << "***3.查询某本小说\t***" << endl;
        cout << "***4.退出\t\t***" << endl;
        cout << "***************************" << endl;
        cout << "请选择功能：" << endl;
        cin >> func;

        //表插入
        if (func == 1)
        {
            addBook();
        }   

        //表所有数据查询
        if (func == 2)
        {
            queryAllBook();
        }

        //表一条数据查询
        if (func == 3)
        {         
            queryBook();
        }

        //退出
        if (func == 4)
        {
            func=0;
        }
    }

    system("pause");
    return 0;
}
