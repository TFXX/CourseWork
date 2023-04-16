/*
【问题描述】将一段英文文章中字符串用给定的字符串替换。
【输入形式】输入包括多行，每一行为一段英文文章（长度不超过80）。以后每行包括2个字符串（长度不超过20），之间由空格分隔，第一个串为原串，第二个串为替换串，当遇到0 0两个串时表示输入结束，并且此行不需处理。注意：本题需要考虑原串和替换串的长度不同的三种情况。情况1：原串的长度大于替换串，如原串为are ，替换串为is。情况2：原串的长度等于替换串，如原串为h ，替换串为H。情况3：原串的长度小替换串，如原串为yes ，替换串为your。
【输出形式】输出替换后的文章。
【样例输入】hello how are yes.
h H
es ou
0 0
【样例输出】Hello How are you.
*/
#include <stdio.h>
#include <string.h>

int is_end(char *s)
{
    return s[0] == '0' && strlen(s) == 1;
}

void exchange(char *sText, char *sYuan, char *sTiHuan)
{
    unsigned long long textSize = strlen(sText);
    unsigned long long yuanSize = strlen(sYuan);
    unsigned long long tiHuanSize = strlen(sTiHuan);
    unsigned long long i = 0;
    for(; sText[i] != '\0'; i++)
    {
        if(!strncmp(sText + i, sYuan, yuanSize))
        {
            // 匹配成功
            if(yuanSize == tiHuanSize)
            {
                ;
            }
            else if(yuanSize < tiHuanSize)
            {
                // 后移
                const unsigned long long d = tiHuanSize - yuanSize;
                unsigned long long k = textSize;
                for(; k != i + yuanSize; k--)
                {
                    sText[k + d] = sText[k];
                }

                textSize += d;
            }
            else if(yuanSize > tiHuanSize)
            {
                // 前移
                const unsigned long long d = yuanSize - tiHuanSize;
                unsigned long long k = i + yuanSize;
                for(; k <= textSize; k++)
                {
                    sText[k - d] = sText[k];
                }

                textSize -= d;
            }

            strncpy(sText + i, sTiHuan, tiHuanSize);
        }
    }
}

int main(int argc, char **argv)
{
    char sText[1024];
    //gets(sText);
    scanf("%[^\n]%*c", sText);

    char sYuan[256];
    char sTiHuan[256];
    while(1)
    {
        scanf("%s %s", sYuan, sTiHuan);

        if(is_end(sYuan) && is_end(sTiHuan))
        {
            break;
        }
        exchange(sText, sYuan, sTiHuan);
    }

    puts(sText);
    return 0;
}