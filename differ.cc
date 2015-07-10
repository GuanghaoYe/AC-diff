#include <bits/stdc++.h>
#define rep(name,start,end,step) for(int name=start;name<=end;name+=step)
using namespace std;
#define Pn(x) printf("%d\n",x)
#define Ps(x) printf("%d ",x)
inline void R(int &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
//cat t |egrep '[p();0-9]+</script>' | sed 's/); /'
string a="wget http://www.lydsy.com/JudgeOnline/userinfo.php?user=";
string target_ID,myself_ID;
set <int> all;
set <int> myAC;
set <int> targetAC;
set <int> intersectionAC;
set <int> targetOnly;
set <int> myselfOnly;
void Download(){
	cout<<"Input target ID:"<<endl;
	cin>>target_ID;
	cout<<"Input your ID"<<endl;
	cin>>myself_ID;
	ofstream getData;
	getData.open("temp.sh");
	getData<<"bash get.sh "<<target_ID<<endl;
	system("bash temp.sh>target.dat");
	getData.close();
	getData.open("temp1.sh");
	getData<<"bash get.sh "<<myself_ID<<endl;
	system("bash temp1.sh > myself.dat");
	getData.close();
	ifstream targetFile,myFile;
	targetFile.open("target.dat");
	myFile.open("myself.dat");
	int temp;
	while(targetFile>>temp) {
		targetAC.insert(temp);
	}
	while(myFile>>temp) {	
		myAC.insert(temp);	
	}
}

int main() {
	Download();
	set_intersection(targetAC.begin(), targetAC.end(), myAC.begin(), myAC.end(), inserter(intersectionAC, intersectionAC.begin()));
	set_difference(targetAC.begin(),targetAC.end(),intersectionAC.begin(),intersectionAC.end(),inserter(targetOnly,targetOnly.begin()));
	set_difference(myAC.begin(),myAC.end(),intersectionAC.begin(),intersectionAC.end(),inserter(myselfOnly,myselfOnly.begin()));
	set<int>::iterator sitr;
	cout<<"Both AC:\n";
	for(sitr=intersectionAC.begin();sitr!=intersectionAC.end();sitr++){
		cout<<*sitr<<",";
	}
	cout<<endl;
	cout<<"only target AC:\n";
	for(sitr=targetOnly.begin();sitr!=targetOnly.end();++sitr){
		cout<<*sitr<<",";
	}
	cout<<endl;
	for(sitr=myselfOnly.begin();sitr!=myselfOnly.end();sitr++){
		cout<<*sitr<<",";
	}
	cout<<endl;
}
