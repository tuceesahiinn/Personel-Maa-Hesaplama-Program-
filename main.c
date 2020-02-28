#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float tumcalisanodenen,devletaylikgelirver,ayliktoplambrutucret,ayliktoplamnetucret,enyukbrut=0,netyukbrut=0;
    float enyukgelver=0,enyuknetucret=0;
    float netenyukgelver=0,netenyuknetucret=0,netenyukbrut=0;
    int girilenpersonelsayisi=0,ikibindenazalanlar=0,gv15=0,gv20=0,gv27=0,gv35=0;
    int tumcalevli=0,tumcalbekar=0,evlicalisesdurum=0,tumcocuksayisi=0,tumcocuklucalisan=0,ucdenfazla=0,engellicalisan=0;
    char enyukad[50],enyuksoyad[50],enyuktc[50];
    char netenyukad[50],netenyuksoyad[50],netenyuktc[50];


    char personeldevam;
    do
    {
        girilenpersonelsayisi++;
        int cocuksayisi,cocukyasi,odenek=0,engelorani,muaftutar,esyardimi=0;
        char ad[50],soyad[50],medenidurum,esdurum,engeldurumu,tcno[50];
        float brutucret,ayliknetmaas,netucret,engelbrutucret,gelirvergisi;

        printf("TC Kimlik Numaranizi Giriniz: ");
        scanf(" %s",&tcno);

        printf("Ad: ");
        scanf(" %s",&ad);
        printf("Soyad: ");
        scanf(" %s",&soyad);

        printf("Aylik Net Maasinizi Giriniz: "); //Projedeki Brüt Ücret=Aylik Net Maaş
        scanf(" %f",&ayliknetmaas);
        if(ayliknetmaas<1777.50)
        {
            ayliknetmaas=1777.50;
        }

        char medenidogrumu='y';
        do
        {
            printf("Medeni Durumunuz(Evli ise E veya e,Bekar ise B veya b): ");
            scanf(" %c",&medenidurum);
            if(medenidurum=='E' || medenidurum=='e')
            {
                tumcalevli++;
                char esdogrumu='y';
                do
                {
                    printf("Esiniz Calisiyor Mu(Evet ise E veya e,Hayir ise H veya h): ");
                    scanf(" %c",&esdurum);
                    if(esdurum=='E' || esdurum=='e')
                    {
                        brutucret=ayliknetmaas;
                        esyardimi=0;
                        esdogrumu='e';
                        evlicalisesdurum++;
                    }
                    else if(esdurum=='H' || esdurum=='h')
                    {
                        brutucret=ayliknetmaas+220;
                        esyardimi=220;
                        esdogrumu='e';
                    }
                    else
                        printf("\n Yanlis giris yaptiniz tekrar giriniz...\n");
                }
                while(esdogrumu=='y');

                printf("Cocuk Sayiniz: ");
                scanf(" %d",&cocuksayisi);
                if(cocuksayisi>0)
                {
                    tumcocuklucalisan++;
                    tumcocuksayisi=tumcocuksayisi+cocuksayisi;

                    for(int i=0; i<cocuksayisi;)
                    {
                        printf("Cocugunuzun Yasini Giriniz: ",i++);
                        scanf(" %d",&cocukyasi);
                        if(cocukyasi<=6)
                        {
                            odenek=odenek+25;
                        }
                        else if(cocukyasi>6)
                        {
                            odenek=odenek+45;
                        }
                    }
                    brutucret=brutucret+odenek;
                }
                if(cocuksayisi>3)
                {
                    ucdenfazla++;
                }

                medenidogrumu='e';
            }
            else if(medenidurum=='B' || medenidurum=='b')
            {
                brutucret=ayliknetmaas;
                medenidogrumu='e';
                tumcalbekar++;
            }
            else
                printf("\nYanlis giris yaptiniz tekrar giriniz...\n");

        }
        while(medenidogrumu=='y');

        char engeldogrumu='y';

        do
        {
            //Aylik Vergiyi Engel Durumuna Göre Hesaplama
            printf("Engel Durumunuz(Evet ise E veya e, Hayir ise H veya h): ");
            scanf(" %c",&engeldurumu);

            if(engeldurumu=='E' || engeldurumu=='e')
            {
                printf("Engel Oraninizi Giriniz(Lutfen 1'den 100'e kadar tamsayi giriniz...): ");
                scanf(" %d",&engelorani);

                if(engelorani>=40 && engelorani<60)
                {
                    engellicalisan++;
                    muaftutar=210;
                    engelbrutucret=brutucret-muaftutar;
                }
                else if(engelorani>=60 && engelorani<80)
                {
                    engellicalisan++;
                    muaftutar=470;
                    engelbrutucret=brutucret-muaftutar;
                }
                else if(engelorani>=80 && engelorani<=100)
                {
                    engellicalisan++;
                    muaftutar=900;
                    engelbrutucret=brutucret-muaftutar;
                }
                engeldogrumu='e';
            }
            else if(engeldurumu=='H' || engeldurumu=='h')
            {
                muaftutar=0;
                engelbrutucret=brutucret;
                engeldogrumu='e';
                printf("\n Engel Durumunuz Bulunmamaktadir.");
            }
            else
                printf("\n Yanlis giris yaptiniz tekrar giriniz...\n");
        }
        while(engeldogrumu=='y');

        if(engelbrutucret<2000)
        {
            netucret=engelbrutucret-((engelbrutucret/100)*15)+muaftutar;
            gelirvergisi=((engelbrutucret/100)*15);
            gv15++;
        }
        else if(engelbrutucret>=2000 && engelbrutucret<5000)
        {
            netucret=engelbrutucret-((engelbrutucret/100)*20)+muaftutar;
            gelirvergisi=((engelbrutucret/100)*20);
            gv20++;
        }
        else if(engelbrutucret>=5000 && engelbrutucret<10000)
        {
            netucret=engelbrutucret-((engelbrutucret/100)*27)+muaftutar;
            gelirvergisi=((engelbrutucret/100)*27);
            gv27++;
        }
        else if(engelbrutucret>=10000)
        {
            netucret=engelbrutucret-((engelbrutucret/100)*35)+muaftutar;
            gelirvergisi=((engelbrutucret/100)*35);
            gv35++;
        }

        if(netucret<2000)
        {
            ikibindenazalanlar++;
        }

        printf("\n");

        printf("\n---CALISAN BILGILERI---");
        printf("\n %s Tc Nolu %s %s",tcno,ad,soyad);
        printf("\n Aylik Net Maas=%.2f TL",ayliknetmaas);
        printf("\n Es Durumundan Odenen Miktar= %d TL",esyardimi);
        printf("\n Cocuk Icin Odenen Miktar= %d TL",odenek);
        printf("\n Aylik Toplam Brut Ucret= %.2f TL",brutucret);
        printf("\n Gelir Vergisi Kesinti Miktari= %.2f TL",gelirvergisi);
        if(engelorani>=40 && engelorani<60)
        {
            printf("\n 3. Dereceden Engelli Indirimi");
        }
        else if(engelorani>=60 && engelorani<80)
        {
            printf("\n 2. Dereceden Engelli Indirimi");
        }
        else if(engelorani>=80 && engelorani<=100)
        {
            printf("\n 1. Dereceden Engelli Indirimi");
        }
        else
        {
            printf("\n Herhangi Bir Engelli Indiriminiz Bulunmamaktadir.");
        }
        printf("\n Aylik Net Ucret= %.2f TL",netucret);
        printf("\n");
        printf("\n---Verilecek Banknotlar---\n");
//--->Banknot Olarak Hesaplama

        if(netucret>netenyuknetucret)
        {
            netenyukbrut=brutucret;
            for(int i=0; i<50; i++)
            {
                netenyuktc[i]=tcno[i];
                netenyukad[i]=ad[i];
                netenyuksoyad[i]=soyad[i];
            }
            netenyukgelver=gelirvergisi;
            netenyuknetucret=netucret;
        }

        if(brutucret>enyukbrut)
        {
            enyukbrut=brutucret;
            for(int i=0; i<50; i++)
            {
                enyuktc[i]=tcno[i];
                enyukad[i]=ad[i];
                enyuksoyad[i]=soyad[i];
            }
            enyukgelver=gelirvergisi;
            enyuknetucret=netucret;
        }
        tumcalisanodenen=tumcalisanodenen+netucret;
        devletaylikgelirver=devletaylikgelirver+gelirvergisi;
        ayliktoplambrutucret=ayliktoplambrutucret+brutucret;
        ayliktoplamnetucret=ayliktoplamnetucret+netucret;


        float banknotum[12]= {200,100,50,20,10,5,1,0.50,0.25,0.10,0.05,0.01};
        int gerekenbanknot[12];

        for(int i=0; i<12; i++)
        {
            gerekenbanknot[i]=netucret/banknotum[i];
            netucret=fmod(netucret,banknotum[i]);
        }
        for(int i=0; i<12; i++)
        {
            if(gerekenbanknot[i]!=0)
            {
                printf("%.2f Banknottan %d adet \n",banknotum[i],gerekenbanknot[i]);
            }
        }
        printf("\n\n");
        printf("Baska Calisan Var Mi[Evet ise E veya e,Hayir ise H veya h): ");
        scanf(" %c",&personeldevam);
    }

    while(personeldevam=='E' || personeldevam=='e');


    printf("\n----Tum Calisanlara Odenenlerin Bilgileri----");
    printf("\n Tum Calisanlara Odenen Aylik Net Ucret= %.2f TL",tumcalisanodenen);
    printf("\n Devlete Odenen Aylik Toplam Gelir Vergisi= %.2f TL",devletaylikgelirver);
    printf("\n Tum Calisanlarin Aylik Toplam Brut Ucret Ortalamasi= %.2f TL",ayliktoplambrutucret/girilenpersonelsayisi);
    printf("\n Tum Calisanlarin Aylik Toplam Net Ucret Ortalamasi= %.2f TL",ayliktoplamnetucret/girilenpersonelsayisi);
    printf("\n Aylik Gereken Para Miktarlari= \n\n");

    //-----------------------------------------------------------------------
    float banknotumtumu[12]= {200,100,50,20,10,5,1,0.50,0.25,0.10,0.05,0.01};
    int gerekenbanknottumu[12];
    for(int i=0; i<12; i++)
    {
        gerekenbanknottumu[i]=ayliktoplamnetucret/banknotumtumu[i];
        ayliktoplamnetucret=fmod(ayliktoplamnetucret,banknotumtumu[i]);
    }
    for(int i=0; i<12; i++)
    {
        if(gerekenbanknottumu[i]!=0)
        {
            printf("%.2f Banknottan %d Adet \n",banknotumtumu[i],gerekenbanknottumu[i]);
        }
    }
    //-------------------------------------------------------------------------
    printf("\n-------------------------------------------------------------------------------------------------------------");
    printf("\n Aylik Net Ucreti 2000'den Az Olan Kisi Sayisi= %d",ikibindenazalanlar);
    printf("\n-------------------------------------------------------------------------------------------------------------");
    float a=((gv15*100)/girilenpersonelsayisi);
    float b=((gv20*100)/girilenpersonelsayisi);
    float c=((gv27*100)/girilenpersonelsayisi);
    float d=((gv35*100)/girilenpersonelsayisi);
    printf("\n Gelir Vergisi 15 lik Dilimdeki Personel Sayisi= %d ve Yuzdelik Orani %.2f dir.",gv15,a);
    printf("\n Gelir Vergisi 20 lik Dilimdeki Personel Sayisi= %d ve Yuzdelik Orani %.2f dir.",gv20,b);
    printf("\n Gelir Vergisi 27 lik Dilimdeki Personel Sayisi= %d ve Yuzdelik Orani %.2f dir.",gv27,c);
    printf("\n Gelir Vergisi 35 lik Dilimdeki Personel Sayisi= %d ve Yuzdelik Orani %.2f fir.",gv35,d);
    printf("\n-------------------------------------------------------------------------------------------------------------");
    printf("\n Aylik Toplam Brut Ucreti En Yuksek Calisanin Tc si= %s",enyuktc);
    printf("\n Aylik Toplam Brut Ucreti En Yuksek Calisanin Adi ve Soyadi= %s %s",enyukad,enyuksoyad);
    printf("\n Aylik Toplam Brut Ucreti En Yuksek Calisanin Brut Ucreti= %.2f TL",enyukbrut);
    printf("\n Aylik Toplam Brut Ucreti En Yuksek Calisanin Gelir Vergisi Kesintisi= %.2f TL",enyukgelver);
    printf("\n Aylik Toplam Brut Ucreti En Yuksek Calisanin Aylik Net Ucreti= %.2f TL",enyuknetucret);
    printf("\n-------------------------------------------------------------------------------------------------------------");
    printf("\n Aylik Toplam Net Ucreti En Yuksek Calisanin Tc si= %s",netenyuktc);
    printf("\n Aylik Toplam Net Ucreti En Yuksek Calisanin Adi ve Soyadi= %s %s",netenyukad,netenyuksoyad);
    printf("\n Aylik Toplam Net Ucreti En Yuksek Calisanin Brut Ucreti= %.2f TL",netenyukbrut);
    printf("\n Aylik Toplam Net Ucreti En Yuksek Calisanin Gelir Vergisi Kesintisi= %.2f TL",netenyukgelver);
    printf("\n Aylik Toplam Net Ucreti En Yuksek Calisanin Aylik Net Ucreti= %.2f TL",netenyuknetucret);
    printf("\n-------------------------------------------------------------------------------------------------------------");
    printf("\n Tum calisanlarin yuzde %.2f si evli yuzde %.2f si bekardir.",((tumcalevli*100)/girilenpersonelsayisi),((tumcalbekar*100)/girilenpersonelsayisi));
    printf("\n-------------------------------------------------------------------------------------------------------------");
    printf("\n Tum evli calisanlarin eslerinin yuzde %.2f si calismaktadir.",((evlicalisesdurum*100)/tumcalevli));
    printf("\n-------------------------------------------------------------------------------------------------------------");
    printf("\n Calisanlarin bakmakla yukumlu oldugu cocuk sayisi ortalamasi= %.2f",tumcocuksayisi/tumcocuklucalisan);
    printf("\n-------------------------------------------------------------------------------------------------------------");
    printf("\n Ucten fazla cocugu olan calisan sayisi= %d",ucdenfazla);
    printf("\n-------------------------------------------------------------------------------------------------------------");
    printf("\n Engelli calisan sayisi %d dir.Tum calisanlarin yuzde %.2f si engellidir.",engellicalisan,((engellicalisan/girilenpersonelsayisi)*100));

    return 0;

}

