import java.io.*;
class BubbleSort1
{
    void main()throws Exception
    {
        int a[]={},i,c,j,n;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter array size");
        n=Integer.parseInt(br.readLine());
        a=new int[n];
        System.out.println("Enter array no.s");
        for(i=0;i<n;i++)
        a[i]=Integer.parseInt(br.readLine());
        
         for(i=0;i<a.length-1;i++)
        {
            for(j=0;j<a.length-1;j++)
            if(a[j]>a[j+1])
            {
                c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
        System.out.println("Elements after sorting :");        
        for(i=0;i<a.length;i++)
        System.out.println(a[i]);        
        
    }
} 