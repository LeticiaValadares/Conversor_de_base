#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// Esse cabecalho limpa a tela e deixa o titulo do programa
void cabecalho(){

    system("cls");
    printf("-------- CONVERSOR DE BASE ----------\n");

}
int menu(){
    int opcao;
    cabecalho();
    printf("--------------------------------------------\n");
        printf("|Digite 1: Base decimal p/ Base binaria     |\n");
        printf("|Digite 2: Base binaria p/ Base decimal     |\n");
        printf("|Digite 3: Base decimal p/ Base Octal       |\n");
        printf("|Digite 4: Base octal p/ Base decimal       |\n");
        printf("|Digite 5: Base decimal p/ Base hexadecimal |\n");
        printf("|Digite 6: Base hexadecimal p/ Base decimal |\n");
        printf("|Digite 7: Base octal p/ Base hexadecimal   |\n");
        printf("|Digite 8: Base hexadecimal p/ Base octal   |\n");
        printf("|Digite 9: Base binaria p/ Base hexadecimal |\n");
        printf("|Digite 10: Base hexadecimal p/ Base binaria|\n");
        printf("--------------------------------------------\n");
        printf("\n");
        printf("Escolha uma opcao: \n");
        scanf("%d",&opcao);

        return opcao;
}

// funcao que conta a quantidade de caracter de um vetor
int quantidade(int v[]){

    int i;
    int cont = 0;

    do{

        cont++;

    }while(v[i] != '\0');

    return cont;
}
// função para inverter qualquer vetor
void inverte(int v[], int tamanho){

    int auxiliar,i;

    /* auxiliar é uma variavel de backup, onde guardados o primeiro valor. Logo passamos o primeiro valor para a ultima
    * posicao e a ultima para a primeira
    */
    int metade = tamanho/2;
    for(i=0; i<metade; i++){
        auxiliar = v[i];
        v[i] = v[tamanho-i-1];
        v[tamanho-i-1] = auxiliar;
    }

}
// Funcao que transforma binario para base decimal
void BinarioDecimal(){
  //  cabecalho();
    char binario[20];
    int somatorio = 0;
    int i;
    int qt;
    // leitura de valores
    printf("Digite um numero em binario: ");
    fflush(stdin);
    gets(binario);

    // Criei uma função para retornar a quantidade de caracter de um vetor
    qt = strlen(binario);
    int novoBinario[qt];

    // Como o vetor é um vetor de caracter, temos que mudar para um vetor de inteiro
    for(i = 0; i<qt; i++){

        if(binario[i] == '0'){
            novoBinario[i] = 0; // o novo vetor recebe o valor de 0
        }
        if(binario[i] == '1'){
            novoBinario[i] = 1; // o novo vetor recebe o valor de 1
        }
    }

    inverte(novoBinario,i);
    i = 0;
    while(i<qt){
        somatorio+= (novoBinario[i] * pow( 2 , i));
        i++;
    }
    printf("\nBinario: %d \n", somatorio);
}

// funcao que converte decimal para binario
void DecimalBinaria(){

    int decimal;
    int resto;
    int quociente;
    int binario[30];
    int cont = 0;
    int i=0,j;
    printf("\nDigite um numero em decimal para a conversao em binario: \n");
    scanf("%d",&decimal);

    //vamos fazer várias divisões por 2, até que o numero chegue a zero e pare o laço de repeticao
    do{

        resto = decimal % 2; // resto da divisao
        quociente = decimal/2; // quociente da divisao, para ser dividido novamente
        binario[cont] = resto; // guarda no vetor
        decimal = quociente; // vira o novo decimal
        cont++;

    }while(decimal != 0);

    // Como as divisões segue uma ordem, vamos ter que inverter o vetor para mostrar o binario correto

   // inverte(binario, cont);

    // Mostra o resultado
    printf("Numero em binario: ");
    j = 0;
    while(j<cont){
        printf("%d", binario[j]);
        j++;
    }

}
// Aqui temos a conversão de numeros decimais para octal
void DecimalOctal(){

    int decimal;
    int resto;
    int quociente;
    int octal[50];
    int cont = 0;
    int i,j;
    printf("Digite um numero em decimal para a conversao em octal: \n");
    scanf("%d",&decimal);

    /*
    * Aqui vamos fazer diversas divisões consecutivas por 8, até o numero em decimal ser zero
    */
    do{

        resto = decimal % 8;
        quociente = decimal/8;
        octal[cont] = resto;
        decimal = quociente; // O quociente dessa divisão será o novo numero decimal
        cont++;
    }while(decimal != 0);

    inverte(octal, cont);

    i = 0;
    while(i<cont){

        printf("%d", octal[i]); // vamos mostrar todo o valor em octal
        i = i + 1;
    }

}

// base octal para a base decimal
void OctalDecimal(){

    char octal[20];
    int somatorio = 0;
    int i,qt;
    int cont =0;
    // vamos fazer a leitura
    printf("\nDigite um numero na base octal para a conversao de decimal: \n");
    scanf("%s", octal);

    qt = strlen(octal); // funcao criada pra retornar a quantidade de caracter de um vetor
    int inteiroOctal[qt];

    // conversao do vetor de caracter para um vetor de inteiros
    cont = 0;
    while(cont<qt){

        if(octal[cont] == '0'){
            inteiroOctal[cont] = 0;
        }
        if(octal[cont] == '1'){
            inteiroOctal[cont] = 1;
        }
        if(octal[cont] == '2'){
            inteiroOctal[cont] = 2;
        }
        if(octal[cont] == '3'){
            inteiroOctal[cont] = 3;
        }
        if(octal[cont] == '4'){
            inteiroOctal[cont] = 4;
        }
        if(octal[cont] == '5'){
            inteiroOctal[cont] = 5;
        }
        if(octal[cont] == '6'){
            inteiroOctal[cont] = 6;
        }
        if(octal[cont] == '7'){
            inteiroOctal[cont] = 7;
        }
        if(octal[cont] == '8'){
            inteiroOctal[cont] = 8;
        }
        if(octal[cont] == '9'){
            inteiroOctal[cont] = 9;
        }
        cont++;
    }
    inverte(inteiroOctal,qt);

    for(i = 0; i<qt; i++){

        // somatorio da multiplicação da posicao com 8 ^ i
        somatorio =+ (inteiroOctal[i] * pow( 8 , i));
    }
    printf("\nDecimal: %d\n", somatorio); // resultado
}
// decimal para hexa decimal
void DecimalHexa(){

    int decimal;
    int r;
    int q;
    int hexa[40];
    char auxiliarHexa[40];
    int i = 0;
    int cont = 0;
    int j;

    printf("\nDigite um numero em decimal para converter em Hexadecimal: \n");
    scanf("%d",&decimal);

    do{

        r = decimal % 16;
        q = decimal/16;
        hexa[cont] = r;
        decimal = q;

        cont++;
    }while(decimal != 0);

    inverte(hexa, cont);

    // Aqui vamos mudar o vetor para um vetor de caracter, já que hexadecimal utilizamos letras
   for(i=0; i<cont; i++){

        if(hexa[i] == 1){
            auxiliarHexa[i] = '1';
            printf("1");
        }
        if(hexa[i] == 2){
            auxiliarHexa[i] = '2';
            printf("2");
        }
        if(hexa[i] == 3){
            auxiliarHexa[i] = '3';
            printf("3");
        }
        if(hexa[i] == 4){
            auxiliarHexa[i] = '4';
            printf("4");
        }
        if(hexa[i] == 5){
            auxiliarHexa[i] = '5';
            printf("5");
        }
        if(hexa[i] == 6){
            auxiliarHexa[i] = '6';
            printf("6");
        }
        if(hexa[i] == 7){
            auxiliarHexa[i] = '7';
            printf("7");
        }
        if(hexa[i] == 8){
            auxiliarHexa[i] = '8';
            printf("8");
        }
        if(hexa[i] == 9){
            auxiliarHexa[i] = '9';
            printf("9");
        }
        if(hexa[i] == 10){
            auxiliarHexa[i] = 'A';
            printf("A");
        }
        if(hexa[i] == 11){
            auxiliarHexa[i] = 'B';
            printf("B");
        }
        if(hexa[i] == 12){
            auxiliarHexa[i] = 'C';
            printf("C");
        }
        if(hexa[i] == 13){
            auxiliarHexa[i] = 'D';
            printf("D");
        }
        if(hexa[i] == 14){
            auxiliarHexa[i] = 'E';
            printf("E");
        }
        if(hexa[i] == 15){
            auxiliarHexa[i] = 'F';
            printf("F");
        }
    }
       printf(" Hexadecimal\n");
       // printf("%s \n", auxiliarHexa);


}
// funcao para transformar base hexa para decimal
void HexaDecimal(){

    char hexa[20];
    int somatorio = 0;
    int i,qt;
    int cont = 0 ;
    printf("Digite um numero em Hexadecimal para a conversao em decimal: ");
    fflush(stdin);
    gets(hexa);

    qt = strlen(hexa);
    int inteiroHexa[qt];

    // convertemos o vetor de caracter para inteiro
    while(cont<qt){

        if(hexa[cont] == '0'){
            inteiroHexa[cont] = 0;
        }
        if(hexa[cont] == '1'){
            inteiroHexa[cont] = 1;
        }
        if(hexa[cont] == '2'){
            inteiroHexa[cont] = 2;
        }
        if(hexa[cont] == '3'){
            inteiroHexa[cont] = 3;
        }
        if(hexa[cont] == '4'){
            inteiroHexa[cont] = 4;
        }
        if(hexa[cont] == '5'){
            inteiroHexa[cont] = 5;
        }
        if(hexa[cont] == '6'){
            inteiroHexa[cont] = 6;
        }
        if(hexa[cont] == '7'){
            inteiroHexa[cont] = 7;
        }
        if(hexa[cont] == '8'){
            inteiroHexa[cont] = 8;
        }
        if(hexa[cont] == '9'){
            inteiroHexa[cont] = 9;
        }
        if(hexa[cont] == 'A' || hexa[cont] == 'a'){
            inteiroHexa[cont] = 10;
        }
        if(hexa[cont] == 'B' || hexa[cont] == 'b'){
            inteiroHexa[cont] = 11;
        }
        if(hexa[cont] == 'C' || hexa[cont] == 'c'){
            inteiroHexa[cont] = 12;
        }
        if(hexa[cont] == 'D' || hexa[cont] == 'd'){
            inteiroHexa[cont] = 13;
        }
        if(hexa[i] == 'E' || hexa[cont] == 'e'){
            inteiroHexa[cont] = 14;
        }
        if(hexa[cont] == 'F' || hexa[cont] == 'f'){
            inteiroHexa[cont] = 15;
        }

        cont++;
    }
    inverte(inteiroHexa,qt);

    // somatorio do valor multiplicado por 16^i
    while(i<qt){

        somatorio =+ (inteiroHexa[i]*pow(16, i));
        i++;
    }
    printf("\nNumero em decimal: %d\n", somatorio);
}
// Aqui passamos de Octal para Hexadecimal
void OctalHexa(){

    char octal[20];
    char aux[20];
    int v[50];
    int somatorio = 0;
    int i;
    int j;
    int cont = 0;
    int r,q;
    printf("Digite um numero em octal: ");
    scanf("%s", octal);

    // numero de caracteres
    int qt = strlen(octal);
    int inteiroOctal[qt];

    // passei de char para inteiro
    while(cont<qt){

        if(octal[cont] == '0'){
            inteiroOctal[cont] = 0;
        }
        if(octal[cont] == '1'){
            inteiroOctal[cont] = 1;
        }
        if(octal[cont] == '2'){
            inteiroOctal[cont] = 2;
        }
        if(octal[cont] == '3'){
            inteiroOctal[cont] = 3;
        }
        if(octal[cont] == '4'){
            inteiroOctal[cont] = 4;
        }
        if(octal[cont] == '5'){
            inteiroOctal[cont] = 5;
        }
        if(octal[cont] == '6'){
            inteiroOctal[cont] = 6;
        }
        if(octal[cont] == '7'){
            inteiroOctal[cont] = 7;
        }
        if(octal[cont] == '8'){
            inteiroOctal[cont] = 8;
        }
        if(octal[cont] == '9'){
            inteiroOctal[cont] = 9;
        }

        cont++;
    }

    // vamos inverter o vetor
    inverte(inteiroOctal,qt);

    cont = 0;

    while(cont<qt){

        somatorio+= (inteiroOctal[i] * pow( 8 , cont)); // somatorio de 8^cont vezes vetor

        cont++;
    }

    i = 0;
    while(somatorio != 0){

        r = somatorio % 16;
        q = somatorio/16;
       // printf("%d ", resto);
        v[i] = r;

        somatorio = q;

        i++;
    }

    inverte(v, i);

   for(cont=0; cont<i; cont++){

        if(v[cont] == 1){
            aux[cont] = '1';
        }
        if(v[cont] == 2){
            aux[cont] = '2';
        }
        if(v[cont] == 3){
            aux[cont] = '3';
        }
        if(v[cont] == 4){
            aux[cont] = '4';
        }
        if(v[cont] == 5){
            aux[cont] = '5';
        }
        if(v[cont] == 6){
            aux[cont] = '6';
        }
        if(v[cont] == 7){
            aux[cont] = '7';
        }
        if(v[cont] == 8){
            aux[cont] = '8';
        }
        if(v[cont] == 9){
            aux[cont] = '9';
        }
        if(v[cont] == 10){
            aux[cont] = 'A';
        }
        if(v[cont] == 11){
            aux[cont] = 'B';
        }
        if(v[cont] == 12){
            aux[cont] = 'C';
        }
        if(v[cont] == 13){
            aux[cont] = 'D';
        }
        if(v[cont] == 14){
            aux[cont] = 'E';
        }
        if(v[cont] == 15){
            aux[cont] = 'F';
        }
    }

        printf("Numero em Hexadecimal: \n");
        printf("%s\n", aux);

}
// Funcao que muda da base hexadecimal para o octal
void HexaOctal(){

    char H[20];
    int aux[50];
    int cont = 0;
    int somatorio = 0;
    int i,q,j;
    int k=0,r;
    printf("Digite um numero em Hexadecimal: ");
    scanf("%s", H);
    int qt;

    qt = strlen(H); // retorna quantidade de caracter
    int Hexa[qt];

    while(cont<qt){

        if(H[cont] == '0'){
            Hexa[cont] = 0;
        }
        if(H[cont] == '1'){
            Hexa[cont] = 1;
        }
        if(H[cont] == '2'){
            Hexa[cont] = 2;
        }
        if(H[cont] == '3'){
            Hexa[cont] = 3;
        }
        if(H[cont] == '4'){
            Hexa[cont] = 4;
        }
        if(H[cont] == '5'){
            Hexa[cont] = 5;
        }
        if(H[cont] == '6'){
            Hexa[cont] = 6;
        }
        if(H[cont] == '7'){
            Hexa[cont] = 7;
        }
        if(H[cont] == '8'){
            Hexa[cont] = 8;
        }
        if(H[cont] == '9'){
            Hexa[cont] = 9;
        }
        if(H[cont] == 'A'){
            Hexa[cont] = 10;
        }
        if(H[cont] == 'B'){
            Hexa[cont] = 11;
        }
        if(H[cont] == 'C'){
            Hexa[cont] = 12;
        }
        if(H[cont] == 'D'){
            Hexa[cont] = 13;
        }
        if(H[cont] == 'E'){
            Hexa[cont] = 14;
        }
        if(H[cont] == 'F'){
            Hexa[cont] = 15;
        }

        cont++;
    }

    inverte(Hexa,qt);
    cont = 0;
    while(cont<qt){

        somatorio =+ (Hexa[cont] * pow( 16 , cont));
        cont++;
    }
    cont = 0;
    while(somatorio != 0){

        r = somatorio % 8;
        q = somatorio/8;
        aux[cont] = r;

        somatorio = q;

        cont++;
    }

    inverte(aux, cont);

    while(k<cont){

        printf("%d", aux[k]);
        k++;
    }

    printf(" Octal\n");

}

void BinarioHexa(){

    char binario[50];
    int inteiroBinario[50];
    int i;
    int k=0;
    int somatorio=0;
    int qt;
    int aux[50];
    int cont = 0;
    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;
    printf("Digite um numero em binario: ");
    fflush(stdin);
    gets(binario);

    qt = strlen(binario); // retorna quantidade de caracter

    while(i<qt){

        if(binario[i]== '0'){
            inteiroBinario[i] = 0;
        }
        if(binario[i]== '1'){
            inteiroBinario[i] = 1;
        }

        i++;
    }
    inverte(inteiroBinario,qt);
    cont = 0;
    for(cont=0; cont<qt; cont++){

        // Tivemos que dividir o binario em grupos de 4 e calcular seu valor em Hexadecimal
        if(i<4){
            aux[0] += (inteiroBinario[i] * pow( 2 , cont));
        }
        if(i>=4 && i<8){
            aux[1] += (inteiroBinario[i] * pow( 2 , cont1));
            cont1++;
        }
        if(i>=8 && i<12){
            aux[2] += (inteiroBinario[i] * pow( 2 , cont2));
            cont2++;
        }
        if(i>=12 && i<16){
            aux[3] += (inteiroBinario[i] * pow( 2 , cont3));
            cont3++;
        }
    }
    inverte(aux,i);
    int j = 0;

    while(j<i){

        if(aux[j]>= 1 && aux[j]<10){

            printf("%d", aux[j]);
        }

        if(aux[j] == 10){
            printf("A");
        }
        if(aux[j] == 11){
            printf("B");
        }
        if(aux[j] == 12){
            printf("C");
        }
        if(aux[j] == 13){
            printf("D");
        }
        if(aux[j] == 14){
            printf("E");
        }
        if(aux[j] == 15){
            printf("F");
        }

        j++;
    }
}
// conversão de Hexadecimal para binario
void HexaBinario(){

    char hexadecimal[50];
    int qt;
    printf("Digite um numero em hexadecimal: \n");
    fflush(stdin);
    gets(hexadecimal);
    int CONT=0;
    qt = strlen(hexadecimal);

    while(CONT<qt){

        if(hexadecimal[CONT] == '1'){
            printf("0001");
        }

        if(hexadecimal[CONT] == '2'){
            printf("0010");
        }

        if(hexadecimal[CONT] == '3'){
            printf("0100");
        }

        if(hexadecimal[CONT] == '4'){
            printf("0100");
        }

        if(hexadecimal[CONT] == '5'){
            printf("0101");
        }

        if(hexadecimal[CONT] == '6'){
            printf("0110");
        }

        if(hexadecimal[CONT] == '7'){
            printf("0111");
        }
        if(hexadecimal[CONT] == '8'){
            printf("1000");
        }
        if(hexadecimal[CONT] == '9'){
            printf("1001");
        }
        if(hexadecimal[CONT] == 'A' || hexadecimal[CONT] == 'a'){
            printf("1010");
        }
        if(hexadecimal[CONT] == 'B' || hexadecimal[CONT] == 'b'){
            printf("1011");
        }
        if(hexadecimal[CONT] == 'C' || hexadecimal[CONT] == 'c'){
            printf("1100");
        }
        if(hexadecimal[CONT] == 'D' || hexadecimal[CONT] == 'd'){
            printf("1101");
        }
        if(hexadecimal[CONT] == 'F' || hexadecimal[CONT] == 'f'){
            printf("1111");
        }

        CONT++;
    }

}
int main(){
    int opcao;
    char resposta;
    do{
        opcao = menu();

        switch(opcao){

        case 1: DecimalBinaria();
            break;
        case 2: BinarioDecimal();
            break;
        case 3: DecimalOctal();
            break;
        case 4: OctalDecimal();
            break;
        case 5: DecimalHexa();
            break;
        case 6:HexaDecimal();
            break;
        case 7: OctalHexa();
            break;
        case 8: HexaOctal();
            break;
        case 9: BinarioHexa();
            break;
        case 10: HexaBinario();
            break;
        default: printf("Nao existe essa opcao\n");
            break;
        }

        printf("\nDeseja executar o programa novamente ? ");
        scanf(" %c", &resposta);

    }while(resposta == 's' || resposta == 'S');
    return 0;
}
