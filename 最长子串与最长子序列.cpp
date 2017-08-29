/*
经典动态规划问题
*/

//求子序列
int lcs1(string str1, string str2)
{
    int len1=str1.length();
    int len2=str2.length();

    int m[len1+1][len2+1];
    int count=0;
    for(int i=0; i<=len1; i++)
    {
        for(int j=0; j<=len2; j++)
        {
            if(i==0 || j==0)
                m[i][j]=0;
            else if(str1[i-1]==str2[j-1])
                m[i][j]=m[i-1][j-1]+1;
            else
                m[i][j]=max(m[i-1][j], m[i][j-1]);
        }
    }
    return m[len1][len2];
}

//求子串，子串要求连续
int lcs2(string str1, string str2)
{
    int len1=str1.length();
    int len2=str2.length();

    int m[len1+1][len2+1];
    int count=0;
    for(int i=0; i<=len1; i++)
    {
        for(int j=0; j<=len2; j++)
        {
            if(i==0 || j==0)
                m[i][j]=0;
            else if(str1[i-1]==str2[j-1])
            {
                m[i][j]=m[i-1][j-1]+1;
                count=max(m[i][j], count);
            }
            else
                m[i][j]=0;
        }
    }
    return count;
}

int main()
{
    string str1, str2;
    getline(cin,str1);
    getline(cin,str2);
    cout<<lcs1(str1, str2)<<endl;
    cout<<lcs2(str1, str2)<<endl;
    return 0;
}

输入:
abc defadde
frga abc deda

输出结果为:
7
6


