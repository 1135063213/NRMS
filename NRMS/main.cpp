#include "book.h"
#include "mysql_books.h"

int main()
{
    //�������ݿ�
    mysql_connect();

    //������
    mysql_create_books();

    //���ܴ���
    int func=1;
    
    while (func)
    {
        cout << "***************************" << endl;
        cout << "***С˵����ϵͳv0.0.1\t***" << endl;
        cout << "***�������£�\t\t***" << endl;
        cout << "***1.����һ��С˵\t***" << endl;
        cout << "***2.��ѯ�����С˵\t***" << endl;
        cout << "***3.��ѯĳ��С˵\t***" << endl;
        cout << "***4.�˳�\t\t***" << endl;
        cout << "***************************" << endl;
        cout << "��ѡ���ܣ�" << endl;
        cin >> func;

        //�����
        if (func == 1)
        {
            addBook();
        }   

        //���������ݲ�ѯ
        if (func == 2)
        {
            queryAllBook();
        }

        //��һ�����ݲ�ѯ
        if (func == 3)
        {         
            queryBook();
        }

        //�˳�
        if (func == 4)
        {
            func=0;
        }
    }

    system("pause");
    return 0;
}
