#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <math.h>

#include <stdio.h>
#include <conio.h>

using namespace std;


bool otl         = true;    // �������

int ind          = 3;       // ������ ������ - �� 1 ��� 3 �����
int Eda          = 12;

bool NextYear    = true; 	// ����� �������� �����
int  toYear      = (rand()%10)*10+rand()%10;    	// ������� ����� (���)
int  Enter 	     = 0;       // ����� ����

double YearSin   = 0;
int toWar        = 0;
bool Flag, Flag0, Flag1, Flag2, Flag3 = false;
int          tmp = 0;
string     tmpG4 ="";
string     tmpT4 ="";
double doubletmp = 0,doubletmp0 = 0,doubletmp1 = 0,doubletmp2 = 0;
string str       ="";
int Posev=0, Urojay=0;

bool Flag_Kataklizm, Flag_Horosho;


int zemly  =   40, tze  = 1, ctze  = 0;  // ����������
int psheno = 1000, tps  = 1, ctps  = 0, CMaxpsheno =4;
int ludi   =   10, tlu  = 1, ctlu  = 0, ludi1Year = ludi, dead = 0;
int vs     =    0, tvs  = 1, ctvs  = 0, Avs  = 0, CofEdaVs = 2;
int gold   =   10, tgo  = 1, ctgo  = 0;
int nalog  =    5, tna  = 1, ctna  = 0;  // �����

int wepons =   10, twe  = 1, ctwe  = 0;
int goods  =   10, tgd  = 1, ctgd  = 0;
int tools  =   10, tto  = 1, ctto  = 0;

int Rielt  	  = 0;
int PP_psheno = 0;
int ZHelp_    = 0;

int CZem = 9, oldCZem = 0, CountPZem = 0;
int CZer = 1, oldCZer = 0;

int Poxod=0, Poxod_Year=0, Poxod_ludi=0, Poxod_gold=0;

int Rez0=0, Rez1=0, Rez2=0, Rez3=0, Rez4=0, Rez5=0, Rez6=0, Rez7=0;



int  ini(){return 1;};
int save(){return 1;};


int PBez(int tmp){return psheno/tmp;};
int PNas()       {return zemly/ludi;};
int BNas()       {return gold/ludi;};





/*
cout << round(value*10)/10. << endl; // ���������� �� ������� �����
 cout << round(value*100)/100. << endl; // �������
 cout << round(value*1000)/1000. << endl; // ��������
 cout << round(value*10000)/10000. << endl; // ����������

 // ������������� �����
 cout << round(-value*10)/10. << endl; // ���������� �� ������� �����
 cout << round(-value*100)/100. << endl; // �������
 cout << round(-value*1000)/1000. << endl; // ��������
 cout << round(-value*10000)/10000. << endl; // ����������

*/



//=== ��������� ��� 0-9 -=====================================
int  RandSBS(){return rand()%10;};
bool RandYN(int da){bool RandYN=false; if(RandSBS()<=da) RandYN=true;  return RandYN;}; // �� � ���������
int  RandBW(double g1, double g2){if(g2<g1)g2=g1;return round(g1+((g2-g1)*RandSBS()/9));};  //  ��������� � ���������
//	cout << "RandBW g1=" <<     << endl;


//=== ���� ))) ===============================================
double iifD(bool usl,double zT,double zF){double iif=zF;if(usl)iif=zT;return iif;};
int    iif(bool usl,int zT,int zF){int iif=zF;if(usl)iif=zT;return iif;};
string iif(bool usl, string zT, string zF){string iif=zF;if(usl)iif=zT;return iif;};

double Sinu_Ur(int Sinus){return  2*0.5+sin(0.4*double(Sinus));} // ������� ������   // 2*0.5+sin(0.4*x)
double Sinu(int Sinus){return  8*sin(0.05*double(Sinus))+6*sin(0.5*double(Sinus));} // ������ �������
//  8*sin(0.08*x)+6*sin(x) �������



//=====================================================================================
//=== 1. ��� 2. � ������������ 3. �������� 4.���-++ 5 ����������
//=====================================================================================
void G4(string in, int SL, int ver, bool UD, bool over){
	if(in=="Di"){if(RandYN(SL)){if(RandYN(ver)){if(UD) {tmpG4=tmpG4+"D+";ctze++;}if(!UD){tmpG4=tmpG4+"D-";ctze--;}}else{if( UD and over){if(over){tmpG4=tmpG4+"D-";ctze--;}}if(!UD and over){if(over){tmpG4=tmpG4+"D+";ctze++;}}}}}
	if(in=="Ku"){if(RandYN(SL)){if(RandYN(ver)){if(UD) {tmpG4=tmpG4+"K+";ctlu++;}if(!UD){tmpG4=tmpG4+"K-";ctlu--;}}else{if( UD and over){if(over){tmpG4=tmpG4+"K-";ctlu--;}}if(!UD and over){if(over){tmpG4=tmpG4+"K+";ctlu++;}}}}}
	if(in=="Ur"){if(RandYN(SL)){if(RandYN(ver)){if(UD) {tmpG4=tmpG4+"U+";ctps++;}if(!UD){tmpG4=tmpG4+"U-";ctps--;}}else{if( UD and over){if(over){tmpG4=tmpG4+"U-";ctps--;}}if(!UD and over){if(over){tmpG4=tmpG4+"U+";ctps++;}}}}}
	if(in=="Vs"){if(RandYN(SL)){if(RandYN(ver)){if(UD) {tmpG4=tmpG4+"V+";ctvs++;}if(!UD){tmpG4=tmpG4+"V-";ctvs--;}}else{if( UD and over){if(over){tmpG4=tmpG4+"V-";ctvs--;}}if(!UD and over){if(over){tmpG4=tmpG4+"V+";ctvs++;}}}}}
	if(in=="Ma"){if(RandYN(SL)){if(RandYN(ver)){if(UD) {tmpG4=tmpG4+"G+";ctgo++;}if(!UD){tmpG4=tmpG4+"G-";ctgo--;}}else{if( UD and over){if(over){tmpG4=tmpG4+"G-";ctgo--;}}if(!UD and over){if(over){tmpG4=tmpG4+"G+";ctgo++;}}}}}
	if(in=="Na"){if(RandYN(SL)){if(RandYN(ver)){if(UD) {tmpG4=tmpG4+"N+";ctna++;}if(!UD){tmpG4=tmpG4+"N-";ctna--;}}else{if( UD and over){if(over){tmpG4=tmpG4+"N-";ctna--;}}if(!UD and over){if(over){tmpG4=tmpG4+"N+";ctna++;}}}}}
};
//=====================================================================================
//=== ���� ��� � ����     �������� ����� ����������!
void T4(string in, int SL, int ver, bool UD, bool over){
	if(in=="Di"){if(RandYN(SL)){if(RandYN(ver)){if(UD) {tmpG4=tmpG4+"TD+";tze++;}if(!UD){tmpG4=tmpG4+"TD-";tze--;}}else{if( UD and over){if(over){tmpG4=tmpG4+"TD-";tze--;}}if(!UD and over){if(over){tmpG4=tmpG4+"TD+";tze++;}}}}}
	if(in=="Ku"){if(RandYN(SL)){if(RandYN(ver)){if(UD) {tmpG4=tmpG4+"TK+";tlu++;}if(!UD){tmpG4=tmpG4+"TK-";tlu--;}}else{if( UD and over){if(over){tmpG4=tmpG4+"TK-";tlu--;}}if(!UD and over){if(over){tmpG4=tmpG4+"TK+";tlu++;}}}}}
	if(in=="Ur"){if(RandYN(SL)){if(RandYN(ver)){if(UD) {tmpG4=tmpG4+"TU+";tps++;}if(!UD){tmpG4=tmpG4+"TU-";tps--;}}else{if( UD and over){if(over){tmpG4=tmpG4+"TU-";tps--;}}if(!UD and over){if(over){tmpG4=tmpG4+"TU+";tps++;}}}}}
	if(in=="Vs"){if(RandYN(SL)){if(RandYN(ver)){if(UD) {tmpG4=tmpG4+"TV+";tvs++;}if(!UD){tmpG4=tmpG4+"TV-";tvs--;}}else{if( UD and over){if(over){tmpG4=tmpG4+"TV-";tvs--;}}if(!UD and over){if(over){tmpG4=tmpG4+"TV+";tvs++;}}}}}
	if(in=="Ma"){if(RandYN(SL)){if(RandYN(ver)){if(UD) {tmpG4=tmpG4+"TG+";tgo++;}if(!UD){tmpG4=tmpG4+"TG-";tgo--;}}else{if( UD and over){if(over){tmpG4=tmpG4+"TG-";tgo--;}}if(!UD and over){if(over){tmpG4=tmpG4+"TG+";tgo++;}}}}}
	if(in=="Na"){if(RandYN(SL)){if(RandYN(ver)){if(UD) {tmpG4=tmpG4+"TN+";tna++;}if(!UD){tmpG4=tmpG4+"TN-";tna--;}}else{if( UD and over){if(over){tmpG4=tmpG4+"TN-";tna--;}}if(!UD and over){if(over){tmpG4=tmpG4+"TN+";tna++;}}}}}
};

//=====================================================================================
//=== �� ��������� �����. ��� �� ������ -. ��� ����������� ������
//=== 1. ������� ����������(������), 2. ���. �������
int GolodEda(int Gol, int mon){int GolodEda = psheno-((ludi*mon) + (vs*mon)*CofEdaVs); return GolodEda+GolodEda*Gol/100;};

//=====================================================================================
//=== 1. ������ ���� 2. ���.��. 3. ����.��. 4.����������������
//=== 5.�� ��������� 6. �� ������� ����	===============================================
int Cena(int OC,    int GDw, int GUp,   int Che,       bool FlagRand,       bool FlagRoll){
	int Cena   = OC;
	int Faktor = RandSBS();

	if(Faktor<5-Che)  Cena = Cena-1;
	if(Faktor>=5+Che) Cena = Cena+1;

	if(FlagRoll){
		if(Cena<GDw) Cena=GUp;
	    if(Cena>GUp) Cena=GDw;
	}else{
		if(Cena<GDw) Cena=GDw;
		if(Cena>GUp) Cena=GUp;
	}

	if(FlagRand & RandYN(0)) Cena = RandBW(GDw,GUp);

//	cout << " ��:" << OC << "  Faktor:" <<  Faktor << "  Cena:" << Cena   << endl;

	return Cena;
};

//=== �������� =====================================
int abundance(){return ( zemly + ludi + psheno/1000000 + goods/100 + gold/1000)/5;}
//***************************************************************
void ZHelp(){
	Rez0  =psheno/100*100;
	if(Rez0>=100){

		cout << "   ������� ������� ii?  max( -" << Rez0 << " ):";
		cin >> ZHelp_;

		ZHelp_ = ZHelp_/100*100;
		if(ZHelp_>-1) ZHelp_=0;
		if(abs(ZHelp_)>Rez0) ZHelp_=Rez0*-1;
		psheno += ZHelp_;
		if(ZHelp_<-99) cout << "   ii " << ZHelp_ << endl;
	};
}
//***************************************************************
void PZerna(){

	oldCZer = CZer;

	CZer =Cena(CZer,1,CMaxpsheno,3,true,true);
	if(RandYN(0)) {CZer *= RandBW(2,5);Flag1=true;}else Flag1=false;  // ���������� ����

	// �������  ������� �����
	Rez7 = iif(gold<0,0,gold)/CZer*100;
	Rez4=abundance()*RandSBS()*100;
	Rez0=Rez7;
	if(Rez4<=Rez0) Rez0 =Rez4;

	// ������� ������ ���������
	Rez6 = psheno/100*100*-1;
	Rez1=abundance()*RandBW(0,4)*100*-1;
	// ��������� ������ �����
	if(RandYN(2) and Rez1>0 ) {Flag=true; Rez1*=RandBW(4,9);} else Flag=false;
	Rez2=Rez6;
	if(Rez2<Rez1) Rez2 = Rez1;


	if(Rez0>0 || Rez2<0){

		cout << "   ii+-ii +" << Rez4 << " / " << iif(Rez7>0,"+","") << Rez7 << "   " << Rez1 << iif(Flag,"*","") << " / " << Rez6 << endl;
		cout << "   ii  ~ " << CZer << iif(Flag1,"*","") << "  max( +" << Rez0	 << " / " << Rez2 <<" ):";
		cin >> PP_psheno;

		if(PP_psheno!=0){

			PP_psheno = PP_psheno/100*100;

			if(PP_psheno>0 &&     PP_psheno >Rez0) PP_psheno=Rez0;  // �������
			if(PP_psheno<0 &&     PP_psheno<Rez2) PP_psheno=Rez2;  // �������

			Rez3 = PP_psheno/100*CZer*-1; // ������

			gold   += Rez3;
			psheno += PP_psheno;

			cout << "   ii " << iif(0<PP_psheno,"+","") << PP_psheno << "    Oo " << iif(0<Rez3,"+","") << Rez3 <<endl;
		}
	}

};


//=== ������� ����� ================================
void PZem(int Pr_zemly){
	int CenaWork=0;
	oldCZem = CZem;


	CZem = Cena(CZem,4,9,1,true,true);
	CenaWork=100*CZem;

	Rez0 =iif(gold<=0,0,gold)/CenaWork;

	cout << "   __ " << CenaWork << "  max( +"<< Rez0 << " / -" << Pr_zemly <<" ):";
	cin >> Rielt;
	if(Rielt!=0){
		if(Rielt>Rez0)  Rielt=Rez0;
		if(Rielt<0 && abs(Rielt)>Pr_zemly) Rielt=Pr_zemly*-1;

		Rez3 =Rielt*CenaWork*-1;
		gold  += Rez3;
		zemly += Rielt;
		cout << "   __ " << iif(0<Rielt,"+","") << Rielt << "    Oo " << iif(0<Rez3,"+","") << Rez3 <<endl;
	}

}
//=== ����� ========================================
void VS(){
	cout << "** ��������� " << vs << " +- max( +" << ludi << " / " << vs*-1 <<" ):";
	cin >> Rez1;

	if(Rez1<0 and Rez1<vs*-1) Rez1=vs*-1;
	if(Rez1> ludi) Rez1=ludi;

	ludi -= Rez1;
	vs   += Rez1;
	cout <<"   � ��������� �: "<< ludi << "/ *: "<< vs  << endl;
}


//=== ������� ���� �� sin ==========================
void vSin(){
	cout << endl;
	cout << "=================================================" <<endl;
	cout << "���:" << toYear  << "   X: " << dead << "   Rich:" << abundance()<< "   Sin:" << round(Sinu_Ur(toYear)*100)/100. << " / " << round(Sinu(toYear)*100)/100.  << endl;   // << "  �����: " << dead
	cout << "=================================================" <<endl;
	cout << "_:"   << zemly << "/" << tze << "/" << ctze
		 << "  X:" << ludi 	<< "/" << tlu << "/" << ctlu
		 << "  i:" << psheno<< "/" << tps << "/" << ctps
		 << "  O:" << gold  << "/" << tgo << "/" << ctgo
	<< endl;
	cout << "-------------------------------------------------" <<endl;
	cout << "We:" << wepons << "/" << twe << "/" << ctwe
		 << "  *:" << vs    << "/" << tvs << "/" << ctvs
		 << "           ~:" << nalog << "/" << tna << "/" << ctna
	<< endl;
	cout << "-------------------------------------------------" <<endl;
	cout << "��:"   << goods << "/" << tgd << "/" << ctgd
		 << "  ��:" << tools << "/" << tto << "/" << ctto
	<< endl;
	cout << "=================================================" <<endl;
	cout << endl;
}

//=== ����� ========================================
void War(){
		Rez0=0;Rez1=0;Rez2=0;Rez3=0;Rez4=0;
		Avs = vs*10/(ludi+vs)*10/10;
		Avs -= 5; // ��������
		Avs = Avs+twe+tvs;
		if(Avs>9) Avs = 9;

		if(RandYN(0)){Avs = RandSBS();cout << "** ���-�� ����� �� �� �����" << endl;}

 		if(RandYN(Avs) or RandYN(1)){

			Rez0    = abundance()/RandBW(1,Avs) + RandBW(1,9);
			ludi   += Rez0;

			Rez1    = Rez0          /RandBW(1,Avs) + RandBW(0,9);
			psheno += Rez1;

			Rez2    = abundance()*10/RandBW(1,Avs) * iif(RandYN(5-Avs),-1,1) + RandBW(0,9);
			gold+= Rez2;

			cout << "** ���� ���������� (" << Avs << "/"<< tvs<< "/"<< twe << ")   � "   << iif(0<Rez0,"+","") << Rez0 <<   "  i " << iif(0<Rez1,"+","") << Rez1 << "  � " << iif(0<Rez2,"+","") << Rez2 << endl;

			tmpG4 ="   ";G4("Di",8,7,true,true);G4("Vs",8,7,true,true);T4("Vs",1,7,true,true);
			cout << tmpG4 << endl;

 		}else{

			Rez0  = abundance()/RandBW(3,Avs)* iif(RandYN(10-Avs),-1,1) + RandBW(0,9);
			ludi+=Rez0;
			Rez4  = vs     /RandBW(5,Avs)*-1 					 + RandBW(0,9);
			vs +=Rez4;
			Rez3  = psheno /RandBW(1,Avs)     					 + RandBW(0,9);
			psheno+=Rez3;
			Rez2  = abundance()*10 /RandBW(1,Avs)* iif(RandYN(10-Avs),-1,1)  + RandBW(0,9);
			gold+=Rez2;

			tmpG4 ="";G4("Di",8,8,true,true);G4("Vs",8,8,true,true);tmpG4 +=" ";T4("Vs",1,8,true,true);
			cout << "** ��������� (" << Avs << "/"<< tvs<< "/"<< twe << ")  � "<< iif(0<Rez0,"+","") << Rez0 <<   "  i " << iif(0<Rez3,"+","") << Rez3 <<   "  * " << iif(0<Rez4,"+","") << Rez4 << "  � " << iif(0<Rez2,"+","") << Rez2  << "  " << tmpG4 << endl;

		};
}












//=== ������ ������ �� ���������� ==================
int VoyajPrem_zem( int z){z      =  z*RandBW(0,9)/10+RandBW(1,9);return z;}
int VoyajPrem_gold(int g){g      =  g*RandBW(0,9)/1000+RandBW(1,9);if(RandYN(4)) g = Poxod_ludi*RandBW(1,9)*-1;return g;}
int VoyajPrem_ludi(int l){int ll = (l*RandBW(0,5)/10)*iif(RandYN(4),-1,1);if(ll<0 and abs(ll)<l) ll=l*-1;return ll;}



//=== ��������� ������ =============================
void SetNalog(){
	cout << "   ~ " << nalog << "  ��������� ����� ����� � Oo: ";
	cin >> Rez0;
//	if(Rez0<1) Rez0=0;    ����� ����� ����������� ������
	if (Rez0!=nalog) cout << "   ~ ����� ������� �����: " << Rez0 << endl;
	nalog = Rez0;
};

//=== ������� ======================================
void Xorosho(){
	Flag_Horosho=false;
	//=== ������� ������� ===========
	if(RandYN(0) and RandYN(1) and 0 < gold){


		Rez1 = RandBW(tze,9)*100/gold;
		Rez1 = Rez1*gold/100;

		if(Rez1>0){

			cout << "   C����� ������ ������ Oo: " << Rez1 << endl;
			cout << "   ������� �����?       Oo: ";
			cin >> Rez0;

			if(0>Rez0) Rez0=0;
			if(gold<Rez0) Rez0=gold;

			tmpG4 ="";G4("Di",4,7,true,true);

			if(0<Rez0)	cout << "   ������� ������ Oo: " << Rez0 << "   " << tmpG4 << endl;

			gold-= Rez0;



/*
			if(RandYN(tze)   and Rez0< 0){ctze++; cout << "   D+" << endl;}
			if(RandYN(9-tze) and Rez0==0){ctze--; cout << "   D-" << endl;}
*/

			Flag_Horosho=true;
		}
	};


	//=== ����������: ������� ������� ===========
	if(RandYN(tze) and RandYN(0)){
		Rez0 = abundance()*RandBW(tze,9)/10;
		gold+=Rez0;

		tmpG4 ="";G4("Di",4,6,true,false);

		cout << "   ������� ������� Oo: +" << Rez0 << "   " << tmpG4 << endl;
		Flag_Horosho=true;
	};


	//=== �������� �������� =====================
	if(RandYN(0) and RandYN(0)){
		Rez0 = abundance()*RandBW(2,6)/10;	gold+= Rez0;
		cout << "   �������� �������� Oo: +" << Rez0 << endl;
		Flag_Horosho=true;
	};


	//=== �������� ==============================
	if(RandYN(0) and RandYN(0)){
		Rez0 = zemly/RandBW(3,9)+RandBW(0,9);
		if(zemly<Rez0) Rez0 = zemly-3;
		if(RandYN(0)) Rez0 = 0;

		Flag = true;
		if(RandYN(4)) {Flag = false;Rez0 /=2;}   // ���� ����)
		if(!Flag and zemly<Rez0 ) Rez0 = zemly-3;
		if(!Flag and zemly<3    ) Rez0 = 0;
		if(!Flag) Rez0 *= -1;

		Rez1 = Rez0/ind;
		if(!Flag and abs(Rez1)>ludi) Rez1 = ludi;

		zemly += Rez0;
		ludi  += Rez1;

		tmpG4 ="";G4("Di",4,8,true,true);G4("Di",4,8,true,true);G4("Ku",4,4,true,true);
		      	  T4("Di",0,8,true,true);T4("Ur",0,8,true,true);T4("Ku",0,8,true,true);T4("Vs",0,8,true,true);T4("Go",0,8,true,true);


		cout << "   ������� ������� __:" << iif(Flag," +","") << Rez0 << iif(Rez0>0,"  Xx: +","  Xx: ") << Rez1 <<  endl;
		cout<< "   " << tmpG4 << endl;

		Flag_Horosho=true;
	};

	//=== + ����������� =============
	if(RandYN(0) and RandYN(0)){

						Rez0 = (zemly/RandBW(1,9)+RandBW(0,9));
		if(RandYN(4)) 	Rez0 = (zemly*RandBW(1,3))+RandBW(0,9);

						Rez1 = (Rez0/ind/RandBW(1,3))+RandBW(0,9);
		if(RandYN(4)) 	Rez1 = (Rez0/ind*RandBW(1,5))+RandBW(0,9);
		if(Rez1<1) Rez1 = 1;

						Rez2 = (Rez1/RandBW(1,3)+RandBW(0,9));
		if(RandYN(2)) 	Rez2 = (Rez1*RandBW(1,5))+RandBW(0,9);

		cout << "   ��� ���� ��������������� ����� �������" << endl;
		cout << "   �������� �����������.  " << endl;
		cout << "** __: +" << Rez0 << "  Xx: +" << Rez1 << "  ii: +" << Rez2 << endl;

		tmp =RandSBS();
		Rez5=0;
		cout << "   ���������? ( " << tmp << " �� )? ";
		cin >> Rez5;


		if(Rez5==tmp){
			zemly  += Rez0;
			ludi   += Rez1;
			psheno += Rez2;

			tmpG4 ="";  G4("Di",0,8,true,true);T4("Ur",0,8,true,true);T4("Ku",0,8,true,true);T4("Vs",0,8,true,true);T4("Go",0,8,true,true);
						T4("Di",0,8,true,true);T4("Ur",0,8,true,true);T4("Ku",0,8,true,true);T4("Vs",0,8,true,true);T4("Go",0,8,true,true);
			cout << "   ������������! ���!!! " << tmpG4 << endl;

	        cout << endl;
			if(Rez1>0 and RandYN(7)){cout << "   ii ������ ����������� �������������� �����." << endl;PZerna();}


		}else{cout << "   ����������  " << endl;}
		Flag_Horosho=true;
	};


	//=== ���������� ���� ===========
	if(RandYN(1) and Poxod_Year>0){
		int tmp = VoyajPrem_ludi(Poxod_ludi);
		if(tmp!=0) cout << "   ���������� Xx: " << iif(tmp>0,"+","") << tmp << endl;
		Poxod_ludi += tmp;

		if(Poxod_ludi<1 ){
			Poxod      = 0;
			Poxod_ludi = 0;
			Poxod_Year = 0;
			Poxod_gold = 0;
			cout << "   ���������� ��������" << endl;
		}
		Flag_Horosho=true;
	};

	//=== ���������� ������ =========
	if(RandYN(1) and Poxod_Year>0){
		int tmp = VoyajPrem_gold(gold);
		cout << " * ���������� Oo: " << iif(tmp>0,"+","") << tmp << endl;
		Poxod_gold += tmp;
		Flag_Horosho=true;
	};

	//=== ���������� ����� ==========
	if(RandYN(0) and Poxod_Year>0){
		int tmp = VoyajPrem_zem(zemly);
		cout << " * ���������� __: " << iif(tmp>0,"+","") << tmp << endl;
		zemly += tmp;
		Flag_Horosho=true;
	};


	//=== ����������� ���������� ===========
	if(RandYN(0) and RandYN(0)){
		Rez0 = (zemly-ludi*3)/3;
		Rez1 = (psheno-ludi*12)/12;
		Rez2 = iif(Rez0<Rez1,Rez0,Rez1)/2;

		if(Rez2!=0 and RandYN(0)){
			ludi += Rez2;
			cout << "   �� " << iif(Rez2>0,"+","") << Rez2 << endl;

	        cout << endl;
			if(Rez1>0 and RandYN(7)){cout << "   ii ������ ����������� �������������� �����." << endl;PZerna();}
		}
		Flag_Horosho=true;
	}









	//=== ����������� ��������� ============
	if(RandYN(0) and RandYN(0)){

		Rez0 = RandSBS()*100/ludi*RandBW(0,5)+RandSBS();

		cout << "   ��!! " << "+max( " << Rez0 <<" )?:";
		cin >> Rez1;

		if(Rez1<0)    Rez1=0;
		if(Rez1>Rez0) Rez1=Rez0;

		cout << "   ��!! �������:" << Rez1 << endl;

		ludi += Rez1;

		if(0 <Rez1){
			if(RandYN(iif(tze<1,0,tze))){
				cout << "   D+�+V+T+" << endl;
				ctze++;ctlu++;ctvs++;ctto++;
			}
		}else{
			if(RandYN(10-tze))			{
				cout << "   D-�-V-T-" << endl;
				ctze--;ctlu--;ctvs--;ctto--;
			}
		}
        cout << endl;
		if(Rez1>0 and RandYN(7)){cout << "   ii ������ ����������� �������������� �����." << endl;PZerna();}

		Flag_Horosho=true;
	}




	//=== ����� ====================== 160410
	if(RandYN(1) and RandYN(1)){
		Flag = false;


		cout << "** ���������" << endl;

		if(RandYN(6)) VS(); else{cout << "** � ������������ �� ��������." << endl;}

		if(RandYN(8))War(); else{Flag = true;cout << "** ����� ���� ����" << endl;}

		if(Flag and RandYN(2)){
			if(RandYN(4)){cout << "** ���� ��������." << endl; VS();}else{cout << "** ���� ��������. � ������������ ����� �� ��������." << endl;}
			War();
		}

		Flag_Horosho=true;
	}

	/*
	//=== ����� +- ======================
	if(RandYN(0) and RandYN(0)){
		cout << "   ��������� �����������" << endl;
		PZem(zemly);
		Flag_Horosho=true;
	}
	*/

	//=== �������� ����� +- ===================
	if(CountPZem==0 and RandYN(4)){ PZem(zemly);CountPZem=0;Flag_Horosho=true;}  //else{cout << "   ������ +- __" << endl;Flag_Horosho=true;}

	if(RandYN(0) and RandYN(0) and CountPZem<-1){
		CountPZem =RandBW(2,4);
		cout << "   ��������� �����������"  << endl;
		cout << "   +- __ ����� " << CountPZem  << " ���(�)"  << endl;
		Flag_Horosho=true;
	}

	if(Flag_Horosho) cout << endl;
}
//=== ��������� ====================================
void Kataklizm(){  // *tze
	Flag_Kataklizm = false;
//	cout << Sinu(toYear) << endl;
	if(Sinu(toYear)<0 or RandYN(2)){
		if(RandYN(0) and RandYN(1)){//=== �������������, ������ ======
			Rez4   =RandBW(0,4);Rez5   =zemly*Rez4/10*iif(RandYN(4),1,-1);	zemly+= Rez5;
			Rez2   =RandSBS();	Rez3   =ludi*Rez2/10*-1;		ludi+= Rez3;
			Rez0   =RandSBS();	Rez1   =abs(psheno)*Rez0/10*-1;	psheno+= Rez1;

			tmpG4 ="";G4("Ku",8,8,false,true);G4("Ku",8,8,false,true);G4("Ur",8,4,false,true);

			cout << iif(RandYN(4),"   ������ __: ","   ������������� __: ") << iif(Rez5>0,"+","") <<Rez5 <<  "  Xx: " << Rez3 << "  ii: " << Rez1 << "   " << tmpG4 << endl;

			Flag_Kataklizm=true;
		};
		if(RandYN(1)){//=== ��������, ����� ============
			Rez2   =RandSBS(); Rez0 =(abs(psheno)*Rez2/10)*-1; psheno+=Rez0;
			tmpG4 =""; G4("Ur",1,4,true,false);
			cout << iif(RandYN(4),"   �������� ii: ","   ����� ii: ") << Rez0 << "  " << tmpG4 << endl;
			Flag_Kataklizm=true;
		};
		if(RandYN(0)  ){//=== ����������, ����� ==========
			Rez2   =RandSBS(); 		Rez0   = (psheno*Rez2/10)*-1; 			psheno+=Rez0;
			Rez3   =RandSBS(); 		Rez1   = (ludi/2*Rez3/10)     *-1; 	    ludi  +=Rez1;
			tmpG4 =""; G4("Ku",4,8,false,false);
			cout << iif(RandYN(4),"   ���������� X: ","   ����� X: ") << Rez1  << "  ii: " << Rez0 << "  " << tmpG4 << endl;
			Flag_Kataklizm=true;
		};
		if(RandYN(0) and RandYN(0)){ //=== ������������� ==
			Rez0 = gold/2*RandSBS()/10;
			if(Rez0>0){
				gold-= Rez0;
				tmpG4 =""; G4("Di",8,4,false,false);G4("Ku",8,8,false,true);
				cout << iif(RandYN(4),"   ������������� Oo: -","   �� ��������������� ������� Oo: -") << Rez0 << "  " << tmpG4 << endl;
				Flag_Kataklizm=true;
			}
		};
		if(RandYN(0) and RandYN(0) and RandYN(9-tlu)){ //=== �������� ==================
			Rez0 = ludi*RandBW(2,6)/10;
			if(Rez0>0){
				ludi-= Rez0;
				if(ludi<0) ludi=0;
				tmpG4 =""; G4("Di",4,4,false,true);G4("Ku",4,4,false,true);
				cout << iif(RandYN(4),"   �������� Xx: -","   �������� Xx: -") << Rez0 << endl;
				Flag_Kataklizm=true;
			}
		};
	};
	if(Flag_Kataklizm) cout << endl;
}













void info(){

	cout << "���:" << toYear  << endl;
	cout << "=================================================" <<endl;
	cout << "_:"   << zemly << "/" << tze
		 << "  X:" << ludi 	<< "/" << tlu
		 << "  i:" << psheno<< "/" << tps
		 << "  O:" << gold  << "/" << tgo
	<< endl;
	cout << "-------------------------------------------------" <<endl;
	cout << "We:" << wepons << "/" << twe
		 << "  *:" << vs    << "/" << tvs
		 << "           ~:" << nalog << "/" << tna
	<< endl;
	cout << "-------------------------------------------------" <<endl;
	cout << "��:"   << goods << "/" << tgd
		 << "  ��:" << tools << "/" << tto
	<< endl;
	cout << "=================================================" <<endl;


	//	cout << "��:" << PBez((Eda+Eda*2)/2) << " ��:" << PNas()  << " ��:" << BNas()    << endl;
}
void Map(){
	cout << endl;
	cout << "�����" << endl;
    cout << "[........................................]" <<endl;
    cout << "[........................................]" <<endl;
    cout << "[........................................]" <<endl;
    cout << "[.......1.........�.....2................]" <<endl;
    cout << "[........................................]" <<endl;
    cout << "[..............�....�.......�............]" <<endl;
    cout << "[.....................�..................]" <<endl;
    cout << "[.................5......................]" <<endl;
    cout << "[.................................3......]" <<endl;
    cout << "[........................................]" <<endl;
    cout << "[..........4.............................]" <<endl;
    cout << "[........................................]" <<endl;
    cout << "[........................................]" <<endl;
}
void Help(){
	cout << endl;
	cout << "������" << endl;
	cout << "=================================================" <<endl;
	cout << "0  ���  1 ������  11/111 ������  2 ����� 3 ����� "	<< endl;
	cout << "4 ����� 6 �������� ������  	                  " << endl;
	cout << "777 �����                                        "	<< endl;
	cout << "=================================================" <<endl;
}
void EnterMenu(){
	while (true){
		cin >> Enter;
		if(Enter==0) break;
		if(Enter==1)  Help();
		if(Enter==11)  vSin();
		if(Enter==111)  info();
		if(Enter==2) SetNalog();
		if(Enter==3) Map();
		if(Enter==4) VS();
		if(Enter==8) PZerna();
	}
}




//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================

int day(){

	Help();

	while (NextYear){


		toYear+=1;

		str   ="";

		Poxod = 0;
		if(Poxod_ludi==0 ) Poxod_Year=0;

		toWar = 0;
		CountPZem -= 1;   // ������� �������� ������� �����
		Rez0=0;	Rez1=0;	Rez2=0;	Rez3=0;

		cout << endl;
		cout << "=================================================" <<endl;
		cout << "=================================================" <<endl;

		if(toYear%5==0) {vSin(); cout << endl;}
		cout << endl;
		info();
		cout << endl;


		//=== �������� ����� ��� ============
		if(RandYN(1)){
			Rez0 = abundance()*RandBW(tze,9)/10;
			if(RandYN(1)) Rez0*=-1;
			gold+= Rez0;

			tmpG4 ="";G4("Di",2,8,true,true);G4("Ku",1,8,true,false);

			cout << "   �������� ����� ��� Oo: " << iif(Rez0<0,"","+") << Rez0 << "  "  << tmpG4 << endl;
			cout << endl;
		};



//		EnterMenu();

		//=== ���� ����� ����� +- =================
		if(PBez((Eda+Eda*2)/2)<5 and RandYN(7)) {
			oldCZer=CMaxpsheno;

			tmpG4 ="";G4("Ps",4,9,true,false);G4("Ku",4,8,false,false);G4("Ku",4,8,false,false);

			if(RandYN(7)){cout << " * �����, ��������! ���� �����."       << "   " << tmpG4 << endl;PZerna();
			}else{        cout << " * ��������. � ����� ��� � �������!  " << "   " << tmpG4 << endl ;}

			cout << endl;
		}





		//=== �������� ============================
		Urojay = 0;
		Posev  = ludi*ind;
		if(Posev>zemly)  Posev = zemly;
		if(Posev>psheno) Posev = psheno;

		psheno -= Posev;
		if(psheno<0) psheno=0;
		cout << "   i_i ��������: -" << Posev  <<endl;

		cout << endl;


		//=== ������� =============================
		Kataklizm();
		Xorosho();
		if(ludi+vs<1)break;



		//=== ���������� ==========================
		if(Poxod_Year>0) {
			cout << " * ���������� : " << Poxod_Year << " ����(�)" <<  "  X: "<< Poxod_ludi <<  "  O: "<< Poxod_gold << endl;
			Poxod_Year++;
			cout << endl;
		};

		//=== ���������� ����������� ==============
    	if(RandYN(6) and Poxod_Year<1){
			Rez2 = ludi-Posev/ind-vs;
			if(10<=Rez2 and Rez2*Eda<psheno and Rez2*10<gold){
				cout << "** � ���������� ������� (max "<< Rez2 << "): ";
				cin >> Poxod_ludi;
				if(Poxod_ludi<0)    Poxod_ludi=0;
				if(Poxod_ludi>Rez2) Poxod_ludi=Rez2;
				if(Poxod_ludi>0){
					Poxod_Year  = 1;
					gold       -= Poxod_ludi*10;
					psheno     -= Poxod_ludi*Eda;
					ludi       -= Poxod_ludi;
					cout << " * � ���������� ����: Xx " << Poxod_ludi << "  ii: " << Poxod_ludi*Eda << "  Oo: " << Poxod_ludi*10 << endl;
				};
				cout << endl;
			};

    	};








		//=== ������������ ====================
    	Rez0 = (ludi-vs-Poxod_ludi)/3;
    	if(0<Rez0){
			Rez1 = iif(RandYN(7), Rez0*RandSBS()*0.1, 0);
			Rez2 = iif(RandYN(7), Rez0*RandSBS()*0.1, 0);
			Rez3 = iif(RandYN(7), Rez0*RandSBS()*0.1, 0);
			goods +=Rez1;
			tools +=Rez2;
			wepons +=Rez3;

			cout << "   ������������  ��:+" << Rez1 << "  To:+" << Rez2<< "  We:+" << Rez3 << endl;
	    };


    	EnterMenu();

//===================================================================
//===================================================================
//===================================================================

		//=== ������� ==================== 160513
    	Rez0=0;Rez1=0;Rez2=0;Rez3=0;Rez4=0;Rez5=0;Rez6=0;

    	Rez0 = GolodEda(0,Eda); // �� ������ ����� � -

		if(Rez0<0){   // �����

			oldCZer= CMaxpsheno;  // ���������� ���� �� �����

			doubletmp0 = (double) abs(Rez0)/psheno;
			doubletmp0 = pow(doubletmp0,2)*pow(doubletmp0,2);
			Rez6       = round((ludi+vs)*doubletmp0);

			if(Rez6>ludi+vs) Rez6 = ludi+vs;

			if(ludi>=vs){
				Rez1 = iif(vs==0,   Rez6, Rez6/3*2);
				if(ludi<Rez6) Rez1 = ludi;
				Rez2 = Rez6-Rez1;
				if(vs<Rez2) Rez2 = vs;
			}else{
				Rez2 = iif(ludi==0, Rez6, Rez6/3);
				if(vs<Rez6) Rez2 = vs;
				Rez1 = Rez6-Rez2;
				if(ludi<Rez1) Rez1 = ludi;
			}

			ludi -= Rez1;
			vs   -= Rez2;
			dead += Rez1+Rez2;

			tmpG4 ="";G4("Ku",4,7,false,false);G4("Ur",4,7,true,false);
			cout <<"  �����  (" << "i: " << psheno << "/" << Rez0 << "/" <<  (double) round(doubletmp0) << ")   �: -" << Rez1 << "  *: -" << Rez2 << "  " << tmpG4 << endl;
			cout << endl;
		}

		if(ludi+vs<1)break; // ����� � �����

    	Rez1 = ludi*Eda;
    	Rez3 = vs*Eda * CofEdaVs;
    	Rez0=Rez1+Rez3;

		psheno -= Rez0;
		if(psheno<0) psheno =0;

		tmpG4 ="";G4("Ku",0,8,true,false);G4("Ur",0,9,true,false);
		cout <<"   �������: -"<< Rez0<<"   "<< "-" << Rez1<<"/"<< iif(Rez3!=0,"-","") <<Rez3<<"  " << tmpG4 << endl;







		//=== ����������� ===================== 160513
    	//  ludi1Year
    	tmp = 1;
    	if(ludi+(vs*CofEdaVs)*Eda<=psheno) tmp ++; else tmp --;
    	if(ludi+vs*ind  <=zemly)           tmp ++; else tmp --;
    	if(ludi+(vs*CofEdaVs)*Eda  <=gold) tmp ++; else tmp --;
    	doubletmp =	round(ludi*10/ludi1Year*tmp/10);

		if(doubletmp<0) doubletmp=0;
		ludi += doubletmp;
		cout << "   �����������: " << iif(doubletmp>0,"+","") << doubletmp  << endl;

		//EnterMenu();








		//=== ������ =====================
		Urojay = 0;

		Rez0 = RandBW(0,6);
		Rez0+=tps+round(Sinu_Ur(toYear)*100)/100.;
		if(8<Rez0){ctps++;}  // ���������� �����
		if(Rez0>9) Rez0=9;

		Urojay = Posev*Rez0    *4;

		psheno += Urojay;
		if(psheno<0) psheno =0;
		cout << "   i_i: " << iif(0<Urojay,"+","") << Urojay << "   " << Posev  << "/" << Rez0   <<endl;


		cout << endl;


		//=== ������� =============================
		Kataklizm();
		Xorosho();
		if(ludi+vs<1)break;









		//=== �������� ������ ============
		if(RandYN(1)){
			Rez0 = abundance()*RandBW(tze,9)/10;
			if(RandYN(1)) Rez0*=-1;
			gold+= Rez0;

			tmpG4 = "";
			if(RandYN(4)){G4("Ku",4,7,true,true);G4("Di",4,7,true,true);G4("Ur",4,7,true,true);}
			cout << "   �������� ������ Oo: " << iif(Rez0<0,"","+") << Rez0 << "  "  <<  tmpG4 << endl;
			cout << endl;
		};






		//=== ������� ����� ������ =============
    	if(RandYN(7)) {PZerna();cout << endl;}





		//=== ���������� ����������� ==============
    	if(Poxod_Year>0 and (RandYN(0) or Poxod_Year==45)){

    		cout << endl;

			Rez0 = 0;
			Rez1 = 0;  // gold
			Rez3 = 0;  // land

			if(RandYN(1)) Poxod_ludi = VoyajPrem_ludi(Poxod_ludi);
				if(Poxod_ludi<1) Poxod_ludi=1; // ���-�� ������ �� ���������)
			if(RandYN(3)) Rez3 = VoyajPrem_zem(zemly);
			if(RandYN(3)) Rez1 = VoyajPrem_gold(gold);

			ludi +=Poxod_ludi;
			gold +=Poxod_gold + Rez1;
			zemly+=Rez3;

			cout << " * ���������� ��������� �  __:" << iif(Rez3>0,"+","") << Rez3 << "  Xx: " << Poxod_ludi << "  Oo: " << iif(Rez1>0,"+","") <<  Rez1  << endl;
			Poxod      = 0;
			Poxod_ludi = 0;
			Poxod_gold = 0;
			Poxod_Year = 0;

			cout << endl;

    	};


		//======================================
		Kataklizm();
		Xorosho();
		if(ludi+vs<1)break;



		//=== ������ � ��������� ===============
		Rez1 = RandBW(7,9);
		Rez0 = nalog*ludi*Rez1/10;

		Rez2 = RandBW(0,3);
		Rez3 = nalog*2*vs*(Rez2/10+1);

		tmpG4 = "";	G4("Na",0,7,true,true); G4("Ku",0,7,true,true);

		cout << "   �����/���� " << "~:" << iif(nalog>0,"+","") << nalog
			 << "/" << iif(Rez0>0,"+","") << Rez0 << "/" << iif(Rez3>0,"-","") << Rez3
			 << "   X:" << ludi << "/" << (double) Rez1/10
			 << "  *:" << vs << "/" << (double) Rez2/10 << endl;
		cout << "              " << tmpG4 << endl;



		gold += Rez0;
		gold -= Rez3;




		//=== �������� =========================
		if(ctze>=   tze*tze+1){ctze=0;tze++; cout << "   TD+" << endl;} // __ ����������
		if(ctze<=-1*tze*tze-1){ctze=0;tze--; cout << "   TD-" << endl;} // __ ����������

		if(ctlu>=   tlu*tlu+1){ctlu=0;tlu++; cout << "   TK+" << endl;} // xx ��������
		if(ctlu<=-1*tlu*tlu-1){ctlu=0;tlu--; cout << "   TK-" << endl;} // xx ��������

		if(ctps>=   tps*tps+1){ctps=0;tps++; cout << "   TU+" << endl;} // ii �����-������
		if(ctps<=-1*tps*tps-1){ctps=0;tps--; cout << "   TU-" << endl;} // ii �����-������

		if(ctvs>=   tvs*tvs+1){ctvs=0;tvs++; cout << "   TV+" << endl;} // ** �����
		if(ctvs<=-1*tvs*tvs-1){ctvs=0;tvs--; cout << "   TV-" << endl;} // ** �����

		if(ctgo>=   tgo*tgo+1){ctgo=0;tgo++; cout << "   TG+" << endl;} // oo �����
		if(ctgo<=-1*tgo*tgo-1){ctgo=0;tgo--; cout << "   TG-" << endl;} // oo �����

		if(ctna>=   tna*tna+1){ctna=0;tna++; cout << "   TN+" << endl;} // ~~ �����
		if(ctna<=-1*tna*tna-1){ctna=0;tna--; cout << "   TN-" << endl;} // ~~ �����

		if(ctwe>=   twe*twe+1){ctwe=0;twe++; cout << "   TW+" << endl;} // we ������
		if(ctwe<=-1*twe*twe-1){ctwe=0;twe--; cout << "   TW-" << endl;} // we ������

		if(ctto>=   tto*tto+1){ctto=0;tto++; cout << "   TT+" << endl;} // to ���������������
		if(ctto<=-1*tto*tto-1){ctto=0;tto--; cout << "   TT-" << endl;} // to ���������������

		if(ctgd>=   tgd*tgd+1){ctgd=0;tgd++; cout << "   T�+" << endl;} // to
		if(ctgd<=-1*tgd*tgd-1){ctgd=0;tgd--; cout << "   ��-" << endl;} // to

		if(ludi+vs<1) break;
		ludi1Year = ludi+vs; 			   // ��� ����������� � ��. ����

		EnterMenu();
		if(Enter==77)break;
	}
	cout << endl;
	cout << "�������� ��������" << endl;
	vSin();
	cin >> Posev;
	return 1;
};


int main() {

	srand (time(NULL));

	ini();
	day();
	save();

	return 1;
}
