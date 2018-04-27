#include <stdio.h>

void Baslangic(void);
void AnaEkran(void);
void AlaniBas(void);
void AtakYap(char,int,int);


char alan[8][8];
int player = 0; // 0  1. oyuncu, 1 2. oyuncu
int satir,sutun,atak_sayisi=0,birinci_tas=2,ikinci_tas=2;

void main(void){
    alan[3][3] = 'O';
    alan[3][4] = 'X';
    alan[4][3] = 'X';
    alan[4][4] = 'O';

    Baslangic();
    while(1){
        AnaEkran();
        if(atak_sayisi>=63){
            if(birinci_tas>ikinci_tas){
                printf("\nTablo doldugu icin oyun bitti.\nKAZANAN 1. OYUNCU");
            }
            else if(ikinci_tas > birinci_tas){
                printf("\nTablo doldugu icin oyun bitti.\nKAZANAN 2. OYUNCU");
            }
            else{
                printf("\nTablo doldugu icin oyun bitti.\nKAZANAN YOK - DURUM BERABERE");
            }
            break;
        }
        if(birinci_tas==0){
            printf("\nOyun Bitti. Kazanan 2. Oyuncu");
            break;
        }
        else if(ikinci_tas==0){
            printf("\nOyun Bitti. Kazanan 1. Oyuncu");
            break;
        }
    }

}


void Baslangic(){
	printf("[Programlamaya Giris III. Odev]\nIrem Koprek - 160204019\nBaslayan Tas=  [O]\n");
}

void AnaEkran(){

	printf("\nHamle Sirasi:  %d. Oyuncu\nToplam Hamle:  %d adet\n\n",player+1,atak_sayisi);
	AlaniBas();
	OyuncuGirdisi();


}

void AlaniBas(){
int i,j;
    printf(" ");
	for(i=0;i<8;i++){
		printf("   %d",i+1);
	}
	printf("\n   ________________________________\n");
	for(i=0;i<8;i++){
		printf("%d |",i+1);
		for(j=0;j<8;j++){
			if(alan[i][j]==NULL){
				printf("   |");
			}
			else{
				printf(" %c |",alan[i][j]);
			}
		}
		printf("\n   ________________________________\n");
	}
}

void OyuncuGirdisi(){
    printf("Satir Sutun [Ornek: 4 5] girin= ");
    scanf("%d %d",&satir,&sutun);
    if(satir>=0 && satir<=8 && sutun>=0 && sutun<=8){
	    if(alan[satir-1][sutun-1]==NULL){
			if(player == 1){
				printf("\nKonulacak Tas: [X]");
				//alan[satir-1][sutun-1] = 'O';
				AtakYap('O',satir-1,sutun-1);
				//player = 0;
			}
			else{
				printf("\nKonulacak Tas: [O]");
				//alan[satir-1][sutun-1] = 'X';
				AtakYap('X',satir-1,sutun-1);
				//player = 1;
			}
		}
		else{
			printf("\n[HATA]:  %d. Oyuncu, ayni yere taş koymaya calisti.\n",player+1);
		}
	}
	else{
			printf("\n[HATA]: %d. Oyuncu, oyun alani disinda konum girdi.",player+1);
	}

}

void AtakYap(char c,int satir,int sutun){
	
	int i,j,a,b,x,y,hatali=0;
	char eklenecek;
	if(c=='X'){eklenecek = 'O';}else{eklenecek='X';}
	for(i=satir-1;i<=satir+1;i++){
		for(j=sutun-1;j<=sutun+1;j++){
			if(i>=0 && i<=7 && j>=0 && j<=7){
				// Gidebileceği alan buldu. Bu yönde ilerleyecek.
				if(alan[i][j]!=c && alan[i][j]!=NULL){
					// Rakip oyuncu tasi buldu.
					a=i;
					b=j;
					while(1){
						// Surekli bu yonde ilerleyecek
						if(alan[a][b]!=c && alan[a][b]!=NULL){
							if(a>satir){a++;}else if(a<satir){a--;}
							if(b>sutun){b++;}else if(b<sutun){b--;}
						}
						else if(alan[a][b]==c){
							//printf("\nBURADA %d  %d\n",a,b);
							x = i;
							y = j;
							while(x!=a || y!=b){
								//printf("\nBURADA 2\n");
								alan[x][y] = c;
								alan[satir][sutun] = c;
								if(c=='X'){birinci_tas++;ikinci_tas--;}else if(c=='O'){birinci_tas--;ikinci_tas++;}
								if(x>a){x--;}else if(x<a){x++;}
								if(y>b){y--;}else if(y<b){y++;}
								hatali=1;
							}
							if(c=='X'){player=1;}else{player=0;}
							atak_sayisi++;
							break;
						}
						else{
							
								break;
						}
						
					}
				}
			}	
		}
		
	}	
	if(hatali==0){printf("\n[HATA]: %d. Oyuncu hatali giris yaptı. Tekrar deneyin.\n",player+1);}
	/*
	char e;
	if(c =='X'){e='O'}else{e='X'}
	
	if(alan[satir][sutun]==e){}
	*/
}












