/* 
令1-正面，0-反面 
要求(a, b)是否为反面，只要看到(a, b)为止翻转了多少次。因为当x>a, y>b
时,(x,y)不会翻转(a,b)
如(12, 16), 12会在1,2,3,4,6,12处，16会在1,2,4,8,16处翻转
所以总共6*5=30次
注意到会使12和16翻转的行和列是其约数，总共的次数即为两个约数的乘积
注意到只有该数为平方数(1, 4, 9, 16...)时，约数为奇数 
而要使翻得次数为奇数次，即乘积为奇数，需要两个都是奇数
所以问题的解为[1, n]中的平方数个数 * [1, m]中的平方数个数

首先对大数n和m求其平方根(取整),再相乘
求平方根的方法可以先更具n和m的长度锁定范围，再二分求之 
*/
#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

//string strmul(string a, string b){
//	int len_a = a.length(), len_b = b.length();
//	string c;
//	int i, j, k;
//	int tp1, tp2;
//	int result;
//	for(i=0; i<len_a+len_b; i++) c+='0';
//	for(i=len_a-1; i>=0; i--){
//		for(j=len_b-1; j>=0; j--){
//			tp1 = a[i]-'0', tp2=b[j]-'0';
//			k = i+j+1;
//			result = tp1*tp2;
//			while(true){
//				result += c[k]-'0';
//				if(result>10){
//					c[k--] = '0'+result%10;
//					result /=10;
//				}else{
//					c[k]='0'+result;
//					break;
//				}
//			}
//
//		}
//	}
//	string d;
//	if(c[0]!='0') d+=c[0];
//	for(i=1; i<c.length(); i++){
//		d+=c[i];
//	}
//	return d;
//}
string strmul(string s1,string s2)//大数乘法
{
    string ans;
    int num[500]={0},i,j;
    for(i=0;i<s1.length();i++)//s计算存到num中
        for(j=0;j<s2.length();j++)
            num[i+j+1]+=(s1[i]-'0')*(s2[j]-'0');
    for(i=s1.length()+s2.length()-1;i>0;i--)//num的处理
        if(num[i]>=10)
        {
            num[i-1]+=num[i]/10;
            num[i]%=10;
        }
    for(int i=0;i<=s1.length()+s2.length()-1;i++)//将num数存到ans字串中，注意进位为0的情况
        if(!i&&num[i]||i)
            ans.push_back(num[i]+'0');
    return ans;
}

int strcmp(string a, string b){
    if(a.length()>b.length()) return 1;
    else if(a.length()<b.length()) return -1;
    else{
        if(a>b) return 1;
        if(a==b) return 0;
        return -1;
    }
}

string strsqrt(string a){
//    cout<<"1: "<<a<<endl;
	int len_a = a.length();
	int prt = (len_a+1) / 2 ;
	string tgt;
	int i;
	for(i=0; i<prt; i++) tgt+='0';
	string lt, mt;
	lt = tgt; lt[0] = '1';
	for(i=0; i<prt; i++) mt+='9';
	int up=0, result;
	for(i=0; i<prt; i++){
		result = lt[i]-'0'+mt[i]-'0'+up*10;
		up = result%2;
		tgt[i] = result/2 + '0';
	}
//	cout<<lt<<endl;
//	cout<<mt<<endl;
//	cout<<tgt<<endl;
	while(true){
		if(strcmp(strmul(tgt, tgt), a)==0){
			return tgt;
		}else if(strcmp(strmul(tgt, tgt), a)<0){
			lt = tgt;
			up=0;
			for(i=0; i<prt; i++){
                result = lt[i]-'0'+mt[i]-'0'+up*10;
                up = result%2;
                tgt[i] = result/2 + '0';
			}

		}else{
			mt = tgt;
			up=0;
			for(i=0; i<prt; i++){
                result = lt[i]-'0'+mt[i]-'0'+up*10;
                up = result%2;
                tgt[i] = result/2 + '0';
			}

		}

        if(tgt[prt-1]>'9'){
            int tmp=prt-1;
            int crt = 0;
            up=0;
            while(tmp>=0){
                crt = tgt[tmp]-'0'+up;
                tgt[tmp] = crt%10+'0';
                up = crt/10;
                tmp--;
            }
        }
//        cout<<"lt"<<lt<<endl;
//        cout<<"mt"<<mt<<endl;
//        cout<<"tgt"<<tgt<<endl;
		if(strcmp(tgt, lt)==0||strcmp(tgt,mt)==0)
		 	break;
	}
	
	if(strcmp(strmul(tgt,tgt), a)<0) return tgt;
	else return lt;
	
}
void solve(){
	string a, b;
	cin>>a; cin>>b;
	string ss1 = strsqrt(a), ss2=strsqrt(b);
//	cout<<ss1<<endl;
//	cout<<ss2<<endl;
	cout<<strmul(ss1, ss2)<<endl;
//	cout<<strcmp(strmul(ss1, ss1), a)<<endl;
//    cout<<strcmp(strmul(ss2, ss2), b)<<endl;
}

int main(){
	solve();
	return 0;
}

/* others*/


//#include <iostream>
//#include <algorithm>
//using namespace std;
//string StrMul(string s1,string s2)//大数乘法
//{
//    string ans;
//    int num[500]={0},i,j;
//    for(i=0;i<s1.length();i++)//s计算存到num中
//        for(j=0;j<s2.length();j++)
//            num[i+j+1]+=(s1[i]-'0')*(s2[j]-'0');
//    for(i=s1.length()+s2.length()-1;i>0;i--)//num的处理
//        if(num[i]>=10)
//        {
//            num[i-1]+=num[i]/10;
//            num[i]%=10;
//        }
//    for(int i=0;i<=s1.length()+s2.length()-1;i++)//将num数存到ans字串中，注意进位为0的情况
//        if(!i&&num[i]||i)
//            ans.push_back(num[i]+'0');
//    return ans;
//}
//bool StrCmp(string s1,string s2,int pos)//比较两字符串大小，pos代表应该在s1后面填几个零
//{
//    if(s1.length()+pos!=s2.length())//如果s1位数不等于s2,
//        return s1.length()+pos>s2.length();
//    else//位数相等
//        return s1>s2;
//}
//string SqrtStr(string s)//大数平方根取整
//{
//    int len;
//    string ans;
//    if(s.length()%2==0)//长度为偶数
//        len=s.length()/2;
//    else
//        len=s.length()/2+1;
//    for(int i=0;i<len;i++)//一位一位的循环
//    {
//        ans.push_back('0');
//        for(int j=0;j<=9;j++)
//        {
//            if(StrCmp(StrMul(ans,ans),s,2*(len-1-i)))//需要添加0的个数是2*（len-1-i）解析见上面
//                break;
//            ans[i]++;
//        }
//        ans[i]--;
//    }
//    return ans;
//}
//int main()
//{
//    string s1,s2;
//    cin>>s1>>s2;
//    cout<<StrMul(SqrtStr(s1),SqrtStr(s2))<<endl;
//    return 0;
//}