#include <iostream>
using namespace std;

#include <string>

#define MAX 1000

struct Person{

    string m_Name;

    int m_Sex;

    int m_Age;

    string m_Phone;

    string m_Addr;
};

struct AddressBookes
{
    struct Person personArray[MAX];

    int m_Size;
};

void addPreson(AddressBookes * abs) {

    if (abs ->m_Size == MAX){

        cout << "通讯录已满，无法添加！"<<endl;
    }else{
        //name
        string name;
        cout <<"请输入您想要添加的联系人姓名："<< endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //sex
        cout << "请输入您想要添加的联系人的性别："<< endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;

        int sex = 0;

        while(true){
            cin >> sex;
            if (sex == 1 || sex == 2){
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "您输的性别有误，请重新输入！" <<endl;
        }

        //age
        cout << "请输入您想要添加的联系人的年龄：" << endl;

        int age = 0;
        while(true){
            cin >> age;
            if (age < 100 && age > 0){
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            cout << "您输的年龄有误，请重新输入！" <<endl;
        }

        //phone
        cout << "请输入您想要添加的联系人的电话号码：" << endl;

        string phoneNum;
        cin >> phoneNum;
        abs->personArray[abs->m_Size].m_Phone = phoneNum;

        //address
        cout << "请输入您想要添加的联系人的家庭住址：" << endl;

        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //upgrade the m_size
        abs->m_Size++;

        cout << "该联系人添加成功！" << endl;
        system("pause");
        system("cls");


    }
}

void showPerson(AddressBookes * abs){

    if (abs->m_Size == 0){
        cout << "当前未添加任何联系人！" << endl;
    } else {
        for (int i = 0; i < abs->m_Size; ++i) {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "地址：" << abs->personArray[i].m_Addr << endl;
        }
        system("pause");
        system("cls");
    }
}

int isExist (AddressBookes * abs, string name){
    for (int i = 0; i < abs->m_Size; ++i) {
        if (abs->personArray[i].m_Name == name){
            return i;
        }
    }
    return -1;
}

void deletePerson (AddressBookes * abs){
    cout << "请输入你想要删除的联系人" << endl;

    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1){
        for (int i = 0; i < abs->m_Size; ++i) {
            abs->personArray[i] = abs->personArray[i+1];

        }
        abs->m_Size--;
        cout << "此人已删除！" << endl;

    }else{
        cout << "查无此人" <<endl;
    }
    system("pause");
    system("cls");

}

void findPerson (AddressBookes * abs){
    cout<<"请输入你要查找的联系人："<<endl;
    string name;
    cin >> name;
    int result = isExist(abs, name);

    if (result != -1 ){
        cout << "姓名：" << abs->personArray[result].m_Name << "\t";
        cout << "性别：" << (abs->personArray[result].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personArray[result].m_Age << "\t";
        cout << "电话：" << abs->personArray[result].m_Phone << "\t";
        cout << "地址：" << abs->personArray[result].m_Addr << endl;
    }else{
        cout << "未找到联系人" << endl;
    }

    system("pause");
    system("cls");
}

void modifyPerson (AddressBookes * abs){
    cout << "请输入你要修改的联系人：" << endl;
    string name;
    cin >> name;

    int result = isExist(abs, name);

    if (result != -1){
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[result].m_Name = name;

        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;

        int sex = 0;

        while (true){
            cin >> sex;
            if (sex == 1 || sex == 2){
                abs->personArray[result].m_Sex = sex;
                break;
            }
            cout << "您输入的性别有误，请重新输入！"<< endl;
        }

        cout << "请输入年龄：" << endl;
        int age = 0;
        while(true){
            cin >> age;
            if (age < 100 && age > 0){
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            cout << "您输的年龄有误，请重新输入！" <<endl;
        }


        cout << "请输入联系人电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[result].m_Phone = phone;

        cout << "请输入家庭地址：" << endl;
        string address;
        cin >> address;
        abs->personArray[result].m_Addr = address;

        cout << "修改成功" << endl;

    }else{
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

void cleanPerson (AddressBookes * abs){

    abs->m_Size = 0;

    cout << "所有联系人已清空" << endl;
    system("pause");
    system("cls");
}

void showMenu() {

    cout << "*************************"<< endl;
    cout << "*****  1. 添加联系人  *****"<< endl;
    cout << "*****  2. 显示联系人  *****"<< endl;
    cout << "*****  3. 删除联系人  *****"<< endl;
    cout << "*****  4. 查找联系人  *****"<< endl;
    cout << "*****  5. 修改联系人  *****"<< endl;
    cout << "*****  6. 清空联系人  *****"<< endl;
    cout << "*****  0. 退出通讯录  *****"<< endl;
    cout << "*************************"<< endl;

};

int main() {

    AddressBookes abs;
    abs.m_Size = 0;

    int userSelect = 0;

    while (true){
        showMenu();

        cin >> userSelect;

        switch (userSelect) {
            case 1:
                addPreson(&abs);
                break;
            case 2:
                showPerson(&abs);
                break;
            case 3:
//            {
//                cout << "请输入要删除的联系人姓名" << endl;
//                string name;
//                cin >> name;
//                if (isExist(&abs, name) == -1){
//                    cout << "查无此人" <<endl;
//                }else{
//                    cout << "已找到此人" << endl;
//                }
//            }

                deletePerson(&abs);
                break;
            case 4:
                findPerson(&abs);
                break;
            case 5:
                modifyPerson(&abs);
                break;
            case 6:
                cleanPerson (&abs);
                break;
            case 0:
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
                break;
            default:
                break;
        }
    }
}
