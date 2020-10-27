 #include<stdio.h>
void main()
{
 int r,c,a,z=0,nz=0,k[2]={0,0},cnt=0;
 printf("Enter the number of rows:");
 scanf("%d",&r);
 
 printf("Enter the number of colum1ns:");
 scanf("%d",&c);
 
 a=(r*c)/2;
 int m[2][r][c],add[r*c],nzero[2][a],row[2][a],col[2][a];
 for(int f=0;f<2;f++)
 {
  printf("Enter matrix number %d:\n",(f+1));
  for(;;)
  {
   for(int i=0;i<r;i++)
   for(int j=0;j<c;j++)
   {
    scanf("%d",&m[f][i][j]);
    if(m[f][i][j]==0)
    z++;
    else
    {
     nz++;
     row[f][k[f]]=i;
     col[f][k[f]]=j;
     nzero[f][k[f]]=m[f][i][j];
    k[f]++;
    }
   }
   if(z>=nz)
   break;
   else
   printf("\nEnter elements again\n");
  }  
  z=0;
  nz=0;
 }
 for(int f=0;f<2;f++)
 {
  printf("Srno.  Row index  Col index   matrix element\n");
  printf("-------------------------------------------\n");
  for(int i=0;i<k[f];i++)
  printf("%d        %d        %d            %d\n",(i+1),row[f][i],col[f][i],nzero[f][i]);
  printf("-------------------------------------------\n\n");
 }
 for(int f=0;f<2;f++)
 {
  for(int q=0;q<k[f];q++)
  {
   add[q]=0;
   if(row[0][q]==row[1][q] && col[0][q]==col[1][q])
   add[q]=add[q]+nzero[f][q];
   else
   add[q]=nzero[f][q];
   cnt++;
  }
 }
 printf("SUM Matrix\n");
 for(int f=0;f<2;f++)
 for(int i=0;i<k[f];i++)
 printf("%d %d %d\n",row[f][i],col[f][i],add[]);
}
