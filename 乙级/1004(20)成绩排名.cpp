#include <stdio.h>
#define N 102
//����������ͬ���ҷ�����ΧΪ0-100��˵�����101��ѧ��������102�������㹻����

struct stu{
    char name[11]; //ע�⣬����ѧ�ų��Ȳ�����10λ����ô�ַ�����Ҫ����11λ��������'\0'ҲҪռһλ
    char no[11];
    int mark;
};

int main(){
    struct stu students[N];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%s%d", students[i].name, students[i].no, &students[i].mark);
    }
    int maxid, minid, maxm = 0, minn = 100;
    for(int i = 0; i < n; i++){
        if (students[i].mark > maxm){
            maxm = students[i].mark;
            maxid = i;
        }
        if (students[i].mark < minn){
            minn = students[i].mark;
            minid = i;
        }
    }
    printf("%s %s\n", students[maxid].name, students[maxid].no);
    printf("%s %s\n", students[minid].name, students[minid].no);
    return 0;
}
