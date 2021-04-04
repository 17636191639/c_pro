#include <stdio.h>  
#include <string.h>  
  
/* 
函数表示：返回给定字符串中的最大子字符串长度 
参数：  src：原始字符串 
        sub：最大子字符串 
返回值：最大子字符串长度(不包含结尾的\0),因为strlen本来也不包含\0。 
说明： 
1. 如果存在多个子字符串的长度相同，返回第一个子字符串 
*/  
int get_max_repeat_sub_str(const char * src, char * sub) 
{  
    int length;             //原始字符串的长度  
    int max_len;                 //最大子字符串的长度  
    int tmp_max_len;            //最大子字符串的长度，临时，比较时使用  
    int i;  
    const char *p1, *p2;          //用来遍历字符串的两个指针  
    const char *p_max_len;                 //指向最终的子字符串的起始位置  
  
    length = strlen(src);  
 

    max_len = 0;  
    p1 = src;  
    p_max_len = src;  

    //从第一个字符开始遍历  
    while (*p1 != '\0') 
    {  
        //与前一个字符比较  
        for (p2 = p1 + 1; *p2 != '\0'; p2++) 
        {  
            tmp_max_len = 0;  
            //如果相等了，表示有可能出现最大连续字符串了，之后就要以p1和p2为起始，比较两者之后的字符串是否相等  
            if (*p1 == *p2) 
            {  
                //起始字符相等后，就开始比较两个字符串  
                for (i = 0; i < p2 - p1; i++) 
                {  
                    if (*(p1 + i) == *(p2 + i)) 
                    {  
                        tmp_max_len++;  
                    } else 
                    {  
                        if (tmp_max_len > max_len) 
                        {  
                            max_len = tmp_max_len;  
                            p_max_len = p1;  
                        }  
                        break;  
                    }  
                }  
            }   
        }  
        p1++;  
    }  
    strncpy(sub, p_max_len, max_len);  
    //最后需要手动加上一个\0  
    sub[max_len] = '\0';  
  
    return max_len;  
}  
  
int main() 
{  
    const char * src = "I am a Chinese and he is not Chinese";  
    char result[100];  

    int max_len;  
    printf("length of src is %d\n", strlen(src));  
    max_len = get_max_repeat_sub_str(src, result); 
    printf("result[%d]: %s\n", max_len, result);  
  
    return 0;  
}  
