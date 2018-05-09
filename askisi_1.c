#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


main(){

    problem();


}


problem(){

    FILE *fp;
    int A=1,i=0,MinMax,j,ln,x=0,grami=0,arithmos_metabliton,z=-1,number_of_reades,g,C=0,l=0,epan=0;
    string trush;

    fp=fopen("askisi.txt", "r");
    // elegho ama to programma mporese na brei to arxei keimenou
    if (fp==0)
        printf("to arxeio den brethike!!\n");
    else
        printf("to arxeio brethike.\n");

    while ((A=fgetc(fp)) != EOF){
        //printf("i %d",A);
        /*if (A==1){
            ln=i;
        }*/
        i++;
    }
    //printf("%d\n",i);

    fclose(fp);

    fp=fopen("askisi.txt", "r");
    // elegho ama to programma mporese na brei to arxei keimenou
    //if (fp==0)
       // printf("to arxeio den brethike!!\n");
    //else
        ;
       // printf("to arxeio brethike.\n");

    int B[i+5];

    i=0;


    while ((A=fgetc(fp)) != EOF){
        B[i]= A;
        //printf("to b ine= %d",B[i]);
        if (B[i]==120)
            x++;
        if (B[i]==10)
            grami++;
        i++;
    }
    grami++;
    //printf("\noi grames ine %d kai ta x ine %d ",grami,x);

    int Eqin[grami];



    if ((B[0]==109 || B[0]==115) && (B[1]==105 || B[1]==73) && (B[2]==110 || B[2]==78 )){
        MinMax=-1;
        //printf("\nproblima elaxistopoihsis");
        arithmos_metabliton = x/grami;

    }
    else if ((B[0]==109 || B[0]==115) &&  (B[1]==97 || B[1]==65) && (B[2]==88 || B[2]==120 ) ) {
        MinMax= 1;
        //printf("problima megistopoihshs");
        arithmos_metabliton = (x-1)/grami;
    }
    else{
        printf("Den exi dothi ama to problima einai megistopoihshs h elaxistopoihshs");
        arithmos_metabliton=0;
    }

    //printf("\no arithmos ton meabliton ana sira ine %d",arithmos_metabliton);

    int c[arithmos_metabliton];

    rewind(fp);

    i=3;
    int a[grami][arithmos_metabliton];
    int m[grami][arithmos_metabliton+1];

     while ((A=fgetc(fp)) != EOF){

        /*if (A>=48 && A<=57){
            B[i]=A;
        }*/
        number_of_reades=fscanf(fp," %d" ,&g);
        if (number_of_reades ==1 && epan<arithmos_metabliton){
            //printf("\nArxiki synartisi number_of_reades %d trush ine %d ",number_of_reades,g);
            c[epan]=g;
            //printf("\no c ine%d ",c[epan]);
            epan++;
        }
        else if (number_of_reades ==1){
            if(C==arithmos_metabliton+1){
                l++;
                C=0;
            }
            m[l][C]=g;
            //printf("\nDeyteri synartisi number_of_reades %d trush ine %d ",number_of_reades,g);
            //printf("\ni stili ine %d kai h seira %d o arithos ine %d kai %d ",C,l,m[C][l],g);
            C++;
        }

        /*if (A==43 || A==45){
            B[i]=A;
        }*/
        if (A==60 || A==61 || A==62){
            if (A==60)
                Eqin[z]=-1;
            else if (A==61)
                Eqin[z]=0;
            else
                Eqin[z]=1;
            z++;
            }

        i++;
    }

    int b[grami];


    //printf(" \n!!!!!!!!!! to b ine %d",m[0][0]);
    for (i=0;i<grami-1;i++){
        for(j=0;j<arithmos_metabliton+1;j++){
            if (j==arithmos_metabliton){
                b[i]=m[i][j];

            }
            else
                a[i][j]=m[i][j];

        }
    }

    fclose(fp);

    fp=fopen("askisi_1.txt","w");

    if(MinMax==-1)
        fputs("min\n",fp);
    else
        fputs("max\n",fp);

    //fprintf(fp,"\n");
    fprintf(fp,"s.t.\n");

    for (i=0;i<grami-1;i++){
        for (j=0;j<arithmos_metabliton;j++){
            z=a[i][j];
            printf("\n%d",z);
            fprintf(fp,"%d ",z);
            if (j==arithmos_metabliton-1){
                if(Eqin[z]==-1){
                    fputs("<",fp);
                }
                else if (Eqin[z]==0)
                    fputs("=",fp);
                else
                    fputs(">",fp);
                fprintf(fp," %d",b[i]);
                fprintf(fp,"\n");

            }

        }
    }



}
