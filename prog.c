/* 

ENES YIGIT
28.06.2019

*/
#include<stdio.h>

int biggestAdress(int netAdress, int subAdress);
int  decToBinary(int * arr,int number);
int main()
{
int IP1, IP2, IP3, IP4, subData, networkIP1 = 0, networkIP2 = 0, networkIP3 = 0, networkIP4 = 0;
int broadCastIP1 =0 ,broadCastIP2 =0, broadCastIP3 =0, broadCastIP4 =0;
int subIP1 =0, subIP2 =0, subIP3 =0, subIP4 = 0;
int subArray[32] ={ 0 };
int subArrayIP1[8] = {0};
int subArrayIP2[8] = {0};
int subArrayIP3[8] = {0};
int subArrayIP4[8] = {0};
int arrayIP1[8] = {0};
int arrayIP2[8] = {0};
int arrayIP3[8] = {0};
int arrayIP4[8] = {0};
int multiplier = 1;


printf("Lutfen ip adresini '0.0.0.0/0' formatında giriniz: ");
scanf("%d.%d.%d.%d/%d",&IP1, &IP2, &IP3, &IP4, &subData);

for(int i = 0; i < subData; i++ )
subArray[i] = 1;


for(int j = 0; j < 8; j++)
subArrayIP1[j] = subArray[7-j];

for(int j = 0; j < 8; j++)
subArrayIP2[j] = subArray[7-j + 8];

for(int j = 0; j < 8; j++)
subArrayIP3[j] = subArray[7-j + 16];

for(int j = 0; j < 8; j++)
subArrayIP4[j] = subArray[7-j + 24];

for(int i =0; i < 8; i++)
{
if( i == 0)
multiplier = 1;
subIP1 +=(multiplier * subArrayIP1[i]);
multiplier = multiplier *2;
}

for(int i =0; i < 8; i++)
{
if( i == 0)
multiplier = 1;
subIP2 +=(multiplier * subArrayIP2[i]);
multiplier = multiplier *2;
}

for(int i =0; i < 8; i++)
{
if( i == 0)
multiplier = 1;
subIP3 +=(multiplier * subArrayIP3[i]);
multiplier = multiplier *2;

}

for(int i =0; i < 8; i++)
{
if( i == 0)
multiplier = 1;
subIP4 +=(multiplier * subArrayIP4[i]);
multiplier = multiplier *2;
}

decToBinary(arrayIP1 ,IP1);
decToBinary(arrayIP2 ,IP2);
decToBinary(arrayIP3 ,IP3);
decToBinary(arrayIP4 ,IP4);

for(int i =0; i < 8; i++)
{
arrayIP1[i] = arrayIP1[i] & subArrayIP1[i];
if( i == 0)
multiplier = 1;
networkIP1 +=(multiplier * arrayIP1[i]);
multiplier = multiplier *2;

}

for(int i =0; i < 8; i++)
{
arrayIP2[i] = arrayIP2[i] & subArrayIP2[i];
if( i == 0)
multiplier = 1;
networkIP2 +=(multiplier * arrayIP2[i]);
multiplier = multiplier *2;

}

for(int i =0; i < 8; i++)
{
arrayIP3[i] = arrayIP3[i] & subArrayIP3[i];
if( i == 0)
multiplier = 1;
networkIP3 +=(multiplier * arrayIP3[i]);
multiplier = multiplier *2;

}

for(int i =0; i < 8; i++)
{
arrayIP4[i] = arrayIP4[i] & subArrayIP4[i];
if( i == 0)
multiplier = 1;
networkIP4 +=(multiplier * arrayIP4[i]);
multiplier = multiplier *2;

}
printf("\n Network IP : %d.%d.%d.%d", networkIP1, networkIP2, networkIP3, networkIP4);
printf("\n Subnet Mask : %d.%d.%d.%d", subIP1, subIP2, subIP3, subIP4);

broadCastIP1 = biggestAdress(networkIP1,subIP1);
broadCastIP2 = biggestAdress(networkIP2,subIP2);
broadCastIP3 = biggestAdress(networkIP3,subIP3);
broadCastIP4 = biggestAdress(networkIP4,subIP4);


printf("\n Broadcast adress : %d.%d.%d.%d",broadCastIP1,broadCastIP2 , broadCastIP3,broadCastIP4);
/*if( subData < 9)
printf("\n A sınıfı adres subnet mask : 255.0.0.0");

else if (IP1 < 192)
printf("\n B sınıfı adres subnet mask : 255.255.0.0");

else if (IP1 < 224)
printf("\n C sınıfı adres subnet mask : 255.255.255.0");

else if (IP1 > 224)
printf("\n Yanlis bir deger girdiniz !!");
*/

//printf("\n %d.%d.%d.%d/%d \n",IP1, IP2, IP3, IP4, subData);
return 0;
}

int decToBinary(int * arr,int number)
{
for(int j = 0; j < 8; j++)
arr[j] = 0;
int i =0;

while( number > 0 )
{
arr[i] = number % 2;
number = number / 2;
i++; 

}

}

int biggestAdress(int netAdress, int subAdress)
{
int multiplier = 1;
int biggestNumber = 255,biggestNumberArr[8], number = 0;
int netAdressArr[8], subAdressArr[8], andArr[8];
decToBinary(netAdressArr,netAdress);
decToBinary(subAdressArr,subAdress);


while(biggestNumber > 0)
{
decToBinary(biggestNumberArr,biggestNumber );
number = 0;
for(int i =0; i < 8; i++)
{
andArr[i] = biggestNumberArr[i] & subAdressArr[i];
if( i == 0)
multiplier = 1;

number +=(multiplier * andArr[i]);
multiplier = multiplier *2;
}

if( number == netAdress)
break;

biggestNumber--;
}
return biggestNumber;
}



