#include <stdio.h>

int main(){
    char arr[81], newarr[41][81];
    gets(arr);

    int total_words = 0, word_start = 0;
    for(int i = 0; i < 81; i++){
        if (arr[i]){
            if (arr[i] == ' '){
                int newpos = 0;
                for(int j = word_start; j < i; j++){
                    newarr[total_words][newpos] = arr[j];
                    newpos++;
                }
                newarr[total_words][newpos] = '\0';
                word_start = i + 1;
                total_words++; //�������һ������֮��û�пո�����total_words���ָ�����һ���������ڵ���
            }
        }
        else{
            int newpos = 0;
            for(int j = word_start; j < i; j++){
                newarr[total_words][newpos] = arr[j];
                newpos++;
            }
            newarr[total_words][newpos] = '\0';
            break;
        }
    }

    for(int i = total_words; i >= 0; i--){
        if (i == total_words)
            printf("%s", newarr[i]);
        else
            printf(" %s", newarr[i]);
    }
    printf("\n");
    return 0;
}
