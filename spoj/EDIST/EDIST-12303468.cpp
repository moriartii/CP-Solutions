#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int dp[2010][2010];
int main()
{
   int p,i,j;
   char s[2010],t[2010];
   //string st,tt;
   scanf("%d",&p);
   while (p--) {
       scanf("%s %s",&s,&t);
       //cout<<s<<" "<<t<<endl;
       int m = strlen(s);
       int n=strlen(t);
       /*for (i=1;i<=m;i++) s[i]=st[i-1];
       for (i=1;i<=m;i++) t[i]=tt[i-1];*/
      // cout<<m<<" "<<n<<endl;
       
       for (i=0;i<=m;i++) dp[i][0]=i;
       for (i=0;i<=n;i++) dp[0][i]=i;
       //cout<<dp[0][1]<<endl;
      // cout<<"j";
           for (j=1;j<=n;j++) {
               for (i=1;i<=m;i++) {
                    if (s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
                    else {
                    dp[i][j] = min ((dp[i-1][j]+1),min((dp[i][j-1]+1),(dp[i-1][j-1]+1)));
                    //cout<<dp[i-1][j]<<" "<<dp[i][j-1]<<" "<<dp[i-1][j-1]<<"\n";
                    }
                    //cout<<dp[i][j]<<" ";
                }
                //cout<<"\n";
            }
            /*for (i=0;i<=m;i++) {
                for (j=0;j<=n;j++) cout<<dp[i][j]<<" ";
                cout<<"\n";
            }*/
            printf("%d\n",dp[m][n]);
   }
   
   return 0;
}
