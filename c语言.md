# 概述
算法考试所有的题目（程序）操作都可以分为四部分：
1. 读入数据
2. 存储数据
3. 操作数据
4. 输出数据

有些考试中帮你完成了输入输出和存储操作，其将数据按一定的格式存储，并作为函数的输入，我们只需编写操作数据的部分并按规定格式返回操作后的数据即可。华为的考试中便是如此。
# 输入输出
C语言常用scanf和printf来完成数据的输入和输出，利用变量来存储数据，下面是变量数据类型和scanf,printf中格式控制符的对照。
| 数据类型|格式控制符|
|-- | --|
|int |%d|
|float |%f|
|double |%lf|
|char |%c|
|字符串 |%s|

## 单个变量
编写程序输出键盘输入的内容（整数），除了字符串之外的其他数据类型，按照表格中更换格式控制符即可
``` C
#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", n);
    float f = 1.0;
    printf("%.2f", f);

}
```

```C
#include<stdio.h>
    char main(){//这儿也是int main，int是main函数的返回类型，和操作啥无关
        char n;
        scanf("%c",&n);
        printf("%c",n);
        return 0;//一般加一个return 0;代表main函数正常执行完毕
    }
```

## 字符串
编写程序输出键盘输入的内容（字符串）
字符串是一种特殊类型的数据，在C语言中用字符数组来存储，且存储字符串的字符数组的最后一个元素为空字符(\0)。

空字符（Null character）又称结束符，缩写 NUL，是一个数值为 0 的控制字符，\0 是转义字符，意思是告诉编译器，这不是字符 0，而是空字符。
如创建一个字符串s = "string"，在计算机中的存储为{s, t, r, i, n ,g, \0}。
因此在读入时，把字符串放到待保存数组的起始地址中
``` C
#include<stdio.h>
int main(){
    char s[20];//长度根据字符串的可能长度来设置
    scanf("%s", s);//因为s是数组，故s本身就存的地址，故不用加&
    //可以直接记住，scanf字符串的时候不加&
    printf("%s", s);
    return 0;
}
```

```C
zq：
#include<stdio.h>
int main(){
    string s[20];
    scanf("%s",s);
    printf("s",s);
}
//错误原因：没有string定义，字符串里面还是字符，所以用char定义，记得scanf不要加&！！！！
```
```C
#include<stdio.h>
    int main(){
        char site[7]={'r','r','t','t','y','y','\0'};
        printf("cainiao:%s\n",site);
    }
//输出：cainiao：rrttyy

#include<stdio.h>
#include<string.h>
    int main()
    {
        char str1[14]="runoob";
        char str2[14]="google";
        char str3[13];
        int len;

        /*复制str1到str3*/
        strcpy(str3,str1);
        printf("strcpy(str3,str1):%s\n",str3);

        /*连接str1,str2*/
        strcat(str1,str2);
        printf("strcat(str1,str2):%s\n",str1);

        /*连接后str1的总长度*/
        //应该让定义的len等于这个strlen(str1);，而不是像上面两个一样直接在字符串上操作
        len = strlen(str1);
        printf("连接后str1的总长度：%d\n",len);
        return 0;
        //记得return0！！
    }
输出：
strcpy(str3,str1):runoob
strcat(str1,str2):runoobgoogle
连接后str1的总长度：12
```
其他的讲解可以看[菜鸟教程](https://www.runoob.com/cprogramming/c-strings.html)


# 数组
数组就是一组类型相同的变量，并且可以通过下标访问，这种方式比直接定义变量更加方便
数组下标从0开始，即数组a中，a[0]为第一个元素，a[1]为第二个元素，
## 遍历数组（操作每一个元素）
>例一：读入一个有n个元素的数组，并输出第k个元素
样例输入：
5 
1 2 3 4 5
3
样例输出：3
样例说明：第一行输入为n，第二行为数组元素，第三行为k
``` C
#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);//读入n
    int a[100];//预设一个100个元素的数组，假设n不会超过100，考试的时候根据数据范围设置
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);//逐个读入元素
    }
    int k;
    scanf("%d", &k);//读入k
    printf("%d", a[k - 1]);//第k个元素在数组中下标为k - 1
}
```

zq：
```C
#include<stdio.h>
    int main()
    {
        //一：怎么定义数组啊？int a[100]；
        int n;//定义数组数量
        scanf ("%d",&n);//读入n
        int a[100];//定义数组
        int k;//定义第k个数
        int i;//忘记定义了
        for (i=0;i<n;++i)//for循环依次读入数组元素
            {
                scanf("%d",&a[i]);//for循环功能
            }
        scanf("%d",&k);//读入k
        printf("第k个元素：%d",a[k-1]);//输出第k个元素
    return 0;
    }

```

>例二：读入一个有n个元素的数组，并输出所有元素
样例输入：
5 
1 2 3 4 5
样例输出：1 2 3 4 5

``` C
#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);//读入n
    int a[100];//预设一个100个元素的数组，假设n不会超过100，考试的时候根据数据范围设置
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);//逐个读入元素
    }
    
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);//逐个输出元素,输出多个元素的时候，注意用空格或是逗号分割元素，此处每次输出一个数组元素和一个空格
    }
}
```
zq：
```C
#include<stdio.h>
    int main ()
    {
        int n;//定义数组元素个数n
        int a[100];//定义数组
        int i=0;//定义初始值
        for(i=0;i<n;++i)//for循环
        {
            scanf("%d",&a[i]);//读入数组元素
            printf("%d",a[i]);//输出数组元素，没加空格

        }
    }
输出：
5 5 8 7 8 5 5
5 5 8 7 8 5 5

```

>例三：读入一个有n个元素的数组，把每个元素都加5，然后输出
样例输入: 
5
1 2 3 4 5
样例输出：6 7 8 9 10
``` C
#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);//读入n
    int a[100];//预设一个100个元素的数组，假设n不会超过100，考试的时候根据数据范围设置
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);//逐个读入元素
        a[i] += 5;//赋值语句，a+=b的意思就是a = a + b
    }
    
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}

zq:
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[100];
    int i;
    for (i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
        a[i]=a[i]+5;
        printf("%d",a[i]);//出错了，结果不对，为什么要用两个for循环呢？------没错，所以用一个for循环就可以呀？
    }
}
```
>例四：读入一个有n个元素的数组，输出其中的最大值
样例输入：
5 
9 8 10 4 5 
样例输出: 10
``` C
#include<stdio.h>
int max(int a, int b){
    if(a > b) return a;
    else return b;
}
int main(){
    int n;
    scanf("%d", &n);
    int a[100];
    scanf("%d", &a[0]);
    int ans = a[0];//用这个元素记录最大值，默认为第一个
    for(int i = 1; i < n; ++i){//因为已经提前读入了第一个元素，则从第二个开始读
        scanf("%d", &a[i]);
        ans = max(ans, a[i]);//如果这个元素比ans大，则当前元素可能成为最大值，则记录在ans中，等全部读完了，ans中的值就为最大值了
    }
    //max函数需要自己实现
    printf("%d", ans);
}

zq：
#include<stdio.h>
int max(int a , int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[100];
    for (int i=0; i<n; ++i)
    {
        scanf("%d",&a[0]);//想的不太对，是在循环之前先把第一个元素a[0]给读进来，当作最大值，后面的元素从a[1]开始进来比较


    }
}

zq修改版：没让ans=max(ans.a[i]);
#include<stdio.h>
int max(int a , int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[100];
    scanf("%d",&a[0]);
    int ans = a[0];
    for (int i=1; i<n; ++i)
    {
        scanf("%d",&a[i]);
        max(ans,a[i]);//错了，应该让ans=max(ans,a[i])
    }
    printf("%d",ans)
}

输出
6
6 9 5 79 5 2
79
```

>读入一个有n个元素的数组，输出他们的和
样例输入：
5 
1 2 3 4 5 
样例输出：15
``` C
#include<stdio.h>
int main(){
    int sum = 0;//记录数组的和
    int a[100];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        sum += a[i];//累计相加
    }
    printf("%d", sum);
}
zq：
#include<stdio.h>
int main ()
{
    int n;
    scanf("%d",&n);
    int sum;//sum应该为0
    int a[100];
    for (int i=0 ; i < n ;++i)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    printf("%d",sum);
}
```
## 数组倒序
>读入一个有n个元素的数组，把他们倒着输出
样例输入：5 1 2 3 4 5
样例输出：5 4 3 2 1
```C
#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[100];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = n - 1; i >= 0; --i){//从n - 1循环到0，就先输出后面的，再输出前面的，完成了倒序输出
        prinf("%d ", a[i]);
    }
}

zq:报错
#include<stdio.h>
int main ()
{
    int n;
    scanf("%d",&n);
    int a[100]；
    int i;
    for(i=0;i<n;++i)//int i=0报错
    {
        scanf("%d",&a[i]);
    }
    for(i=n; i>=0; --i)//应该改为n-1
    {
        printf("%d",a[i]);
    }
}

```

# 字符串
字符串是一种特殊的数据类型，在c语言中用字符数组来存储
c语言中有一些现成的字符串函数可以用来操作字符串
函数| 目的
|--- |--- |
|strcpy(s1, s2)|复制字符串s2到字符串s1。
strcat(s1, s2)|连接字符串s2到字符串s1的末尾。
strlen(s1)|返回字符串s1的长度。
strcmp(s1, s2) |如果s1和s2是相同的，则返回0；如果s1<s2则返回小于0；如果s1>s2则返回大于 0。
strchr(s1, ch)|返回一个指针，指向字符串s1中字符ch的第一次出现的位置。
strstr(s1, s2)|返回一个指针，指向字符串s1中字符串s2的第一次出现的位置。

这些函数功能非常强大，也非常常用，但是手动实现一遍既可以加深对字符串的理解，也可以锻炼代码能力，同时也可以避免在考试的时候忘了参数和返回值都是什么不会调用函数，因此下面的例题都使用两种方法解答，一种为利用库函数，另外一种为手动实现相应的功能。
考试时选取自己熟悉的方式即可。
## 统计字符串长度
>输入一个字符串，输出他的长度
样例输入：abcdef
样例输出：6

函数版：
``` C 
#include<stdio.h>
#include<string.h>//字符串函数所在的库
int main(){
    char s[100];//开一个字符数组存储字符串
    scanf("%s", s);//因为s是数组，因此s本身就代表地址，故不用加&
    printf("%d", strlen(s));
}
zq:
#include<stdio.h>
#include<string.h>
int main()
{
    char str;//不对，因为应该是char str[100]
    scanf("%s",str)
    printf("%s",strlen(str));//!!!!!输出的是长度，%d
}
```
手动版：
``` C
#include<stdio.h>
int main(){
    int len = 0;
    char s[100];
    scanf("%s", s);
    while(s[len] != '\0'){//只知道结尾处会有'\0'，那就一直往后读，一直到'\0'为止
        len++;//每读到一个不是\0的，计数器就+1
    }
    printf("%d", len);
}
```
## 遍历字符串
>输入一个字符串，逐个输出其中的字符
样例输入：abcdef
样例输出：a b c d e f
函数版：
```C
#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    scanf("%s", s);
    int len = strlen(s);//先统计长度，把字符串按一个有len个元素的字符数组处理
    for(int i = 0; i < len; ++i){
        printf("%c ", s[i]);
    }
    return 0;
}
zq：
#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    scanf("%s",s);
    int len = strlen(s);
    for(int i=0;i<len;++i){
        printf("%s",s[i]);//错在%c啦，这个时候输出的是字符不是字符串咯
    }
}
```
手动版：
```C
#include<stdio.h>
int main(){
    char s[100];
    scanf("%s", s);
    int i = 0;
    while(s[i] != '\0'){
        printf("%c ", s[i]);
        i++;
    }
}
```
## 复制字符串
>读入字符串到s2，然后复制到s1中，并输出s1
样例输入：abc
样例输出：abc
函数版
```C
#include<stdio.h>
#include<string.h>
int main(){
    char s1[100];
    char s2[100];
    scanf("%s",s2);
    strcpy(s1, s2);
    printf("%s", s1);
}

zq:
#include<stdio.h>
#include<string.h>
int main(){
    char s1[100];
    char s2[100];
    scanf("%s",s2);
    strcpy(s1,s2);
    printf("%s",s1);
}
```
手动版
```C
#include<stdio.h>
#include<string.h>
int main(){
    char s1[100];
    char s2[100];
    scanf("%s",s2);
    int cnt = 0;//cnt代表s1中有多少个字符，同时作为待写入位置的下标
    //策略为一个一个的元素往s1中填充，填完之后最后加上'\0'作为结束符
    int len = strlen(s2);//统计长度按数组处理
    for(int i = 0; i < len; ++i){
        s1[cnt++] = s2[i];//逐个填充
    }
    s1[cnt] = '\0';//最后加上结束符
    printf("%s", s1);
}
```

>输入一个字符串s，将其反转之后连接到其末尾然后输出（2024哈工大复试机试原题）
样例输入：abcd
样例输出：abcddcba
函数版
```C
#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    scanf("%s", s);
    int len = strlen(s);
    char s1[100];//存储反转的字符串
    for(int i = 0; i < len; ++i){
        s1[len - i - 1] = s[i];//两个下标加起来为len - 1，就是对称的位置
    }
    s1[len] = '\0';//记得加入结束符
    strcat(s, s1);
    printf("%s", s);
}
zq：//没加结束符,但是纯自己做的哦！！！！！
#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    char sn[100];
    scanf("%s",s);
    int len = strlen(s);//获取s的长度
    int i;
    int cnt=0;//往sn里面一个一个倒着填s的元素

    for(i=len-1;i>=0;--i){//一开始写的i<1不对，从len-1到s[0],填入sn
        sn[cnt++]=s[i];
    }
    sn[len] = '\0';
    strcat(s,sn);//把sn连到s后面
    printf("%s",s);

}

```
手动版
```C
#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    scanf("%s", s);
    int len = strlen(s);
    char s1[100];//存储反转的字符串
    for(int i = 0; i < len; ++i){
        s1[len - i - 1] = s[i];//两个下标加起来为len - 1，就是对称的位置
    }
    char s2[200];//存储答案，注意长度
    int cnt = 0;//新字符串的下标
    for(int i = 0; i < len; ++i){
        s2[cnt++] = s[i];//原本的放到前面
    }
    for(int i = 0; i < len; ++i){
        s2[cnt++] = s1[i];//反转的放到后面
    }
    s2[cnt] = '\0';
    printf("%s", s2);
}
```
## 比较字符串
字符串可以按照ascii比较大小，ascii的小，比如abc<abd，ab < abc。如果两个字符串不等长，且前面部分字典序相等，则长的大于短的（即可以理解为短的后面补'\0'。
>输入两个字符串s1和s2，若s1更大输出1，s2更大输出-1，二者相等输出0
样例输入：
abcd abce
样例输出：0

函数版：
```C
#include<stdio.h>
#include<string.h>
int main(){
    char s1[100];
    char s2[100];
    scanf("%s", s1);
    scanf("%s", s2);
    int ans = strcmp(s1, s2);
    if(ans > 0) printf("1");
    else if(ans < 0) printf(" -1");
    else printf("0");
}
zq：
#include<stdio.h>
#include<string.h>
int main(){
    char s1[100];
    char s2[100];
    scanf("%s",s1);
    scanf("%s",s2);
    int ans = strcmp(s1,s2);
    int end;
    if(ans<0)
        return end = -1;//错了，不应该有return，删掉return就对啦
    else if (ans>0)
    {
        return end = 1;
    }
    else
        return end =0;
    printf("%d",end);

}

```
手动版
```C
#include<stdio.h>
#include<string.h>
int cmp_str(char* s1, char* s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i = 0;
    while(i < len1 && i < len2 && s1[i] == s2[i]){//如果相等，就一直往后扫描，直到二者不相等
        i++;
    }
    return s1[i] - s2[i];
}
int main(){
    int ans = cmp_str(s1, s2);
    if(ans > 0) printf("1");
    else if(ans < 0) printf(" -1");
    else printf("0");
}
```

# 排序
上面两章讲述了算法考试中的常见数据类型以及在C语言中的存储方式和对特定数据类型的基本操作
下面将讲述一些其他的基本操作。
## 冒泡排序
[直接看视频吧](https://www.bilibili.com/video/BV1qY4y1h7Lz/)
这个和qsort一定都要会，冒泡排序是稳定的排序，题目中可能会要求，大小相同者按输入顺序（倒序）输出，这种情况下qsort不一定好使。
```C
void swap(int* x, int* y){//交换两个元素，用到指针操作
    int temp = *x;//先存储第一个元素
    *x = *y;//第二个放到第一个里面
    *y = temp;//备份的第一个元素放到第一个里面
}

void Bubble_sort(int a[], int n){//基础写法
    for(int i = n - 1; i > 0; --i){//i代表区间长度，每一趟排序后，最后一个元素就位
        for(int j = 0; j < i; ++j){
            if(a[j + 1] < a[j]){//从小到大排序，如果后面的更小，则交换
                swap(&a[j + 1], &a[j]);//如果这写<=的话，相同大小者在排完序后会倒序
            }
        }
    }

}
```

**例题**
>输入n个同学的身高和体重，按身高从小到大排序，身高相同的按体重从小到大排序
样例输入：
5
180 80
180 90
181 92
170 77
175 65
样例输出：
170 77
175 65
180 80
180 90
181 92

思路：
**总体思路：把数据读进来，存到数组里，然后对这个数组进行排序，然后输出。**
1.先考虑怎么存储数据（数组的数据类型）：每个同学有两个参数，身高和体重，而且需要绑定存储，因此考虑用结构体存储，故定义一个stu结构体，有身高height和体重weight两个参数
```C
struct stu{
    int height, weight;//身高和体重
};
```
2.定义完用来存储数据的单元后，将数据读入并存储，之后的任务是排序，那就写一个选择排序
```C
int n;
scanf("%d", &n);
struct stu S[100];
for(int i = 0; i < n; ++i){
    scanf("%d %d", &S[i].height, &S[i].weight);
}
//冒泡
for(int i = n - 1; i > 0; --i){
        for(int j = 0; j < i; ++j){
            if(){//发现这里不是一个单一变量了，不好直接比较
                swap(&S[j + 1], &S[j]);
            }
        }
    }
```
3.由于使用结构体，判断元素是否有序的条件不方便用一句话表达，因此if中的条件考虑用函数表达，函数中内容按题意直接表达即可，函数参数为两个结构体元素a和b，返回值为1代表a应该排在b前面，为0代表b应该排在a后面
```C
int cmp(struct stu a, struct stu b){//由于有些c编译器不支持bool，因此使用int，返回值为1代表真，返回值为0代表假
    if(a.height == b.height) return a.weight < b.weight;//如果身高相同，则返回体重的比较结果
    else return a.height < b.height;//如果身高不同，则返回身高的比较结果
}
```
4.输出排序后的元素即可，最终代码如下：

```C
#include<stdio.h>
struct stu{
    int height, weight;//身高和体重
};

int cmp(struct stu a, struct stu b){
    if(a.height == b.height) return a.weight < b.weight;//如果身高相同，则返回体重的比较结果
    else return a.height < b.height;//如果身高不同，则返回身高的比较结果
}
void swap(struct stu *a, struct stu *b){
    struct stu temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int n;
    scanf("%d", &n);
    struct stu S[100];
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &S[i].height, &S[i].weight);
    }

    //排序部分
    for(int i = n - 1; i > 0; --i){
        for(int j = 0; j < i; ++j){
            if(!cmp(S[j + 1], S[j])){//如果cmp函数返回值为真，则说明a[i]应当排在a[j]之前，所以当cmp返回值为假时，应该交换两个元素
                swap(&S[j + 1], &S[j]);
            }
        }
    }
    for(int i = 0; i < n; ++i){
        printf("%d %d\n", S[i].height, S[i].weight);
    }
    return 0;
}
```
**[例2.车厢重组](https://www.luogu.com.cn/problem/P1116)**
先仔细阅读一下题目，关键词是“每次只能交换相邻的车厢”，“对车厢进行排序”，发现这个题的任务其实就是，对一个序列进行排序，每次只能交换相邻的两个元素，求需要多少次交换，可以完成对这个序列的排序。
不难联想到利用冒泡排序方法，在每次交换时，加一个计数器，统计出数量即可。

## qsort函数
qsort函数是C语言中自带的快速排序函数，其用法如下：
qsort(待排序序列的首元素指针，序列元素个数，序列元素大小，比较函数);
其中比较函数可以自己编写
不知道网上为什么都非要定义成void类型然后再转换，可读性极差，因为老版本的编译器中，编写函数要严格按照声明来，但是现在版本其实已经不用。
导致我一直没有学会这个东西怎么用，今天经过实践发现，其实cmp函数的写法很简单，下面是一个例子：
```C
//把数组元素从小到大排序
#include<stdio.h>
int cmp(int* a, int* b) {//待排序的序列中元素是什么类型，这儿两个参数就是什么类型的指针，这样写可能会有warning，在某些版本的编译器里可能跑不通
    return *a - *b;//这个返回值为负的，就说明a应该在b前面，否则a在b的后面
}
//如果不放心，就这么写
int cmp_nowarning(const void* a, const void* b) {
    int* x = (int*)a;
    int* y = (int*)b;//先转换过来，然后操作x和y，而不是每次转换
    return *x - *y;
}
//对比网上的版本
int cmp_network(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);//这玩意看着谁有用的欲望？
}
int main(){
    int* a = (int*)malloc(sizeof(int)*100);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    for(int i = 0; i < n; i++){
        printf("%d", a[i]);
    }
    return 0;
}

```
有了上面的优化版本，在编写cmp函数的时候，只需专注于序列本身的逻辑即可，不再被眼花缭乱的指针类型转换困扰
>输入n个字符串，将其按字典序排序之后输出
```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a, const void *b){
    char** x = (char**)a;//strs的每个元素是指向char的指针，即char*，则传进来的是指向char*的指针，即char**
    char** y = (char**)b;
    return strcmp(*x, *y);
}

int cmp_mamul(const void *a, const void *b){//手动实现字符串比较
    char* x = *((char**)a);//定义一个char*类型变量，其中存储的是指向这个字符串首个元素的指针
    char* y = *((char**)b);
    int i = 0;
    int lena = strlen(x);
    int lenb = strlen(y);
    while(i < lena && i < lenb && x[i] == y[i]){//如果相等就一直往后比，直到一个到了结束符或者不相等
        i++; 
    }
    return x[i] - y[i];
}
int main(){
    char* strs[100];
    for(int i = 0; i < 100; i++){//100个字符串，每个最大长度为100
        strs[i] = (char*)malloc(sizeof(char)*100);
    }
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", strs[i]);
    }

    qsort(strs, n, sizeof(char*), cmp);//在这儿因为是一个char*数组，所以每个大小为sizeof(char*)

    for(int i = 0; i < n; i++){
        printf("%s\n", strs[i]);
    }
    return 0;
}
```
# 函数
函数又称子程序，对于实现某个特定的功能的过程，可以以函数的形式编写，然后调用。
大部分问题的求解思路都是“大事化小，小事化了”，即将问题分成一些小问题，再将问题分成基本的操作，直至可以通过最基本的操作实现。那么在编写程序的过程中，将每个小问题都编写成函数，逐个解决，相比于将所有基本操作罗列在主程序中，思路更加清晰明确，也便于调试。

如求两个数的最大值
``` C
int _max(int a, int b){
    if(a > b) return a;
    else return b;
}
```
那么我们在需要的时候就可以调用
```C
int main(){
    int a = 5;
    int b = 7;
    int x = _max(a, b);
}
```
对于上面的程序，我们一眼就可以看出，其是将a，b值较大者赋给x，但如果这样写：
```C
int main(){
    int a = 5;
    int b = 7
}
```

## 形参和实参
具体是啥我到现在也不懂，这都从哪儿搞出来的名词，反正我统一叫函数的参数
然后主要理解函数的执行过程，就不会弄混
还是看上面的例子，我们完整的写一下，方便后面的讲解
```C {.line-numbers}
int _max(int a, int b){
    if(a > b) return a;
    else return b;
}
int main(){
    int a1 = 5;
    int b1 = 7;
    int x = _max(a, b);
}
```
下面来完整的执行一下这个程序。
main函数为整个程序的入口，故程序从第5行，main开始执行
先执行第一句，定义一个整型变量a，并且赋值为5
再定义一个整型变量b，赋值为7
定义一个变量值x，待赋值为_max函数，参数为a和b的返回值
此时_max被调用，程序跳转到_max函数处，即第一行开始执行
此时，执行_max函数中的内容时，先执行操作：
int a = a1;
int b = b1;
即将调用函数处，传递给函数的参数，赋值给函数接口处的参数变量,
然后再执行函数中的if语句，最终返回特定的值。
如果将函数完全展开，则应该像下面这样写：
``` C
int main(){
    int a1 = 5;
    int b1 = 7;

    int a = a1;
    int b = b1;
    int x;
    if(a > b) x = a;
    else x = b;

    return 0;
}
```
两段代码对比一下，不难发现函数的优点
1. 使代码逻辑更清晰
2. 可以不考虑变量重名的问题，方便迁移


# 指针
## 变量在内存中的存储方式
在计算机中，所有数据都被以01的二进制方式，在内存中存储，读取时通过不同的编码方式，来区分开不同的类型。如二进制形式0011 0000按照int类型解码，则得到48，而按照char类型解码，则得到字符'0'（ascii码为48）。
不同的数据类型，每位数据表达的含义不同，每个单位数据所包含的位数也不同。如每个int类型数据用32位二进制数来存储，每个char类型的数据用8位二进制数来存储。下面列出了常见数据类型所占的二进制位数：
|数据类型|所占二级制位数|
|-- | -- |
|int|32|
|char|8|
|long long|64|
|float|32|
|double|64|

所以，int类型也经常被称作32位整型，long long经常被称为64位整型。

### sizeof函数
在写程序时，我们经常也要知道，一个变量占多大的空间，所有的都去自己记自己算也太麻烦了，不同计算机上可能占的还不一样，因此C语言中提供了sizeof函数，可以得到数据单元所占的字节数（8位二进制数为一个字节）
下面是几个例子
```C
#include<stdio.h>
int main(){
    int n;
    double d;
    char c;
    int a[100];
    int size_n = sizeof(n);
    int size_d = sizeof(d);
    int size_c = sizeof(c);
    int size_a = sizeof(a);

    printf("%d %d %d %d", size_n, size_d, size_c, size_a);
    return 0;
}
```
想知道数据类型所占的空间，也可以用sizeof函数
```C
#include<stdio.h>
int main(){
    printf("%d %d %d %d", sizeof(int), sizeof(char), sizeof(double), sizeof(float));
}
```

## 指针变量
每一块内存都有他们自己对应的地址，指针变量里面所存储的内容便是内存地址。
一般变量的地址值可以用&运算符得到

比如这样
|地址| 内容 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
---|----| 
0|00 00 00 20|
4|00 00 04 67|
8|08 44 00 00|
12|00 00 03 12|
16|00 00 16 04|

以十六进制表示，每两个数代表一个字节（8位）
指针变量和普通变量的区别就在于，其存放的不是变量本身的内容，而是存放了一个内存地址。
通过操作符*，可以访问这个变量内容所指向的内存处的值，而仅有地址还不够，还需知道读几个字节的内容，才能完成对内容的解码。因此指针变量也需要有类型，即在定义时的int*,char*。
故，访问int* 类型指针变量所指内存的值时，计算机会从变量中所存地址处，读四个字节的内容，并且按照int类型解码。如 在上面的例子中，若定义int* a = 0，则*a的值为32。（但是真正使用的时候一般不会直接给指针变量赋值），若需要赋值，一般通过取地址符号&来得到存放其他变量位置的内存地址。

指针变量也可以做运算，但一般仅跟常数相加
定义整型指针变量int* a，那么a + 1的意义是，a后面一个整型变量单元的地址
如果打印一下的话发现a和a+1其实差4，也就是sizeof(int)
a - 1同理，就是a前面一个整型变量的起始地址

```C
#include<stdio.h>
int main(){
    int *a = 4;//此处仅为了说明，实际定义指针变量一定一定不能这么直接赋值
    //正确写法应该是再定义一个变量n，然后让a = &n，此处为了方便说明指针变量和常量加减的运算才这样书写
    printf("%d %d %d", a, a + 1, a - 1);
    return 0;
}
```

**补充**：计算机中最基本的，不能再细分的操作有三种：
1. 计算: 
包含加，减，乘，除，位移，比较（大于小于等于）
2. 跳转
修改下一条指令的位置（默认为当前执行指令的下一行）
3. 访存
访问内存，取出里面的值

我们用到的所有操作都可以切分成这三种操作来执行
如：
语句a = a + b
可以拆分为：
从a和b中读取值
把这两个值相加
把相加的结果放到a中

``` C{.line-numbers}
if(a > b){
    a = 1;
}
else{
    a = 2;
}
```
可以拆分为：
从a,b中取出值
比较这两个值
若比较结果为大于，则将下一条指令修改为第5行

而语句b = *a则可以拆分为：
读取a中的值
访问这个值所在的内存地址，并读出里面的值
将这个值写入b
## 指针和数组

数组作为一组连续的相同类型的变量，其在C语言中本质就是对指针变量的访问
定义数组int a[100]; 计算机会在内存中开辟一片连续的空间（大小为sizeof(int) * 100)，然后将这片内存的起始地址存在指针变量a中。然后当我们需要访问数组中下标为i的元素时，计算机就从起始地址+sizeof(int)*i处，取四个字节的内容，按int类型解码，得到该值，是不是非常神奇，看似a是是个数组，但是他是个指针变量。
不信我们可以试试
```C
#include<stdio.h>
int main(){
    int a[100];
    //如果上面说的成立，那这俩输出的结果应该是一样的，都是a的起始地址
    printf("%d\n", &a[0]); 
    printf("%d\n", a);

    //这俩也应该一样，还都是5
    a[0] = 5;
    printf("%d\n", a[0]);
    printf("%d\n", *a);
    return 0;
}
```
其实，a[i]的底层操作，和*(a + i)是一样的，都是在起始地址+sizeof(int)*i处取出内容，二者写法等价，a[i]仅仅是直观，好写而已
## 指针的用法

### 传递参数

#### 操作内存中的内容
在前文中介绍的函数，是程序的一个过程，但是在不借助指针时，实现不了更改变量内容的功能，比如我需要实现，计算a和b的和，并将结果存储到二者较大的变量中。似乎借助上面的传参方式，不太好实现。
那么此时，可以考虑设计一个操作内存的函数，而非计算的函数，即把将函数的参数类型设为指针变量，即将地址作为参数传递给函数
```C
void sum(int* a, int* b){
    int temp = *a + *b;
    if(*a > *b) 
        *a = temp;
    else 
        *b = temp;
}
```
这个函数的意义可以解读为：
将内存地址a和内存地址b中的内容相加，放到变量temp中
如果内存地址a中的内容大于内存地址b中的内容，则将temp存入内存地址a
否则将temp中的内容存入内存地址b

在调用时可以这样操作：
```C
#include<stdio.h>
int main(){
    int a = 2;
    int b = 3;
    sum(&a, &b);//将a的地址，b的地址传给函数
    printf("%d %d\n",a,b);
    return 0;
}
```

还有一个典型应用就是，交换两个变量的值
```C
void swap(int* a, int* b) {
    int temp = *a;//先备份内存地址a中的内容到temp中
    *a = *b;//把内存地址b中的内容写到内存地址a中
    *b = temp;//把temp中的内容写到内存地址b中
}
```

#### 数组作为参数
既然数组可以作为一些相同类型变量的集合，那么是否可以做函数参数，答案是可以的
下面函数将对一个数组的值求和，并返回这个和
```C
int sum_array(int* a, int a_size){
    int sum = 0;
    for(int i = 0; i < a_size; ++i){
        sum += a[i];//此处替换成*(a + i)也是可以的
    }
    return sum;
}
int main(){
    int a[100];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    printf("%d", sum(a, 3));//求前三个值的和
    return 0;
}
```
也可以在函数中操作数组中的元素：
```C
void add(int* a, int a_size){//给数组中的每个元素都+1
    for(int i = 0; i < a_size; i++){
        a[i] += 1;
    }
}
```
同理，字符串也可以以同样的方式作为参数，这里可以把前面的**字符串基本操作的手动版写成函数形式，作为小练习**

如：
```C
#include<stdio.h>
int my_strlen(char* str){
    int len = 0;
    while(s[len] != '\0'){//只知道结尾处会有'\0'，那就一直往后读，一直到'\0'为止
        len++;//每读到一个不是\0的，计数器就+1
    }
    return len;
}
int main(){
    char s[100];
    scanf("%s", s);
    int len = my_strlen(s);
    printf("%d\n", len);
    return 0;
}
```

至此，基本上任何能编写出来的操作，都可以通过函数实现了。


### 动态分配内存malloc
前面的数组定义基本都是通过直接定义实现，如定义一个100个元素的int类型数组，通常都写作int a[100]。但是这样分配的内存都在栈区，容易出问题（具体为啥先不用管，就知道栈里面的空间分配比较随意，而且可用的空间比较少就行），所以对于函数中定义数组的操作，最好通过指针+malloc函数来执行，这样会在内存的堆区分配空间（堆区空间管理的较有调理，且可用空间多，不容易出问题）
malloc函数以长度作为参数，表示需要的内存字节数，其返回一个内存地址值，代表系统分配给你所需大小内存的起始地址。

所以我们可以这样用他，假设现在需要一个100个元素的整型数组

```C
#include<stdio.h>
#include<stdlib.h>//malloc函数所在的库
int main(){
    int *a = (int*)malloc(sizeof(int)*100);
    //定义一个指针变量，用来存放这片内存的起始地址
    //(int*)代表将malloc的返回值转换成int类型指针，以便后续操作
    //参数通过写类型所占字节*所需单元个数来表达，比直接写数更清晰更易修改
    
    //下面再分配一个100个元素的字符数组（字符串）
    char* str = (char*)malloc(sizeof(char)*100);
}
```
这些分配出来的空间，里面可能原本就存着一些元素，没有固定的初始值。因此在使用之前，如果不确定所用到的元素是否都会被设置上想要的值，最好对其进行清零

```C
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *a = (int*)malloc(sizeof(int)*100);
    for(int i = 0; i < 100; ++i) a[i] = 0;
    return 0;
}   
```

**小练习： 可以把前面的数组还有字符串操作里面的数组定义，改成malloc+指针试一试**

## 指针和结构体

### 结构体的定义和存储方式
c语言中还有一类复合数据类型，称作结构体，其实也可以称作自定义数据类型。其底层逻辑和数组其实差不多，都是通过读取首地址+偏移量位置处指定字节的内存中的内容进行解码，来读取指定的数据。
定义一个结构体如下：
```C
struct example{//结构体的声明，说明这种数据类型由哪些元素组成，起名叫做example
    int data;
    char name[20];
    int* next;
};

int main(){
    struct example e;//定义一个example类型的变量
    e.data = 5;
    strcpy(e.name, "exampleaaaaaaa");
    int n = 7;
    e.next = &n;

    //可以通过.名称的方式访问里面的小变量

    printf("%d %s %d\n", e.data, e.name, *e.next);
    printf("%d %d\n", e, &e);//都输出出来看看，直接读e会读出来什么
    printf("%d %d", sizeof(e), sizeof(struct example));
    return 0;
}
```
经过上面的测试，在例子中结构体变量e，是一个大小为28字节的元素。
不难猜测，其前面4个字节用于存放int变量data，再往后20个字节用于存放字符数组name，最后四个字节用于存放指针变量next。
即e.data就是访问e的前四个字节，按int类型解码
e.name就是访问e从第五个字节开始至第25个字节，按char数组类型解码（其实也是个指针）
e.next就是访问e里面的最后四个字节，按int指针类型解码

### 结构体指针
那么结构体变量也可以定义指针，并且按存储方式可以直接实践访问
用指针直接访问内存实践一下试试
```C
struct example* ee = &e;
printf("%d\n", *(ee));
printf("%s\n", ((char*)ee + 4));//ee是example类型的指针，故ee+1是ee往后20个字节，转成char类型的指针之后，ee+4是ee往后四个字节
//第三个变量需要涉及到二级指针，过于繁琐，一般没人用
```
这样写好像也很麻烦，又要类型转换，又要计算位置
故C语言中给了访问结构体指针变量中内容的方式。
```C
struct example* ee = &e;
printf("%d\n", ee->data);//ee->data就等于*(ee)
printf("%s", &ee->name);//ee->name相当于取ee中name对应位置中的内容，但要做字符串输出，故还需要取出来地址
printf("%d", *(ee->next));
```

### 结构体指针的用处
这个比较典型的应用就是qsort里面的cmp，可以用来给结构体排序
因为cmp函数都是用指针传参，所以必须要会操作结构体指针
下面用qsort完成一下排序章节中的例题：按身高体重排序

```C
#include<stdio.h>
#include<stdlib.h>
struct stu{
    int height, weight;//身高和体重
};

int cmp(struct stu* a, struct stu* b){
    if(a->height == b->height) return a->weight - b->weight;
    else return a->height - b->height;
}
//无warning版
int cmp_nowarning(const void* a, const void* b){
    struct stu* x = (struct stu*)a;
    struct stu* y = (struct stu*)b;
    if(x->height == y->height) return x->weight - y->weight;
    else return x->height - y->height;
}

int main(){

    int n;
    scanf("%d", &n);
    struct stu S[100];
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &S[i].height, &S[i].weight);
    }

    qsort(S, n, sizeof(struct stu), cmp_nowarning);
    for(int i = 0; i < n; ++i){
        printf("%d %d\n", S[i].height, S[i].weight);
    }
    return 0;
}
```
# 其他典型操作

## 进制转换
### 基本原理
数$x$在$k$进制下的表示$a_na_{n - 1}...a_0$，即为$a_n*k^n + a_{n - 1} * k^{n - 1} + ... + a_1 * k^1 + a_0 * k^0$，其中$a_n$的取值范围为$0$到$k - 1$，$n$为使$k^n < x$的最大整数。
例如十进制数263，可以写为$2 * 10^2 + 6 * 10^1 + 3 * 10^0$，也可表示为$4*8^2 + 0 * 8^1 + 7 * 8^0$，故十进制数263在8进制下的表示为407。
有了以上理论，那么对于任意数$x = a_n*k^n + a_{n - 1} * k^{n - 1} + ... + a_1 * k^1 + a_0 * k^0$，想得到其在$k$进制下的表示，只需求出$\{a_n\}$中的各项即可。

不难发现，$x - a_0$可以被$k$整除，故有$x\%k = a_0$，且在计算机整除操作下$x/k = a_n*k^{n - 1} + a_{n - 1} * k^{n - 2} + ... + a_1 * k^0$，故根据这两个公式，可以迭代逐项求出$\{a_n\}$：
$x\%k = a_0$
$(x/k) \% k = a_1$
$((x/k)/k) \% k = a_2$
$......$
$(x/k^n)\%k = a_n$
不难发现，$x/k^{n + 1} = 0$，故不用专门求出n，一直重复上面的步骤，每次将x除k，直到x为0停止迭代即可。
自左向右将$\{a_n\}$各项排开，即得到$x$在$k$进制下的表示。
但在计算过程中，先得到$a_0$，最后得到$a_n$，但在输出时要先输出$a_n$，最后输出$a_0$，即先得到的值后输出，后得到的值先输出，因此可以使用栈这个数据结构来进行操作。
故不难写出代码：
```C
void Num_k(int x, int k){//数x在k进制下的各项系数
    int stack[100];//栈
    int top = 0;//栈顶指针

    while(x){//直到x= 0，停止
        stack[top++] = x%k;//放到栈中
        x/=k;
    }
    
    while(top){//弹出栈中元素
        printf("%d", stack[--top]);//此处top为待写入位置，故top-1为栈顶元素，故使用--top
    }
}
```

### 基本操作
通常情况下，数都以十进制形式给出，上文中的Num_k函数就是将十进制数x转为k进制表示的方法。将该方法反过来，就可以从k进制得到十进制。
对于给出n进制，转成m进制的问题，那就先把n进制转十进制，然后再把十进制转m进制。

```C
int K_num(char* num, int k){//k进制数num以字符串形式给出
    int ret = 0;
    int len = strlen(num);
    int mul = 1;//k的i次方
    for(int i = len - 1; i >= 0; --i){//方便累乘，从低位往高位遍历，最低位为a0
        ret += (num[i] - '0') * mul;//因为是字符，故要减去‘0’
        mul *= k;
    }
    return ret;
}
```
### 例题
![21](https://i.imgur.com/hxtGBTn.png)

题目要求就是把十进制数k转成m进制，然后统计有多少个n。
那就先完成进制转换，存到数组里，然后再统计数字就可以了。这儿不要求输出，进制，所以都不用把结果反过来。

下面的代码都按考试规范写，main函数中完成输入输出，解决问题的函数单独实现。
```C
#include<stdio.h>
#include<string.h>
int Solve(int k, int n, int m){//待实现函数
    int a[100];//存放m进制数
    int cnt = 0;//位数
    while(k){
        a[cnt++] = k%m;
        k/=m;
    }
    int ans = 0;//幸运数字的个数，初始为0
    for(int i = 0; i < cnt; ++i){
        if(a[i] == n) ans++;
    }
    return ans;
}

int main(){
    int n, m ,k;
    scanf("%d %d %d", &k, &n, &m);
    printf("%d", Solve(k, n, m));
    return 0;
}
```
## 字符串/数字转换
### 字符串转数字
>给定一个只包含0-9的字符串，如"124"，将其转成int形式。

思路和k进制转10进制差不多，一共三位，那就是$1*10^2 + 2 * 10^1 + 4$，也可以表示为
$((1*10) + 2)*10 + 4$(提公因式)，这样就是遍历字符串，每次将之前的数*10，再加上当前字符和字符0的差值即可

``` C
int str2num(char* str){
    int len = strlen(str);
    int ret = 0;//存放整数的位置
    for(int i = 0; i < len; ++i){
        ret = ret*10 + (str[i] - '0');//一定记得加括号，否则可能会溢出
    }
    return ret;
}
```
### 数字转字符

>给定一个int类型的数字，读出每一位放到字符数组str中

这个思路和十进制转其他进制差不多，每次$\%10$取一位，然后$/10$抹掉最后一位，再取模求最后一位，然后反转即可
``` C
char* num2str(int num){
    char ret[20];
    char stack[20];
    int top = 0;//栈顶指针
    int cnt = 0;
    while(num){
        stack[top++] = num%10;//先放到栈中
        num/=10;
    }
    //出栈，将结果倒序，得到正序的字符
    while(top){
        ret[cnt++] = stack[--top];
    }
    return ret;
}
```
## 标记数组
这是一种思想，用数组下标作为编号，然后数组中存储相应编号所对应的内容。最典型的应用是桶排序。
对于一个序列[3, 2, 3, 4, 4, 5]，要进行排序，如果我知道了，里面的每个数，各出现了多少次，那么从小到大拿出来放置，即完成了排序。
如上面序列里面有一个2，两个3，两个4， 一个5，那么现在如此构造序列，放置一个2，再放置两个3，再放置两个4，再放置一个5，便得到了序列。
那么如何完成统计每个数有多少呢，此处就用到标记数组思想，即开辟一个数组bucket，初始值都赋值0，其中bucket[i]代表，i在序列中有几个。故只需扫描序列，对于每个元素nums[i]，进行bucket[nums[i]]++操作，即可完成统计

```C
void bucketSort(int* nums, int numsSize){//桶排序
    int bucket[10000];//nums里面最大是多少就开多大
    memset(bucket, 0, sizeof(bucket));
    for(int i = 0; i < numsSize; ++i){
        bucket[nums[i]]++;
    }
    int cnt = 0;
    for(int i = 0; i < 10000; ++i){//有几个就在序列里面放几个
        while(bucket[i]--) nums[cnt++] = i;
    }
}
```
例题有215.最大的k数，136.只出现一次的数字
和排序综合的例题有真题32.网元信息同步，1366.通过投票对团队排名
## 简易计算器
>实现一个能实现加法和乘法的计算器


C卷100分 火星文计算

