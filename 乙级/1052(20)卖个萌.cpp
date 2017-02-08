#include <stdio.h>

int findNum(char part[]){
    int count1 = 0, i = 0;
    while(part[i]){
        if(part[i] == '[')
            count1++;
        i++;
    }
    return count1;
}

void myprint(char part[], int id){//����ҵ�������1�����û�ҵ�������0
    int count1 = 0;
    for(int i = 0; i < 100; i++){
        if(part[i] == '[')
            count1++;
        else if(count1 == id && part[i] != ']')
            printf("%c", part[i]);
        else if(count1 == id && part[i] == ']')
            return;
    }
}

int main(){
    char hand[100] = {'\0'}, eye[100] = {'\0'}, mouth[100] = {'\0'};
    gets(hand); gets(eye); gets(mouth);
    int handnum = findNum(hand), eyenum = findNum(eye), mouthnum = findNum(mouth);

    int num, id1, id2, id3, id4, id5;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf("%d%d%d%d%d", &id1, &id2, &id3, &id4, &id5);
        //��Ŀ��˵�����û�ѡ�����Ų����ڡ���Ҫע�����Ϊ������0�����
        if(id1 > 0 && id1 <= handnum && id2 > 0 &&  id2 <= eyenum && id3 > 0 && id3 <= mouthnum && id4 > 0 &&  id4 <= eyenum && id5 > 0 &&  id5 <= handnum){
            myprint(hand, id1);
            printf("(");
            myprint(eye, id2);
            myprint(mouth, id3);
            myprint(eye, id4);
            printf(")");
            myprint(hand, id5);
        }
        else
            printf("Are you kidding me? @\\/@");//ע�ⷴб��\Ҫ��ת���ַ�
        printf("\n");
    }
    return 0;
}
